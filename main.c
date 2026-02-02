#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;

    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    // Exercise I: Add d at the end
    struct node d;
    b.next = &d;
    d.value = 11;
    d.next = NULL;

    // Insert from front
    struct node e;
    e.value = 2;
    e.next = &a;
    head = &e;
   
    // Insert f between a and b
    struct node f;
    f.value = 7;
    f.next = &b;
    a.next = &f;

    typedef struct node Node;
    typedef struct node* NodePtr;
    NodePtr tmp = head; 

    // Exercise III: Use for loop
    printf("Exercise III: Print using for loop\n");
    int i, n=5;
    for(i=0; i<n; i++){
        printf("%3d\n", tmp->value);
        tmp = tmp->next;
    }

    // Exercise IV: Change to while loop
    printf("Exercise IV: Print using while loop\n");
    tmp = head; // 
    while(tmp != NULL){
        printf("%3d\n", tmp->value);
        tmp = tmp->next;
    }

    printf("\n--- Starting Dynamic Memory (Malloc) ---\n");

     /*  Exercise V Use malloc to create all nodes, instead of create a struct!!

         //use a loop to help
     */
    NodePtr temp;
    head = (NodePtr) malloc(sizeof(struct node));
    temp = head;
    n = 10;
    for(i=0; i<n; i++){
        temp->value = 7+i*2;
        temp->next = (NodePtr) malloc(sizeof(struct node));
        temp = temp->next;
    }
    tmp = head;
    temp->value = 7+i*2;
    temp->next = NULL;
    while(tmp != NULL) {
        printf("Malloc Node: %d\n", tmp->value);
        tmp = tmp->next;
    }

    /* Exercise VI: Free all nodes
    */
    printf("\nExercise VI: Freeing memory\n");
    while(head != NULL) {
        tmp = head;           
        head = head->next; 
        printf("Freeing node: %d\n", tmp->value);
        free(tmp);                 
    }
    return 0;
}