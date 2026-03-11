//sum of left elements of diagonals
#include<stdio.h>
#define N 3
int matrix[N][N];
int sum=0;
int main(){
    int i=0,j=0;
    printf("enter matrix elements:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&matrix[i][j]);
            if(i>j){
                sum+=matrix[i][j];
            }
        }
    }
    printf("sum of left elements of diagonal=%d",sum);
    return 0;
}