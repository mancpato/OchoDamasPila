/**
	OchoDamas

	Versión sencilla que localiza las 92 soluciones
	No detecta simetrías.

	manc
*/

#include <stdio.h>
#include "Pila.h"

#define DEBUG 0

int N = 8;
int Soluciones = 0;
char T[8][8];

//int OpPila = 0;

struct Pila PDamas;

void PonerDamas();
void QuitarDama(int c);
int SePuede(int i, int j);
void MostrarTablero();

int main()
{
    puts("Problema de las 8 damas");
    puts("Iniciando la búsqueda de soluciones");

    SetUp(&PDamas);

    for ( int i=0 ; i<N ; i++ )
        for ( int j=0 ; j<N ; j++ )
            T[i][j] = '-';
    MostrarTablero();
    PonerDamas();

    return 0;
}

void PonerDamas()
{
    int c, r;

    for ( r=0 ; r<N ; r++ )
        Push(&PDamas, r, 0);

    while ( !PilaVacia(&PDamas) ) {
        int  n = Pop(&PDamas);
        r = n/N;
        c = n%N;
        QuitarDama(c);
        if ( SePuede(r, c) )
            T[r][c++] = 'D';
        else
            continue;

        if ( c == N) {
            Soluciones++;
            printf("\nSolución %d\n", Soluciones);
            MostrarTablero();
            T[r][--c] = '-';
            continue;
        }
        for ( int i=0 ; i<N ; i++ )
            if ( SePuede(i, c) )
                Push(&PDamas, i, c);
    }
}

void QuitarDama(int c)
{
    for ( ; c<N ; c++ )
        for ( int i=0 ; i<N ; i++ )
            if ( T[i][c] == 'D' ) {
                T[i][c] = '-';
                break;
            }
}

int SePuede(int r, int c)
{
    int i, j;

    for ( i=0; i<N ; i++ )
        if ( T[i][c] == 'D' )
            return NO;

    for ( i=0; i<N ; i++ )
        if ( T[r][i] == 'D' )
            return NO;

    int m = r<c ? r : c;
    for ( i=r-m, j=c-m ; i<N && j<N ; i++,j++ )
        if ( T[i][j] == 'D' )
            return NO;

    for ( i=r+1, j=c-1; i<N && j>=0 ; i++, j--)
        if ( T[i][j] == 'D' )
            return NO;
    for ( i=r-1, j=c+1; i>=0 && j<N ; i--, j++)
        if ( T[i][j] == 'D' )
            return NO;

    return SI;
}

void MostrarTablero()
{
    for (int i =0; i<N; i++) {
        for(int  j = 0; j<N; j++)
            printf("%c ", T[i][j]);
        printf("\n");
    }
    printf("\n");
}

/* Fin de archivo */
