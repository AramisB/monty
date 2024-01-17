#include "monty.h"
/**
 * main - checks the code
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
		error_exit("Error occurred while processing file", stack, file);
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
		if (process_instruction(opcode, arg, stack, line_number) != 0)
		{
			return (-1);
		}
	}
	return (0);
}
/**
 * process_instruction - processes a single instrction
 *
 * @opcode: pointer to the opcode
 * @arg: pointer to the argument
 * @stack: double pointer to the first element in the stack
 * @line_number: lne number in the file
 *
 * Return: 0 on success
 */
int process_instruction(const char *opcode, char *arg, stack_t **stack, unsigned int line_number)
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
		{NULL, NULL}
	};
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				m_push(stack, line_number, arg);
			}
			else
			{
				instructions[i].f(stack, line_number);
			}
			found = 1;
			break;
		}
		i++;
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (-1);
	}
	return (0);
}
/**
 * error_exit - handles exit errors
 *
 * @message: pointer to the error message
 * @stack: double pointer to the first element in the stack
 * @file: pointer to the file
 *
 */
void error_exit(const char *message, stack_t *stack, FILE *file)
{
	fprintf(stderr, "%s\n", message);
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
