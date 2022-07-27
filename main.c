#include <stdio.h>
#include "src/linked_list.h"

void
printLinkedListLength(struct List *list)
{
	printf("Linked list length %d\n", list->length);
}

void
testLinkedList()
{
	struct List *list = ll_init();
	ll_add(list, "item 1");
	printLinkedListLength(list);
	ll_print(list);
	ll_add(list, "item 2");
	printLinkedListLength(list);
	ll_print(list);
	ll_add(list, "item 3");
	printLinkedListLength(list);
	ll_print(list);

	printf("Linked list contains 'item 1': %d, 'item 2': %d, 'item 3' %d, 'item 4': %d\n",
		ll_contains(list, "item 1"),
		ll_contains(list, "item 2"),
		ll_contains(list, "item 3"),
		ll_contains(list, "item 4")
		);

	list = ll_remove(list, "item 1");
	printLinkedListLength(list);
	ll_print(list);
	list = ll_remove(list, "item 3");
	printLinkedListLength(list);
	ll_print(list);
	list = ll_remove(list, "item 2");
	printLinkedListLength(list);
	ll_print(list);
}

struct List*
readFile()
{
	struct List *list = ll_init("");
	FILE *fd = fopen("/home/ethan/Documents/bio.md", "r");
	char buff[255];
	while (fgets(buff, sizeof buff, fd)) {
		ll_add(list, buff);
	}
	fclose(fd);
	return list;
}

int
main()
{
	testLinkedList();
	struct List *list = readFile();
	/* ll_print(list); */
}
