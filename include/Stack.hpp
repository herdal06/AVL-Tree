#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
using namespace std;

class Stack
{
private:
	int *items;
	int head;
	int length;
	int capacity;
	bool IsFull();
	void Reserve(int);
public:
	Stack();
	bool IsEmpty() const;
	void Push(const int&);
	void Pop();
	const int &Top() const;
	void Clear();
	~Stack();
    void display();
};
#endif