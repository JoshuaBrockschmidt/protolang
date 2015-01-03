#ifndef PROTOLANG_TYPE_H
#define PROTOLANG_TYPE_H

enum types_t {
  TYPE_BOOLEAN = 0,
  TYPE_LIST    = 1,
  TYPE_NUMBER  = 2,
  TYPE_STRING  = 3,
  TYPE_TABLE   = 4,
};

/* It seems we aren't using these #defines... maybe we should trash them? */
#define TRUE  1
#define FALSE 0

#endif /* #ifndef PROTOLANG_TYPE_H */
