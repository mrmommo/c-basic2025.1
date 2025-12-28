#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MOD 1000000007
char math[10001];
long long num[10001] ={0};
char op[5001] ;
int main(){
    fgets(math,10001,stdin);
    math[strcspn(math,"\n")]='\0';
    int length = strlen(math) ;
    if(math[0] == '+' || math[0] == '*' || math[length-1] =='+' || math[length-1] == '*'){
        printf("NOT_CORRECT");
        return 0;
    }
    int i;
    for( i= 0 ; i< length ; i++){
        if(math[i] == '*' || math[i] == '+'){
            if(math[i+1] == '*' || math[i+1] =='+'){
                printf("NOT_CORRECT");
                return 0;
            }
        }
    }
    char *ptr = math;
    int dem1 = 0 , dem2 = 0;
    while( *ptr != '\0'){
        num[dem1++] = strtoll(ptr,&ptr,10);
        if(*ptr != '\0'){
            op[dem2++] = *ptr;
            ptr++;
        }
    }
    for( i=0 ; i < dem2 ; i++){
        if(op[i] == '*'){
            num[i +1] = num[i] * num[i+1] % MOD;
            num[i] = 0 ;
        }
    }
    long long sum = 0 ; 
    for( i =0  ;i < dem1 ; i++){
        sum = (sum + num[i]) % MOD;
    }
    printf("%lld", sum % MOD);
    return 0;

}

