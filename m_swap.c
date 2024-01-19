#include "monty.h"
/**
 * m_swap - a function that swaps the first two elements of a stack
 *
 * @stack: double pointter to the first element of stack
 * @line_number: line number in the file
 *
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;

	if (second->next != NULL)
	{
		second->next->prev = first;
	}
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	*stack = second;
}
