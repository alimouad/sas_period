#include <stdio.h>
#include <stdlib.h>

int main()
{ 

    int numberArray;

    printf("enter the Array Element : ");
    scanf("%d", &numberArray);
    int array[numberArray];  

        for (int i = 0; i < numberArray; i++) {
            printf("Enter value for element %d: ", i + 1);
            scanf("%d", &array[i]);
        }

        // Affiche les éléments du tableau
        printf("Array elements are:\n");
        for (int i = 0; i < numberArray; i++) {
            printf("%d ", array[i]);
        }

    return 0;
}