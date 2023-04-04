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
		printf("%d ", vec.arr.intArr[i]);
	}
}


void testVectorInts() {
	vector vec = make(INT_ARR, 5);
	int x = 12;
	vec = append(vec, &x);
	x++;
	vec = append(vec, &x);
	x++;
	vec = append(vec, &x);
	x++;
	vec = append(vec, &x);
	x++;
	vec = append(vec, &x);
	x++;
	vec = append(vec, &x);
	x++;
	vec = append(vec, &x);

	char* str = toString(vec);
	printf("vec = %s\n", str);

	vec = pop(vec);
	str = toString(vec);
	printf("vec = %s\n", str);

	vector s = slice(vec, 2, 5);
	str = toString(s);
	printf("vec = %s\n", str);

	s.arr.intArr[1] = 92342;
	str = toString(vec);
	printf("vec = %s\n", str);
	str = toString(s);
	printf("vec = %s\n", str);
}


void testVectorDoubles() {
	double val = 123.321;
	vector vec = make(DOUBLE_ARR, 5);
	vec = append(vec, &val);
	val = 8.3;
	vec = append(vec, &val);
	val = 32.123;
	vec = append(vec, &val);
	val = 93.43;
	vec = append(vec, &val);
	val = 13.41;
	vec = append(vec, &val);
	val = 0.988;
	vec = append(vec, &val);
	val = 543.543;
	vec = append(vec, &val);

	printf("%lf\n", vec.arr.doubleArr[0]);
	printf("%lf\n", vec.arr.doubleArr[1]);
	printf("%lf\n", vec.arr.doubleArr[2]);
	printf("%lf\n", vec.arr.doubleArr[3]);
	printf("%lf\n", vec.arr.doubleArr[4]);
	printf("%lf\n", vec.arr.doubleArr[5]);
	printf("%lf\n", vec.arr.doubleArr[6]);
	char* str = toStringDouble(vec);
	printf("vec = %s\n", str);

	vec = pop(vec);
	str = toStringDouble(vec);
	printf("vec = %s\n", str);

	vector s = slice(vec, 2, 5);
	str = toStringDouble(s);
	printf("vec = %s\n", str);

	s.arr.doubleArr[1] = 9999.99999;
	str = toStringDouble(vec);
	printf("vec = %s\n", str);
	str = toStringDouble(s);
	printf("vec = %s\n", str);
}

/* void testVectorChars() { */
/* 	vector vec = make(CHAR_ARR, 5); */
/* 	vec = append(vec, &"test1"); */
/* 	vec = append(vec, &"test2"); */
/* 	vec = append(vec, &"test3"); */
/* 	vec = append(vec, &"test4"); */
/* 	vec = append(vec, &"test5"); */
/* 	vec = append(vec, &"test6"); */
/* 	vec = append(vec, &"test7"); */

/* 	printf("%s\n", vec.arr.charArr[0]); */
/* 	printf("%s\n", vec.arr.charArr[1]); */
/* 	printf("%s\n", vec.arr.charArr[2]); */
/* 	printf("%s\n", vec.arr.charArr[3]); */
/* 	printf("%s\n", vec.arr.charArr[4]); */
/* 	printf("%s\n", vec.arr.charArr[5]); */
/* 	printf("%s\n", vec.arr.charArr[6]); */
	/* char* str = toString(vec); */
	/* printf("vec = %s\n", str); */

	/* vec = pop(vec); */
	/* str = toString(vec); */
	/* printf("vec = %s\n", str); */

	/* vector s = slice(vec, 2, 5); */
	/* str = toString(s); */
	/* printf("vec = %s\n", str); */

	/* s.arr.intArr[1] = 92342; */
	/* str = toString(vec); */
	/* printf("vec = %s\n", str); */
	/* str = toString(s); */
	/* printf("vec = %s\n", str); */
/* } */

int main() {
	/* testLinkedList(); */
	/* struct List *list = readFile(); */
	/* ll_print(list); */

	/* testVectorInts(); */
	testVectorDoubles();
	/* testVectorChars(); */
}
