/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:02:46 by maroard           #+#    #+#             */
/*   Updated: 2025/12/10 13:18:40 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <push_swap.h>

static int	is_number(char *arg)
{
	size_t	i;

	i = 0;
	while ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == ' ')
		i++;
	if (!arg[i])
		return (0);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int main()
{
    const char *tests[] = {
        "3 5 9 7 6 1 4 8",
        "-32 +5",
        "-15 ++5454",
        "+ 123",
        "--45",
        " -45",
        "+-2",
        "124a1",
        "ABC",
        " 1 2 3 --4",
        "2        4   5       6      7",
        "-2+45-4-5+7+96",
    };

    printf("---------- INIT TEST ----------\n");

    for (unsigned i = 0; i < (sizeof(tests) / sizeof(*tests)); ++i)
    {
        const char *t = tests[i];
        const unsigned expected_output = is_number(tests[i]);
        const unsigned output = ft_atoi(tests[i]);

        printf("atoi(\"%s\") == ft_atoi(\"%s\") : %d == %d ", t, t, expected_output, output);
		verifyOutput(output == expected_output);
    }
}