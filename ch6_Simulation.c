/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 14/03/2015
Skopos				: Ylopoihsh ouras prosomoiwshs
Αναθεώρηση			:  <Το όνομα σας-Ημερομηνία>
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ch6_QArray1.h"
#include "TStoixeiouOuras.h"

int main(void)
{	TOuras      	oura;				 /*oura pelatwn*/
	float			pithanotita_afiksis; /*pi8anothta afikshs*/
	unsigned int	xronos_eksipiretisis;/*xronos e3yphrethshs enos pelath*/ 
	unsigned int	xronos_prosomoiosis; /*synolikos xronos prosomoiwshs*/
	
	unsigned int	xronos;				 /*roloi prosomoiwshs*/
	unsigned int	enapomenon_xronos;	 /*xronos gia to telos e3yphrethshs enos pelath*/
	unsigned int	arithmos_pelaton; 	 /*plh8os e3yphreth8entwn pelatwn*/
	unsigned int	xronos_anamonis;	 /*synolikos xronos anamonhs*/
	TPelatis		Pelatis;		 	/* o pelaths sthn oyra*/
	float			mesos_xronos;		 /*mesos xronos anamonhs tvn pelatvn*/
	float			randomAfixi;
	int             tamiasInactive=0;
	time_t			t;


	printf("Dwste xrono prosomoiwshs (0 <=), pi8anothta afikshs (0,1) kai xrono e3yphrethshs (>=1) )\n");
	scanf("%u %f %u",&xronos_prosomoiosis,&pithanotita_afiksis,&xronos_eksipiretisis);
	getchar();
	printf("H prosomoiwsh 8a diarkesei %4u lepta.\n",xronos_prosomoiosis);
	printf("H pi8anothta afikshs pelath se ena lepto einai: %4.2f.\n",pithanotita_afiksis);
	printf("H diarkeia e3yphrethshs enos pelath einai stauerh %d lepta.\n",xronos_eksipiretisis);

	OuraDimiourgia(&oura);
	xronos = 0;
	enapomenon_xronos = 0;
	arithmos_pelaton = 0;
	xronos_anamonis =0;
	srand(time(&t));

	while( xronos < xronos_prosomoiosis )
	{	/* Pelatis */
		randomAfixi = (float)rand()/(float)RAND_MAX; 

		if ( randomAfixi < pithanotita_afiksis ){
			PelatisSetXronoEisodou(&Pelatis, xronos);
			if (!OuraProsthesi(&oura, Pelatis)){
                  printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
                  getchar();
                  return 0;
        	};
    	};
    	
    	/* Tamias */
    	
		if ( enapomenon_xronos == 0)	/*eley8eros tamias*/
			if (!OuraKeni(oura))			/*yparxei pelaths*/
			{	OuraApomakrynsh(&oura,&Pelatis);		/*phgainei sto tamio*/
				xronos_anamonis += xronos - PelatisGetXronoEisodou(&Pelatis);	/*ypologismos xronoy paramonhs*/
				arithmos_pelaton++;
				enapomenon_xronos = xronos_eksipiretisis-1; /* kallyptei to trexon lepto */
			}else tamiasInactive++;
		else enapomenon_xronos --;		/*o tamias apasxolhmenos me pelath */
		
		xronos++; /*o xronos prosomoivshs ay3anetai kata 1 lepto*/
	} /*while( xronos < xronos_prosomoiosis )*/

	if (arithmos_pelaton == 0)
		mesos_xronos = 0.0;
	else
		mesos_xronos = ((float)xronos_anamonis)/((float)arithmos_pelaton);

	printf("\nEksyphreth8hkan %d pelates\n",arithmos_pelaton);
	printf("O mesos xronos anamonhs htan %4.2f lepta.\n",mesos_xronos);
	printf("O tamias htan adranhs gia %d lepta\n", tamiasInactive);
    getchar();
	return 0;
}
