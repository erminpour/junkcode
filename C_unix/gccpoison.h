
#ifndef __GCCPOISON_H__
#define __GCCPOISON_H__

#ifdef __GNUC__

/* String handling functions */
#   pragma GCC poison strcpy wcscpy stpcpy wcpcpy
#   pragma GCC poison scanf sscanf vscanf fwscanf swscanf wscanf
#   pragma GCC poison gets puts
#   pragma GCC poison strcat wcscat
#   pragma GCC poison wcrtomb wctob
#   pragma GCC poison sprintf vsprintf vfprintf
#   pragma GCC poison asprintf vasprintf
#   pragma GCC poison strncpy wcsncpy
#   pragma GCC poison strtok wcstok
#   pragma GCC poison strdupa strndupa

/* Signal related */
#   pragma GCC poison longjmp siglongjmp
#   pragma GCC poison setjmp sigsetjmp

/* Memory allocation */
/* #   pragma GCC poison alloca */
#   pragma GCC poison mallopt

/* File API's */
#   pragma GCC poison remove
#   pragma GCC poison mktemp tmpnam tempnam
#   pragma GCC poison getwd

/* Misc */
#   pragma GCC poison getlogin getpass cuserid
#   pragma GCC poison rexec rexec_af

#endif /* GCC */

#endif /* __GCCPOISON_H__ */

