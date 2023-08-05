/******************************************
*  Autor       :    PCMA-SOFT   
*  Proyect     :    img2text   
*  fecha       :    04/08/2023 19:57 
*  version     :    1.0.0.0.
*******************************************/

#include <stdio.h> // salidas estandar del sistema 
#include <stdlib.h> // funciones system del sistema
#include <string.h>
#include <conio.h>

// inicio del programa

int main(int argc, char * argv[])
{
	system("title Formatear archivo a array int en C");
	
	
	char nombre_img[100];
	char nombre_img_ftm[115];
	if (argv[1]==NULL){
		printf("debe ingresar el nombre del archivo con la extenci\242n, ej. imagen.jpg");
		getch();
		exit(-1);
	}
	else {
		strcpy(nombre_img,argv[1]);
		strcpy(nombre_img_ftm,argv[1]);
	}
	FILE* lee_img;
	FILE* crea_txt;
	strcat(nombre_img_ftm,"_formateado.txt");

	lee_img = fopen(nombre_img,"rb");
	crea_txt = fopen(nombre_img_ftm,"w");

	
	puts(nombre_img_ftm);
	fclose(lee_img);
	fclose(crea_txt);
	getch();
	return 0;
}