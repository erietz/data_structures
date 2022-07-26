#include <stdio.h>
#include "src/linked_list.h"

void
testLinkedList() {
	struct node *list = linkedListInit("item 1");
	linkedListPrint(list);
	linkedListAdd(list, "item 2");
	linkedListPrint(list);
	linkedListAdd(list, "item 3");
	linkedListPrint(list);
	list = linkedListRemove(list, "item 3");
	linkedListPrint(list);
	list = linkedListRemove(list, "item 2");
	linkedListPrint(list);
	list = linkedListRemove(list, "item 1");
	linkedListPrint(list);
}

int
main() {
	testLinkedList();
}
