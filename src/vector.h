
typedef struct vector {
	int len;
	int cap;
	int* arr;
} vector;

vector make(int capacity);
vector append(struct vector vec, int val);
vector pop(struct vector vec);
vector slice(struct vector vec, int low, int high);
char* toString(struct vector vec);
