#include "monty.h"

/**
 * _fl_open - this func will open the files
 *
 * @pth: path of the oppend_fil
 *
 * Return: this is void func
 *
 */
void _fl_open(char *pth)
{
	FILE *fd = fopen(pth, "r");

	if (pth == NULL || fd == NULL)
		error_msg(2, pth);

	_fl_rd(fd);
	fclose(fd);
}


/**
 * _fl_rd - this func will reads the opned_file
 *
 * @fd: fl_ ptr
 *
 * Return: this is void func
 *
 */

void _fl_rd(FILE *fd)
{
	int line_number, strct = 0;
	char *buf = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buf, &len, fd) != -1; line_number++)
	{
		strct = _fl_prs(buf, line_number, strct);
	}
	free(buf);
}


/**
 * _fl_prs - / func to sple to identfies the rls
 *
 * @buf: fl plc
 *
 * @line_number: spc noum
 *
 * @strct: depnd on nde will create struct
 *
 * Return:  one or zero
 */

int _fl_prs(char *buf, int line_number, int strct)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buf == NULL)
		error_msg(4);

	opcode = strtok(buf, delim);
	if (opcode == NULL)
		return (strct);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	f_srcher(opcode, value, line_number, strct);
	return (strct);
}



/**
 * f_srcher - serach for the func
 *
 * @opcode: this is opcode
 *
 * @value: op args
 * @strct: depnd on nde will create struct
 * @ln: opliqls
 *
 * Return: this is void func
 *
 */



void f_srcher(char *opcode, char *value, int ln, int strct)
{
	int inc;
	int sign;

	instruction_t func_list[] = {
		{"push", stk_plus},
		{"pall", stk_prt},
		{"pint", fi_prt},
		{"pop", f_pop},
		{"do_na", do_na},
		{"swap", nde_swp},
		{"add", nde_pls},
		{"sub", stk_pls},
		{"div", nde_dv},
		{"mul", nde_multi},
		{"mod", mod_nodes},
		{"pchar", prt_asc},
		{"pstr", string_prt},
		{"rt_nde", rt_nde},
		{"tp_nde", tp_nde},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (sign = 1, inc = 0; func_list[inc].opcode != NULL; inc++)
	{
		if (strcmp(opcode, func_list[inc].opcode) == 0)
		{
			_func_getter(func_list[inc].f, opcode, value, ln, strct);
			sign = 0;
		}
	}
	if (sign == 1)
		error_msg(3, ln, opcode);
}




/**
 * _func_getter - this func will ret needed func
 *
 * @func: this is ptr
 *
 * @_ptrp: this is str
 *
 * @val: this is str for int
 *
 * @ln: the order int in que
 *
 * @strct: one or zero
 *
 */


void _func_getter(op_func func, char *_ptrp, char *val, int ln, int strct)
{
	stk_lif *node;
	int sign;
	int inc;

	sign = 1;
	if (strcmp(_ptrp, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			sign = -1;
		}
		if (val == NULL)
			error_msg(5, ln);
		for (inc = 0; val[inc] != '\0'; inc++)
		{
			if (isdigit(val[inc]) == 0)
				error_msg(5, ln);
		}
		node = nde_strc(atoi(val) * sign);
		if (strct == 0)
			func(&node, ln);
		if (strct == 1)
			qu_plus(&node, ln);
	}
	else
		func(&head, ln);
}
