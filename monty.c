#include "monty.h"
#include <stdio.h>

vars var;

/**
 * main - The main function of Start monty program
 * @ac: Number of arguments
 * @av: Pointer containing arguments
 * Return: 0 Success, 1 Failed
 */
int main(int ac, char **av)
{
	char *cod;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(av[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (getline(&var.buff, &var.tmp, var.file) != EOF)
	{
		cod = strtok(var.buff, " \r\t\n");
		if (cod != NULL)
			if (call_funct(&var, cod) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
