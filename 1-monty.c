#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: The Double linked list
 * @line_number: The File line exec
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *sta = *stack;
	(void) line_number;

	if (!sta)
		return;
	while (sta)
	{
		printf("%d\n", sta->n);
		sta = sta->next;
	}
}

/**
 * push - pushes an element to the stack
 * @stack: The Double linked list
 * @line_number: The File line exec
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *stak = NULL, *sta = *stack;
	char *numb;

	numb = strtok(NULL, " \r\t\n");
	if (numb == NULL || (_isdigit(numb) != 0 && numb[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	stak = malloc(sizeof(stack_t));
	if (!stak)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	stak->n = atoi(numb);
	if (var.MODE == 0 || !*stack)
	{
		stak->next = *stack;
		stak->prev = NULL;
		if (*stack)
			(*stack)->prev = stak;
		*stack = stak;
	}
	else
	{
		while (sta->next)
			sta = sta->next;
		sta->next = stak;
		stak->prev = sta;
		stak->next = NULL;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: The Double linked list
 * @line_number: The File line exec
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - removes the top element of the stack
* @stack: The Double linked list
* @line_number: The File line exec
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *sta;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	sta = *stack;
	*stack = sta->next;
	if (sta->next)
		sta->next->prev = NULL;
	free(sta);
}
