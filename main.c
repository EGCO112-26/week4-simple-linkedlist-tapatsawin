#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    NodePtr head = NULL;
    NodePtr temp = NULL;

    // --- การแทรก Node จาก Input Argument (Exercise V) ---
    // เริ่มที่ i=1 และขยับทีละ 2 เพื่อจับคู่ ID และ Name
    for (int i = 1; i < argc; i += 2) {
        if (i + 1 >= argc) break; // ป้องกันกรณีใส่ argument ไม่ครบคู่

        NodePtr newNode = (NodePtr)malloc(sizeof(Node));
        if (newNode != NULL) {
            newNode->id = atoi(argv[i]);
            strcpy(newNode->name, argv[i+1]); // คัดลอกชื่อลงใน node
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
                temp = head;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
        }
    }

    // --- การพิมพ์ข้อมูลทั้งหมดใน Linked List ---
    temp = head;
    while (temp != NULL) {
        printf("%d %s\n", temp->id, temp->name);
        temp = temp->next;
    }

    // --- การลบ Linked List ทั้งหมด (Exercise VI) ---
    while (head != NULL) {
        temp = head;
        head = head->next;
        // printf("Deleting %d\n", temp->id); // เปิดไว้ถ้าต้องการดูตอนลบ
        free(temp);
    }

    return 0;
}