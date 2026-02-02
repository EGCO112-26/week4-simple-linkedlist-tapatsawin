#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

int main(int argc, const char * argv[]) {
    int c = 5;
    struct node a, b, *head;

    a.id = 5;
    strcpy(a.name, "Static_A");
    a.next = &b;
    head = &a;
    b.id = head->id + 3;
    strcpy(b.name, "Static_B");

/* Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    struct node d;
    b.next = &d;
    d.id = 11;
    strcpy(d.name, "Static_D");
    d.next = NULL;

/* Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
*/
    struct node e;
    e.id = 2;
    strcpy(e.name, "Static_E");
    e.next = head;
    head = &e;

    struct node f;
    f.id = 7;
    strcpy(f.name, "Static_F");
    f.next = &b;
    a.next = &f;

    typedef struct node* NodePtr;
    NodePtr tmp = head;

/* Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
*/
    int i, n = 5;
    printf("--- Exercise III Output ---\n");
    for (i = 0; i < n; i++) {
        if (tmp != NULL) {
            printf("ID: %-8d Name: %-10s\n", tmp->id, tmp->name);
            tmp = tmp->next;
        }
    }

/* Exercise IV change to while loop!! (you can use NULL to help)
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
*/
    printf("\n--- Exercise IV Output ---\n");
    tmp = head;
    while (tmp != NULL) {
        printf("ID: %-8d Name: %-10s\n", tmp->id, tmp->name);
        tmp = tmp->next;
    }

/* Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
*/
    NodePtr m_head = NULL, m_temp = NULL;
    for (i = 1; i < argc; i += 2) {
        NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
        if (!newNode) break;

        newNode->id = atoi(argv[i]);
        if (i + 1 < argc) {
            strncpy(newNode->name, argv[i + 1], 29);
            newNode->name[29] = '\0';
        } else {
            strcpy(newNode->name, "Unknown");
        }
        newNode->next = NULL;

        if (m_head == NULL) {
            m_head = newNode;
            m_temp = m_head;
        } else {
            m_temp->next = newNode;
            m_temp = m_temp->next;
        }
    }

    printf("\n--- Exercise V Output (Malloc) ---\n");
    tmp = m_head;
    while (tmp != NULL) {
        printf("Malloc ID: %-8d Name: %-10s\n", tmp->id, tmp->name);
        tmp = tmp->next;
    }

/* Exercise VI Free all node !!
         //use a loop to help
*/
    printf("\n--- Exercise VI Output (Freeing) ---\n");
    while (m_head != NULL) {
        tmp = m_head;
        m_head = m_head->next;
        printf("Freeing ID: %d (%s)...\n", tmp->id, tmp->name);
        free(tmp);
    }

    return 0;
}