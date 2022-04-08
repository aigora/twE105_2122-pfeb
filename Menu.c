#include <stdio.h>

int main(){

int menu, salir=1;

printf("Este es el menu del programa.\n");
printf("\n");
while(salir){
printf("\nSeleccione una de las siguientes opciones: Tablero (1), Movimientos (2), Condiciones para ganar/perder/empatar (3), Turnos(4), Tiempo(5) y para salir(9)\n");
scanf("%d", &menu);



switch(menu){

    case 1:
        printf("Tablero\n");
        printf("    1. Dibujar tablero\n");
        printf("    2. Establecer las piezas en su respectiva casilla\n");
        printf("    3. Al mover la piezas que detecten la casilla\n");
        printf("    4. Recordar la nueva posicion de las piezas");

        break;
    case 2:
        printf("Movimientos\n");
        printf("    1. Peon\n");
        printf("        a. Movimiento del peon\n");
        printf("        b. Comer otras piezas\n");
        printf("        c. Coronar\n");
        printf("        d. Hacer jaque\n");
        printf("    2. Torre\n");
        printf("        a. Movimiento de torres\n");
        printf("        b. Comer otras piezas\n");
        printf("        c. Hacer jaque\n");
        printf("    3. Alfil\n");
        printf("        a. Movimiento del alfil\n");
        printf("        b. Comer otras piezas\n");
        printf("        c. Hacer jaque\n");
        printf("    4. Caballo\n");
        printf("        a. Movimientos del caballo\n");
        printf("        b. Comer otras piezas\n");
        printf("        c. Hacer jaque\n");
        printf("    5. Reina\n");
        printf("        a. Movimientos de la reina(combinacion entre torre y alfil)\n");
        printf("        b. Comer otras piezas\n");
        printf("        c. Hacer jaque\n");
        printf("    6. Rey\n");
        printf("        a. Movimiento del rey\n");
        printf("        b. Comer otras piezas\n");
        printf("        c. Detectar el jaque\n");
        printf("    7. Restricciones\n");
        printf("        a. Otra pieza del mismo jugador en el mismo sitio\n");
        printf("        b. Cuando los peones estan en frente de otra pieza(no puede seguir avanzando)\n");

        break;
    case 3:
        printf("Condiciones para ganar/perder/empatar");
        printf("    1. Jaque mate\n");
        printf("    2. Rendirse\n");
        printf("    3. Tablas por ahogado\n");
        printf("    4. Insuficinetes piezas para hacer jaque mate\n");
        printf("    5. Agota el tiempo\n");

        break;
    case 4:
        printf("Turnos\n");
        printf("    1. Cambio de turno\n");
        printf("    2. Indicar de quien es el turno\n");
        printf("    3. Mostrar el tiempo restante\n");

        break;
    case 5:
        printf("Tiempo\n");
        printf("    1. Guardar el tiempo de cada jugador\n");
        printf("    2. Disminuir el tiempo\n");
        printf("    3. Pausar el tiempo cuando se cambia de turno\n");

        break;
    case 9:
        printf("Salir\n");
        salir=0;
    default:
        printf("Seleccione un valor de los indicados.\n");
        break;


}

}

return 0;
}
