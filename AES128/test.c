#include <stdio.h>
#include <stdint.h>

void aes_encrypt(const uint8_t plaintext[16],
                 const uint8_t key[16],
                 uint8_t ciphertext[16],
                 int show_trace);

int main(void) {
    const uint8_t plaintext[16] = {
        0x00,0x11,0x22,0x33,
        0x44,0x55,0x66,0x77,
        0x88,0x99,0xAA,0xBB,
        0xCC,0xDD,0xEE,0xFF
    };

    const uint8_t key[16] = {
        0x00,0x01,0x02,0x03,
        0x04,0x05,0x06,0x07,
        0x08,0x09,0x0A,0x0B,
        0x0C,0x0D,0x0E,0x0F
    };

    const uint8_t expected[16] = {
        0x69,0xC4,0xE0,0xD8,
        0x6A,0x7B,0x04,0x30,
        0xD8,0xCD,0xB7,0x80,
        0x70,0xB4,0xC5,0x5A
    };

    uint8_t ciphertext[16];

    printf("========== AES-128 TEST ==========\n");

    aes_encrypt(plaintext, key, ciphertext, 1);

    int pass = 1;

    printf("\n========== KET QUA KIEM THU ==========\n");

    printf("Ciphertext mong doi: ");
    for (int i = 0; i < 16; i++)
        printf("%02X", expected[i]);

    printf("\nCiphertext thuc te : ");
    for (int i = 0; i < 16; i++)
        printf("%02X", ciphertext[i]);

    for (int i = 0; i < 16; i++) {
        if (ciphertext[i] != expected[i]) {
            pass = 0;
            break;
        }
    }

    if (pass)
        printf("\nTEST AES-128: PASS\n");
    else
        printf("\nTEST AES-128: FAIL\n");

    return pass ? 0 : 1;
}