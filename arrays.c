#include <stdio.h>
#include <stdlib.h>

int main()
{ 

    int numberArray;
    // int result = 0;
    int lowestNumber;

    printf("enter the Array Element : ");
    scanf("%d", &numberArray);
    int array[numberArray];  

        for (int i = 0; i < numberArray; i++) {
            printf("Enter value for element %d: ", i + 1);
            
            scanf("%d", &array[i]);
        }
        for (int i = 0; i < numberArray; i++) {
            lowestNumber = array[0];
            if (lowestNumber > array[i]){
                lowestNumber = array[i];
            }

        }
        printf("the result is %d",lowestNumber);


        
    return 0;
}