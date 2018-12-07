#include "HeapType.h"
#include <iostream>
using namespace std;


HeapType::HeapType()
{
	calls = new Call[queuedCallsMaxSize];
	queuedCallsSize = 0;
}


HeapType::~HeapType()
{
	queuedCallsSize = 0;
}

void HeapType::ReheapDown(int root, int bottom)
{
	int minChild;
	int rightChild;
	int leftChild;
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			minChild = leftChild;
		else
		{
			if (calls[leftChild].get_relationship() < calls[rightChild].get_relationship())
				minChild = leftChild;
			else if (calls[leftChild].get_relationship() == calls[rightChild].get_relationship())
			{
				if (calls[leftChild].get_durationInSeconds() < calls[rightChild].get_durationInSeconds())
				{
					minChild = rightChild;
				}
				else
					minChild = leftChild;
			}
			else
				minChild = rightChild;
		}
		if (calls[root].get_relationship() > calls[minChild].get_relationship()) {
			swap(calls[root], calls[minChild]);
			ReheapDown(minChild, bottom);
		}
		else if (calls[root].get_relationship() == calls[minChild].get_relationship()) {
			if (calls[root].get_durationInSeconds() < calls[minChild].get_durationInSeconds())
			{
				swap(calls[root], calls[minChild]);
				ReheapDown(minChild, bottom);
			}
		}
	}
}

void HeapType::ReheapUp(int root, int bottom)
{
	int parent = (bottom - 1) / 2;
	if (parent < root)
		return;
	else if (calls[parent].get_relationship() > calls[bottom].get_relationship())
	{
		swap(calls[parent], calls[bottom]);
		ReheapUp(root, parent);
	}
	else if (calls[bottom].get_relationship() == calls[parent].get_relationship())
	{
		if (calls[bottom].get_durationInSeconds() > calls[parent].get_durationInSeconds()) {
			swap(calls[parent], calls[bottom]);
			ReheapUp(root, parent);
		}
	}
}

void HeapType::swap(Call & one, Call & two)
{
	Call temp;
	temp = one;
	one = two;
	two = temp;
}

void HeapType::enqueue(Call newCall)
{
	if (is_full())
	{
		cout << "List is full" << endl;

	}
	else {
		queuedCallsSize++;
		calls[queuedCallsSize - 1] = newCall;
		ReheapUp(0, queuedCallsSize - 1);
	}
}

void HeapType::dequeue(Call &dequeuedCall)
{
	if (is_empty())
		cout << "no call to dequeue" << endl;
	else {
		dequeuedCall = calls[0];
		calls[0] = calls[queuedCallsSize - 1];
		queuedCallsSize--;
		ReheapDown(0, queuedCallsSize - 1);
	}
}

bool HeapType::is_empty()
{
	return queuedCallsSize == 0;
}

bool HeapType::is_full()
{
	return queuedCallsSize >= queuedCallsMaxSize;
}

int HeapType::get_size()
{
	return queuedCallsSize;
}

void HeapType::make_empty()
{
	queuedCallsSize = 0;
}

bool HeapType::hasNextCall()
{
	return queuedCallsSize >= 1;
}
