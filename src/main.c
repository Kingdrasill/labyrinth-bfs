#include "labirinto.h"

int main() {
    Labirinto L;
    Fila F;
    Item I;
    int iteracoes=0, l=0, c=0;

    I.x = 0;
    I.y = 0;
    FFVazia(&F);

    printf("Quantidade de linhas do labirinto: ");
    scanf("%d", &l);
    printf("Quantidade de colunas do labirinto: ");
    scanf("%d", &c);
    
    Inicializar(&L, l, c);

    LerArquivo(&L);
    Enfileira(&F, I);
    L.map[I.x][I.y].added = true;

    printf("\n");
    ImprimirLab(&L);

    iteracoes = BFS(&L, &F);

    printf("\nNumero de iteracoes: %d\n", iteracoes);

    Finalizar(&L);

    return 0;
}