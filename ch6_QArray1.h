/**********************************************+**************************
Αρχείο Επικεφαλίδας	: QArray.h
Συγγραφέας				: Γ. Κοτρώνης
Σκοπός					: Υλοποίηση με πίνακα Αφηρημένου Τύπου Δεδομένων Ουρά
**************************************************************************/
#ifndef __CH2_QARRAY__ 
#define __CH2_QARRAY__
#include "TStoixeioyOuras.h"

/*δηλώσεις τύπων*/

#define PLITHOS 5

typedef struct {
	int embros;		/*θέση του πρώτου στοιχείου της ουράς*/
	int piso;		/*θέση του τελευταίου στοιχείου της ουράς*/
	int metritis;
	TStoixeioyOuras pinakas[PLITHOS];	/*ο πίνακας στοιχείων*/
} TOuras;	   /*ο τύπος της ουράς*/

/*δηλώσεις συναρτήσεων*/

/*δημιουργία*/  
void OuraDimiourgia(TOuras *oura);

/*Πράξεις έλεγχου*/
int	OuraKeni	(TOuras oura);
int	GematiOura	(TOuras oura);
int SizeOuras(TOuras oura);

/*Πράξεις προσθεσης/απομάκρυνσης*/
int OuraProsthesi	(TOuras *oura, TStoixeioyOuras stoixeio);
int OuraApomakrynsh(TOuras *oura, TStoixeioyOuras *stoixeio);

void inspectQbyOrder (TOuras oura);
void inspectQbyArray (TOuras oura);

#endif /*#ifndef __CH2_QARRAY__ */
