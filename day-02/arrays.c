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

    int inxArray;
    printf("the array index you wanna change: ");
    scanf("%d",&inxArray);


    int value;
    printf("enter the new value change :");
    scanf("%d",&value);

    printf("the old array \n");

    for(int i = 0; i < numberArray ; i++){
        printf("%d", array[i]);
        printf("\n");
    }
      // Update the value at the given index
    array[inxArray] = value;

    // Print the updated array
    printf("The updated array:\n");
    for (int i = 0; i < numberArray; i++) {
        printf("%d\n", array[i]);
    }



    
     

            
           


    return 0;
}