#include <stdio.h>
#include <stdlib.h>
#include "node.h" // เรียกใช้ struct ที่มีแค่ value และ next

int main(int argc, const char * argv[]) {
    // --- ส่วนของ Exercise I-IV: Static List (ใช้ค่า value) ---
    struct node a, b, d, e, f, *head;

    a.value = 5;
    a.next = &b;
    head = &a;
    b.value = head->value + 3;

    // Exercise I: เพิ่ม d ต่อท้าย
    b.next = &d;
    d.value = 11;
    d.next = NULL;

    // Exercise II: แทรก e ไว้หน้าสุด
    e.value = 2;
    e.next = head;
    head = &e;

    // แทรก f ระหว่าง a และ b
    f.value = 7;
    f.next = &b;
    a.next = &f;

    // Exercise III & IV: การพิมพ์ผลลัพธ์จาก Static List
    struct node *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->value); // พิมพ์แค่ value ตามโครงสร้าง node.h
        tmp = tmp->next;
    }
    printf("\n");

    // --- Exercise V: Malloc (รับค่าจาก argv) ---
    /* เนื่องจาก Autograder ส่งค่ามาเป็นคู่ (ID Name) แต่ node.h มีแค่ value 
       เราจะเก็บ ID ไว้ใน value และข้ามส่วนของ Name ไปเพื่อให้คอมไพล์ผ่านครับ */
    struct node *m_head = NULL;
    struct node *m_temp = NULL;

    for (int i = 1; i < argc; i += 2) {
        if (i + 1 >= argc) break;

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) break;

        newNode->value = atoi(argv[i]); // เก็บตัวเลข ID ไว้ใน value
        newNode->next = NULL;

        if (m_head == NULL) {
            m_head = newNode;
            m_temp = newNode;
        } else {
            m_temp->next = newNode;
            m_temp = newNode;
        }
    }

    // พิมพ์ผลลัพธ์ส่วน Malloc
    tmp = m_head;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");

    // --- Exercise VI: Free Memory ---
    tmp = m_head;
    while (tmp != NULL) {
        struct node *nextNode = tmp->next;
        free(tmp);
        tmp = nextNode;
    }

    return 0;
}