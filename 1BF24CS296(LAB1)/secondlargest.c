#include <stdio.h>
#define N 5

int main(){
    int arr[N],i;
    printf("Enter elements of array : ");
    for(i = 0 ; i < N ; i++){
       scanf("%d", &arr[i]);
    }

    int large = arr[0];
    int secondLarge = arr[1];

    for(int i = 0 ; i < N; i++){
        if(arr[i] > large){
            secondLarge = large;
            large = arr[i];
        }
        else if(arr[i] > secondLarge && arr[i] != large){
            secondLarge = arr[i];
        }
    }

    printf("The second largest element is : %d",secondLarge);

}