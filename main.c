#include "monty.h"
/*stack_t *head = NULL;*/

/**
 * main - Program Entry Point
 * @argv: Parameter count argument
 * @argc: Count parameter argument
 * Return: Success (0)
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates a new-node
 * @d: Parameter
 * Return: Success (1), Otherwise (NULL.)
 */
stack_t *create_node(int d)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->d = d;
	return (node);
}

/**
 * free_nodes - Pops nodes
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
* add_to_queue -pushes new node to the queue
* @new_node: next node
* @line: new line code
*/
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int line)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

