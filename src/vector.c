#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "vector.h"


vector make(int capacity) {
	int* arr = malloc(capacity);
	vector vec = {
		.len = 0,
		.cap = capacity,
		.arr = arr,
	};
	return vec;
}

vector resize(struct vector vec) {
	if (vec.len == vec.cap) {
		vec.cap *= 2;
		vec.arr = realloc(vec.arr, vec.cap);
		puts("realloc expanding");
	} else if (vec.len < vec.cap / 4 && vec.len > 10) {
		vec.cap /= 2;
		vec.arr = realloc(vec.arr, vec.cap);
		puts("realloc shrinking");
	}
	return vec;
}

vector append(struct vector vec, int val) {
	vec = resize(vec);
	vec.arr[vec.len] = val;
	vec.len++;
	return vec;
}

vector pop(struct vector vec) {
	assert(vec.len > 0);
	vec.len--;
	vec = resize(vec);
	return vec;
}

vector slice(struct vector vec, int low, int high) {
	assert(low >= 0);
	high = high > vec.len ? vec.len : high;
	int len = high - low;
	vec.arr = &vec.arr[low];
	vec.len = len;
	resize(vec);
	return vec;
}

char* toString(struct vector vec) {
	char* str = malloc((2 * vec.len)*sizeof(int) + 4*sizeof(int));

	int i = 0;
	str[i++] = '{';
	str[i++] = ' ';

	for (int j = 0; j < vec.len; j++) {
		int n = sprintf(str + i, "%d", vec.arr[j]);
		i += n;
		str[i++] = ' ';

	}

	str[i++] = '}';
	return str;
}
