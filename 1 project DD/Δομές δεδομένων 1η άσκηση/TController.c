/*************************************************************************
Implementation File	: TController.c
Author Date			: G.Samios 22/03/2016
Purpose				:  Controller Functions
Revision			: Γρηγόρης Σάμιος-1115201500141-27/3/15
**************************************************************************/
#include "TController.h"
void ControllerDimiourgia(TController *Controller){
	Controller->ArithmoPelaton=0;
	Controller->enapomenonXronos=0;
	Controller->TimeBusy=0;
	Controller->TimeInactive=0;
}
void ControllerNewCustomer(TController *Controller){
	Controller->ArithmoPelaton++;
	Controller->TimeBusy++;
}
void ControllerSetXrono(TController *Controller, int xronosEksipiretisis){
	Controller->enapomenonXronos=xronosEksipiretisis;
}
void ControllerNoWork(TController *Controller){
	Controller->TimeInactive++;
}
void ControllerBusy(TController *Controller){
	Controller->TimeBusy++;
	Controller->enapomenonXronos--;
}
int ControllerFree(TController Controller){
	return !(Controller.enapomenonXronos);
}
int ControllerGetArithmosPelatwn(TController Controller){
	return Controller.ArithmoPelaton;
}
int ControllerGetEnapomenonXronos(TController Controller){
	return Controller.enapomenonXronos;
}
int ControllerGetInactiveXronos(TController Controller){
	return Controller.TimeInactive;
}
int ControllerGetBusyXronos(TController Controller){
	return Controller.TimeBusy;
}
