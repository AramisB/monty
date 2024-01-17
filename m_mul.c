#include "monty.h"
/**
 * m_mul - finds the product of the first two element of a stack
 *
 * @stack: double pointer to the first element
 * @line_number: line number in the file
 *
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int prod;
	
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;
	prod = second->n * first->n;
	m_pop(stack, line_number);
	(*stack)->n = prod;
}
