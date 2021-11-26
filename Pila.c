/**
	Pila.c
*/

#include "Pila.h"

void SetUp(struct Pila *P)
{
	P->Tope = 0;
}

void Push(struct Pila *P, int i, int j)
{
	P->Damas[P->Tope].i = i;
	P->Damas[P->Tope].j = j;
	P->Tope++;
}

/** Las dos coordenadas se codifican como un número
	Si Celda = i*8 + j, entonces
		i = Celda/8
		j = Celda%8
*/
int Pop(struct Pila *P)
{
	P->Tope--;
	return P->Damas[P->Tope].i*8 + P->Damas[P->Tope].j;
}

int PilaVacia(struct Pila *P)
{
	return P->Tope == 0 ? SI : NO;
}

/* Fin de archivo */
