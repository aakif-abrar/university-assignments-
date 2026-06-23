// 1. Program to check if each word in a 2D array of strings is a palindrome
#include <stdio.h>
#include <string.h>

int isPalindrome(char word[]) {
    int len = strlen(word);
    for(int i = 0; i < len / 2; i++) {
        if(word[i] != word[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char words[5][20];
    for(int i = 0; i < 5; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }
    for(int i = 0; i < 5; i++) {
        if(isPalindrome(words[i])) {
            printf("%s: Palindrome\n", words[i]);
        } else {
            printf("%s: Not Palindrome\n", words[i]);
        }
    }
    return 0;
}

