#include "monty.h"
/**
 * m_add - adds the first two element of a stack
 *
 * @stack: double pointer to the first element
 * @line_number: line number in the file
 *
 */
void m_add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;
	sum = first->n + second->n;
	m_pop(stack, line_number);
	(*stack)->n = sum;
}
