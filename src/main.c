/******************************************
*  Autor       :    PCMA-SOFT   
*  Proyect     :    img2text   
*  fecha       :    04/08/2023 19:57 
*  version     :    1.0.0.0.
*******************************************/

#include <stdio.h> // salidas estandar del sistema 
#include <stdlib.h> // funciones system del sistema
#include <string.h>

// inicio del programa

int main(int argc, char * argv[])
{
	system("title Mi primer programa de consola en C");
	
	
	char nombre_img[100];
	if (argv[1]==NULL)strcpy(nombre_img,"vacio");
	else strcpy(nombre_img,argv[1]);
	
	
	puts(nombre_img);
	system("pause>nul");
	return 0;
}