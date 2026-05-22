/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaferna <adaferna@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:40:46 by adaferna          #+#    #+#             */
/*   Updated: 2026/05/22 13:57:08 by adaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
More info here : https://github.com/un418/push_swap/issues/16

BUILD
cd test
cc -Wall -Wextra -Werror test_input.c -o test_input

TEST

From PDF subject:
- shuf -i 0-9999 -n 20 > args.txt ; ./test_input $(cat args.txt) | wc -l
- ARG="4 67 3 87 23"; ./test_input $ARG
- ./test_input --simple 5 4 3 2 1

From rumours:
- ./test_input --simple "5 4 3 2 1"

*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
for (int j = 0; j < argc; j++)
	printf("argv[%d]: %s\n", j, argv[j]);
exit(EXIT_SUCCESS);
}

