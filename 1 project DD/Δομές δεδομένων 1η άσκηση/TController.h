/*************************************************************************
Implementation File	: TController.h
Author Date			: G.Samois 23/03/2016
Purpose				: Controller Functions
Revision			: Γρηγόρης Σάμιος-1115201500141- 27/3/15
**************************************************************************/

typedef struct{
	unsigned int TimeBusy;
	unsigned int TimeInactive;
	unsigned int ArithmoPelaton;
	unsigned int enapomenonXronos;
}TController;



void ControllerDimiourgia(TController *Controller); // arxikopoiei ta melh tou struct
void ControllerNewCustomer(TController *Controller);// auxanei to metrhth pelaton kai prosthetiei 1 monada xronoy apasxoishs ston elegth
void ControllerSetXrono(TController *Controller, int xronosEksipiretisis);// arxikopoiei enapominonta xrono os ton xrono exypyretishs gia kathe neo pelath
void ControllerNoWork(TController *Controller); // auxanei xrono adranias kata mia monada
void ControllerBusy(TController *Controller);// auxanei xrono apasxolishs kai meionei enapominonta xrono kata mia monada
int ControllerFree(TController Controller); // elegxei an einai diathesimos
int ControllerGetArithmosPelatwn(TController Controller); // epistrefei arithmo pelton
int ControllerGetEnapomenonXronos(TController Controller); // epistrefei enapominonta xrono
int ControllerGetInactiveXronos(TController Controller); // epistrefei xrono adraneias
int ControllerGetBusyXronos(TController Controller); // epistrefei xrono apasxolishs
