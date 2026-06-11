*This project has been created as part of the 42 curriculum by pficcare, adaferna.*

---

# push_swap

> Sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.


## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a restricted set of operations, while minimizing the total number of moves.

The project enforces a rigorous understanding of algorithmic complexity by requiring four distinct sorting strategies, each targeting a different complexity class.  
The program selects a strategy at runtime, either manually via a flag or automatically based on a **disorder metric** computed from the initial state of the stack.


## Instructions

### Requirements

- C compiler (`cc`) with flags `-Wall -Wextra -Werror`
- GNU/Linux or macOS terminal
- **Bash** recommended (Zsh works with `setopt SH_WORD_SPLIT`, see note below)

### Compilation

```bash
make        # build push_swap
make clean  # remove object files
make fclean # remove object files and binary
make re     # full rebuild
```

### Usage

```bash
./push_swap 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --bench 5 4 3 2 1
./push_swap --adaptive --bench 5 4 3 2 1
```

### Shell compatibility (important)

When you pass the numbers directly, every shell behaves the same:

```bash
./push_swap 5 4 3 2 1
```

The difference shows up only when you store the list in a **variable** and rely on the shell to split it into separate arguments:

```bash
ARG="5 4 3 2 1"
./push_swap $ARG
```

- In **Bash**, `$ARG` is split on spaces into five arguments → works as expected.
- In **Zsh** (the default on many machines), `$ARG` is **not** word-split: the whole string is passed as a single argument `"5 4 3 2 1"`, which is not a valid integer → the program prints `Error`.

**Zsh users, two ways to get Bash-like behavior:**

```zsh
# Option 1: enable word splitting for the current shell, then run normally
setopt SH_WORD_SPLIT
./push_swap $ARG

# Option 2: drop into a Bash shell first
bash
./push_swap $ARG
```

#### Why we don't handle this inside the program

A single argument that contains spaces (`"5 4 3 2 1"`) is, by definition, not a valid integer, so rejecting it is the correct behavior.  
The issue is never in `push_swap` itself, it comes purely from how Bash and Zsh expand variables differently.  
Silently accepting and re-splitting such an argument would hide real input errors and diverge from the way the subject and the checker feed arguments, so we deliberately keep the parsing strict.

For more details on argument passing and word splitting:
- https://42born2code.slack.com/archives/CMX2R5JSW/p1657522228588669

### Usage examples: valid and invalid

```bash
# Valid
./push_swap 5 4 3 2 1                       # default (adaptive) strategy
./push_swap --complex 3 1 4 5 9 2           # force a specific strategy
./push_swap --bench --adaptive 5 4 3 2 1    # strategy flag + --bench
./push_swap --adaptive --bench 5 4 3 2 1    # flag order does not matter
ARG="5 4 3 2 1" && ./push_swap $ARG         # variable list (Bash, or Zsh + SH_WORD_SPLIT)

# Invalid: every line below prints Error on stderr
./push_swap --adaptive --simple 5 4 3 2 1   # two strategy flags
./push_swap --complex 3 1 4 1 5 9           # duplicate value (1 appears twice)
./push_swap ARG="5 4 3 2 1"                 # the assignment is passed as one argument
./push_swap "5 4 3 2 1"                     # the whole list quoted as one argument
```

### Flag rules

- You can select **one strategy flag only** per run.
- `--bench` is the only optional flag that may be combined with a strategy flag.
- `--bench` alone is valid, the program will run in adaptive mode by default.
- Passing two strategy flags or an unknown flag will print `Error`.

### Error handling

The program prints `Error` on stderr and exits when:
- An argument is not a valid integer
- A value is outside the range `[-2147483648, 2147483647]`
- Duplicate values are detected
- An unknown or malformed flag is passed
- Two strategy flags are provided

---

