#include <stdio.h>

int main() {
    char ch, encrypted, decrypted;
    int key;

    printf("Enter a character to encrypt: \n");
    scanf("%c", &ch);

    printf("Enter an encryption key (integer): \n");
    scanf("%d", &key);

    encrypted = ch ^ key;
    printf("Encrypted character: %c\n", encrypted);

    decrypted = encrypted ^ key;
    printf("Decrypted character: %c\n", decrypted);

    return 0;
}
