#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "type_table.h"

/* Global functions */

void initType_table(void)
{
	typenames[TYPE_BOOLEAN] = "boolean";
	typenames[TYPE_LIST] = "list";
	typenames[TYPE_NUMBER] = "number";
	typenames[TYPE_STRING] = "string";
	typenames[TYPE_TABLE] = "table";
	valStrFuncs[TYPE_BOOLEAN] = boolToStr;
	valStrFuncs[TYPE_LIST] = listToStr;
	valStrFuncs[TYPE_NUMBER] = numToStr;
	valStrFuncs[TYPE_STRING] = strToStr;
	valStrFuncs[TYPE_TABLE] = tableToStr;
}

table *newTable(void)
{
	table *tablep = malloc(sizeof(table));
	tablep->size = 0;
	return tablep;
}

void addToTable(table *tablep, var *varp)
{
	// Add to beginning of stack.
	tableseg *newseg = malloc(sizeof(tableseg));
	newseg->varp = varp;
	newseg->next = tablep->first;
	tablep->first = newseg;
	tablep->size += 1;
}

void rmvFromTable(table *tablep, unsigned int i)
{
	if (i > tablep->size) {
		return;
	}
	tableseg *before;
	tableseg *after;
	before = tablep->first;
	int cnt;
	for (cnt = 1; cnt < i - 1; cnt++)
		before = before->next;
	after = before->next;
	if (after) {
		after = after->next;
		free((void *)before->next);
	}
	before->next = after;
	tablep->size -= 1;
}

void showTable(table *tablep)
{
	if (tablep->first == NULL) {
		puts("nothing in table");
		return;
	}
	tableseg *cur;
	var *varp;
	for (cur = tablep->first; cur != NULL; cur = cur->next) {
		varp = cur->varp;
		char str[60];
		strcpy(str, typenames[varp->type]);
		strcat(str, "\t");
		strcat(str, varValStr(varp));
		puts(str);
	}
}

/* Static functions */

char *varValStr(var *varp)
{
	return valStrFuncs[varp->type] (varp->value);
}

char *listToStr(void *value)
{
	/* Change later */
	UNUSED(value);
	return (char *)"DOIT";
}

char *boolToStr(void *value)
{
	if ((char *)value == 0) {
		return (char *)"FALSE";
	} else {
		return (char *)"TRUE";
	}
}

char *tableToStr(void *value)
{
	/* Change later */
	UNUSED(value);
	return (char *)"DOIT";
}

char *numToStr(void *value)
{
	char *str = malloc(sizeof(char) * 50);
	snprintf(str, 50, "%f", *(double *)value);
	return str;
}

char *strToStr(void *value)
{
	return (char *)value;
}
