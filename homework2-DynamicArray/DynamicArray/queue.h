// Licensed in GPL v3
// Copyright 2013-2013 xvblack

#include "headers.h"
#include "DynamicArray.h"
#include "LinkedDynamicArray.h"

#define RECYCLE_N 30000000
#define QUEUE_RECYCLE true


template<typename T,bool queue_recycle=false>
class Queue{
public:
	Queue(){
		_start=0;
		_end=0;
		_storage=new T;
	}
	void Push(int i){
		_storage->Push(i);
		_end++;
		/*
		if (_storage->Length()==_storage->Capacity()){
			drecycle();
		}
		*/
		if ((_start>RECYCLE_N)&&queue_recycle&&_storage->Storage()!=nullptr){
			recycle();
		}
		/**/
	}
	int Pop(){
		if (_start==_end) throw 0;
		int result=_storage->Get(_start);
		_start++;
		return result;
	}
	int Length(){
		return _end-_start;
	}
	void Reset(){
		_storage->Reset();
		_start=0;
		_end=0;
	}
private:
	void recycle(){
		std::cout << "RECYCLING";
		T* new_storage=new T(_storage->Storage()+_start,_end-_start);
		delete _storage;
		_storage=new_storage;
		int length=_end-_start;
		_start=0;
		_end=length;
	}
	void drecycle(){
		std::cout << "RECYCLE and DOUBLE CAPACITY" << std::endl;
		T* new_storage=new T(_storage->Storage()+_start,_end-_start,_storage->Capacity()+1);
		delete _storage;
		_storage=new_storage;
		int length=_end-_start;
		_start=0;
		_end=length;
	}
	T* _storage;
	int _start,_end;
};