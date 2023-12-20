#include <stdio.h>

long long power(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exponent > 0) {
        // 如果指数是奇数，乘上当前的base
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        // 将指数减半，底数取平方
        base = (base * base) % mod;
        exponent = exponent / 2;
    }

    return result;
}

int main() {
    long long base, exponent, mod;
    
    printf("Enter base: ");
    scanf("%lld", &base);
    
    printf("Enter exponent: ");
    scanf("%lld", &exponent);

    printf("Enter mod value: ");
    scanf("%lld", &mod);

    long long result = power(base, exponent, mod);

    printf("Result: %lld\n", result);

    return 0;
}
