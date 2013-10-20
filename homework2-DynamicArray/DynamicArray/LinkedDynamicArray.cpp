// Licensed in GPL v3
// Copyright 2013-2013 xvblack

#include "LinkedDynamicArray.h"

// initialization

LinkedDynamicArray::LinkedDynamicArray(){
	init(nullptr,0,DEFAULT_CAPACITY);
}


LinkedDynamicArray::LinkedDynamicArray(const int* array, int length){
	init(array,length,DEFAULT_CAPACITY);
}

LinkedDynamicArray::LinkedDynamicArray(const int* array, int length, int capacity){
	init(array,length,least_two_power(capacity));
}

void LinkedDynamicArray::init(const int* array, int length, int least_capacity){
	_length=length;
	_capacity=least_capacity>length ? least_capacity : least_two_power(length);
	_storage_head=new LinkedNode;
	_storage_head->storage=new int[_capacity];
	_storage_head->length=_capacity;
	_storage_head->next=nullptr;
	std::memset(_storage_head->storage,0,sizeof(int)*_capacity);
	std::memcpy(_storage_head->storage,array,sizeof(int)*_length);
	_storage_end=_storage_head;
}

LinkedDynamicArray::~LinkedDynamicArray(){
	clean();
}

void LinkedDynamicArray::clean(){
	LinkedNode* iter=_storage_head,*iterr;
	while (iter!=nullptr) {
		iterr=iter;
		delete iter->storage;
		iter=iter->next;
		delete iterr;
	}
	_length=0;
	_capacity=0;
}

void LinkedDynamicArray::Reset(){
	clean();
	init(nullptr,0,DEFAULT_CAPACITY);
}

void LinkedDynamicArray::reserve_additional(int capacity){
	//std::cout<< "allocing " << capacity << std::endl;
	if (capacity==0) return;
	LinkedNode* new_storage=new LinkedNode;
	new_storage->storage=new int[capacity];
	new_storage->next=nullptr;
	new_storage->length=capacity;
	_storage_end->next=new_storage;
	_storage_end=new_storage;
	_capacity+=capacity;
}

void LinkedDynamicArray::Append(int num){
	if (_length==_capacity){
		reserve_additional(_capacity);
	}
	LinkedNode* iter=_storage_head;
	int length=_length;
	while(iter->next!=nullptr){
		length-=iter->length;
		iter=iter->next;
	}
	iter->storage[length]=num;
	_length++;
}

void LinkedDynamicArray::Push(int num){
	Append(num);
}

int LinkedDynamicArray::Pop(){
	_length--;
	int result=Get(_length);
	return result;
}

int LinkedDynamicArray::Get(int i){
	LinkedNode* iter=_storage_head;
	while (i>=iter->length){
		i-=iter->length;
		iter=iter->next;
	}
	return iter->storage[i];
}

int LinkedDynamicArray::Length(){
	return _length;
}

int LinkedDynamicArray::Capacity(){
	return _capacity;
}

void LinkedDynamicArray::CleanUpto(int i){
	LinkedNode* iter=_storage_head,*iterr;
	_length-=i;
	_capacity=_capacity-i;
	while (i>=iter->length){
		iterr=iter;
		i-=iter->length;
		iter=iter->next;
		delete iterr->storage;
		delete iterr;
	}
	LinkedNode* new_storage=new LinkedNode;
	new_storage->storage=new int[iter->length-i];
	new_storage->length=iter->length-i;
	new_storage->next=iter->next;
	memcpy(new_storage->storage,iter->storage+i,iter->length-i);
	_storage_head=new_storage;
}

const int* LinkedDynamicArray::Storage(){return nullptr;}