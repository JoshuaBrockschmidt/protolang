/* Should only be #include'd in 'src/type_tables.c' */
/* Doing otherwise could result in some unexpected scope issues (note the */
/* static function declarations) */
#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

#define UNUSED(x) (void)(x)

typedef struct tableseg {
	struct var *varp;
	struct tableseg *next;
} tableseg;

void initType_table(void);
table *newTable(void);
void addToTable(table *tablep, var *varp);
void rmvFromTable(table *tablep, unsigned int i);
void showTable(table *tablep);
static char *varValStr(var *varp);
static char *listToStr(void *value);
static char *boolToStr(void *value);
static char *tableToStr(void *value);
static char *numToStr(void *value);
static char *strToStr(void *value);

static const char *typenames[5];
static char *(*valStrFuncs[5]) (void *value);

#endif
