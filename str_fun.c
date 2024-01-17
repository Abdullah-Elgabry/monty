#include "monty.h"

/**
 * prt_asc - this func will prt ASCII vals
 *
 * @stack: top nde ptr*
 *
 * @line_number: opcde ->
 *
 */

void prt_asc(stk_lif **stack, unsigned int line_number)
{
	int letr;

	if (stack == NULL || *stack == NULL)
		_hndl_strerr(11, line_number);

	letr = (*stack)->n;
	if (letr < 0 || letr > 127)
		_hndl_strerr(10, line_number);
	printf("%c\n", letr);
}


/**
 * string_prt - Prints a string.
 * @stack: top nde ptr*
 * @ln: opcde ->
 */
void string_prt(stk_lif **stack, __attribute__((unused))unsigned int ln)
{
	int letr;
	stk_lif *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		letr = tmp->n;
		if (letr <= 0 || letr > 127)
			break;
		printf("%c", letr);
		tmp = tmp->next;
	}
	printf("\n");
}



/**
 * rotl - this func will rt the nde for the stack to btm
 *
 * @stack: top nde ptr*
 * @ln: opcde ->
 */

void rotl(stk_lif **stack, __attribute__((unused))unsigned int ln)
{
	stk_lif *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - this func will rt the nde from tp
 *
 * @stack: top nde ptr*
 *
 * @ln: opcde ->
 *
 */

void rotr(stk_lif **stack, __attribute__((unused))unsigned int ln)
{
	stk_lif *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
