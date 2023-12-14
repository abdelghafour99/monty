#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: The Double linked list
 * @line_number: The File line exec
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *sta = *stack;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;
	(*stack)->next->prev = NULL;
	while (sta->next)
		sta = sta->next;
	sta->next = *stack;
	(*stack) = (*stack)->next;
	sta->next->next = NULL;
	sta->next->prev = sta;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: Double linked list
 * @line_number: File line execution
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *sta;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	sta = *stack;
	while (sta->next)
		sta = sta->next;

	sta->next = *stack;
	sta->prev->next = NULL;
	sta->prev = NULL;

	(*stack)->prev = sta;
	*stack = sta;

}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: The Double linked list
 * @line_number: The File line exec
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	var.MODE = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: The Double linked list
 * @line_number: The File line exec
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	var.MODE = 1;
}
