#include "headers.h"

class LinkedDynamicArray{
public:
	typedef struct LinkedNode{
		LinkedNode* next;
		int* storage;
		int length;
	} LinkedNode;
	LinkedDynamicArray();
	LinkedDynamicArray(const int* array, int length);
	LinkedDynamicArray(const int* array, int length, int capacity);
	~LinkedDynamicArray();
	void Reset();
	void Append(int);
	void Push(int);
	int Pop();
	int Get(int);
	int Length();
	int Capacity();
	void CleanUpto(int i);
	const int* Storage();
private:
	void init(const int *array, int length, int least_capacity);
	void clean();
	void reserve_additional(int capacity);
	LinkedNode* _storage_head;
	LinkedNode* _storage_end;
	int _length;
	int _capacity;
};