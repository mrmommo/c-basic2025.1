#include <stdio.h>
int n;
int arr[21] ={0};
void solution(){
    for( int i =0 ; i< n ;i++) printf("%d", arr[i]);
    printf("\n");
}
void Try(int k){
    for( int i =0 ; i <= 1 ; i++){
        arr[k] = i;
        if(arr[k] == 1 && arr[k-1] ==1 ) continue;
        if( k == n - 1) solution();
        else Try(k+1);
    }
}
int main(){
    scanf("%d", &n);
    Try(0);
    return 0;
}