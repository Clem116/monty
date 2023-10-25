#include "monty.h"


/**
 * add_to_stack - Function for stack addition
 * @new_node: next upcoming node
 * @line: ln parameter
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int line)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - prints stack queue
 * @stack: Queue stack
 * @ln_number: line element
 */
void print_stack(stack_t **stack, unsigned int ln_number)
{
	stack_t *tmp;

	(void) ln_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Newest element.
 * @stack: stack queue
 * @ln_number:line element
 */
void pop_top(stack_t **stack, unsigned int ln_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, ln_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - start with the last element in
 * @stack: stack queue
 * @ln_number: line element
 */
void print_top(stack_t **stack, unsigned int ln_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, ln_number);
	printf("%d\n", (*stack)->n);
}
