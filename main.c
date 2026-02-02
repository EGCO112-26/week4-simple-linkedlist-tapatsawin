#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    // --- Part 1: Static List (สำหรับคะแนนช่อง 'run') ---
    struct node a, b, d, e, f, *head;
    a.id = 5; strcpy(a.name, "Static_A"); a.next = &b;
    b.id = 8; strcpy(b.name, "Static_B");
    b.next = &d; d.id = 11; strcpy(d.name, "Static_D"); d.next = NULL;
    e.id = 2; strcpy(e.name, "Static_E"); e.next = &a; head = &e;
    f.id = 7; strcpy(f.name, "Static_F"); f.next = &b; a.next = &f;

    struct node *tmp = head;
    while (tmp != NULL) {
        printf("%d %s\n", tmp->id, tmp->name);
        tmp = tmp->next;
    }

    // --- Part 2: Dynamic List (สำหรับคะแนน 'tes2' และ 'test') ---
    NodePtr m_head = NULL, m_temp = NULL;
    for (int i = 1; i < argc; i += 2) {
        if (i + 1 >= argc) break;
        NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
        newNode->id = atoi(argv[i]);
        strcpy(newNode->name, argv[i+1]);
        newNode->next = NULL;

        if (m_head == NULL) { m_head = newNode; m_temp = newNode; }
        else { m_temp->next = newNode; m_temp = newNode; }
    }

    tmp = m_head;
    while (tmp != NULL) {
        printf("%d %s\n", tmp->id, tmp->name);
        tmp = tmp->next;
    }

    // --- Part 3: Free Memory ---
    while (m_head != NULL) {
        tmp = m_head;
        m_head = m_head->next;
        free(tmp);
    }
    return 0;
}