/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			: Γρηγόρης Σάμιος -1115201500141-27/3/15
**************************************************/
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"
#include "TController.h"
struct oures{
	TOuras oura;
	TSOuras Pelatis;
	TController Controller;
	unsigned int	CountIn;			/*Posa autokinhta bikan*/
	unsigned int	CountOut;			/*Posa autokinhta bgikan*/
}*diodio;
double Input(const char *message) {			/*Sunarthsh gia elgxo ti on eisodou*/
	char input[100];
	unsigned int length, i,found_character;
	double num;
	do {
		printf("%s",message);
		scanf("%s", input);
		length = strlen(input);
		found_character = 0;
		if (input[0] == '0' && input[1] == '.' && !strcmp(message,"Dwste pithanothta afikshs (0,1)\n")) {
			for (i = 2;i < length; i++) {
				if (!isdigit(input[i])) {
					printf("Entered input is not a number in (0,1) \n");
					found_character = 1;
					break;
				}
			}
		}
		else {
			for (i = 0;i < length; i++) {
				if (!isdigit(input[i])) {
					printf("Entered input is not a number >=0 \n");
					found_character = 1;
					break;
				}
			}
		}
	} while (found_character);
	sscanf(input,"%lf",&num);
	return num;
}
int Simulation(unsigned int *sunolikos_ArithmosPelaton,float *mesos_xronos)
{
	float			pithanotita_afiksis; /*pi8anothta afikshs*/
	int	min=1001;
	unsigned int	elaxistos_xronos_eksipiretisis;/*elaxistos xronos e3yphrethshs enos pelath*/
	unsigned int	megistos_xronos_eksipiretisis;/*megistos xronos e3yphrethshs enos pelath*/ 
	unsigned int	xronos_prosomoiosis; /*synolikos xronos prosomoiwshs*/
	unsigned int	xronos;				 /*roloi prosomoiwshs*/
	unsigned int	xronos_anamonis;	 /*synolikos xronos anamonhs*/
	unsigned int 	arithmos_ouron;		/*synolikos arithmos ouron*/
	unsigned int	i,f;				/*metrites gia ta loop*/
	TSOuras		Pelatis;		 	/* o pelaths sthn oyra*/
	float			randomAfixi;	/*tuxaia puthanothta afhxhs*/
	unsigned int	randomXronos_eksipiretisis;	/*tuxaios xronos exyphrethshs*/
	time_t			t;
	xronos_prosomoiosis=(unsigned int)Input("Dwste units of time prosomoiwshs (0 <=)\n");
	arithmos_ouron = (unsigned int)Input("Dwste arithmo_ouron (0 <=)\n");
	elaxistos_xronos_eksipiretisis =(unsigned int)Input("Dwste elaxisto(>=1) xrono e3yphrethshs\n");
	megistos_xronos_eksipiretisis=(unsigned int)Input("Dwste megisto(>=1) xrono e3yphrethshs\n");
	pithanotita_afiksis = (float)Input("Dwste pithanothta afikshs (0,1)\n");
	getchar();
	printf("H prosomoiwsh 8a diarkesei %4u units of time.\n",xronos_prosomoiosis);
	printf("To plithos ton ouron einai %u\n",arithmos_ouron);
	printf("H pi8anothta afikshs pelath se ena unit of time einai: %4.2f.\n",pithanotita_afiksis);
	printf("H diarkeia e3yphrethshs enos pelath einai metaxy %d kai %d units of time.\n",elaxistos_xronos_eksipiretisis,megistos_xronos_eksipiretisis);
	diodio=malloc(arithmos_ouron*sizeof(struct oures));
	for(i=0;i<arithmos_ouron;i++){		/*arxikopoihsh timon*/
		OuraDimiourgia(&(diodio[i].oura));
		ControllerDimiourgia(&(diodio[i].Controller));
		diodio[i].CountIn = 0;
		diodio[i].CountOut = 0;
	}
	xronos = 0;
	xronos_anamonis =0;
	srand(time(&t));

	while( xronos < xronos_prosomoiosis )
	{	/* Pelatis- Aytokinhto  */
		randomAfixi = (float)rand()/(float)RAND_MAX; 
		if (randomAfixi < pithanotita_afiksis) {
			PelatisSetXronoEisodou(&Pelatis, xronos);
			for (i = 0;i < arithmos_ouron;i++) {
				if (diodio[i].oura.metritis < min || diodio[i].oura.metritis == 0) {		/*Euresh diodiou me mikroterh oura*/
					min = diodio[i].oura.metritis;
					f = i;
					break;
				}
			}
			if (!OuraProsthesi(&(diodio[f].oura), Pelatis)) {							/*Eisodos sthn oura*/
				printf("Oi oyres einai mikres! H prosomoivsh stamataei \n");
				getchar();
				return 0;
			}
			else {
				diodio[f].CountIn++;				/*Eisodos sthn oura*/
			}
		}
    	
    		/* Tamias-Elegxos */
		for (i = 0;i < arithmos_ouron;i++) {
			if (ControllerFree(diodio[i].Controller)) {	/*eley8eros tamias*/
				if (!OuraKeni(diodio[i].oura)) {			/*yparxei pelaths*/
					OuraApomakrynsh(&(diodio[i].oura), &Pelatis);
					diodio[i].CountOut++;		/*phgainei sto tamio*/
					xronos_anamonis += xronos - PelatisGetXronoEisodou(Pelatis);	/*ypologismos xronoy paramonhs sthn oura*/
					printf("Time is %d Time out %d\n", xronos, PelatisGetXronoEisodou(Pelatis));
					randomXronos_eksipiretisis = (rand() % (megistos_xronos_eksipiretisis - elaxistos_xronos_eksipiretisis)) + elaxistos_xronos_eksipiretisis;
					PelatisSetXronoEksipiretisis(&Pelatis, randomXronos_eksipiretisis);
					ControllerSetXrono(&(diodio[i].Controller), randomXronos_eksipiretisis);
					ControllerNewCustomer(&(diodio[i].Controller));
					diodio[i].Controller.enapomenonXronos = randomXronos_eksipiretisis - 1; /* kallyptei to trexon unit time */
				}
				else {
					ControllerNoWork(&(diodio[i].Controller));
				}
			}
			else {
				ControllerBusy(&(diodio[i].Controller));		/*o tamias apasxolhmenos me pelath */
			}
		}
		xronos++; /*o xronos prosomoivshs ay3anetai kata 1 unit of time*/
	} /*while( xronos < xronos_prosomoiosis )*/
	for (i = 0;i < arithmos_ouron;i++) {
		*sunolikos_ArithmosPelaton += diodio[i].Controller.ArithmoPelaton;	/*Ypologismos synolikou arithmou pelaton pou exupuretithikan*/
	}
	if (!sunolikos_ArithmosPelaton) {
		*mesos_xronos = 0.0;
	}
	else {
		*mesos_xronos = ((float)xronos_anamonis) / ((float)*sunolikos_ArithmosPelaton);
	}
	for (i = 0;i < arithmos_ouron;i++) {
		printf("--O %dos elegkths exuphrethse %d pelates,htan apasxolhmenos gia %d units of time,htan adranhs gia %d units of time \nbikan %d bgikan %d kai perisepsan sthn oura(dn exupyretithikan) %d autokinhta\n\n", i + 1, diodio[i].Controller.ArithmoPelaton, diodio[i].Controller.TimeBusy, diodio[i].Controller.TimeInactive, GetCountIn(diodio[i].CountIn), GetCountOut(diodio[i].CountOut),diodio[i].oura.metritis);
	}
	return 1;
}
