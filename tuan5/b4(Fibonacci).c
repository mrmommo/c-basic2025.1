#include <stdio.h>
int n, arr[100002]= {0};
long long Fun(int n){
    if(n < 0) return 0;
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(n>=2){
       if (arr[n] !=0) return arr[n];
        else{
        arr[n]=(Fun(n-1)+Fun(n-2))%1000000007;
            return arr[n];
        }
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    printf("%lld",Fun(n));
    return 0;

}
