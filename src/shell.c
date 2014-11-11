#include "../include/video.h"

char * prompt = ">MaritoUser$ ";

void startShell(){

	printSplashScreen();
	printf("%s",prompt);
	while(1){

	}
}

void printSplashScreen(){
	printf("\n");
	printf("\n");
	printf("$$       $$                      $$    $$                $$$$$$$                                           $$$$$$    $$$$$$\n");
	printf("$$$     $$$                            $$                $$    $$                                         $$    $$  $$    $$\n");
	printf("$$$$   $$$$   $$$$$$    $$$$$$   $$  $$$$$$     $$$$$$   $$    $$   $$$$$$    $$$$$$   $$$$$$    $$$$$$$  $$    $$  $$\n");
	printf("$$ $$ $$ $$        $$  $$    $$  $$    $$      $$    $$  $$$$$$$         $$  $$    $$       $$  $$        $$    $$   $$$$$$\n");
	printf("$$  $$$  $$   $$$$$$$  $$        $$    $$      $$    $$  $$    $$   $$$$$$$  $$        $$$$$$$  $$        $$    $$        $$\n");
	printf("$$   $   $$  $$    $$  $$        $$    $$  $$  $$    $$  $$    $$  $$    $$  $$       $$    $$  $$        $$    $$  $$    $$\n");
	printf("$$       $$   $$$$$$$  $$        $$     $$$$    $$$$$$   $$$$$$$    $$$$$$$  $$        $$$$$$$   $$$$$$$   $$$$$$    $$$$$$\n");
	printf("\n");
	printf("\n");
}