#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

static struct node *createNode(char *data);


struct node*
createNode(char *data)
{
	struct node *newNode = malloc(sizeof(struct node));
	char *newData = malloc(strlen(data) + 1);
	strcpy(newData, data);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct node*
linkedListInit(char *data)
{
	return createNode(data);
}

void
linkedListAdd(struct node *head, char *data)
{
	struct node *curr;
	for (curr = head; curr->next; curr = curr->next);
	struct node *newNode = createNode(data);
	curr->next = newNode;
}

struct node*
linkedListRemove(struct node *head, char *data)
{
	struct node *curr = head;

	if (curr->next == NULL) {
		curr->data = NULL;
		free(curr);
		return NULL;
	}

	while (curr->next != NULL) {
		if (strcmp(curr->next->data, data) == 0) {
			struct node* tmp = curr->next;
			curr->next = tmp->next;
			tmp->data = NULL;
			free(tmp);
			return head;
		}
		curr = curr->next;
	}
	curr->next->data = NULL;
	free(curr->next);
	curr->next = NULL;
	return head;
}

void
linkedListPrint(struct node *head)
{
	struct node *curr = head;
	if (!curr) {
		puts("[ (null) ]");
		return;
	}

	printf("[ ");
	while (curr->next) {
		printf("%s, ", curr->data);
		curr = curr->next;
	}
	printf("%s ]\n", curr->data);
}
