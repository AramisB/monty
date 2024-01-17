#include "monty.h"
/**
 * m_div - finds the difference of the first two element of a stack
 *
 * @stack: double pointer to the first element
 * @line_number: line number in the file
 *
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int quotient;
	
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        {
		fprintf(stderr, "L%d: can't div, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;
	quotient = second->n / first->n;
	m_pop(stack, line_number);
	(*stack)->n = quotient;
}
