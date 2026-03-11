//  Write a program in C to find the second smallest element in an array.

#include <stdio.h>
#define N 4

int main(){
    int arr[N],i;
    printf("Enter elements of array : ");
    for(i = 0 ; i < N ; i++){
       scanf("%d", &arr[i]);
    }

    int small = arr[0];
    int secondSmall = arr[1];

    for(int i = 0 ; i < N; i++){
        if(arr[i] < small){
            secondSmall = small;
            small = arr[i];
        }
        else if(arr[i] < secondSmall && arr[i] != small){
            secondSmall = arr[i];
        }
    }

    printf("The second smallest element is : %d",secondSmall);
}