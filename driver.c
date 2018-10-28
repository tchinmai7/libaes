#include <stdio.h>
#include <stdlib.h>
#include "aes.h"

void print_word(uint8_t* word, int len) 
{
    for (int i = 0; i < len; i++) {
        printf("%02x", word[i]); 
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    uint8_t key_128_bit[16] = {  0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c }; 
    int Nr;
    int len;
    Nr = getNr(4);
    len = 4 * (Nr + 1) * 4;
    uint8_t word_128[len]; 
    expand_key(key_128_bit, 4, word_128);
    uint8_t input[16] = { 0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34 };
    uint8_t output[16] = {0x00}; 
    printf("128:\t ");
    print_word(word_128, len);
    cipher(input, output, word_128);
/*    
    printf("Encrypted: \t");
    print_word(output, 16);
    uint8_t key_192_bit[24] = {  0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5, 0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b}; 
    Nr = getNr(6);
    len = 4 * (Nr + 1) * 4;
    uint8_t word_192[len]; 
    expand_key(key_192_bit, 6, word_192);
    printf("192: ");
    print_word(word_192, len);
    
    uint8_t key_256_bit[32] = {  0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81, 0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4 };
    Nr = getNr(8);
    len = 4 * (Nr + 1) * 4;
    uint8_t word_256[len]; 
    expand_key(key_256_bit, 8, word_256);
    printf("256: ");
    print_word(word_256,len);
*/
    return 0;
}
