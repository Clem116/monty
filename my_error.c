#include "monty.h"

/**
 * err - Prints appropiate error messages produced by their error code.
 * @error_code: Error codes are as follows:-
 * (1) => User does not give any file or more than one file to the program.
 * (2) => File provided is not a file that can be opened or read.
 * (3) => File provided contains an invalid instruction.
 * (4) => While program is unable to malloc more memory.
 * (5) => While parameter passed to the instruction "push" is not an int.
 * (6) => While stack it empty for pint.
 * (7) => While stack it empty for pop.
 * (8) => While stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list arg;
	char *ope;
	int l_number;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			l_number = va_arg(arg, int);
			ope = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_number, ope);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - More err handling
 * @error_code: Error codes are as follows:-
 * (6) => While stack it empty for pint.
 * (7) => While stack it empty for pop.
 * (8) => While  stack is too short for operation.
 * (9) => Divide by zero.
 */
void more_err(int error_code, ...)
{
	va_list arg;
	char *ope;
	int l_number;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			l_number = va_arg(arg, unsigned int);
			ope = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_number, ope);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - String for Error handling
 * @error_code: Error codes are as follows:-
 * (10) ~> Number inside a node is outside ASCII bounds.
 * (11) ~> Stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list arg;
	int l_number;

	va_start(arg, error_code);
	l_number = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}