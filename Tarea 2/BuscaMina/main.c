#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

#define TRUE 0
#define FALSE 1
#define Tam_pizarra 6


void crear_tablero();
void crear_tab_juego();
void crear_minas();
void print_tablero();
void tablerocompleto();
void inicio();
int jugar_juego();
void jugar_nuevo();
int mirar_gano();
void buscar_minas(int, int);
int revisar_minas_cercanas(int, int);


char tablero[Tam_pizarra][Tam_pizarra];
char tablero_juego[Tam_pizarra][Tam_pizarra];
int perdida = 0;


int main()
{


    printf("\nPresionar enter");


    getchar();
    system("cls");

    inicio();

    return 0;

}

void inicio()
{
    perdida = 0;

    crear_tablero();
    crear_tab_juego();


    do
    {
    jugar_juego();
    print_tablero();
    } while(perdida != 1);


    jugar_nuevo();
}

void crear_tablero()
{

    int i, j;



    for(i = 0; i < Tam_pizarra; i++)
        for(j = 0; j < Tam_pizarra; j++)
            tablero[i][j] = 'o';

    crear_minas();
}

void crear_tab_juego()
{

    int i, j;
    int fila, col, cur = 4;
    printf("Creando Partida");

    for(i = 0; i < Tam_pizarra; i++)
        for(j = 0; j < Tam_pizarra; j++)
            tablero_juego[i][j] = 'o';


    for(col = 0; col < Tam_pizarra; col++)
        printf("%d ", col + 1);

    printf("\n\n");

    for(fila = 0; fila < Tam_pizarra; fila++)
    {
        for(col = 0; col < Tam_pizarra; col++)
        {
            printf("%c ", tablero_juego[fila][col]);
        }
        printf(" %d ", fila + 1);
        printf("\n");
    }
}

void crear_minas()
{
    int i, random;

    srand(time(0));

    for (i = 0; i < Tam_pizarra; i++)
    {
        random = rand() % (Tam_pizarra);
        tablero[random][i] = '*';
    }

}

void print_tablero()
{
    int fila, col;

    system("cls");
    for(col = 0; col < Tam_pizarra; col++)
        printf("%d ", col + 1);

    printf("\n\n");
        for(fila = 0; fila < Tam_pizarra; fila++)
    {
        for(col = 0; col < Tam_pizarra; col++)
        {
            printf("%c ", tablero_juego[fila][col]);
        }
        printf(" %d ", fila + 1);
        printf("\n");
    }
}

void tablerocompleto()
{
    int fila, col;

    system("cls");
    for(col = 0; col < Tam_pizarra; col++)
        printf("%d ", col + 1);

    printf("\n\n");
        for(fila = 0; fila < Tam_pizarra; fila++)
    {
        for(col = 0; col < Tam_pizarra; col++)
        {
            printf("%c ", tablero[fila][col]);
        }
        printf(" %d ", fila + 1);
        printf("\n");
    }
}

int jugar_juego()
{
    int r_seleccion = 0, c_seleccion = 0,
        minacercana = 0, minacercana2 = 0,
        minacercana3 = 0, minacercana4 = 0,
        minacercana5 = 0, minacercana6 = 0,
        minacercana7 = 0, minacercana8 = 0,
        i = 0;



    do {
    printf("\nHaga su Seleccion: \n");
    printf("Fila--> ");
    scanf("%d", &r_seleccion);
    printf("Columna--> ");
    scanf("%d", &c_seleccion);

    } while(r_seleccion < 1 || r_seleccion > Tam_pizarra || c_seleccion < 1 || r_seleccion > Tam_pizarra);

    buscar_minas(r_seleccion - 1, c_seleccion - 1);

    if(perdida == 1)
        return -1;

    minacercana = revisar_minas_cercanas(r_seleccion - 1, c_seleccion - 1);
    tablero_juego[r_seleccion - 1][c_seleccion - 1] = (char)( ((int)'0') + minacercana );


    if(minacercana == 0)
    {
        if(c_seleccion != Tam_pizarra)
        {
            i = 0;
            while(minacercana == 0 && (c_seleccion - 1 + i) < Tam_pizarra)
            {

                minacercana = revisar_minas_cercanas(r_seleccion - 1, (c_seleccion - 1 + i));
                if(minacercana != -1)
                {
                tablero_juego[r_seleccion - 1][(c_seleccion - 1) + i] = (char) ( ((int)'0') + minacercana );
                i++;
                }
            }
                if(r_seleccion != 1)
                {
                    i = 0;
                    while(minacercana5 == 0 && (c_seleccion - 1 + i) < Tam_pizarra && (r_seleccion - 1 - i) > 0)
                    {

                        minacercana5 = revisar_minas_cercanas((r_seleccion - 1 - i), (c_seleccion - 1 + i));
                        if(minacercana5 != -1)
                        {
                        tablero_juego[(r_seleccion - 1) - i][(c_seleccion - 1) + i] = (char) ( ((int)'0') + minacercana5);
                        i++;
                        }
                    }
                }
                if(r_seleccion != Tam_pizarra)
                {
                    i = 0;
                    while(minacercana6 == 0 && (r_seleccion - 1 + i) < Tam_pizarra && (c_seleccion - 1 + i) < Tam_pizarra )
                    {

                        minacercana6 = revisar_minas_cercanas((r_seleccion - 1 + i), (c_seleccion - 1 + i));
                        if(minacercana != -1)
                        {
                        tablero_juego[(r_seleccion - 1) + i][(c_seleccion - 1) + i] = (char) ( ((int)'0') + minacercana6);
                        i++;
                        }
                    }
                }
        }

        if(r_seleccion != Tam_pizarra)
        {
            i = 0;
            while(minacercana2 == 0 && (r_seleccion - 1 + i) < Tam_pizarra)
            {

                minacercana2 = revisar_minas_cercanas((r_seleccion - 1 + i), c_seleccion - 1);
                if(minacercana2 != -1)
                {
                tablero_juego[(r_seleccion - 1) + i][c_seleccion - 1] = (char) ( ((int)'0') + minacercana2 );
                i++;
                }
            }

            if(c_seleccion != Tam_pizarra)
            {
                i = 0;
                while(minacercana7 == 0 && (r_seleccion - 1 + i) < Tam_pizarra && (c_seleccion - 1 - i) > 0)
                {

                    minacercana7 = revisar_minas_cercanas((r_seleccion - 1 + i), (c_seleccion - 1 - i));
                    if(minacercana != -1)
                    {
                    tablero_juego[(r_seleccion - 1) + i][(c_seleccion - 1) - i] = (char) ( ((int)'0') + minacercana7);
                    i++;
                    }
                }
            }
        }

        if(r_seleccion != 1)
        {
            i = 0;
            while(minacercana3 == 0 && (r_seleccion - i) > 0)
            {

                minacercana3 = revisar_minas_cercanas((r_seleccion - 1 - i), c_seleccion - 1);
                if(minacercana3 != -1)
                {
                tablero_juego[(r_seleccion - 1) - i][c_seleccion - 1] = (char) ( ((int)'0') + minacercana3 );
                i++;
                }
            }
            if(c_seleccion != Tam_pizarra)
            {
                while(minacercana8 == 0 && (c_seleccion - 1 - i) > 0 && (r_seleccion - 1 - i) > 0)
                {

                    minacercana8 = revisar_minas_cercanas((r_seleccion - 1 - i), (c_seleccion - 1 - i));
                    if(minacercana8 != -1)
                    {
                    tablero_juego[(r_seleccion - 1) - i][(c_seleccion - 1) - i] = (char) ( ((int)'0') + minacercana8);
                    i++;
                    }
                }
            }
        }

        if(c_seleccion != 1)
        {
            i = 0;
            while(minacercana4 == 0 && (c_seleccion - i) > 0)
            {

                minacercana4 = revisar_minas_cercanas(r_seleccion - 1, (c_seleccion - 1 - i));
                if(minacercana4 != -1)
                {
                tablero_juego[r_seleccion - 1][(c_seleccion - 1) - i] = (char) ( ((int)'0') + minacercana4 );
                i++;
                }
            }
        }
    }




    if(mirar_gano() == TRUE)
    {
        system("cls");
        tablerocompleto();
        printf("\n\nGano\n\n");
        jugar_nuevo();
    }

    return 0;
}


