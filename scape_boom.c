#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int menu();





int main()
{

	int menu, salir = 1, jugadores, jugador, i, dificultad;
	char nombre_grupo[50], aux2[100];
	char respuestas[10];

	datos dato[N];

	FILE *f;

	while (salir)
	{

        f = fopen("BOMABA.txt", "r");
            if(f == NULL){
                printf("No se he podido abrir el fichero\n");
            }
            while(!feof(f)){
                fgets(aux2, 100, f);
                printf("%s", aux2);
            }

    fclose(f);
    sleep(3);
    system("cls");


		printf("\t\t\t\tBIENVENIDOS AL SCAPE BOOM!\n\n");
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
			sleep(3);
			system("cls");

			printf("\n");
			printf("\t\tSELECCIONE NIVEL DE DIFIICULTAD:\n\n");
			printf("\t\t\t1. FACIL\n\n");
			printf("\t\t\t2. MEDIO\n\n");
			printf("\t\t\t3. DIFICIL\n");
			scanf("%d", &dificultad);
			system("cls");

			i = preguntas(dificultad, nombre_grupo);
			printf("\t\tHAS CONSEGIDO %d ACIERTOS\n", i);

			if(i<5)
            {
                printf("\t\tNO HAS CONSEGUIDO DESACTIVAR LA BOMBA!!\n");

                f = fopen("EXPLOSION.txt", "r");
                    if(f == NULL){
                    printf("No se he podido abrir el fichero\n");
                    }
                    while(!feof(f)){
                    fgets(aux2, 100, f);
                    printf("%s", aux2);
                    }

                fclose(f);
			}

            else
            {
                 printf("\t\tLA BOMBA HA SIDO DESCATIVADA CORRECTAMENTE\n");

                 f = fopen("NEUTRALIZACION.txt", "r");
                    if(f == NULL){
                    printf("No se he podido abrir el fichero\n");
                    }
                    while(!feof(f)){
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
		case 5:

			i = preguntas(1, "nombre_grupo");
			printf("%d\n", i);
			break;

		default:
			printf("Seleccione un valor de los indicados.\n");
			break;
		}
    return 0;
	}

	return 0;
}

int preguntas(int dificultad, char* ng)
{
	int i, j, puntos = 0;
	char buffer[150];
	char solus[7];
	char solucion_facil[] = "BCCAABB";
	char solucion_media[] = "DABCBCD";
	char solucion_dificil[] = "CBDAADC";
	FILE *f;
	int puntuacion = 0;

	switch (dificultad)
	{
	case 1:
		printf("\t\t\tEL GRUPO %s HA SELECCIONADO LA DIFICULTAD FACIL\n\n", ng);
		strcpy(solus, solucion_facil);
		f = fopen("PREGUNTAS_FACIL.txt", "r");
		break;
	case 2:
		printf("\t\t\tEL GRUPO %s HA SELECCIONADO LA DIFICULTAD MEDIA\n\n", ng);
		strcpy(solus, solucion_media);
		f = fopen("PREGUNTAS_MEDIO.txt", "r");
		break;
	case 3:
		printf("\t\t\tEL GRUPO %s HA SELECCIONADO LA DIFICULTAD DIFICIL\n\n", ng);
		strcpy(solus, solucion_dificil);
		f = fopen("PREGUNTAS_DIFICIL.txt", "r");
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
		for (i = 0; i < 8; i++)
		{
			fgets(buffer, 100, f);
			printf("%s", buffer);
		}
		scanf("%s", buffer);
		while(buffer[0] < 'A' || buffer[0] > 'D'|| strlen(buffer)>1){
			printf("Esa no es una respuesta valida.\nIntroduce A, B, C o D \n");
			scanf("%s", buffer);
		}

		if(buffer[0] == solus[j]){
			puntos++;
		}
	}

	fclose(f);
	return puntos;
}

void instrucciones(){

    printf("\tLAS INSTRUCCIONES DE ESTE ESCAPE ROOM SON MUY SENCILLAS YA QUE LOS INTEGRANTES \n\tDEL GRUPO DEBERAN RESOLVER UNA SERIE DE ENIGMAS LOS CUALES SERVIRAN PARA DESACTIVAR LA BOMBA\n\n");
    printf("\tEL JUEGO CONSTA CON TRES NIVELES DE DIFICULTAD: FACIL, MEDIO Y DIFICIL\n\n");
    printf("\tUNA VEZ ELEGIDA LA DIFICULTAD, EL JUEGO COMIENZA\n\n");
    printf("\tLA BOMBA TIENE UNA CONTRASEÑA OCULTA Y PARA CONSEGUIRLA SERA NECESAREO RESOLVER CINCO PREGUNTAS CON EXITO\n\n");
    printf("\tEN CASO DE CONSEGUIR ESOS CINCO ACIERTOS LA BOMBA EXPLOTARA\n\n");
}


