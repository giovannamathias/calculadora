#include <stdio.h>
#include <math.h>

void decimalParaBinario(int num) {
    int binario[32];
    int i = 0;

    printf("Conversão de %d para Binário:\n", num);
    while (num > 0) {
        binario[i] = num % 2;
        printf("Passo %d: %d %% 2 = %d\n", i + 1, num, binario[i]);
        num = num / 2;
        i++;
    }

    printf("Resultado: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n\n");
}

void decimalParaOctal(int num) {
    int octal[32];
    int i = 0;

    printf("Conversão de %d para Octal:\n", num);
    while (num > 0) {
        octal[i] = num % 8;
        printf("Passo %d: %d %% 8 = %d\n", i + 1, num, octal[i]);
        num = num / 8;
        i++;
    }

    printf("Resultado: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n\n");
}

void decimalParaHexadecimal(int num) {
    char hex[32];
    int i = 0;

    printf("Conversão de %d para Hexadecimal:\n", num);
    while (num > 0) {
        int temp = num % 16;
        hex[i] = (temp < 10) ? (temp + '0') : (temp - 10 + 'A');
        printf("Passo %d: %d %% 16 = %d\n", i + 1, num, temp);
        num = num / 16;
        i++;
    }

    printf("Resultado: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n\n");
}

void decimalParaBCD(int num) {
    printf("Conversão de %d para BCD:\n", num);
    while (num > 0) {
        int digit = num % 10;
        printf("Digit: %d -> ", digit);
        for (int j = 3; j >= 0; j--) {
            printf("%d", (digit >> j) & 1);
        }
        printf(" (BCD)\n");
        num = num / 10;
    }
    printf("\n");
}

void mostrarFloat(float num) {
    unsigned int *p = (unsigned int*)&num;
    printf("Float: %f\n", num);
    printf("Sinal: %u\n", (*p >> 31) & 1);
    printf("Expoente: %u\n", (*p >> 23) & 0xFF);
    printf("Fração: %u\n", *p & 0x7FFFFF);
}

void mostrarDouble(double num) {
    unsigned long long *p = (unsigned long long*)&num;
    printf("Double: %lf\n", num);
    printf("Sinal: %u\n", (*p >> 63) & 1);
    printf("Expoente: %u\n", (*p >> 52) & 0x7FF);
    printf("Fração: %llu\n", *p & 0xFFFFFFFFFFFFF);
}

int main() {
    int num;
    float fnum;
    double dnum;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    decimalParaBinario(num);
    decimalParaOctal(num);
    decimalParaHexadecimal(num);
    decimalParaBCD(num);

    printf("Digite um número real (float): ");
    scanf("%f", &fnum);
    mostrarFloat(fnum);

    printf("Digite um número real (double): ");
    scanf("%lf", &dnum);
    mostrarDouble(dnum);

    return 0;
}