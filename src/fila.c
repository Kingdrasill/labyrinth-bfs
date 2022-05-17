#include "fila.h"

void FFVazia(Fila *f){
	f->P = NULL;
	f->U = NULL;
}

void Enfileira(Fila *f, Item d){
	Bloco *novo = (Bloco*)malloc(sizeof(Bloco));
    novo->data = d;
    novo->prox = NULL;
    if (f->P == NULL) {
		f->P = novo;
	}
    else {
		f->U->prox = novo;
	}
	f->U = novo;
}

void Desenfileira(Fila *f, Item *d){
	Bloco *aux;

	if(f->P == NULL){
		printf("FILA VAZIA!\n");
		d->x = -1;
		d->y = -1;
		return;
	}
	
	*d = f->P->data;
	aux = f->P;
	f->P = f->P->prox;
	free(aux);
	if(f->P == NULL)
		f->U = NULL;
}


void Imprime(Fila *f){
	Bloco *aux;

	aux = f->P;
	while(aux != NULL){
		printf("(%d,%d)\n", aux->data.x, aux->data.y);
		aux = aux->prox;
	}

}