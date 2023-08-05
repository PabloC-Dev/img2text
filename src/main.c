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
	
	
	char nombre_arch[100];
	char nombre_ext[100];
	char nombre_ftm[100];
	char nombre_arreglo[100];
	if (argv[1]==NULL && argv[2]==NULL && argv[3]==NULL && argv[4]==NULL ){
		printf("Debe ingresar el nombre del archivo, la extenci\242n, nombre para el archivo con la extension, nombre para el array;\
		 		EJEMPLO: nombre_archivo .extensi\242 nombre_archivo_salida nombre_array");
		getch();
		exit(-1);
	}
	else {
		strcpy(nombre_arch,argv[1]);
		strcpy(nombre_ext,argv[2]);
		strcpy(nombre_ftm,argv[3]);
		strcpy(nombre_arreglo,argv[4]);

	}
	FILE* lee_arch;
	FILE* crea_txt;
	

	lee_arch = fopen(nombre_arch,"rb");
	crea_txt = fopen(nombre_ftm,"w");

	int valor,contador=0;
	char hex[11];
	char nombre_arreglo_fin[100];

	fputs("#pragma once\n",crea_txt);

	char arch_nom_s[100];
	strcpy(arch_nom_s,"char ");
	strcat(arch_nom_s,"nombre_archivo[]= \"");
	strcat(arch_nom_s,nombre_arch);
	strcat(arch_nom_s,"\";\n");
	fputs(arch_nom_s,crea_txt);

	strcpy(nombre_arreglo_fin,"int ");
	strcat(nombre_arreglo_fin,nombre_arreglo);
	strcat(nombre_arreglo_fin,"[]={\n");
	fputs(nombre_arreglo_fin,crea_txt);
	while(!feof(lee_arch)){
		//fread(&valor,sizeof(int),1,archivo);
		fread(&valor,sizeof(int),1,lee_arch);
		//fputc('"',crea_txt);
		// 1° forma
		//fwrite(&valor,sizeof(int),1,crea_txt);
		
		// 2° forma
		//sprintf(hex,"%X",valor);
		//fwrite(hex,sizeof(int),1,crea_txt);
		
		// 3° forma
		fprintf(crea_txt,"0x%08X",valor);
		
		//fputc('"',crea_txt);
		
		contador++;
		if(!feof(lee_arch)) fputc(',',crea_txt);
		if((contador % 16) == 0) fputc('\n',crea_txt);
		
	}
	fputs("};\n",crea_txt);
	char cantidad[50];
	strcpy(cantidad,"int cantidad = ");
	char cont_s[11];
	itoa(contador,cont_s,10);
	strcat(cantidad,cont_s);
	strcat(cantidad,";\n");
	fputs(cantidad,crea_txt);

	char ext_s[100];
	strcpy(ext_s,"char ");
	strcat(ext_s,"extension[]= \"");
	strcat(ext_s,nombre_ext);
	strcat(ext_s,"\";\n");
	fputs(ext_s,crea_txt);
	

	puts("Formateado correctamente!..\n");
	fclose(lee_arch);
	fclose(crea_txt);
	getch();
	return 0;
}