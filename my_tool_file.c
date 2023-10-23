#include "monty.h"

/**
 * open_file - Opn file func
 * @file_name: name of path
 * Return: (void)
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - Func read file
 * @fd: discr of fle
 * Return: (void)
 */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line - Ln Separator
 * which function to call
 * @buffer: Buffer ln
 * @line_number: ln parameter
 * @format:  storage parameter 
 * if 1 nodes will be entered as a queue.
 * Return:This Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}

/**
 * find_func - Function find
 * @opcode: opecode function
 * @value: Opcde args
 * @format: fmt parameter
 * @line: Ln member
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int line, int format)
{
	int n;
	int flg;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flg = 1, n = 0; func_list[n].opcode != NULL; n++)
	{
		if (strcmp(opcode, func_list[n].opcode) == 0)
		{
			call_fun(func_list[n].f, opcode, value, line, format);
			flg = 0;
		}
	}
	if (flg == 1)
		err(3, line, opcode);
}


/**
 * call_fun - Function Call.
 * @func: Function pointer.
 * @ope: Opecode reps.
 * @val: str rep of a number vlue.
 * @line: Ln number for the instruction.
 * @format: Format spacifiar. 
 */
void call_fun(op_func func, char *ope, char *val, int line, int format)
{
	stack_t *node;
	int flg;
	int n;

	flg = 1;
	if (strcmp(ope, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flg = -1;
		}
		if (val == NULL)
			err(5, line);
		for (n = 0; val[n] != '\0'; n++)
		{
			if (isdigit(val[n]) == 0)
				err(5, line);
		}
		node = create_node(atoi(val) * flg);
		if (format == 0)
			func(&node, line);
		if (format == 1)
			add_to_queue(&node, line);
	}
	else
		func(&head, line);
}
