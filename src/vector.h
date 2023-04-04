enum VectorDataType {
	INT_ARR,
	DOUBLE_ARR,
	CHAR_ARR,
};

union VectorData {
	int* intArr;
	double* doubleArr;
	char* charArr;
};

typedef struct Vector {
	int len;
	int cap;
	union VectorData arr;
	enum VectorDataType type;
} vector;

vector make(enum VectorDataType type, int capacity);
vector append(struct Vector vec, enum VectorDataType val);
vector pop(struct Vector vec);
vector slice(struct Vector vec, int low, int high);
char* toString(struct Vector vec);
