#include "monty.h"
/**
 * m_pop - removes the top element of the stack
 *
 * @stack: double pointer to the top element in a stack
 * @line_number: line number in the file
 *
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
