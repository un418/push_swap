#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

SCRIPT_DIR="$(dirname "$0")"

./push_swap "$@" 2> "$SCRIPT_DIR/test_out.txt"

echo "Error" > "$SCRIPT_DIR/expected_out.txt"

if diff -q "$SCRIPT_DIR/expected_out.txt" "$SCRIPT_DIR/test_out.txt" > /dev/null; then
	echo -e "${GREEN}[OK] stderr matched${RESET}"
else
	echo -e "${RED}[KO] difference:${RESET}"
	diff -u "$SCRIPT_DIR/expected_out.txt" "$SCRIPT_DIR/test_out.txt"
fi
