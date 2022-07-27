#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

struct Node {
	struct Node *next;
	char *data;
};

struct List {
	struct Node *head;
	int length;
};

struct List *ll_init();
void ll_add(struct List *list, char *data);
struct List * ll_remove(struct List *list, char *data);
bool ll_contains(struct List *list, char *data);
void ll_print(struct List *list);

#endif // LINKED_LIST_H
