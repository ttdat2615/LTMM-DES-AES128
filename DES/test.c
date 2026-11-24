#include <stdio.h>
#include <stdint.h>

uint64_t des_encrypt(uint64_t plaintext, uint64_t key, int show_trace);
uint64_t des_decrypt(uint64_t ciphertext, uint64_t key);

int main(void) {
    const uint64_t plaintext = 0x0123456789ABCDEFULL;
    const uint64_t key       = 0x133457799BBCDFF1ULL;
    const uint64_t expected  = 0x85E813540F0AB405ULL;

    printf("========== DES TEST VECTOR ==========\n\n");

    uint64_t ciphertext = des_encrypt(plaintext, key, 1);

    printf("\n========== KIEM THU ==========\n");
    printf("Ban ro mong doi : %016llX\n",
           (unsigned long long)plaintext);
    printf("Khoa            : %016llX\n",
           (unsigned long long)key);
    printf("Ban ma mong doi : %016llX\n",
           (unsigned long long)expected);
    printf("Ban ma thuc te  : %016llX\n",
           (unsigned long long)ciphertext);

    if (ciphertext == expected)
        printf("TEST MA HOA: PASS\n");
    else
        printf("TEST MA HOA: FAIL\n");

    uint64_t recovered = des_decrypt(ciphertext, key);

    printf("Ban ro giai ma  : %016llX\n",
           (unsigned long long)recovered);

    if (recovered == plaintext)
        printf("TEST GIAI MA: PASS\n");
    else
        printf("TEST GIAI MA: FAIL\n");

    return (ciphertext == expected && recovered == plaintext) ? 0 : 1;
}