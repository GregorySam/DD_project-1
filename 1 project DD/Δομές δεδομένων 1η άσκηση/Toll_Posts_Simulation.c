/*************************************************
Arxeio ylopoihshs	: Toll_Posts_Simulation.c
Syggrafeas			: G.Samios 24/03/2016
Skopos				:Ylopoihsh programma pelath
Revision 			: Γρηγόρης Σάμιος-1115201500141- 27/3/15
**************************************************/
#include <stdio.h>
unsigned int Simulation(unsigned int *, float *);
int main(void) {
	unsigned int sunolikos_ArithmosPelaton = 0;
	float mesos_xronos;		/*mesos xronos anamonhs tvn pelatvn*/
	if (Simulation(&sunolikos_ArithmosPelaton, &mesos_xronos)) {
		printf("\nEksyphreth8hkan %d pelates\n", sunolikos_ArithmosPelaton);
		printf("O mesos xronos anamonhs htan %4.2f units of time.\n", mesos_xronos);
		getchar();
		return 0;
	}
	else {
		return 0;
	}
}
