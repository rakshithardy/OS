//sum of rows and columns
#include<stdio.h>
#define N 3
int sum=0;
int matrix[N][N];
int row[N],column[N];
int main(){
    int i=0,j=0;
    printf("enter matrix elements:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&matrix[i][j]);
            }
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            sum+=matrix[i][j];
            row[i]=sum;
        }
        sum=0;
    }
    for(j=0;j<N;j++){
        for(i=0;i<N;i++){
            sum+=matrix[i][j];
            column[j]=sum;
        }
        sum=0;
    }
    for(int i=0;i<N;i++){
        printf("sum of row %d=%d\n",i+1,row[i]);
    }
    for(int i=0;i<N;i++){        
        printf("sum of column %d=%d\n",i+1,column[i]);
    }
    return 0;
}