/* To do list:
 *  - MAYBE make a global table, in which all variables reside
 *  - add booleans, lists, strings, and functions
 *  - finish showTable()
 *  - MAYBE move newVar() to it's own file; could be a waste of space, though
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

var *newVar(unsigned char type, void *value);

int main(void)
{
	initType_table();

	/* Test */
	table *table1 = newTable();
	showTable(table1);
	double x = 1337.0314159265;
	var *var1 = newVar(TYPE_NUMBER, (void *)&x);
	addToTable(table1, var1);
	showTable(table1);
	/* EOF Test */

	return 0;
}

var *newVar(unsigned char type, void *value)
{
	var *varp = malloc(sizeof(var));
	varp->type = type;
	varp->value = value;
	return varp;
}
