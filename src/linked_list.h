#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

struct node {
	struct node *next;
	char *data;
};

struct node *linkedListInit();
void linkedListAdd(struct node *head, char *data);
struct node *linkedListRemove(struct node *head, char *data);
bool linkedListContains(struct node *head, char *data);
int linkedListLength(struct node *head);
void linkedListPrint(struct node *head);

#endif // LINKED_LIST_H
