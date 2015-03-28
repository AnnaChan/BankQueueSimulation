/*************************************************************************
Αρχείo Υλoπoίησης	: QArray.c
Συγγραφέας			: Γ. Κοτρώνης
Σκoπός				: Υλoπoίηση με πίνακα Αφηρημένoυ Τύπoυ Δεδoμένων, Ουρά
**************************************************************************/
#include <stdio.h>

#include "ch6_QArray1.h"

/*oρισμός συναρτήσεων*/

void OuraDimiourgia(TOuras *oura )
{/*	Pro: 		kamia
  *	Meta: 		Dhmioyrgia kenhs oyras */
	oura->embros =  0;
	oura->piso = 0;
	oura->metritis = 0;
}

int OuraKeni(TOuras oura)
{/*	Pro: 		Dhmioyrgia Oyras
  *	Meta:		epistrefei 1 an h oyra einai gemath, diaforetika 0 */
	return ( oura.metritis == 0 );
}

int GematiOura(TOuras oura)
{/*	Pro: 		Dhmioyrgia Oyras
  *	Meta:		epistrefei 1 an h oyra einai gemath, diaforetika 0 */
	return (oura.metritis == PLITHOS);
}

int SizeOuras(TOuras oura)
{/*	Pro: 		Dhmioyrgia Oyras
  *	Meta:		epistrefei to plhthos stoixeiwn ths ouras */
  return oura.metritis;
	
}

int OuraProsthesi(TOuras *oura, TStoixeioyOuras stoixeio)
{/*	Pro: 		Dhmioyrgia Oyras
  *	Meta: 		Oyra exei epayksh8ei me to stoixeio */
	if (GematiOura(*oura))
		return 0;
	else
	{
		oura->metritis++;
		TSoura_setValue(&(oura->pinakas[oura->piso]),stoixeio); /* abstraction for any type */
		oura->piso = ( oura->piso + 1 )% PLITHOS;
	}
	return 1;
}

int OuraApomakrynsh(TOuras *oura, TStoixeioyOuras *stoixeio)
{/*	Pro: 		Dhmioyrgia Oyras
  *	Meta: 		Oyra exei meiw8ei kata ena stoixeio */
	if (OuraKeni(*oura))
		return 0;
	else
	{
		oura->metritis--;
		TSoura_setValue(stoixeio, oura->pinakas[oura->embros]); /* abstraction for any type */
		oura->embros = ( oura->embros + 1 )% PLITHOS;
	}
	return 1;
}

void inspectQbyOrder (TOuras oura)
{ int current=oura.embros;
	if (!OuraKeni(oura))
	{
		do
		{
			TSoura_writeValue(stdout, oura.pinakas[current]);
			printf("-");
			current = (current+1)%PLITHOS;
		}
		while (current != oura.piso);
		printf("\n");
	}
}


void inspectQbyArray (TOuras oura)
{ int i;
	for (i=0; i<PLITHOS; i++)
	{
			TSoura_writeValue(stdout, oura.pinakas[i]);
			printf("-");
	}
	printf("\n");

}

