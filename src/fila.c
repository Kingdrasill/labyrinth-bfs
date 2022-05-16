#include "fila.h"

void FFVazia(Fila *f){
	f->P = (Bloco*) malloc (sizeof(Bloco));
	f->U  = f->P;
	f->P->prox = NULL;
}

void Enfileira(Fila *f, Item d){
	f->U->prox = (Bloco*) malloc (sizeof(Bloco));
	f->U = f->U->prox;
	f->U->data = d;
	f->U->prox = NULL;
}

void Desenfileira(Fila *f, Item *d){
	Bloco *aux;

	if(f->P == f->U || f == NULL || f->P->prox == NULL){
		printf("FILA VAZIA!\n");
		d->x = -1;
		d->y = -1;
		return;
	}
	
	aux = f->P->prox;
	f->P->prox = aux->prox;
	d->x = aux->data.x;
	d->y = aux->data.y;
	free(aux);
}


void Imprime(Fila *f){
	Bloco *aux;

	aux = f->P->prox;
	while(aux != NULL){
		printf("(%d,%d)\n", aux->data.x, aux->data.y);
		aux = aux->prox;
	}

}