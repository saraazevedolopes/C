#include <stdio.h>

// Conta o peso total dos produtos
int conta_peso(int p[], int N) {
    int total = 0;
    for(int i = 0; i < N; i++) {
        total += p[i];
    }
    return total;
}

int sacos(int p[], int N, int C) {
    int num_sacos = 0;
    int total = conta_peso(p, N);
    if(total % C == 0) num_sacos = total/C;
    else num_sacos = total/C + 1;
    return num_sacos;
}

int main() {
    int pesos[] = {10, 26, 30}; // Exemplo de pesos
    int N = 3;  // Número de elementos no array
    int capacidade = 10;  // Capacidade dos sacos

    int num_sacos = sacos(pesos, N, capacidade);
    printf("Número de sacos necessários: %d\n", num_sacos);

    return 0;
}