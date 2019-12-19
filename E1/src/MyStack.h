#pragma once
#include <string>

using namespace std;

class MyStack
{
private:

	int *base=nullptr;
	int size=0;

public:

	void push(int element);
	int pop();
	string toString();
	int getSize();
	void copy(MyStack *dest);
	MyStack();
	~MyStack();
	void clear();
};

