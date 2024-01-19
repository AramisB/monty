#include "monty.h"
/**
 * m_mod - finds the difference of the first two element of a stack
 *
 * @stack: double pointer to the first element
 * @line_number: line number in the file
 *
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int remainder;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	remainder  = second->n % first->n;
	m_pop(stack, line_number);
	(*stack)->n = remainder;
}
