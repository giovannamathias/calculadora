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

void decimalParaBaseComSinal(int num) {
    short baseComSinal = (short)num; 
    
    // Mostra o sinal
    printf("Número original: %d\n", num);
    if (baseComSinal < 0) {
        printf("Sinal: 1 (Negativo)\n");
    } else {
        printf("Sinal: 0 (Positivo)\n");
    }

   
    unsigned short complementoDois = 0;
    if (baseComSinal < 0) {
       
        complementoDois = (~(-baseComSinal) + 1) & 0xFFFF;
    } else {
        complementoDois = (unsigned short)(baseComSinal & 0xFFFF); 
    }

    printf("Resultado em binário: ");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (complementoDois >> i) & 1);
    }
    printf("\n\n");
}

void exibirMenu() {
    printf("Escolha uma opção:\n");
    printf("1. Converter inteiro\n");
    printf("2. Mostrar float\n");
    printf("3. Mostrar double\n");
    printf("4. Converter para base com sinal (16 bits)\n");
    printf("0. Sair\n");
}

int main() {
    int opcao, num;
    float fnum;
    double dnum;

    do {
        exibirMenu();
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número inteiro: ");
                scanf("%d", &num);
                decimalParaBinario(num);
                decimalParaOctal(num);
                decimalParaHexadecimal(num);
                decimalParaBCD(num);
                break;
            case 2:
                printf("Digite um número real (float): ");
                scanf("%f", &fnum);
                mostrarFloat(fnum);
                break;
            case 3:
                printf("Digite um número real (double): ");
                scanf("%lf", &dnum);
                mostrarDouble(dnum);
                break;
            case 4:
                printf("Digite um número inteiro para conversão em base com sinal (16 bits): ");
                scanf("%d", &num);
                decimalParaBaseComSinal(num);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}