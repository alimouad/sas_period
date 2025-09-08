#include <stdio.h>
#include <string.h>

int add( int a[], int n) {

    int i,s=0;
    for (i =0; i < n ; i++) {
        s+= a[i];
    }
    return s;
    
}

int main() {
    int a[] ={3,3,4};
	int s = add (a,3);
    printf("%d", s);
    return 0;
}