#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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
} stk_lif;

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
void (*f)(stk_lif **stack, unsigned int line_number);
} instruction_t;

extern stk_lif *head;
typedef void (*op_func)(stk_lif **, unsigned int);


void _fl_open(char *pth);
int _fl_prs(char *buf, int line_number, int strct);
void _fl_rd(FILE *);
int _get_lenght(FILE *);
void f_srcher(char *, char *, int, int);


void error_msg(int _flw_err, ...);
void error_hndler(int _flw_err, ...);
void _hndl_strerr(int _flw_err, ...);
void rotr(stk_lif **, unsigned int);


stk_lif *nde_strc(int n);
void nde_cl(void);
void stk_prt(stk_lif **, unsigned int);
void stk_plus(stk_lif **, unsigned int);
void qu_plus(stk_lif **, unsigned int);

void _func_getter(op_func, char *, char *, int, int);

void fi_prt(stk_lif **, unsigned int);
void f_pop(stk_lif **, unsigned int);
void nop(stk_lif **, unsigned int);
void nde_swp(stk_lif **, unsigned int);


void prt_asc(stk_lif **, unsigned int);
void string_prt(stk_lif **, unsigned int);
void rotl(stk_lif **, unsigned int);


void nde_pls(stk_lif **, unsigned int);
void stk_pls(stk_lif **, unsigned int);
void nde_dv(stk_lif **, unsigned int);
void nde_multi(stk_lif **, unsigned int);
void mod_nodes(stk_lif **, unsigned int);

#endif
