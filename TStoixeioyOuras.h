#ifndef __TStoixeioyStoivas_H__
#define __TStoixeioyStoivas_H__
#include <stdio.h>

typedef int TStoixeioyOuras;

void TSoura_setValue (TStoixeioyOuras *target, TStoixeioyOuras source);
int TSoura_readValue (FILE *from,  TStoixeioyOuras *Elem);
void TSoura_writeValue (FILE *to, TStoixeioyOuras Elem);
#endif
