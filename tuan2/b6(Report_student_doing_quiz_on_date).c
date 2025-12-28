#include <stdio.h>
#include <string.h>
 typedef struct{
    int yyyy , mm , dd;
    int h , m , s;
    char user_id[10];
    int q_id;

 }sv;
int main(){
    sv  a[1000];
    int i =0 ;
    char line[100];
    while(1){
        fgets(line,100,stdin);
        line[strcspn(line,"\n")] = '\0';
        if( line[0] == '*') break;
        sscanf(line,"%d-%d-%d %d:%d:%d %s question%d ", &a[i].yyyy, &a[i].mm, &a[i].dd, &a[i].h, &a[i].m, &a[i].s, &a[i].user_id, &a[i].q_id);
        i++;
    }
    return 0;
    
}