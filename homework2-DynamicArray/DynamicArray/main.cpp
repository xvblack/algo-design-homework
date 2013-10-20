// Licensed in GPL v3
// Copyright 2013-2013 xvblack

#include "queue.h"
#include "test.h"

#define TEST(T)\
	int x[]={1,10,100,1000,10000,100000};\
	std::cout<< #T << std::endl;\
	for (int i=0;i<6;i++){\
		std::cout << "for K=" << x[i] << " " << "used " << T.Test(x[i])<<" ms " << std::endl;	\
	}\
	std::cout<<std::endl;

int main(){
	LinkedDynamicArray a;
	ArrayTest<Queue<DynamicArray>,10> t1;
	ArrayTest<Queue<DynamicArray,QUEUE_RECYCLE>,10> t2;
	ArrayTest<Queue<DynamicArray>,50> t3;
	ArrayTest<Queue<DynamicArray,QUEUE_RECYCLE>,50> t4;
	ArrayTest<Queue<DynamicArray>,100> t5;
	ArrayTest<Queue<DynamicArray,QUEUE_RECYCLE>,100> t6;
	ArrayTest<Queue<LinkedDynamicArray>,10> t7;
	ArrayTest<Queue<LinkedDynamicArray>,50> t8;
	ArrayTest<Queue<LinkedDynamicArray>,100> t9;
	//ArrayTest<Queue<LinkedDynamicArray,QUEUE_RECYCLE>,100> t10;
	TEST(t6)
	std::cout<<"ended";
	int i;
	std::cin >> i;
}