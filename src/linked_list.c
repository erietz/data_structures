#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

static struct Node *createNode(char *data);

struct Node*
createNode(char *data)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	char *newData = malloc(strlen(data) + 1);
	strcpy(newData, data);
	newNode->data = newData;
	newNode->next = NULL;
	return newNode;
}

struct List*
ll_init()
{
	struct List *list = malloc(sizeof(struct List));
	list->head = NULL;
	list->length = 0;
	return list;
}

void
ll_add(struct List *list, char *data)
{
	struct Node *curr;
	struct Node *node = createNode(data);
	list->length++;

	if (list->head == NULL) {
		list->head = node;
		return;
	}

	for (curr = list->head; curr->next; curr = curr->next);
	curr->next = node;
}

struct List*
ll_remove(struct List *list, char *data)
{
	struct Node *curr = list->head;
	list->length--;

	if (strcmp(curr->data, data) == 0) {
		list->head = curr->next;
		curr->data = NULL;
		free(curr);
		return list;
	}

	while (curr->next != NULL) {
		if (strcmp(curr->next->data, data) == 0) {
			struct Node* tmp = curr->next;
			curr->next = tmp->next;
			tmp->data = NULL;
			free(tmp);
			return list;
		}
		curr = curr->next;
	}
	curr->next->data = NULL;
	free(curr->next);
	curr->next = NULL;
	return list;
}

bool
ll_contains(struct List *list, char *data)
{
	struct Node *curr = list->head;
	while (curr != NULL) {
		if (strcmp(curr->data, data) == 0)
			return true;
		curr = curr->next;
	}
	return false;
}

void
ll_print(struct List *list)
{
	struct Node *curr = list->head;
	if (!curr) {
		puts("[ ]");
		return;
	}

	printf("[ ");
	while (curr->next) {
		printf("%s, ", curr->data);
		curr = curr->next;
	}
	printf("%s ]\n", curr->data);
}
