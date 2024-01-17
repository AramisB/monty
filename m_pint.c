#include "monty.h"

/**
 * m_pint - prints the value at the top of the stack, followed by a new line
 *
 * @stack: double pointer to the top of the stack.
 * @line_number: line number in the script.
 *
 */
void m_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
