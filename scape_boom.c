#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#define N 2

#define FACIL 1
#define MEDIO 2
#define DIFICIL 3

typedef struct
{
	char nombre[50];
	char apellido1[50];
	char apellido2[50];
} datos;

void instrucciones();
int preguntas(int dificultad, char *ng, int *fallos);
int printDificultad();

int main()
{

	int menu, salir = 1, jugadores, jugador, i, dificultad;
	char nombre_grupo[50], aux2[100];
	char respuestas[10];

	int fallos = 0, max_fallos;
	datos dato[N];
    srand(time(NULL));

	FILE *f;

	f = fopen("BOMABA.txt", "r");
	if (f == NULL)
	{
		printf("No se he podido abrir el fichero\n");
	}
	while (!feof(f))
	{
		fgets(aux2, 100, f);
		printf("%s", aux2);
	}

	fclose(f);

	printf("\t\t ____________________________________________________\n");
	printf("\t\t/____________________________________________________\\\r");
	printf("\t\t/");
	for (i = 0; i < 52; i++, usleep(100))
	{
		printf("|");
		if((rand() % 20) < 1){
			sleep(1);
		}
	}

	system("cls");

	printf("\t\tBIENVENIDOS AL SCAPE BOOM!\n\n");

	while (salir)
	{

		printf("\t\tINDIQUE UNA DE LAS OPCIONES:\n\n");
		printf("\t\t\t 1. REGRISTRARSE Y JUGAR\n\n");
		printf("\t\t\t 2. INSTRUCCIONES\n\n");
		printf("\t\t\t 0. SALIR\n\n");
		scanf("%d", &menu);

		system("cls");

		switch (menu)
		{

		case 1:

			do
			{
				printf("\n");
				printf("\tINTRODUZCA EL NUMERO DE JUGADORES QUE VAN A PARTICIPAR (EL MAXIMO SON TRES JUGADORES):\n");
				fflush(stdin);
				scanf("%d", &jugadores);
			} while (jugadores > 3);

			for (i = 0; i < jugadores; i++)
			{
				printf("\t\tDATOS DEL JUGADOR NUMERO %d:\n", i + 1);

				printf("\t\tNOMBRE:\t");
				scanf("%s", dato[i].nombre);
				printf("\t\tPRIMER APELLIDO: ");
				scanf("%s", dato[i].apellido1);
				printf("\t\tSEGUNDO APELLIDO: ");
				scanf("%s", dato[i].apellido2);
			}

			for (i = 0; i < jugadores; i++)
			{
				printf("\t\t%s ", dato[i].nombre);
				printf("%s ", dato[i].apellido1);
				printf("%s \n", dato[i].apellido2);
			}

			printf("\n");
			printf("\tA CONTINUACION, INTRODUZCA EL NOMBRE DE SU EQUIPO:\n");
			fflush(stdin);
			scanf("%s", &nombre_grupo);

			printf("\t\tREGISTRO COMPLETADO\n\n");
			printf("\t\tBIENVENIDOS %s!!\n", nombre_grupo);
			printf("\n");
			printf("\t\tCARGANDO...\n");
			// sleep(3);

			for (i = 0; i < 100; i++, usleep(1000))
			{
				if(i == 70){
					sleep(1);
				}
				printf("\tCargando recursos %d/100\r", i + 1);
			}
			printf("\tCargando recursos %d/100  ", i);
			sleep(1);
			printf("\n");

			system("cls");

			dificultad = printDificultad();
			system("cls");

			i = preguntas(dificultad, nombre_grupo, &fallos);
			printf("\t\tHAS TENIDO %d/7 ACIERTOS\n", 7 - fallos);


			if (i < 0)
			{
				printf("\t\tLA BOMBA HA EXPLOTADO!!\n\n");
				printf("\t\tLA PROXIMA VEZ SERA\n");
                    for (i = 0; i < jugadores; i++){
                        printf("\t\t%s ", dato[i].nombre);
                        printf("%s ", dato[i].apellido1);
                        printf("%s \n", dato[i].apellido2);
                    }

				f = fopen("EXPLOSION.txt", "r");
				if (f == NULL)
				{
					printf("No se he podido abrir el fichero\n");
				}
				while (!feof(f))
				{
					fgets(aux2, 100, f);
					printf("%s", aux2);
				}

				fclose(f);


			}

			else
			{
				printf("\t\tLA BOMBA HA SIDO DESCATIVADA CORRECTAMENTE!!\n\n");
				printf("\t\tENHORABUENA!!\n");
                    for (i = 0; i < jugadores; i++){
                        printf("\t\t%s ", dato[i].nombre);
                        printf("%s ", dato[i].apellido1);
                        printf("%s \n", dato[i].apellido2);
                    }

				f = fopen("NEUTRALIZACION.txt", "r");
				if (f == NULL)
				{
					printf("No se he podido abrir el fichero\n");
				}
				while (!feof(f))
				{
					fgets(aux2, 100, f);
					printf("%s", aux2);
				}

				fclose(f);
			}

			break;

		case 2:

			instrucciones();

			break;

		case 0:
			printf("SALIENDO...\n");
			salir = 0;
			break;

		default:
			printf("Seleccione un valor de los indicados.\n");
			break;
		}

		system("pause");
		system("cls");

	}

	return 0;
}

