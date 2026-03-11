//no of duplicate elements in an array..
#include<stdio.h>
#define N 5
int array[N];
int count=0;
int main(){
    int i=0,j=0;
    printf("enter array elements:\n");
    for(i=0;i<N;i++){
        scanf("%d",&array[i]);
    }
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            if(array[i]==array[j]){
                count++;
                break;
            }
        }
    }
    printf("no of duplicate elements=%d",count);
    return 0;
}