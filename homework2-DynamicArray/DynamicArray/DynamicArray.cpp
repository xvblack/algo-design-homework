// Licensed in GPL v3
// Copyright 2013-2013 xvblack

#include "DynamicArray.h"

// initialization

int least_two_power(int length){
	int result=0;
	while(length >>= 1) result++;
	return 1<<(result+1);
}

DynamicArray::DynamicArray(){
	init(nullptr,0,DEFAULT_CAPACITY);
}


DynamicArray::DynamicArray(const int* array, int length){
	init(array,length,DEFAULT_CAPACITY);
}

DynamicArray::DynamicArray(const int* array, int length, int capacity){
	init(array,length,least_two_power(capacity));
}

void DynamicArray::init(const int* array, int length, int least_capacity){
	_length=length;
	_capacity=least_capacity>length ? least_capacity : least_two_power(length);
	_storage=new int[_capacity];
	std::memset(_storage,0,sizeof(int)*_capacity);
	std::memcpy(_storage,array,sizeof(int)*_length);
}

DynamicArray::~DynamicArray(){
	clean();
}

void DynamicArray::clean(){
	delete _storage;
	_length=0;
	_capacity=0;
}

void DynamicArray::Reset(){
	clean();
	init(nullptr,0,DEFAULT_CAPACITY);
}

void DynamicArray::reserve(int capacity){
	//std::cout<< "allocing " << capacity << std::endl;
	if (_capacity>capacity) return;
	int* new_storage=new int[capacity];
	memcpy(new_storage,_storage,sizeof(int)*_length);
	delete _storage;
	_storage=new_storage;
	_capacity=capacity;
}

void DynamicArray::Append(int num){
	if (_length==_capacity){
		reserve(2*_capacity);
	}
	_storage[_length]=num;
	_length++;
}

void DynamicArray::Push(int num){
	Append(num);
}

void DynamicArray::Extend(DynamicArray right){
	if (_length+right.Length()>_capacity){
		reserve(least_two_power(_length+right.Length()));
	}
	memcpy(_storage+sizeof(int)*_length,right.Storage(),right.Length());
}

int DynamicArray::Pop(){
	_length--;
	int result=Get(_length);
	return result;
}

int DynamicArray::Get(int i){
	return _storage[i];
}

int DynamicArray::Length(){
	return _length;
}

int DynamicArray::Capacity(){
	return _capacity;
}

const int* DynamicArray::Storage(){
	return (const int*)_storage;
}