//Perform a sequence of operations over a queue, each element is an integer:
//PUSH v: push a value v into the queue
//POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
//Input
//Each line contains a command (operration) of type
//PUSH  v
//POP
//Output
//Write the results of POP operations (each result is written in a line)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//
#define max 100
int queue[max] = {0};
int top = 0 ;

void push( int v){
    if( top < max ){
        queue[top++] = v;
    }
}
void pop(){
    if ( top > 0){
        printf("%d\n", queue[0]);
        for( int i = 0 ; i < top ; i++){
            queue[i] = queue[i+1];
        }
        top--;
    }
    else printf("NULL\n");
}
int main(){
    char line[100];
    while(fgets(line, sizeof(line), stdin)){
        if(line[0] == '#') break;
        if(!strncmp(line,"PUSH", 4)){
            int v;
            sscanf(line+5, "%d", &v);
            push(v);
        }
        else if(!strncmp(line, "POP", 3)){
            pop();
        }
    }
    return 0;
}
