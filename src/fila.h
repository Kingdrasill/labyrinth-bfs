#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Item Item;
typedef struct Bloco Bloco;
typedef struct Fila Fila;

struct Item{
	int x;
	int y;
};

struct Bloco{
	Item data;
	Bloco *prox;
};

struct Fila{
	Bloco *P;
	Bloco *U;
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);
void Imprime(Fila *f);