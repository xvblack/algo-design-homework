#include "headers.h"

#define M 1024*1024
#define K 1024

namespace Test{
	bool initiliazed=false;
	int* storage;
	const int length=100*K;
}

template<typename T,int test_size>
class ArrayTest{
public:
	ArrayTest(){
		if (!Test::initiliazed){
			Test::initiliazed=true;
			Test::storage=new int[Test::length];
			for (int i=0;i<Test::length;i++){
				Test::storage[i]=std::rand();
			}
		}
		_storage=T();
	}
	int Test(int x){
		_storage.Reset();
		clock_t start = clock(), diff;
		try{
			while(_storage.Length()<test_size*M){
				for (int i=0;i<2*x;i++){
					_storage.Push(Test::storage[i%Test::length]);
				}
				for (int i=0;i<x;i++){
					_storage.Pop();
				}
			}
		}catch(const std::bad_alloc&){
			return 0;
			_storage.Reset();
		}
		diff=clock()-start;
		int msec=diff*1000/CLOCKS_PER_SEC;
		//std::cout<<"used " << msec << "milliseconds" << std::endl ;
		return msec;
		_storage.Reset();
	}
private:
	int _length;
	T _storage;
};