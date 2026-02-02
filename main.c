#include <stdio.h>
#include <stdlib.h>
#include "node.h" // กลับมาใช้ node.h (มีแค่ value และ next)

int main(int argc, const char * argv[]) {
    int c = 5;
    struct node a, b, *head;

    a.value = c;
    a.next = &b;
    head = &a;
    b.value = head->value + 3;

/* Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    struct node d;
    b.next = &d;
    d.value = 11;
    d.next = NULL;

/* Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
*/
    struct node e;
    e.value = 2;
    e.next = head;
    head = &e;

    struct node f;
    f.value = 7;
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
    printf("--- Exercise III Output (Static) ---\n");
    for (i = 0; i < n; i++) {
        if (tmp != NULL) {
            printf("%3d -> ", tmp->value);
            tmp = tmp->next;
        }
    }
    printf("NULL\n");

/* Exercise IV change to while loop!! (you can use NULL to help)
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
*/
    printf("\n--- Exercise IV Output (Static) ---\n");
    tmp = head;
    while (tmp != NULL) {
        printf("%3d -> ", tmp->value);
        tmp = tmp->next;
    }
    printf("NULL\n");

/* Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
*/
    NodePtr m_head = NULL, m_temp = NULL;
    // รับค่าจาก argv ทีละ 1 ตัวเลขต่อ 1 Node
    for (i = 1; i < argc; i++) {
        NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
        if (!newNode) break;

        newNode->value = atoi(argv[i]); // เปลี่ยนจาก id เป็น value
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
        printf("Malloc Value: %d\n", tmp->value);
        tmp = tmp->next;
    }

/* Exercise VI Free all node !!
         //use a loop to help
*/
    printf("\n--- Exercise VI Output (Freeing) ---\n");
    while (m_head != NULL) {
        tmp = m_head;
        m_head = m_head->next;
        printf("Freeing value: %d\n", tmp->value);
        free(tmp);
    }

    return 0;
}