#include <stdio.h>
//queue
int class[901][901] = {0};
int queue1[901];
int queue2[901];
int top = 0 ;
void push( int u, int v){
    if( top < max ){
        queue1[top++] = u;
        queue2[top++] = v;
    }
}
void pop(){
    if ( top > 0){
        for( int i = 0 ; i < top ; i++){
            queue1[i] = queue1[i+1];
            queue2[i] = queue2[i+1];
        }
        top--;
    }
}
//gcd
int gcd( int a ,int b){
    if(b ==0) return a;
    return gcd(b,a%b); 
}
int max(int a, int b){
    return a > b ? a : b ;
}
//check
int Check(int a, int b ,int c){
    if(c <= max(a,b) && c % gcd(a,b) == 0) return 1;
    else return 0;
}
//wtj
int waterjugs( int a, int b , int c){
    if (!Check(a,b,c)) return 0;
    else{
        int b1 = 0 , b2 = 0;
        while(1){
            pop();
            


        }













    }
}



int main(){
    queue1[0] = 0 , queue2[0] = 0;
    int a , b ,c ;
    scanf("%d %d %d", &a,&b,&c);
    printf("%d\n", waterjugs(a,b,c));
    return 0;
}