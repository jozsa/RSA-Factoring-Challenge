#include <stdio.h>
#include <stdlib.h>

/**
 * main - Factorize numbers
 * @argc: The count of arguments passed to the program
 * @argv: Double pointer to arguments passed to the program
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *fd;
	char *number = NULL;
	size_t len;
	unsigned long int i;
	unsigned long int num;

	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	while (getline(&number, &len, fd) != EOF)
	{
		num = atoi(number);
		if (num == 1)
			printf("1=1*1");
		for (i = 2; i <= num; i++)
		{
			if (num % i == 0)
			{
				if (i == num)
					i = 1;
				printf("%lu=%lu*%lu\n", num, num / i, i);
				break;
			}
		}
	}
	free(number);
	fclose(fd);
	return (0);
}