int preguntas(int dificultad, char *ng, int *fallos)
{
	int i, j, puntos = 0;
	char buffer[150];
	char solus[7];
	char solucion_facil[] = "BCCAABB";
	char solucion_media[] = "DABCBCD";
	char solucion_dificil[] = "CBDAADC";
	FILE *f;

	int max_fallos = 4;

	switch (dificultad)
	{
	case 1:
		printf("\t\t\t%s HA SELECCIONADO LA DIFICULTAD FACIL\n\n", ng);
		strcpy(solus, solucion_facil);
		f = fopen("PREGUNTAS_FACIL.txt", "r");

		break;
	case 2:
		printf("\t\t\t%s HA SELECCIONADO LA DIFICULTAD MEDIA\n\n", ng);
		strcpy(solus, solucion_media);
		f = fopen("PREGUNTAS_MEDIO.txt", "r");
		max_fallos = 2;
		break;
	case 3:
		printf("\t\t\t%s HA SELECCIONADO LA DIFICULTAD DIFICIL\n\n", ng);
		strcpy(solus, solucion_dificil);
		f = fopen("PREGUNTAS_DIFICIL.txt", "r");
		max_fallos = 1;
		break;
	}
	if (f == NULL)
	{
		printf("No se he podido abrir el fichero\n");
	}
	printf("\t\t\tCOMENCEMOS...\n");

	for (j = 0; j < 7; j++)
	{
		printf("\n\n");
		printf("%d/%d fallos\n\n", (*fallos), max_fallos);
		for (i = 0; i < 8; i++)
		{
			fgets(buffer, 100, f);
			printf("%s", buffer);
		}
		scanf("%s", buffer);
		while (buffer[0] < 'A' || buffer[0] > 'D' || strlen(buffer) > 1)
		{
			printf("Esa no es una respuesta valida.\nIntroduce A, B, C o D \n");
			scanf("%s", buffer);
		}

		if (buffer[0] != solus[j])
		{
			(*fallos)++;
			if ((*fallos) >= max_fallos)
			{
				fclose(f);
				return -1;
			}
		}
	}

	fclose(f);

	return 0;
}


void instrucciones()
{
	printf("\tLAS INSTRUCCIONES DE ESTE SCAPE ROOM SON MUY SENCILLAS YA QUE LOS INTEGRANTES \n\tDEL GRUPO DEBERAN RESOLVER UNA SERIE DE ENIGMAS LOS CUALES SERVIRAN PARA DESACTIVAR LA BOMBA\n\n");
	printf("\tEL JUEGO CONSTA CON TRES NIVELES DE DIFICULTAD: FACIL, MEDIO Y DIFICIL\n\n");
	printf("\tUNA VEZ ELEGIDA LA DIFICULTAD, EL JUEGO COMIENZA\n\n");
	printf("\tDEPENDIENDO DE LA DIFICULTAD ELEGIDA, PODREIS TENER UN MAXIMO DE ERRORES, \n\tES DECIR, EN LA DIFICULTAD FACIL SERAN 4 ERRORES, EN LA MEDIA 2 Y EN LA DIFICIL 1\n\n");
	printf("\tEN CASO DE SUPERAR ESOS ERRORES, LA BOMBA EXPLOTARA\n\n");

}



int printDificultad()
{
	int dificultad;

	printf("\t\tSELECCIONE NIVEL DE DIFIICULTAD:\n\n");
	printf("\t\t\t1. FACIL\n\n");
	printf("\t\t\t2. MEDIO\n\n");
	printf("\t\t\t3. DIFICIL\n");
	scanf("%d", &dificultad);
	return dificultad;
}
