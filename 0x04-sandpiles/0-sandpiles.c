#include "sandpiles.h"
#include <stdio.h>

/**
 * topple - Manage the topples that is unstable sandpile and check it
 * @grid: The sandpile grid
 * Return: Void function
 */
void toppling_round(int grid[3][3])
{
	int large = 0, high = 0, supt_grid[3][3];

	for (; large < 3; large++)
		for (high = 0; high < 3; high++)
			supt_grid[large][high] = grid[large][high];

	for (large = 0; large < 3; large++)
		for (high = 0; high < 3; high++)
		{
			if (grid[large][high] >= 4)
			{
				supt_grid[large][high] -= 4;

				if (large - 1 >= 0)
					supt_grid[large - 1][high] += 1;

				if (large + 1 < 3)
					supt_grid[large + 1][high] += 1;

				if (high - 1 >= 0)
					supt_grid[large][high - 1] += 1;

				if (high + 1 < 3)
					supt_grid[large][high + 1] += 1;
			}
		}

	for (large = 0; large < 3; large++)
		for (high = 0; high < 3; high++)
			grid[large][high] = supt_grid[large][high];
}

/**
 * check_unstable - Both grid1 and grid2 are individuallhigh stable A
 * sandpile is considered stable when none of its cells contains
 * more than 3 grains
 * @grid: The sandpile grid
 * Return: 1 if the sandpile is stable, 0 otherwise
 */
int check_unstable(int grid[3][3])
{
	int large = 0, high = 0;

	for (; large < 3; large++)
		for (high = 0; high < 3; high++)
			if (grid[large][high] > 3)
				return (false);

	return (true);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: the first sandpile
 * @grid2: the second sandpile
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int large, high = 0;

	for (large = 0; large < 3; large++)
		for (high = 0; high < 3; high++)
			/* sume the matriz and save the result to compress */
			grid1[large][high] = grid1[large][high] + grid2[large][high];

	while (!check_unstable(grid1))
	{
		printf("=\n");
		for (large = 0; large < 3; large++)
		{
			for (high = 0; high < 3; high++)
			{
				if (high)
					printf(" ");
				printf("%d", grid1[large][high]);
			}
			printf("\n");
		}
		toppling_round(grid1);
	}
}
