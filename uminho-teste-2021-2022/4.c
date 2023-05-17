#include <stdio.h>
#include <stdlib.h>

void inc(char s[]) {
    int num = atoi(s); // Converte uma string para int, pertence a #include <stdlib.h>
    num++;
    sprintf(s, "%d", num); // Converte int para string, pertence a #include <stdio.h>
}
// As funções auxiliares podem ser usadas no teste se for referida a sua biblioteca

int main() {
    char str[10] = "123";
    printf("Antes: %s\n", str);
    inc(str);
    printf("Depois: %s\n", str);
    return 0;
}
