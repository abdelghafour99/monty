#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_var - golbal variabl
 * @file: The file name
 * @buff: Getline buffer
 * @tmp: Getline counter
 * @dict: instruction dictionary
 * @head: pointer to list
 * @line_number: Stores file current line
 * @MODE: Program configuration stack or queu
 */
typedef struct glob_var
{
	FILE *file;
	char *buff;
	size_t tmp;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} vars;


extern vars var;

/* ================================================================= */
/* 				0-monty.c 			     */
/* ================================================================= */
int start_vars(vars *var);
instruction_t *create_instru();
int call_funct(vars *var, char *opcode);
void free_all(void);
int _isdigit(char *string);

/* ================================================================= */
/* 				1-monty.c 			     */
/* ================================================================= */
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* ================================================================= */
/* 				2-monty.c 			     */
/* ================================================================= */
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

/* ================================================================= */
/* 				3-monty.c 			     */
/* ================================================================= */
void sub(stack_t **stack, unsigned int line_number);
void divm(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/* ================================================================= */
/* 				4-monty.c 			     */
/* ================================================================= */
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/* ================================================================= */
/* 				5-monty.c 			     */
/* ================================================================= */
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
