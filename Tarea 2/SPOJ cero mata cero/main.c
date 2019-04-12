#include <stdio.h>
#include <conio.h>

char cuadrado[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int revisar();
void tabla();

int main()
{
    int jugador = 1, i, opcion;

    char marca;
    do
    {
        tabla();
        jugador = (jugador % 2) ? 1 : 2;

        printf("Jugador #%d, introduce un numero:  ", jugador);
        scanf("%d", &opcion);

        marca = (jugador == 1) ? 'X' : 'O';

        if (opcion == 1 && cuadrado[1] == '1')
            cuadrado[1] = marca;

        else if (opcion == 2 && cuadrado[2] == '2')
            cuadrado[2] = marca;

        else if (opcion == 3 && cuadrado[3] == '3')
            cuadrado[3] = marca;

        else if (opcion == 4 && cuadrado[4] == '4')
            cuadrado[4] = marca;

        else if (opcion == 5 && cuadrado[5] == '5')
            cuadrado[5] = marca;

        else if (opcion == 6 && cuadrado[6] == '6')
            cuadrado[6] = marca;

        else if (opcion == 7 && cuadrado[7] == '7')
            cuadrado[7] = marca;

        else if (opcion == 8 && cuadrado[8] == '8')
            cuadrado[8] = marca;

        else if (opcion == 9 && cuadrado[9] == '9')
            cuadrado[9] = marca;

        else
        {
            printf("Jugada Invalida ");

            jugador--;
            getch();
        }
        i = revisar();

        jugador++;
    }while (i ==  - 1);

    tabla();

    if (i == 1)
        printf("==>\aJugador #%d gana ", --jugador);
    else
        printf("==>\aEmpate");

    getch();

    return 0;
}

int revisar()
{
    if (cuadrado[1] == cuadrado[2] && cuadrado[2] == cuadrado[3])
        return 1;

    else if (cuadrado[4] == cuadrado[5] && cuadrado[5] == cuadrado[6])
        return 1;

    else if (cuadrado[7] == cuadrado[8] && cuadrado[8] == cuadrado[9])
        return 1;

    else if (cuadrado[1] == cuadrado[4] && cuadrado[4] == cuadrado[7])
        return 1;

    else if (cuadrado[2] == cuadrado[5] && cuadrado[5] == cuadrado[8])
        return 1;

    else if (cuadrado[3] == cuadrado[6] && cuadrado[6] == cuadrado[9])
        return 1;

    else if (cuadrado[1] == cuadrado[5] && cuadrado[5] == cuadrado[9])
        return 1;

    else if (cuadrado[3] == cuadrado[5] && cuadrado[5] == cuadrado[7])
        return 1;

    else if (cuadrado[1] != '1' && cuadrado[2] != '2' && cuadrado[3] != '3' &&
        cuadrado[4] != '4' && cuadrado[5] != '5' && cuadrado[6] != '6' && cuadrado[7]
        != '7' && cuadrado[8] != '8' && cuadrado[9] != '9')

        return 0;
    else
        return  - 1;
}


void tabla()
{
    system("cls");
    printf("\n\n\tCero Mata Cero\n\n");

    printf("Jugador 1 (X)  -  Jugador 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", cuadrado[1], cuadrado[2], cuadrado[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", cuadrado[4], cuadrado[5], cuadrado[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", cuadrado[7], cuadrado[8], cuadrado[9]);

    printf("     |     |     \n\n");
}

