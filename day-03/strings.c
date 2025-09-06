#include <stdio.h>
#include <string.h>
#include <ctype.h>


void removeSpaces(char *str) {
    int count = 0; 

   int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0'; 
}

int main() {
    char myString[] = "  This is a string with spaces  ";
    printf("Original string: \"%s\"\n", myString);

    removeSpaces(myString);
    printf("String after removing spaces: \"%s\"\n", myString);

    return 0;
}