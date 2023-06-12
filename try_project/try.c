#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Base64 character mapping table
static const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Function to encode a 6-bit number to base64
char base64_encode_bits(uint8_t bits) {
    return base64_chars[bits];
}

int main() {
    unsigned int number = 0b101010101010; // Example unsigned integer

    // Extract the two 6-bit groups
    uint8_t group1 = (number >> 6) & 0x3F;
    uint8_t group2 = number & 0x3F;

    // Encode each group using base64
    char encoded_char1 = base64_encode_bits(group1);
    char encoded_char2 = base64_encode_bits(group2);

    // Print the base64 encoded characters
    printf("Base64 Encoded Characters: %c%c\n", encoded_char1, encoded_char2);

    return 0;
}
