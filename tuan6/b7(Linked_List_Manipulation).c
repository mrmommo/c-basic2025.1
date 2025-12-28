#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//
#define max 100
typedef struct Node {
    int key;
    struct Node* next;
}node;
node* head = NULL;
//
int Check(int k){
    node* p = head ;
    while(p){
        if(p->key == k) return 1;
        p = p->next ;
    }
    return 0;

}
//
void addlast( int k){
    if(Check(k) != 0) return ;
    else{
        node* newnode = (node*)malloc(sizeof(node));
        newnode -> key = k;
        newnode -> next = NULL;
        node* p = head;
        if( head == NULL){
            head = newnode;
            return;
        }
        else{
            while ( p -> next) p = p -> next;
            p -> next = newnode ; 
        }
    }
}
//
void addfirst( int k){
    if(Check(k) != 0) return ;
    node *newnode = (node*)malloc(sizeof(node));
    newnode -> key = k;
    newnode -> next = NULL;
    if( head == NULL){
        head = newnode;
        return;
    }
    node*p = head;
    head = newnode;
    head -> next = p;

}
//
void addafter( int u , int v){
    if(Check(u) != 0) return ;
    node* p = head ;
    while( p != NULL){
        if(p -> key == v){
            node* newnode = (node*)malloc(sizeof(node));
            newnode -> key = u;
            newnode -> next = p -> next ;
            p -> next = newnode;
            return;
        }
        p = p -> next;

    }
}
//
void addbefore( int u , int v){
    if(Check(u) != 0 ) return ;
    node* p = head;
    node*before = head;
    while(p != NULL){
        if(head -> key == v){
            node* newnode = (node*)malloc(sizeof(node));
            newnode -> key = u ;
            newnode -> next = head;
            head = newnode;
            return;
        }
        else if( p -> key == v){
            node* newnode = (node*)malloc(sizeof(node));
            newnode -> key = u ;
            newnode -> next = p;
            before -> next = newnode;
            return;

        }
        if( p != head) before = before -> next;
        p = p -> next;
    }
}
//remove k
void removeKey( int k ){
    //ko có node
    if(!head) return ;
    if(head-> key == k){
        node* tmp;
        tmp = head;
        head = head -> next;
        free(tmp);
        return;
    }
    node* cur = head;
    node* prev  = NULL;
    while( cur && cur -> key != k){
        prev = cur ;
        cur = cur -> next ;
    }
    if(!cur) return;
    prev -> next = cur -> next;
    free(cur);
    return;
}
//reverse
void reverse(){
    node* prev = NULL;
    node* cur = head;
    while( cur ){
        node* tmp = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = tmp;
    }
    head = prev;
    return;
    
}
// printflist
void printfList(){
    node* p = head;
    while(p){
        printf("%d", p->key);
        if(p -> next) printf(" ");
        p = p -> next;
    }
    printf("\n");
    return;
}

int main(){
    int n , k ;
    scanf("%d", &n);
    for( int i = 0 ;i <n ;i++){
        scanf("%d", &k);
        addlast(k);
    }
    char line[100];
    while(fgets(line,max,stdin)){
        if( line[0] == '#') break ;
        if( !strncmp(line,"addlast", 7)){
            int v; 
            sscanf(line+8,"%d", &v);
            addlast(v);
        }
        else if (!strncmp(line,"addfirst", 8)){
            int v;
            sscanf(line+9, "%d", &v);
            addfirst(v);
        }
        else if (!strncmp(line,"addafter",8)){
            int u,v;
            sscanf(line+9,"%d %d", &u, &v);
            addafter(u,v);
        }
        else if (!strncmp(line,"addbefore",9)){
            int u,v;
            sscanf(line+10,"%d %d", &u, &v);
            addbefore(u,v);
        }
        else if (!strncmp(line,"remove",6)){
            int v;
            sscanf(line+7,"%d", &v);
            removeKey(v);
        }
        else if(!strncmp(line, "reverse",7)){
            reverse();
        }
    }
    printfList();
    return 0;
    
}