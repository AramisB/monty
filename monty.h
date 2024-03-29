#ifndef MONTY_H
#define MONTY_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
int process_file(FILE *file, stack_t **stack);
int p_inst(const char *opcode, char *arg, stack_t **stack, unsigned int l_no);
void error_exit(stack_t *stack, FILE *file);
ssize_t read_line(char *buffer, size_t size, FILE *stream);
void free_stack(stack_t *stack);
void m_push(stack_t **stack, unsigned int line_number, char *arg);
void m_push_arg(stack_t **stack, unsigned int line_number);
int is_int(char *string);
void m_pall(stack_t **stack, unsigned int line_number);
void m_pint(stack_t **stack, unsigned int line_number);
void m_pop(stack_t **stack, unsigned int line_number);
void m_swap(stack_t **stack, unsigned int line_number);
void m_add(stack_t **stack, unsigned int line_number);
void m_nop(stack_t **stack, unsigned int line_number);
void m_sub(stack_t **stack, unsigned int line_number);
void m_div(stack_t **stack, unsigned int line_number);
void m_mul(stack_t **stack, unsigned int line_number);
void m_mod(stack_t **stack, unsigned int line_number);
#endif
