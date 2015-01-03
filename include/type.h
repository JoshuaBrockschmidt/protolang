#ifndef PROTOLANG_TYPE_H
#define PROTOLANG_TYPE_H

enum types_t {
  TYPE_BOOLEAN = 0,
  TYPE_LIST    = 1,
  TYPE_NUMBER  = 2,
  TYPE_STRING  = 3,
  TYPE_TABLE   = 4,
};

#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#endif /* #ifndef PROTOLANG_TYPE_H */
