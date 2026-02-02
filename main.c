#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h" // หรือ std_node.h ให้ดูว่าในไฟล์นั้นมี id กับ name หรือยัง

int main(int argc, const char * argv[]) {
    // --- Exercise I - IV (Static Part) ---
    // (ใส่ Code ส่วน Static ของคุณตามปกติ)

    // --- Exercise V: Malloc for Autograder ---
    // Autograder ส่งค่ามาเป็น: ./a.out 1234 DIDI 135 DODO
    typedef struct node* NodePtr;
    NodePtr m_head = NULL, m_temp = NULL;

    for (int i = 1; i < argc; i += 2) { // วนลูปทีละ 2 เพราะมาเป็นคู่ (ID, Name)
        NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
        if (!newNode) break;

        newNode->id = atoi(argv[i]); // เก็บ ID
        if (i + 1 < argc) {
            strcpy(newNode->name, argv[i+1]); // เก็บ Name
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

    // ส่วนการ Print ต้องให้ตรงตาม Format ที่เทสต้องการ (ปกติคือ ID แล้วตามด้วย Name)
    NodePtr tmp = m_head;
    while (tmp != NULL) {
        printf("ID: %d Name: %s\n", tmp->id, tmp->name);
        tmp = tmp->next;
    }

    // --- Exercise VI: Freeing ---
    while (m_head != NULL) {
        NodePtr toFree = m_head;
        m_head = m_head->next;
        free(toFree);
    }

    return 0;
}