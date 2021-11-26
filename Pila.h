#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define SI 1
#define NO 0

struct Dama {
	int i, j;
};

struct Pila {
	struct Dama Damas[64];
	int Tope;
};

void SetUp(struct Pila *P);
void Push(struct Pila *P, int i, int j);
int Pop(struct Pila *P);
int PilaVacia(struct Pila *P);

#endif // PILA_H_INCLUDED
