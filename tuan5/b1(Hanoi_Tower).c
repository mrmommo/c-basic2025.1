#include <stdio.h>
int n , A , B , C , D ;
int dem = 0;
int Hanoi(int n , int A, int B, int C, int D ){
    dem++;
    if(n==1){
        if(D!= 0 ) printf("%d %d\n", A, B);
        return dem;
    }
    Hanoi(n-1,A,C,B,D);
    if(D!=0) printf("%d %d\n", A,B);
    Hanoi(n-1,C,B,A,D);
}

int main(){
    scanf("%d %d %d %d", &n ,&A, &B, &C);
    Hanoi(n,A,B,C,0);
    printf("%d\n",dem);
    dem = 0;
    Hanoi(n,A,B,C,1);
    return 0;
}