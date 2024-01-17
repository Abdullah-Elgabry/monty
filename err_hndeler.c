#include "monty.h"

/**
 * error_msg - this func will prt err msgif found.
 *
 * @_flw_err: this will prt the cases
 *
 * case one - if there is any file given
 *
 * case two - issue happend in opinning the file
 *
 * case three - there is an issue in the file itself
 *
 * case four - if prog cannot add more space
 *
 * case five - if the insertation not number
 *
 * case six - if the que has no data
 *
 * case seven - if que has no data for unqueed
 *
 * case eight - if que is has less len than expected
 *
 */

void error_msg(int _flw_err, ...)
{
	va_list er;
	char *_ptrp;
	int _nt;

	va_start(er, _flw_err);
	switch (_flw_err)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(er, char *));
			break;
		case 3:
			_nt = va_arg(er, int);
			_ptrp = va_arg(er, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", _nt, _ptrp);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(er, int));
			break;
		default:
			break;
	}
	nde_cl();
	exit(EXIT_FAILURE);
}






/**
 * error_hndler - this func will acts as err hndel
 *
 * @_flw_err: this will prt the cases
 *
 * case six -  if the que has no data
 *
 * case seven - if que has no data for unqueed
 *
 * case eight - if que is has less len than expected
 *
 * case nine - if the user div / 0
 *
 */

void error_hndler(int _flw_err, ...)
{
	va_list er;
	char *_ptrp;
	int _nt;

	va_start(er, _flw_err);
	switch (_flw_err)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(er, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(er, int));
			break;
		case 8:
			_nt = va_arg(er, unsigned int);
			_ptrp = va_arg(er, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", _nt, _ptrp);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(er, unsigned int));
			break;
		default:
			break;
	}
	nde_cl();
	exit(EXIT_FAILURE);
}




/**
 * _hndl_strerr - this func will hndle str err
 *
 * @_flw_err: this will prt the cases
 *
 * case ten - if num outof expected
 *
 * case eleven - if the que has no data
 *
 */

void _hndl_strerr(int _flw_err, ...)
{
	va_list er;
	int _nt;

	va_start(er, _flw_err);
	_nt = va_arg(er, int);
	switch (_flw_err)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", _nt);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", _nt);
			break;
		default:
			break;
	}
	nde_cl();
	exit(EXIT_FAILURE);
}
