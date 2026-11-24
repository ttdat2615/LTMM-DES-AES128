

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Bang hoan vi ban dau IP cua DES
const int IP[64] = {
    58, 50, 42, 34, 26, 18, 10,  2,
    60, 52, 44, 36, 28, 20, 12,  4,
    62, 54, 46, 38, 30, 22, 14,  6,
    64, 56, 48, 40, 32, 24, 16,  8,
    57, 49, 41, 33, 25, 17,  9,  1,
    59, 51, 43, 35, 27, 19, 11,  3,
    61, 53, 45, 37, 29, 21, 13,  5,
    63, 55, 47, 39, 31, 23, 15,  7
};

// Ham hoan vi bit theo bang cho truoc
uint64_t permute(uint64_t input, const int *table,
                 int output_bits, int input_bits) {
    uint64_t result = 0;

    for (int i = 0; i < output_bits; i++) {
        int shift = input_bits - table[i];
        uint64_t bit = (input >> shift) & 1ULL;

        result = (result << 1) | bit;
    }

    return result;
}

int main(void) {
    uint64_t plaintext = 0x0123456789ABCDEFULL;
    uint64_t key = 0x133457799BBCDFF1ULL;

    printf("=== DES ENCRYPTION ===\n");
    printf("Plaintext: %016" PRIX64 "\n", plaintext);
    printf("Key      : %016" PRIX64 "\n", key);

    // Buoc 1: Initial Permutation
    uint64_t ip_result = permute(plaintext, IP, 64, 64);

    printf("After IP : %016" PRIX64 "\n", ip_result);

    // Buoc 2: Chia thanh hai nua 32 bit
    uint32_t L0 = (uint32_t)(ip_result >> 32);
    uint32_t R0 = (uint32_t)(ip_result & 0xFFFFFFFFULL);

    printf("L0       : %08" PRIX32 "\n", L0);
    printf("R0       : %08" PRIX32 "\n", R0);

    return 0;
}
