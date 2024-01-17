#include "monty.h"
/**
 * m_pall - a function that prints all the elements of a stack
 * starting at the top
 *
 * @stack: double pointer to the top of the stack
 *
 */
void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * is_int - checks if a string is an integer
 *
 * @string: the string to check
 *
 * Return: 1 if the string is an integer, otherwise 0
 */
int is_int(char *string)
{
	if (!string || *string == '\0')
	{
		return (0);
	}
	if (*string == '-' || *string == '+')
	{
		string++;
	}
	while (*string)
	{
		if (!isdigit((unsigned char)*string))
		{
			return (0);
		}
		string++;
	}
	return (1);
}

/**
 * m-push - a function that pushes the element to the stack
 *
 * @stack: a double pointer to the top of the stack
 * @line_number: line number in the script
 * @arg: the argument to push
 */
void m_push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_element;
	int num;

	if (!is_int(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(arg);

	new_element = malloc(sizeof(stack_t));

	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_element->n = num;
	new_element->prev = NULL;
	new_element->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_element;
	}
	*stack = new_element;
}

/**
 * m_push_arg - extracts args then calls m_push
 *
 * @stack: double pointer to the first number of the stack
 * @line_number: ine number in the file
 *
 */
void m_push_arg(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");

	m_push(stack, line_number, arg);
}
/**
 * free_stack - a function that frees stack
 *
 * @stack: pointer to the first elementof the stack
 *
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