void buscar_minas(int r_select, int c_select)
{
    if(tablero[r_select][c_select] == '*')
    {
        printf("\nYou LOSE!!!!!!!\n");
        getchar(); getchar();
        perdida = 1;
    }
}


int revisar_minas_cercanas(int r_select, int c_select)
{
    int cont_mina_cercana = 0;

    if(tablero[r_select][c_select] == '*')
    {
        return -1;
    }

    if(r_select < (Tam_pizarra - 1) && c_select < (Tam_pizarra - 1))
    {

        if(tablero[r_select + 1][c_select] == '*')
            cont_mina_cercana++;

        if(tablero[r_select][c_select + 1] == '*')
            cont_mina_cercana++;

        if(tablero[r_select + 1][c_select + 1] == '*')
            cont_mina_cercana++;


        if(c_select != 0)
        {

            if(tablero[r_select + 1][c_select - 1] == '*')
                cont_mina_cercana++;

            if(tablero[r_select][c_select - 1] == '*')
                cont_mina_cercana++;
        }

        if(r_select != 0)
        {

            if(tablero[r_select - 1][c_select] == '*')
                cont_mina_cercana++;

            if(tablero[r_select - 1][c_select + 1] == '*')
                cont_mina_cercana++;

            if(c_select != 0)
            {

                if(tablero[r_select - 1][c_select - 1] == '*')
                    cont_mina_cercana++;
            }
        }
    }

    if(r_select == (Tam_pizarra - 1) && c_select != (Tam_pizarra - 1))
    {

            if(tablero[r_select - 1][c_select] == '*')
                cont_mina_cercana++;

            if(tablero[r_select - 1][c_select + 1] == '*')
                cont_mina_cercana++;
    }

    if(c_select == (Tam_pizarra - 1) && r_select != (Tam_pizarra - 1))
    {

            if(tablero[r_select][c_select - 1] == '*')
                cont_mina_cercana++;

            if(tablero[r_select + 1][c_select - 1] == '*')
                cont_mina_cercana++;
    }

    if(r_select == (Tam_pizarra - 1) && c_select == (Tam_pizarra - 1))
    {

            if(tablero[r_select][c_select - 1] == '*')
                cont_mina_cercana++;

            if(tablero[r_select - 1][c_select - 1] == '*')
                cont_mina_cercana++;

            if(tablero[r_select - 1][c_select] == '*')
                cont_mina_cercana++;
    }

    return cont_mina_cercana;
}

int mirar_gano()
{
    int fila, col;

    for(fila = 0; fila < Tam_pizarra; fila++)
        for(col = 0; col < Tam_pizarra; col++)
        {
            if(tablero_juego[fila][col] == 'o' && tablero[fila][col] != '*')
                return FALSE;
        }

    return TRUE;
}

void jugar_nuevo()
{
    char resp;

    printf("\n\nDesea jugar de nuevo? (s/n) --> ");
    scanf(" %c", &resp);

    if(toupper(resp) == 'S')
    {
        system("cls");
        inicio();
    }

    else
    {
        printf("\n\nFIN\n)");
        (void) getchar();
        exit(EXIT_SUCCESS);

    }
}
