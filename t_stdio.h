#ifndef T_STDIO_H_
#define T_STDIO_H_
#include<stdio.h>
#define E_MSG(STRING, VAL) do{perror(STRING);return (VAL);}while(0)
#endif