### Operations available

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack a |
| `sb` | Swap the first two elements of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top of b onto a |
| `pb` | Push the top of a onto b |
| `ra` | Rotate a upward (first becomes last) |
| `rb` | Rotate b upward (first becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate a (last becomes first) |
| `rrb` | Reverse rotate b (last becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## Data structure

The stacks are implemented as **doubly circular linked lists**, with the head pointer always marking the top of the stack. Because the list is circular and doubly linked, `rotate` and `reverse_rotate` run in O(1): they only move the head pointer forward or backward, no node is touched.

**Why this structure?**  
Of the options available, the doubly circular linked list is the one that maps most naturally onto the *stack* concept the subject asks for: a clear top and bottom, cheap pushes and pops, and rotations that wrap around for free.  
It was also a deliberate choice on our side: we wanted to practice this kind of structure to sharpen our handling of pointer manipulation on linked lists.

Each node also carries a **normalized index** from `0` to `n-1`, assigned before sorting starts.  
The algorithms then work on these indices rather than the raw values, which keeps comparisons and bit manipulation stable and bounded.

## Algorithms

All four strategies are embedded in the binary and selectable at runtime.

### Disorder metric

Before any move, the program computes a **disorder score** between `0.0` and `1.0`:

```
disorder = number_of_inversions / total_pairs
```

An inversion is any pair `(i, j)` where `i` appears before `j` in the stack but `a[i] > a[j]`. A score of `0` means the stack is already sorted; `1` means worst-case order.

This metric is computed on the initial stack and drives the adaptive strategy.

### Strategy 1 - Simple `O(n²)` - `--simple`

**Selection sort by minimum extraction.**

Finds the minimum element remaining in stack a, brings it to the top using the cheapest rotation (`ra` or `rra` depending on position), and pushes it onto b. Repeats until 3 elements remain, sorts them with `sort_3`, then pushes all of b back onto a.

Complexity: each extraction costs at most `n/2` rotations, repeated `n` times → `O(n²)` operations.

Best for: low-disorder inputs (few inversions).

### Strategy 2 - Medium `O(n√n)` - `--medium`

**Chunk sort with optimal rotation.**

Divides the index range `[0, n-1]` into `√n` chunks of equal size. For each chunk, scans stack a sequentially and pushes any element whose index falls within the current chunk range onto b, rotating past others. Once all elements are on b, pulls them back onto a by always finding and bringing the maximum to the top of b using `rb`/`rrb`.

Complexity: `√n` passes over n elements → `O(n√n)` operations.

Best for: medium-disorder inputs.

### Strategy 3 - Complex `O(n log n)` - `--complex`

**Radix sort LSD (Least Significant Bit first) on indices.**

Elements are indexed from `0` to `n-1` before sorting begins. For each bit position from LSB to MSB (`log₂(n)` passes total): elements whose current bit is `0` are pushed onto b, elements with bit `1` are rotated to the back of a. Then all of b is pushed back onto a. After `log₂(n)` passes, a is fully sorted.

Complexity: `log₂(n)` passes × `n` operations per pass → `O(n log n)` operations.

Best for: high-disorder inputs and large datasets. Most consistent performance regardless of initial order.

### Strategy 4 - Adaptive - `--adaptive` (default)

**Disorder-driven strategy selection.**

Computes the disorder metric before sorting and routes to the appropriate algorithm:

| Disorder | Algorithm used | Complexity |
|----------|---------------|------------|
| `< 0.2` | Simple (selection sort) | `O(n²)` |
| `0.2 ≤ d < 0.5` | Medium (chunk sort) | `O(n√n)` |
| `≥ 0.5` | Complex (radix LSD) | `O(n log n)` |

This is the default behavior when no strategy flag is provided.

**Threshold rationale:**  
- For low disorder, most elements are already near their correct position, so a simple local-fix approach like selection sort is cheap.  
- For medium disorder, chunk sort benefits from partial ordering.  
- For high disorder, radix sort's consistent linear-pass structure outperforms comparison-based approaches.



## Performance targets

| Input size | Minimum (pass) | Good | Excellent |
|------------|---------------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

### Benchmark mode

Run with `--bench` to display sorting metrics on stderr after execution:

```bash
./push_swap --adaptive --bench 5 4 3 2 1 2>/dev/null   # ops on stdout only
./push_swap --adaptive --bench 5 4 3 2 1 2>bench.txt   # save metrics to file
cat bench.txt
```

Output format:
```
[bench] disorder: 100.00%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 10
[bench] sa: 1 sb: 0 ss: 0  pa: 2  pb: 2
[bench] ra: 3 rb: 1 rr: 0 rra: 1  rrb: 0 rrr: 0
```

### Verify with checker

On larger, random inputs, generate the numbers with `shuf` and pipe the output straight into the checker:

```bash
# 50 random numbers between 1 and 1000
# sort and verify in one go
shuf -i 1-1000 -n 50 > nums.txt; ./push_swap $(cat nums.txt) | ./checker_linux $(cat nums.txt)   # should print OK

# how many operations were used?
./push_swap $(cat nums.txt) | wc -l

# same input with --bench: checker reads stdout, metrics go to a file
./push_swap --bench $(cat nums.txt) 2> bench.txt | ./checker_linux $(cat nums.txt)
cat bench.txt
```


## Resources

- [42 push_swap subject](https://cdn.intra.42.fr/pdf/pdf/136659/en.push_swap.pdf)
- [Radix sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Big-O notation - Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Sorting algorithm comparison](https://en.wikipedia.org/wiki/Sorting_algorithm)

### AI usage

Claude (Anthropic) was used during this project for:
- Discussing algorithm choices and their complexity implications in the push_swap operation model
- Help, theory and pseudo code for implementing algorithm logic.
- Drafting this README

All AI-generated content was reviewed, tested, and validated by both contributors before integration. No code was used without full understanding of its behavior.


## Collaboration

This project was built by **adaferna** and **pficcare** working together. We chose a
**feature-branch + pull-request** workflow: each feature lived on its own branch and was
merged through a PR. Every PR was peer-reviewed by the other author, which let us share
knowledge progressively and made sure both of us understand and can defend the whole
codebase.

You can follow our git project management here: <https://github.com/un418/push_swap>

Claude (Anthropic) was also used as an **MCP experiment** to enrich the descriptions of our
git issues and pull requests. The tasks themselves were always defined by us first, and
Claude was explicitly instructed **not to provide any technical solution** while enriching
the tickets.