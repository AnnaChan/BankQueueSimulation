#include "TStoixeioyOuras.h"

void TSoura_setValue (TStoixeioyOuras *target, TStoixeioyOuras source)
{
	*target=source;
}

int TSoura_readValue (FILE *from, TStoixeioyOuras *ElemPtr)
{
     return (fscanf(from, "%d", ElemPtr));
}

void TSoura_writeValue (FILE *to, TStoixeioyOuras Elem)
{
	fprintf(to, "%d", Elem);
}
