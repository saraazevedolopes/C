#include <stdio.h>

// Foram adaptadas perguntas das 100Q, para a elaboração da nesimo

// Calcula a frequência de um inteiro
int freqC(int x, int s[]) {
    int i, freq = 0;
    for (i = 0; s[i]; i++) {
        if (s[i] == x)
            freq++;
    }
    return freq;
}

// Indica o elemento menos frequente
int intMenosFreq(int s[]) {
    int menosFreq = s[0];
    int i, freqMin = freqC(s[0], s), freq;
    for (i = 0; s[i] != '\0'; i++) {
        if ((freq = freqC(s[i], s)) < freqMin) {
            freqMin = freq;
            menosFreq = s[i];
        }
    }
    return menosFreq;
}

// Remove um elemento
void tail(int s[], int x) {
    int i, j;
    for (i = 0, j = 0; s[i]; i++) {
        if (s[i] != x) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}

void nesimo(int a[], int N, int i) {
    int numeros[N];
    for (int j = 0; j < N; j++) {
        numeros[j] = a[j];
    }
    for (int j = 0; j < i; j++) {
        int elementoMenosFreq = intMenosFreq(numeros);
        tail(numeros, elementoMenosFreq);
        a[j] = elementoMenosFreq;
    }
}

int main() {
    // Testar a função nesimo
    int numeros[] = {1, 2, 3, 3, 4, 4, 4};
    int i = 2;
    nesimo(numeros, 7, i);
    
    printf("Os %d menores elementos do array são: ", i);
    for (int j = 0; j < i; j++) {
        printf("%d ", numeros[j]);
    }
    printf("\n");

    return 0;
}
