/* To do list:
 *  - MAYBE make seperate files for each variable type; easier to manage
 *  - MAYBE make a global table, in which all variables reside
 *  - add booleans, lists, strings, and functions
 *  - finish showTable()
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"

#define UNUSED(x) (void)(x)

struct table_t *newTable (void);
struct var_t *newVar (unsigned char type, void *value);
void addToTable (struct table_t *tablep, struct var_t *varp);
void rmvFromTable (struct table_t *tablep, unsigned int i);
char *varValStr (struct var_t *varp);
char *listToStr (void *value);
char *boolToStr (void *value);
char *tableToStr (void *value);
char *numToStr (void *value);
char *strToStr (void *value);
void showTable (struct table_t *tablep);

struct table_t {
  unsigned int size;
  struct tableseg_t *first;
};

struct tableseg_t {
  struct var_t *varp;
  struct tableseg_t *next;
};

struct var_t {
  unsigned char type;
  void *value;
};


const char *typenames[5];
char *(*valStrFuncs[5]) (void *value);


int main (void)
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
  
  /* Test */
  struct table_t *table1 = newTable();
  showTable(table1);
  double x = 9000.1;
  struct var_t *var1 = newVar(TYPE_NUMBER, (void*)&x);
  addToTable(table1, var1);
  showTable(table1);
  /* EOF Test */
  
  return 0;
}


struct table_t *newTable (void)
{
  struct table_t *tablep = malloc(sizeof(struct table_t));
  tablep->size = 0;
  return tablep;
}

struct var_t *newVar (unsigned char type, void *value)
{
  struct var_t *varp = malloc(sizeof(struct var_t));
  varp->type = type;
  varp->value = value;
  return varp;
}

void addToTable (struct table_t *tablep, struct var_t *varp)
{
  // Add to beginning of stack.
  struct tableseg_t *newseg = malloc(sizeof(struct tableseg_t));
  newseg->varp = varp;
  newseg->next = tablep->first;
  tablep->first = newseg;
  tablep->size += 1;
}

void rmvFromTable (struct table_t *tablep, unsigned int i)
{
  if (i > tablep->size) {
    return;
  }
  struct tableseg_t *before;
  struct tableseg_t *after;
  before = tablep->first;
  int cnt;
  for (cnt=1; cnt<i-1; cnt++)
    before = before->next;
  after = before->next;
  if (after) {
    after = after->next;
    free((void*)before->next);
  }
  before->next = after;
  tablep->size -= 1;
}

char *varValStr (struct var_t *varp)
{
  return valStrFuncs[varp->type](varp->value);
}

char *listToStr (void *value)
{
  /* Change later */
  UNUSED(value);
  return (char *) "DOIT";
}

char *boolToStr (void *value)
{
  if ((char*)value == 0) {
    return (char *) "FALSE";
  } else {
    return (char *) "TRUE";
  }
}

char *tableToStr (void *value)
{
  /* Change later */
  UNUSED(value);
  return (char *) "DOIT";
}

char *numToStr (void *value)
{
  char *str = malloc(sizeof(char)*50);
  snprintf(str, 50, "%f", *(double*)value);
  return str;
}

char *strToStr (void *value)
{
  return (char*)value;
}

void showTable (struct table_t *tablep)
{
  if (tablep->first == NULL) {
    puts("nothing in table");
    return;
  }
  struct tableseg_t *cur;
  struct var_t *varp;
  for (cur = tablep->first; cur != NULL; cur = cur->next) {
    varp = cur->varp;
    char str[60];
    strcpy(str, typenames[varp->type]);
    strcat(str, "\t");
    strcat(str, varValStr(varp));
    puts(str);
  }
}
