#include "monty.h"

/**
 * nde_multi - this func will ++ ele to the stck
 *
 * @stack: top nde ptr*
 *
 * @line_number: opcde ->
 *
 */

void nde_multi(stk_lif **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_hndler(8, line_number, "mul");

	(*stack) = (*stack)->next;
	tot = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - this func will ++ ele to the stck
 * @stack: top nde ptr*
 * @line_number: opcde ->
 */
void mod_nodes(stk_lif **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		error_hndler(8, line_number, "mod");


	if ((*stack)->n == 0)
		error_hndler(9, line_number);
	(*stack) = (*stack)->next;
	tot = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
