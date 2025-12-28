#include <stdio.h>
int n , m ;
int arr[11];
int sum = 0;
void solution(){
    for(int i=0 ;i <n ; i++)
    printf("%d ",arr[i]);
    printf("\n");
}
void Try( int k){
    for(int i = 1 ; i <= m -n + 1 ;i++){
        arr[k] = i;
        sum += i;
        if(k == n -1 ){
            if(sum == m) solution();
        }
        else if(sum >= m){
            sum -= i;
            continue;
        }
        else Try(k+1);
        sum -=i;

    }
}
int main(){
    scanf("%d %d", &n ,&m);
    Try(0);
    return 0;
}