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
	char nombre_arreglo[115];
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

	int valor,contador=0;
	char hex[11];

	strcpy(nombre_arreglo,"int ");
	strcat(nombre_arreglo,nombre_img);
	strcat(nombre_arreglo,"[]={\n");
	fputs(nombre_arreglo,crea_txt);
	while(!feof(lee_img)){
		//fread(&valor,sizeof(int),1,archivo);
		fread(&valor,sizeof(int),1,lee_img);
		//fputc('"',crea_txt);
		// 1° forma
		//fwrite(&valor,sizeof(int),1,crea_txt);
		
		// 2° forma
		//sprintf(hex,"%X",valor);
		//fwrite(hex,sizeof(int),1,crea_txt);
		
		// 3° forma
		fprintf(crea_txt,"%X",valor);
		
		//fputc('"',crea_txt);
		
		contador++;
		if(!feof(lee_img)) fputc(',',crea_txt);
		if((contador % 16) == 0) fputc('\n',crea_txt);
		
	}
	fputs("};",crea_txt);
	puts(nombre_img_ftm);
	fclose(lee_img);
	fclose(crea_txt);
	getch();
	return 0;
}