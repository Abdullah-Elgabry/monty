#include "monty.h"
stk_lif *head = NULL;

/**
 * main - this is the main prog
 *
 * @argc: this is counter for args
 *
 * @argv: args log
 *
 * Return: zero
 *
 */


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_fl_open(argv[1]);
	nde_cl();
	return (0);
}



/**
 * nde_strc - this func will build  the nde
 *
 * @n: nde to styl
 *
 * Return: n/a or zero
 *
 */

stk_lif *nde_strc(int n)
{
	stk_lif *node;

	node = malloc(sizeof(stk_lif));
	if (node == NULL)
		error_msg(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}



/**
 * nde_cl - this func will clear que nde
 *
 */

void nde_cl(void)
{
	stk_lif *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}



/**
 * qu_plus - this func will + nde
 *
 * @_nde_ad: nde ptr*
 *
 * @ln: opcode plc
 *
 */

void qu_plus(stk_lif **_nde_ad, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *_nde_ad;
	(*_nde_ad)->prev = tmp;

}
