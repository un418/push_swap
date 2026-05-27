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

# checks stderr="Error" and exit=1 in one run
check_error() {
	label="$1"; shift
	got_stderr="$("$PROG" "$@" 2>&1 >/dev/null)"
	got_exit=$?
	report "$label (stderr)" "$got_stderr" "Error"
	report "$label (exit)"   "$got_exit"   "1"
}

# checks exit=0
check_success() {
	label="$1"; shift
	"$PROG" "$@" >/dev/null 2>&1
	report "$label" "$?" "0"
}

# captures stdout only — for future sorting validation (pipe into checker_42)
check_stdout() {
	label="$1"; expected="$2"; shift 2
	got="$("$PROG" "$@" 2>/dev/null)"
	report "$label" "$got" "$expected"
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
check_error "letter"              1 2 a
check_error "int underflow"       1 2 -2147483649
check_error "int overflow"        1 2 2147483648
check_error "invalid number --43" 1 2 --43
check_error "invalid number ++43" 1 2 ++43
check_error "lone +"              +
check_error "lone -"              -
check_error "flag after numbers"  1 2 --simple

echo -e "${YELLOW}\n--- parser : invalid flags ---${RESET}"
check_error "unknown flag"             --unvalid 1 2 3
check_error "--adaptive --simple"      --adaptive --simple 1 2 3
check_error "--simple --complex"       --simple --complex 1 2 3
check_error "--adaptive repeated"      --adaptive --adaptive 1 2 3
check_error "--simple repeated"        --simple --simple 1 2 3
check_error "--bench repeated"         --bench --bench 1 2 3
check_error "--medium repeated"        --medium --medium 1 2 3
check_error "--bench first (adaptive)" --bench --adaptive 1 2 3
check_error "--bench first (simple)"   --bench --simple 1 2 3
check_error "--bench first (complex)"  --bench --complex 1 2 3
check_error "3 flags"                  --simple --bench --complex 1 2 3

echo -e "${YELLOW}\n--- parser : valid numbers ---${RESET}"
check_success "single number"     42
check_success "positive sign +42" +42
check_success "zero"              0
check_success "+0"                +0
check_success "-0"                -0
check_success "negative numbers"  -1 -2 -3
check_success "INT_MAX"           2147483647
check_success "INT_MIN"           -2147483648
check_success "already sorted"    1 2 3

echo -e "${YELLOW}\n--- parser : valid flags ---${RESET}"
check_success "--adaptive"             --adaptive 1 2 3
check_success "--simple"               --simple 1 2 3
check_success "--medium"               --medium 1 2 3
check_success "--complex"              --complex 1 2 3
check_success "--bench alone"          --bench 1 2 3
check_success "--adaptive --bench"     --adaptive --bench 1 2 3
check_success "--simple --bench"       --simple --bench 1 2 3
check_success "--medium --bench"       --medium --bench 1 2 3
check_success "--complex --bench"      --complex --bench 1 2 3
check_success "flag only, no numbers"  --simple


# TODO: once ops are implemented, use check_stdout to pipe into checker_42

summary
exit $(( failed != 0 ))
