#include <stdio.h>
#include <stdint.h>

// Funções para as conversões

void decimalToBinary(int n) {
    printf("Base 2: ");
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

void decimalToOctal(int n) {
    printf("Base 8: %o\n", n);
}

void decimalToHexadecimal(int n) {
    printf("Base 16: %X\n", n);
}

void decimalToBCD(int n) {
    printf("Código BCD: ");
    for (int i = 28; i >= 0; i -= 4) {
        int digit = (n >> i) & 0xF;
        printf("%d ", digit);
    }
    printf("\n");
}

void decimalToTwosComplement(int n) {
    printf("Complemento a 2 com 16 bits: ");
    if (n < 0) {
        n = (1 << 16) + n;
    }
    for (int i = 15; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

void printBinary(uint64_t num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        uint64_t mask = (uint64_t)1 << i;
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

void floatToBinary(float f) {
    union {
        float input;
        uint32_t output;
    } data;

    data.input = f;

    uint32_t sign = (data.output >> 31) & 1;
    uint32_t exponent = (data.output >> 23) & 0xFF;
    uint32_t mantissa = data.output & 0x7FFFFF;

    printf("Float - Sinal: %u, Expoente: %u, Mantissa: %u\n", sign, exponent, mantissa);
    printf("Float - Binário: ");
    printBinary(data.output, 32);
}

void doubleToBinary(double d) {
    union {
        double input;
        uint64_t output;
    } data;

    data.input = d;

    uint64_t sign = (data.output >> 63) & 1;
    uint64_t exponent = (data.output >> 52) & 0x7FF;
    uint64_t mantissa = data.output & 0xFFFFFFFFFFFFF;

    printf("Double - Sinal: %lu, Expoente: %lu, Mantissa: %lu\n", sign, exponent, mantissa);
    printf("Double - Binário: ");
    printBinary(data.output, 64);
}

// Função principal com menu

int main() {
    int choice, num;
    float f;
    double d;

    do {
        printf("\nCalculadora Programador Didática\n");
        printf("1. Base 10 para Base 2\n");
        printf("2. Base 10 para Base 8\n");
        printf("3. Base 10 para Base 16\n");
        printf("4. Base 10 para Código BCD\n");
        printf("5. Base 10 para Complemento a 2 (16 bits)\n");
        printf("6. Converter Real para Float\n");
        printf("7. Converter Real para Double\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite um número em base 10: ");
                scanf("%d", &num);
                decimalToBinary(num);
                break;
            case 2:
                printf("Digite um número em base 10: ");
                scanf("%d", &num);
                decimalToOctal(num);
                break;
            case 3:
                printf("Digite um número em base 10: ");
                scanf("%d", &num);
                decimalToHexadecimal(num);
                break;
            case 4:
                printf("Digite um número em base 10: ");
                scanf("%d", &num);
                decimalToBCD(num);
                break;
            case 5:
                printf("Digite um número em base 10: ");
                scanf("%d", &num);
                decimalToTwosComplement(num);
                break;
            case 6:
                printf("Digite um número real (float): ");
                scanf("%f", &f);
                floatToBinary(f);
                break;
            case 7:
                printf("Digite um número real (double): ");
                scanf("%lf", &d);
                doubleToBinary(d);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (choice != 8);

    return 0;
}