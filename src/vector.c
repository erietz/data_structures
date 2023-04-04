#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "vector.h"


vector make(enum VectorDataType type, int capacity) {
	vector vec = {
		.len = 0,
		.cap = capacity,
		.type = type,
	};

	switch (type) {
		case INT_ARR:
			vec.arr.intArr = malloc(sizeof(int) * capacity);
		break;
		case DOUBLE_ARR:
			vec.arr.doubleArr = malloc(sizeof(double) * capacity);
		break;
		case CHAR_ARR:
			vec.arr.charArr = malloc(sizeof(char) * capacity);
		break;
		default:
			fprintf(stderr, "Invalid datatype");
			exit(1);
		break;
	}

	return vec;
}

vector resize(struct Vector vec) {
	int needsResized = 0;

	if (vec.len == vec.cap) {
		vec.cap *= 2;
		needsResized = 1;
	} else if (vec.len < vec.cap / 4 && vec.len > 10) {
		vec.cap /= 2;
		needsResized = 1;
	}

	if (needsResized) {
		switch (vec.type) {
			case INT_ARR:
				vec.arr.intArr = realloc(vec.arr.intArr, vec.cap * sizeof(int));
			break;
			case DOUBLE_ARR:
				vec.arr.doubleArr = realloc(vec.arr.doubleArr, vec.cap * sizeof(double));
			break;
			case CHAR_ARR:
				vec.arr.charArr = realloc(vec.arr.charArr, vec.cap * sizeof(char));
			break;
		}
	}

	return vec;
}

vector append(struct Vector vec, void *val) {
	vec = resize(vec);
	switch (vec.type) {
		case INT_ARR:
			vec.arr.intArr[vec.len] = *(int*)val;
		break;
		case DOUBLE_ARR:
			vec.arr.doubleArr[vec.len] = *(double*)val;
		break;
		case CHAR_ARR:
			strcpy(vec.arr.charArr[vec.len], *(char*)val);
		break;
	}
	vec.len++;
	return vec;
}

vector pop(struct Vector vec) {
	assert(vec.len > 0);
	vec.len--;
	vec = resize(vec);
	return vec;
}

vector slice(struct Vector vec, int low, int high) {
	assert(low >= 0);
	high = high > vec.len ? vec.len : high;
	int len = high - low;

	switch (vec.type) {
		case INT_ARR:
			vec.arr.intArr = &vec.arr.intArr[low];
		break;
		case DOUBLE_ARR:
			vec.arr.doubleArr = &vec.arr.doubleArr[low];
		break;
		case CHAR_ARR:
			vec.arr.charArr = &vec.arr.charArr[low];
		break;
	}

	vec.len = len;
	resize(vec);
	return vec;
}

char* toString(struct Vector vec) {
	char* str = malloc((2 * vec.len)*sizeof(int) + 4*sizeof(int));

	int i = 0;
	str[i++] = '{';
	str[i++] = ' ';

	for (int j = 0; j < vec.len; j++) {
		int n = sprintf(str + i, "%d", vec.arr.intArr[j]);
		i += n;
		str[i++] = ' ';

	}

	str[i++] = '}';
	return str;
}

char* toStringDouble(struct Vector vec) {
	char* str = malloc((2 * vec.len)*sizeof(double) + 4*sizeof(double));

	int i = 0;
	str[i++] = '{';
	str[i++] = ' ';

	for (int j = 0; j < vec.len; j++) {
		int n = sprintf(str + i, "%lf", vec.arr.doubleArr[j]);
		i += n;
		str[i++] = ' ';

	}

	str[i++] = '}';
	return str;
}
