*This project has been created as part of the 42 curriculum by pficcare, adaferna.*

---

# push_swap

> Sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

---

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a restricted set of operations, while minimizing the total number of moves.

The project enforces a rigorous understanding of algorithmic complexity by requiring four distinct sorting strategies, each targeting a different complexity class. The program selects a strategy at runtime — either manually via a flag or automatically based on a **disorder metric** computed from the initial state of the stack.

---

## Instructions

### Requirements

- C compiler (`cc`) with flags `-Wall -Wextra -Werror`
- GNU/Linux or macOS terminal
- **Bash shell** (see note below)

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

### Shell compatibility — important

**This program must be run in a Bash shell.** If you are using ZSH or another shell, switch to Bash first:

```bash
bash
```

Then run the program normally:

```bash
ARG="5 4 3 2 1"
./push_swap $ARG
```

### Correct usage examples

```bash
./push_swap 5 4 3 2 1                    # correct
ARG="5 4 3 2 1" && ./push_swap $ARG      # correct
./push_swap --complex 3 1 4 1 5 9        # correct
./push_swap --bench --adaptive 5 4 3 2 1 # WRONG — bench must come after strategy
./push_swap --adaptive --bench 5 4 3 2 1 # correct
./push_swap ARG="5 4 3 2 1"              # WRONG — do not pass the variable assignment
./push_swap "5 4 3 2 1"                  # WRONG — do not quote the whole list
```

### Flag rules

- You can select **one strategy flag only** per run.
- The `--bench` flag as is an optional flag is the only one who can be use with an other flag.
- `--bench` alone is valid — the program will run in adaptive mode by default.
- Passing two strategy flags or an unknown flag will print `Error`.

For more details on argument passing:
- https://42born2code.slack.com/archives/CMX2R5JSW/p1657522228588669
- https://app.slack.com/client/T039P7U66/CMX2R5JSW

### Error handling

The program prints `Error` on stderr and exits when:
- An argument is not a valid integer
- A value is outside the range `[-2147483648, 2147483647]`
- Duplicate values are detected
- An unknown or malformed flag is passed
- Two strategy flags are provided
- If you input an amout of integer above the MAX_INT_LIMIT, expect an undefined behavior.

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

## Algorithms

All four strategies are embedded in the binary and selectable at runtime.

### Disorder metric

Before any move, the program computes a **disorder score** between `0.0` and `1.0`:

```
disorder = number_of_inversions / total_pairs
```

An inversion is any pair `(i, j)` where `i` appears before `j` in the stack but `a[i] > a[j]`. A score of `0` means the stack is already sorted; `1` means worst-case order.

This metric is computed on the initial stack and drives the adaptive strategy.

### Strategy 1 — Simple `O(n²)` — `--simple`

**Selection sort by minimum extraction.**

Finds the minimum element remaining in stack a, brings it to the top using the cheapest rotation (`ra` or `rra` depending on position), and pushes it onto b. Repeats until 3 elements remain, sorts them with `sort_3`, then pushes all of b back onto a.

Complexity: each extraction costs at most `n/2` rotations, repeated `n` times → `O(n²)` operations.

Best for: low-disorder inputs (few inversions).

### Strategy 2 — Medium `O(n√n)` — `--medium`

**Chunk sort with optimal rotation.**

Divides the index range `[0, n-1]` into `√n` chunks of equal size. For each chunk, scans stack a sequentially and pushes any element whose index falls within the current chunk range onto b, rotating past others. Once all elements are on b, pulls them back onto a by always finding and bringing the maximum to the top of b using `rb`/`rrb`.

Complexity: `√n` passes over n elements → `O(n√n)` operations.

Best for: medium-disorder inputs.

### Strategy 3 — Complex `O(n log n)` — `--complex`

**Radix sort LSD (Least Significant Bit first) on indices.**

Elements are indexed from `0` to `n-1` before sorting begins. For each bit position from LSB to MSB (`log₂(n)` passes total): elements whose current bit is `0` are pushed onto b, elements with bit `1` are rotated to the back of a. Then all of b is pushed back onto a. After `log₂(n)` passes, a is fully sorted.

Complexity: `log₂(n)` passes × `n` operations per pass → `O(n log n)` operations.

Best for: high-disorder inputs and large datasets. Most consistent performance regardless of initial order.

### Strategy 4 — Adaptive — `--adaptive` (default)

**Disorder-driven strategy selection.**

Computes the disorder metric before sorting and routes to the appropriate algorithm:

| Disorder | Algorithm used | Complexity |
|----------|---------------|------------|
| `< 0.2` | Simple (selection sort) | `O(n²)` |
| `0.2 ≤ d < 0.5` | Medium (chunk sort) | `O(n√n)` |
| `≥ 0.5` | Complex (radix LSD) | `O(n log n)` |

This is the default behavior when no strategy flag is provided.

**Threshold rationale:** for low disorder, most elements are already near their correct position — a simple local-fix approach like selection sort is cheap. For medium disorder, chunk sort benefits from partial ordering. For high disorder, radix sort's consistent linear-pass structure outperforms comparison-based approaches.

---

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
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5
[bench] ra: 2  rb: 1  rr: 0  rra: 0  rrb: 0  rrr: 0
```

### Verify with checker

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker $ARG   # should print OK
```

---

## Implementation notes

The stacks are implemented as **doubly circular linked lists**. The head pointer always points to the top of the stack. Operations like `rotate` and `reverse_rotate` are O(1) — they simply move the head pointer forward or backward without touching any node.

Each integer receives a **normalized index** from `0` to `n-1` before sorting. Algorithms work on these indices rather than raw values, making comparison and bit manipulation stable and bounded.

---

## Resources

- [42 push_swap subject](https://cdn.intra.42.fr/pdf/pdf/136659/en.push_swap.pdf)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Big-O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Sorting algorithm comparison](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [42 Slack — argument passing details](https://42born2code.slack.com/archives/CMX2R5JSW/p1657522228588669)

### AI usage

Claude (Anthropic) was used during this project for:
- Discussing algorithm choices and their complexity implications in the push_swap operation model
- Help, theory and pseudo code for implementing algorithm logic.
- Drafting this README

All AI-generated content was reviewed, tested, and validated by both contributors before integration. No code was used without full understanding of its behavior.

Project made in colaboration between Adaferna and Pficcare.