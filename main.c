#include <stdio.h>
#include <stdlib.h>
#include "src/linked_list.h"
#include "src/vector.h"

void printLinkedListLength(struct List *list) {
	printf("Linked list length %d\n", list->length);
}

void testLinkedList() {
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

struct List* readFile() {
	struct List *list = ll_init("");
	FILE *fd = fopen("/home/ethan/Documents/bio.md", "r");
	char buff[255];
	while (fgets(buff, sizeof buff, fd)) {
		ll_add(list, buff);
	}
	fclose(fd);
	return list;
}

void printVector(vector vec) {
	for (int i = 0; i < vec.len; i++) {
		printf("%d ", vec.arr[i]);
	}
}


void testVector() {
	vector vec = make(5);
	vec = append(vec, 12);
	vec = append(vec, 13);
	vec = append(vec, 14);
	vec = append(vec, 15);
	vec = append(vec, 16);
	vec = append(vec, 17);
	vec = append(vec, 18);

	char* str = toString(vec);
	printf("vec = %s\n", str);

	vec = pop(vec);
	str = toString(vec);
	printf("vec = %s\n", str);

	vector s = slice(vec, 2, 5);
	str = toString(s);
	printf("vec = %s\n", str);
}

int main() {
	/* testLinkedList(); */
	/* struct List *list = readFile(); */
	/* ll_print(list); */

	testVector();
}
