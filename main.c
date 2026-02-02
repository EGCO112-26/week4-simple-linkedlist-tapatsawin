//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include "node.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
  struct node *head = NULL;
  struct node *temp = NULL;
  int i;

  for (i = 1; i < argc; i += 2) {
    if (i + 1 >= argc)
      break;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->id = atoi(argv[i]);
    newNode->name = (char *)argv[i + 1];
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      temp = newNode;
    } else {
      temp->next = newNode;
      temp = newNode;
    }
  }

  temp = head;
  while (temp != NULL) {
    printf("%d %s\n", temp->id, temp->name);
    temp = temp->next;
  }

  temp = head;
  while (temp != NULL) {
    struct node *nextNode = temp->next;
    free(temp);
    temp = nextNode;
  }

  return 0;
}