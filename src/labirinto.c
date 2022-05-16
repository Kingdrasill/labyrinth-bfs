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

int BFS(Labirinto *lab, Fila *f);

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
                lab->map[i][j].left = false;
                lab->map[i][j].right = false;
                lab->map[i][j].bottom = false;
                j++;
            }
        }
    }
    fclose(fp);

    return true;
}