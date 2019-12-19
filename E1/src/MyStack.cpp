#include "pch.h"
#include "MyStack.h"


void MyStack::push(int element)
{
	if (!size)
	{
		size++;
		base = new int[1];
		*base = element;
	}
	else
	{
		size++;
		int *temp = new int[size];
		int *base_buff = base;
		int *temp_buff = temp;

		for (int i = 0; i < size - 1; i++)
		{
			*temp_buff = *base_buff;
			temp_buff++;
			base_buff++;
		}

		*temp_buff = element;

		delete [] base;

		base = temp;
	}
}

int MyStack::pop()
{
	int peak;
	
	if (size > 1)
	{
		size--;
		peak = *(base + size);
		
		int *temp= new int[size];
		int *base_buff=base;
		int *temp_buff = temp;

		for (int i = 0; i < size; i++)
		{
			*temp_buff = *base_buff;
			base_buff++;
			temp_buff++;
		}

		delete [] base;
		base = temp;

		return peak;
	}
	else if (size == 1)
	{
		peak = *base;
		size = 0;

		delete [] base;
		base = nullptr;
		
		return peak;
	}
	else
	{
		return -1;
	}
}

string MyStack::toString()
{
	string msg = "";
	int *base_buff = base;

	if (!size)
	{
		msg = "Stos pusty";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			msg = msg + to_string(*base_buff) + " ";
			base_buff++;
		}		
	}

	return msg;
}

MyStack::MyStack()
{

}

MyStack::~MyStack()
{
	if (base != nullptr)
	{
		delete[] base;
	}
}

void MyStack::clear()
{
	delete[]base;
	base = nullptr;
	size = 0;
}

int MyStack::getSize()
{
	return size;
}

void MyStack::copy(MyStack *dest)
{
	int *base_buff = base;

	dest->clear();

	if (size)
	{
		for (int i = 0; i < size; i++)
		{
			dest->push(*base_buff);
			base_buff++;
		}
	}
}
