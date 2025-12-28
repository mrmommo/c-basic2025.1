#include <stdio.h>
int arr[1001][4] ;
int main(){
    int n;
    scanf("%d", &n);
    int i ,j ;
    for( int i =0 ; i <n ;i++){
        for(j =0 ;j <4 ;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int x1 , y1 ,x2 ,y2 ;
    int temp1 =1001 , temp2 = 0 ;
    for(i =0 ; i < n ; i++){
        for(j =0 ; j <4 ; j+= 2){
            if(arr[i][j] < temp1) temp1 =arr[i][j];
            if(arr[i][j] > temp2) temp2 =arr[i][j];
        }
    }
    x1 = temp1 , x2 = temp2 ;
    temp1 =1001 , temp2 = 0 ;
    for(i =0 ; i < n ; i++){
        for(j =1 ; j <4 ; j+= 2){
            if(arr[i][j] < temp1) temp1 =arr[i][j];
            if(arr[i][j] > temp2) temp2 =arr[i][j];
        }
    }
    y1 = temp1 , y2 = temp2 ;
    int sum = (x2-x1)*(y2-y1);
    printf("%d", sum);
    return 0;


}