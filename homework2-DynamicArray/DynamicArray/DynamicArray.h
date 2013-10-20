// Licensed in GPL v3
// Copyright 2013-2013 xvblack

#include "headers.h"

class DynamicArray{
public:
	DynamicArray();
	DynamicArray(const int* array, int length);
	DynamicArray(const int* array, int length, int capacity);
	~DynamicArray();
	void Reset();
	void Append(int);
	void Push(int);
	void Extend(DynamicArray);
	int Pop();
	int Get(int);
	int Length();
	int Capacity();
	const int* Storage();
private:
	void init(const int *array, int length, int least_capacity);
	void clean();
	void reserve(int capacity);
	int* _storage;
	int _length;
	int _capacity;
};