#pragma once
#include "pch.h"
#include <iostream>
#include<memory>
using namespace std;

template <typename ElemType>
struct Stack
{
	ElemType *items;//元素
	int capacity;	//容量
	int top;		//栈顶下标（栈顶指针）
	Stack(int c = 10)
	{
		top = 0;
		capacity = c;
		items = new ElemType[capacity];//申请栈空间
	}
	~Stack()
	{
		delete[]items;
	}
	void output()
	{
		for (int i = 0; i < top; i++)
			cout << items[i] << " ";
		cout << endl;
	}
	void resize(int c)
	{
		capacity = c;
		ElemType *newdata = new ElemType[capacity];
		if (items != NULL)
		{
			memcpy(newdata, items, top * sizeof(ElemType));
			delete[]items;
		}
		items = newdata;
	}
	void push(ElemType e)
	{
		if (top == capacity)
			resize(capacity * 2);
		items[top++] = e;
	}
	ElemType peek()	//取栈顶元素，但不出栈
	{
		if (top == 0)
			throw 1;
		return items[top - 1];
	}
	ElemType pop()
	{
		if (top == 0)
			throw 1;
		top--;
		ElemType e = items[top];
		return e;
	}
};