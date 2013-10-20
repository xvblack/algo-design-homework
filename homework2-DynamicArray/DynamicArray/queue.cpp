#include "queue.h"

Queue::Queue():_storage(storage){}

void Queue::Push(int i){
	_storage->Push(i);
	_end++;
}

int Queue::Pop(){
	if (_start==_end) throw 0;
	_start++;
	return _storage->Get(_start-1);
}