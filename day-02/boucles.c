#include <stdio.h>
#include <stdlib.h>

int main()
{ 
    // exercice 3******
    // int number,i;
    // int result = 0;
    // printf("entre a number: ");
    // scanf("%d", &number);

    // for (i=1; i<=number; i++){

    //     result += i;
    // };
    // printf("the result is %d", result);


    // EXERCCIE 4:*******8

    // int number,i; 
    // int current_odd = 1;
    // // int result = 0;
    // printf("entre a number: ");
    // scanf("%d", &number);
  

       
    // for (i = 0; i < number; i++) {


//   // exercice 5
//     int number,i; 
//     // int current_odd = 1;
//     int exposant ;
//     int result = 1;  
//     printf("entre a the base number: ");
//     scanf("%d", &number);

//     printf("enter the exposant ");
//     scanf("%d" , &exposant);


//     for (i = 0; i < exposant; i++) {
//             result *= number;  
//         }

//         printf("The result is: %d\n", result);
    
     // exercice 6
    

    //  exercice 5
    // int number; 
    // // int current_odd = 1;
    // // int exposant ;
    // int reverse = 0;
    // // int result = 1;  
    // printf("entre a the base number: ");
    // scanf("%d", &number);
    
    // while (number != 0) {
    //     reverse= reverse* 10;
    //     reverse = reverse+ number % 10;
    //     number = number / 10;
    // }

    // printf("Reversed number = %d", reverse);
     
    int number, i;
    int result=0;

    printf("enter a number: ");
    scanf("%d", &number);

    for (i = 1; i <= number; i++){
        result += i;
          
    }
    printf("the result is %d", result);
    return 0;
}
