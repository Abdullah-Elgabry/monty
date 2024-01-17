#include "monty.h"

/**
 * nop - this func will do nothing
 *
 * @stack: top nde ptr*
 * @line_number: opcde ->
 *
 */

void nop(stk_lif **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * nde_swp - this fun will swp the fce ele
 *
 * @stack: top nde ptr*
 *
 * @line_number: opcde ->
 */
void nde_swp(stk_lif **stack, unsigned int line_number)
{
	stk_lif *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_hndler(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * nde_pls - this func will ++ ele to the top
 *
 * @stack: top nde ptr*
 *
 * @line_number: opcde ->
 *
 */

void nde_pls(stk_lif **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_hndler(8, line_number, "add");

	(*stack) = (*stack)->next;
	tot = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}




/**
 * stk_pls - this func will ++ ele to the stk
 *
 * @stack: top nde ptr*
 *
 * @line_number: opcde ->
 *
 */

void stk_pls(stk_lif **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		error_hndler(8, line_number, "sub");


	(*stack) = (*stack)->next;
	tot = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nde_dv - this func will ++ ele to the stk
 *
 * @stack: top nde ptr*
 *
 * @line_number: opcde ->
 *
 */

void nde_dv(stk_lif **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_hndler(8, line_number, "div");

	if ((*stack)->n == 0)
		error_hndler(9, line_number);
	(*stack) = (*stack)->next;
	tot = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
