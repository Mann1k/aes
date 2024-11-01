#include "AES_128_CBC.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void output(const char *title, uint8_t *data, uint32_t size) {
  printf("%s", title);
  for (uint8_t index = 0; index < size; index++) {
    printf("%02x ", data[index]);
  }
  printf("\n");
}

int main() {
  // Example Key (128 bits / 16 bytes)
  uint8_t key[16] = {0x96, 0xe9, 0x3b, 0x42, 0x72, 0x15, 0x96, 0x1b,
                     0x8b, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  // Example IV (128 bits / 16 bytes)
  uint8_t iv[16] = {0x3d, 0xd7, 0x13, 0xcb, 0x7a, 0x1e, 0xab, 0x89,
                    0xdd, 0x2b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  // Example Data (16 bytes)
//   uint8_t data[16] = {0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20,
//                       0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20};

  uint8_t data[16] = {0x54, 0x68, 0x69, 0x73, 0x51, 0x00, 0x01, 0x01,
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


  output("original: ", data, 16);

  AES_CTX ctx;
  AES_EncryptInit(&ctx, key, iv);
  AES_Encrypt(&ctx, data, data);

  output("\nencrypted: ", data, 16);

  // Decryption Example
  AES_DecryptInit(&ctx, key, iv);
  AES_Decrypt(&ctx, data, data);

  output("\ndecrypted: ", data, 16);

  return 0;
}
