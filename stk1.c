#include "monty.h"

/**
 * stk_plus - this func will ++ nde
 *
 * @_nde_ad: nde ptr*
 *
 * @ln: opcode->
 *
 */

void stk_plus(stk_lif **_nde_ad, __attribute__((unused))unsigned int ln)
{
	stk_lif *tmp;

	if (_nde_ad == NULL || *_nde_ad == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *_nde_ad;
		return;
	}
	tmp = head;
	head = *_nde_ad;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * stk_prt - stk ++
 * @stack: first element ptr*
 *
 * @line_number: opc ->
 *
 */

void stk_prt(stk_lif **stack, unsigned int line_number)
{
	stk_lif *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}



/**
 * f_pop - this func will ++ nde
 *
 * @stack: first element ptr*
 *
 * @line_number: opc ->
 *
 */

void f_pop(stk_lif **stack, unsigned int line_number)
{
	stk_lif *tmp;

	if (stack == NULL || *stack == NULL)
		error_hndler(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * fi_prt - this func will prt stack top element
 *
 * @stack: first element ptr*
 *
 * @line_number: opc ->
 *
 */

void fi_prt(stk_lif **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		error_hndler(6, line_number);
	printf("%d\n", (*stack)->n);
}
