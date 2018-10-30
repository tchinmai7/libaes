#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"
#include "decrypt.h"
#include "aes.h"
#include "inv_aes.h"

int main(int argc, char* argv[])
{
    if (argv[1] == NULL) {
	printf("Error, enter a value to encrypt!\n");
    	return -1;
    }
    size_t input_size = strlen(argv[1]);
    if ((input_size % 16) != 0) {
    	printf("Error, input should be a multiple of 16\n");
	return -1;
    }

    uint8_t key_128_bit[16] = {  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
    printf("The key used is\n");
    print_word(key_128_bit, 16); 
    aes_params_t* params = init_aes_params();
    set_aes_key(params, AES_128_BIT, key_128_bit); 
    uint8_t* input = NULL;
    printf("Input size is %ld\n", input_size);
    input = malloc(input_size);
    memcpy(input, argv[1], input_size);
    
    printf("128 Bit AES - \n");
    printf("Bytes Plain: \t");
    print_word(input, input_size);
    printf("STR: Input: %s\n", input);
    
    uint8_t output[input_size + 16]; 
    size_t enc_len = encrypt(params, input, output, input_size);
    printf("Encrypted bytes: \t");
    print_word(output, enc_len);

    uint8_t plain[input_size+1];
    size_t dec_len = decrypt(params, output, plain, enc_len);
    // Null terminate the string
    plain[input_size] = '\0';
    printf("Decrypted bytes: \t");
    print_word(plain, dec_len);
    printf("decrypted_string %s\n", plain);
/*
    uint8_t key_192_bit[24] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17 };
    set_aes_key(params, AES_192_BIT, key_192_bit);
    printf("192 Bit AES - \n");
    printf("Plain: \t");
    print_word(input, 16);
    encrypt(params, input, output, strlen(argv[1]));
    printf("Encrypted: \t");
    print_word(output, 16);

    decrypt(params, output, plain);
    printf("Decrypted: \t");
    print_word(plain, 16);
    printf("%s\n", plain);
    
    uint8_t key_256_bit[32] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f };
    set_aes_key(params, AES_256_BIT, key_256_bit);
    printf("256 Bit AES - \n");
    printf("Plain: \t");
    print_word(input, 16);
    
    encrypt(params, input, output, strlen(argv[1]));
    printf("Encrypted: \t");
    print_word(output, 16);

    decrypt(params, output, plain);
    printf("Decrypted: \t");
    print_word(plain, 16);
    printf("%s\n", plain);
  */
    return 0;
}
