#!/bin/bash
# Integration tests -- run: bash test/integration_test.sh

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROG="$DIR/../push_swap"

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
RESET='\033[0m'

passed=0
failed=0

# $1 = label, $2 = got, $3 = expected
report() {
	if [ "$2" = "$3" ]; then
		echo -e "${GREEN}[PASS]${RESET} $1"
		((passed++))
	else
		echo -e "${RED}[FAIL]${RESET} $1  (got: [$2] / expected: [$3])"
		((failed++))
	fi
}

# $1 = label, $2 = expected, $@ = program args
# shift 2 drops $1 and $2, so $@ becomes the program args only
check_stderr() {
	label="$1"; expected="$2"; shift 2
	got="$("$PROG" "$@" 2>&1 >/dev/null)"
	report "$label" "$got" "$expected"
}

check_stdout() {
	label="$1"; expected="$2"; shift 2
	got="$("$PROG" "$@" 2>/dev/null)"
	report "$label" "$got" "$expected"
}

check_exit() {
	label="$1"; expected="$2"; shift 2
	"$PROG" "$@" >/dev/null 2>&1
	report "$label" "$?" "$expected"
}

summary() {
	echo
	if [ "$failed" -eq 0 ]; then
		echo -e "${GREEN}==> $passed/$((passed + failed)) passed${RESET}"
	else
		echo -e "${RED}==> $passed/$((passed + failed)) passed ($failed failed)${RESET}"
	fi
}

echo -e "${YELLOW}--- parser : invalid numbers ---${RESET}"
check_stderr "letter"                    "Error"  1 2 a
check_stderr "int underflow"             "Error"  1 2 -2147483649
check_stderr "int overflow"              "Error"  1 2 2147483648
check_stderr "invalid number --43"       "Error"  1 2 --43
check_stderr "invalid number ++43"       "Error"  1 2 ++43
check_stderr "lone +"                    "Error"  +
check_stderr "lone -"                    "Error"  -
check_stderr "flag after numbers"        "Error"  1 2 --simple

echo -e "${YELLOW}\n--- parser : invalid flags ---${RESET}"
check_stderr "unknown flag"              "Error"  --unvalid 1 2 3
check_stderr "--adaptive --simple"       "Error"  --adaptive --simple 1 2 3
check_stderr "--simple --complex"        "Error"  --simple --complex 1 2 3
check_stderr "--adaptive repeated"       "Error"  --adaptive --adaptive 1 2 3
check_stderr "--simple repeated"         "Error"  --simple --simple 1 2 3
check_stderr "--bench repeated"          "Error"  --bench --bench 1 2 3
check_stderr "--medium repeated"         "Error"  --medium --medium 1 2 3
check_stderr "--bench first (adaptive)"  "Error"  --bench --adaptive 1 2 3
check_stderr "--bench first (simple)"    "Error"  --bench --simple 1 2 3
check_stderr "--bench first (complex)"   "Error"  --bench --complex 1 2 3
check_stderr "3 flags"                   "Error"  --simple --bench --complex 1 2 3

echo -e "${YELLOW}\n--- parser : valid numbers ---${RESET}"
check_exit "single number"     0  42
check_exit "positive sign +42" 0  +42
check_exit "zero"              0  0
check_exit "+0"                0  +0
check_exit "-0"                0  -0
check_exit "negative numbers"  0  -1 -2 -3
check_exit "INT_MAX"           0  2147483647
check_exit "INT_MIN"           0  -2147483648
check_exit "already sorted"    0  1 2 3

echo -e "${YELLOW}\n--- parser : valid flags ---${RESET}"
check_exit "--adaptive"              0  --adaptive 1 2 3
check_exit "--simple"                0  --simple 1 2 3
check_exit "--medium"                0  --medium 1 2 3
check_exit "--complex"               0  --complex 1 2 3
check_exit "--bench alone"           0  --bench 1 2 3
check_exit "--adaptive --bench"      0  --adaptive --bench 1 2 3
check_exit "--simple --bench"        0  --simple --bench 1 2 3
check_exit "--medium --bench"        0  --medium --bench 1 2 3
check_exit "--complex --bench"       0  --complex --bench 1 2 3
check_exit "flag only, no numbers"   0  --simple


# TODO: once ops are implemented, pipe $OUT into checker_42 to validate the sort

summary
exit $(( failed != 0 ))
