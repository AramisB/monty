#include "monty.h"
/**
 * main - checks the code
 * @argv: number of arguments
 * @argc: argument type
 *
 * Return: always 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (process_file(file, &stack) != 0)
	{
		error_exit(stack, file);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
/**
 * process_file - processes each line of the line
 *
 * @file: pointer to file
 * @stack: double pointer to the first element in the stack
 *
 * Return: 0 always
 */
int process_file(FILE *file, stack_t **stack)
{
	char line[BUFFER_SIZE];
	char *opcode, *arg;
	unsigned int line_number = 0;

	while (read_line(line, BUFFER_SIZE, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL)
		{
			continue;
		}
		arg = strtok(NULL, " \t\n");
		if (p_inst(opcode, arg, stack, line_number) != 0)
		{
			return (-1);
		}
	}
	return (0);
}
/**
 * p_inst - processes a single instrction
 *
 * @opcode: pointer to the opcode
 * @arg: pointer to the argument
 * @stack: double pointer to the first element in the stack
 * @l_no: lne number in the file
 *
 * Return: 0 on success
 */
int p_inst(const char *opcode, char *arg, stack_t **stack, unsigned int l_no)
{
	int i = 0, found = 0;
	instruction_t instructions[] = {
		{"push", m_push_arg},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{NULL, NULL}
	};
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				m_push(stack, l_no, arg);
			}
			else
			{
				instructions[i].f(stack, l_no);
			}
			found = 1;
			break;
		}
		i++;
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l_no, opcode);
		return (-1);
	}
	return (0);
}
/**
 * error_exit - handles exit errors
 *
 * @stack: double pointer to the first element in the stack
 * @file: pointer to the file
 *
 */
void error_exit(stack_t *stack, FILE *file)
{
	if (file != NULL)
	{
		fclose(file);
	}
	if (stack != NULL)
	{
		free_stack(stack);
	}
	exit(EXIT_FAILURE);
}
