#ifndef stdnode_h  // เปลี่ยนเป็น ifndef (if not defined)
#define stdnode_h

struct node {
    int id;
    char name[30];
    struct node *next;
};

typedef struct node* nodePtr;

#endif /* ต้องมีบรรทัดนี้ปิดท้ายไฟล์เสมอ! */