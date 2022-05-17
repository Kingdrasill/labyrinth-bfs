#include "labirinto.h"

void Inicializar(Labirinto *lab, int l, int c) {
    lab->coluna = c;
    lab->linha = l;
    lab->map = malloc(l * sizeof(Cell*));

    for(int i=0; i<l; i++) {
        lab->map[i] = malloc(c *sizeof(Cell));
    }
}

void Finalizar(Labirinto *lab) {
    for(int i=0; i<lab->linha; i++) {
        free(lab->map[i]);
    }
    free(lab->map);
}

void ImprimirLab(Labirinto *lab) {
    for(int i=0; i<lab->linha; i++) {
        for(int j=0; j<lab->coluna; j++) {
            printf("%c ", lab->map[i][j].value);
        }
        printf("\n");
    }
}

int BFS(Labirinto *lab, Fila *f) {
    bool cont=true;
    int count = 1, x=0, y=0;
    Item aux, tmp;

    while (cont)
    {
        Desenfileira(f, &aux);
        x = aux.x;
        y = aux.y;
        if((x+1) < lab->linha && lab->map[x+1][y].value != '#' && !lab->map[x+1][y].added && cont) {
            tmp.x = x+1;
            tmp.y = y;;
            lab->map[tmp.x][tmp.y].added = true;
            Enfileira(f, tmp);
            count++;
            if(checkLast(lab, f))
                cont = false;
        }
        if((y+1) < lab->coluna && lab->map[x][y+1].value != '#' && !lab->map[x][y+1].added && cont) {
            tmp.x = x;
            tmp.y = y+1;
            lab->map[tmp.x][tmp.y].added = true;
            Enfileira(f, tmp);
            count++;
            if(checkLast(lab, f))
                cont = false;
        }
        if((y-1) >= 0 && lab->map[x][y-1].value != '#' && !lab->map[x][y-1].added && cont) {
            tmp.x = x;
            tmp.y = y-1;
            lab->map[tmp.x][tmp.y].added = true;
            Enfileira(f, tmp);
            count++;
            if(checkLast(lab, f))
                cont = false;
        }
        if((x-1) >= 0 && lab->map[x-1][y].value != '#' && !lab->map[x-1][y].added && cont) {
            tmp.x = x-1;
            tmp.y = y;
            lab->map[tmp.x][tmp.y].added = true;
            Enfileira(f, tmp);
            count++;
            if(checkLast(lab, f))
                cont = false;
        }
    }

    return count;
}

bool checkLast(Labirinto *lab, Fila *f) {
    if(f->U->data.x == (lab->linha-1) && f->U->data.y == (lab->coluna-1))
        return true;
    return false;
}

bool LerArquivo(Labirinto *lab) {
    FILE *fp;
    char arquivo[ARQ_MAXTAM];
    char cell;
    int i=0, j=0;

    scanf("%c", (char *) stdin);
    printf("Nome do arquivo onde esta o  labirinto(com extensao): ");
	fgets(arquivo, ARQ_MAXTAM, stdin);
	strtok(arquivo, "\n");

    fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!\n");
        exit(1);
    } else {
        while((cell = (char)fgetc(fp)) != EOF) {
            if(cell == '\n') {
                i++;
                j = 0;
            }
            else {
                lab->map[i][j].value = cell;
                lab->map[i][j].added = false;
                j++;
            }
        }
    }
    fclose(fp);

    return true;
}