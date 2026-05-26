#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

./push_swap "$@" 2> test_out.txt

echo "Error" > expected_out.txt

if diff -q expected_out.txt test_out.txt > /dev/null; then
	echo -e "${GREEN}[OK] stderr matched${RESET}"
else
	echo -e "${RED}[KO] difference:${RESET}"
	diff -u expected_out.txt test_out.txt
fi
