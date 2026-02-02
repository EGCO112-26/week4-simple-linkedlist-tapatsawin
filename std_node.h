#ifndef stdnode_h
#define stdnode_h

struct node {
    int id;
    char name[30];
    struct node *next; // ต้องใช้ชื่อเดียวกันกับ struct ด้านบน
};

typedef struct node* nodePtr; // เพื่อความสะดวกในการประกาศ Pointer

#endif