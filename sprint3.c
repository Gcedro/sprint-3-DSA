#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    float energia;
    float tempo;
    float custo;
} Sessao;

void cadastrar(Sessao s[], int *q) {
    if (*q >= MAX) {
        printf("Limite atingido!\n");
        return;
    }

    printf("\nID: ");
    scanf("%d", &s[*q].id);

    printf("Energia (kWh): ");
    scanf("%f", &s[*q].energia);

    printf("Tempo (min): ");
    scanf("%f", &s[*q].tempo);

    printf("Custo (R$): ");
    scanf("%f", &s[*q].custo);

    (*q)++;
    printf("Sessao cadastrada!\n");
}

void listar(Sessao s[], int q) {
    if (q == 0) {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    for (int i = 0; i < q; i++) {
        printf("\nID: %d | Energia: %.2f kWh | Tempo: %.2f min | Custo: R$ %.2f\n",
               s[i].id, s[i].energia, s[i].tempo, s[i].custo);
    }
}

void buscar(Sessao s[], int q) {
    int id, achou = 0;

    printf("\nDigite o ID: ");
    scanf("%d", &id);

    for (int i = 0; i < q; i++) {
        if (s[i].id == id) {
            printf("ID: %d | Energia: %.2f kWh | Tempo: %.2f min | Custo: R$ %.2f\n",
                   s[i].id, s[i].energia, s[i].tempo, s[i].custo);
            achou = 1;
            break;
        }
    }

    if (!achou)
        printf("Sessao nao encontrada.\n");
}

void ordenar(Sessao s[], int q) {
    int op;
    Sessao temp;

    printf("\n1 - ID\n2 - Energia\n3 - Custo\n4 - Tempo\n");
    printf("Ordenar por: ");
    scanf("%d", &op);

    for (int i = 0; i < q - 1; i++) {
        for (int j = 0; j < q - 1 - i; j++) {

            int troca = 0;

            if (op == 1 && s[j].id > s[j + 1].id)
                troca = 1;
            else if (op == 2 && s[j].energia > s[j + 1].energia)
                troca = 1;
            else if (op == 3 && s[j].custo > s[j + 1].custo)
                troca = 1;
            else if (op == 4 && s[j].tempo > s[j + 1].tempo)
                troca = 1;

            if (troca) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("Sessoes ordenadas!\n");
}

void estatisticas(Sessao s[], int q) {
    if (q == 0) {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    float energia = 0, faturamento = 0;
    float maior = s[0].energia;
    float menor = s[0].energia;

    for (int i = 0; i < q; i++) {
        energia += s[i].energia;
        faturamento += s[i].custo;

        if (s[i].energia > maior)
            maior = s[i].energia;

        if (s[i].energia < menor)
            menor = s[i].energia;
    }

    printf("\n===== ESTATISTICAS =====\n");
    printf("Sessoes: %d\n", q);
    printf("Energia total: %.2f kWh\n", energia);
    printf("Faturamento: R$ %.2f\n", faturamento);
    printf("Ticket medio: R$ %.2f\n", faturamento / q);
    printf("Maior consumo: %.2f kWh\n", maior);
    printf("Menor consumo: %.2f kWh\n", menor);
}

int main() {
    Sessao sessoes[MAX];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n===== ESTACAO DE RECARGA =====\n");
        printf("1 - Nova sessao\n");
        printf("2 - Listar sessoes\n");
        printf("3 - Buscar sessao\n");
        printf("4 - Ordenar sessoes\n");
        printf("5 - Estatisticas\n");
        printf("6 - Encerrar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrar(sessoes, &quantidade); break;
            case 2: listar(sessoes, quantidade); break;
            case 3: buscar(sessoes, quantidade); break;
            case 4: ordenar(sessoes, quantidade); break;
            case 5: estatisticas(sessoes, quantidade); break;
            case 6: printf("Programa encerrado!\n"); break;
            default: printf("Opcao invalida!\n");
        }

    } while (opcao != 6);

    return 0;
}