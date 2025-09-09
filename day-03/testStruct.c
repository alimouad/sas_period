// #include <stdio.h>

// struct student{
//     char name[20];
//     char lastName[20];
// };
   


// struct student std[100];

// void addStudent(){
//     int studentNumber;
//     printf("*****add A Student***");
    
//     printf("enter how many student u wanna add: \n");
//     scanf("%d", &studentNumber);

//     for(int i =0; i < studentNumber ; i++){
//         printf("Enter the new contact number: ");
//         scanf("%s", std[i].name);

//         printf("Enter the new contact email address: ");
//         scanf("%s", std[i].lastName);
//     }
// }



// void elementByIdx(int idx){
//     printf("%s %s", std[idx].name,  std[idx].lastName);
// }

// int main(){
//     addStudent();
//     elementByIdx(0);
//     return 0;
// }



// #include <stdio.h>
// void selectionSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         int minIndex = i;                  // Assume the minimum is the first unsorted element
//         for (int j = i + 1; j < n; j++) { // Look through the rest of the unsorted elements
//             if (arr[j] < arr[minIndex]) { // If a smaller element is found
//                 minIndex = j;             // Update minIndex to this new minimum element
//             }
//         }
//         // Swap the found minimum element with the first unsorted element
//         int temp = arr[i];
//         arr[i] = arr[minIndex];
//         arr[minIndex] = temp;
//     }
// }

// int main() {
//     int i;
//     int arra[] = {12,323,223,1,13};
//     int length = sizeof(arra) / sizeof(arra[0]);
//      for (i = 0; i < length; i++){
//         printf("%d\n",arra[i]);
//     }
//     printf("done");
//     // must be an array, not string literal
//     selectionSort(arra, length);
//     for (i = 0; i < length; i++){
//         printf("%d\n",arra[i]);
//     }
//     printf("done");
//     return 0;
// }

// linaire search**********
// #include<stdio.h>
// int main (){
//    int a[50], n, i, key, flag = 0;


//    printf("enter the no: of elements :");
//    scanf ("%d",&n);

//    for (i=0; i<n; i++){
//         printf("enter the elements:");
//         scanf( "%d", &a[i]);
//    }
      
//    printf("enter a key element:");
//    scanf ("%d", &key);

//    for (i=0; i<n; i++){
//       if (a[i] == key){
//          flag = 1;
//          break;
//       }
//    }
//    if (flag == 1)
//       printf("search is successful:");
//    else
//       printf("search is unsuccessfull:");
//    return 0;
// }


#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // found at index mid
        } else if (arr[mid] < target) {
            left = mid + 1; // search in the right half
        } else {
            right = mid - 1; // search in the left half
        }
    }

    return -1; // not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("✅ Element found at index: %d\n", result);
    } else {
        printf("❌ Element not found in the array.\n");
    }

    return 0;
}