#include <stdio.h>
#include <string.h>
#include <ctype.h>


 void stringToUppercase(char *str) {
   int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = toupper((unsigned char)str[i]);
        }
        i++;
    }
    str[j] = '\0';  // Null-terminate the result
}


int main() {
     char str1[200];
    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // remove newlin

    stringToUppercase(str1);
    printf("Uppercase string: %s\n", str1);
    

    return 0;
}