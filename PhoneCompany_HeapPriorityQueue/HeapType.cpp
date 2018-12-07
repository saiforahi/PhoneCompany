#include "HeapType.h"



HeapType::HeapType()
{
	calls = new Call[queuedCallsMaxSize];
	queuedCallsSize = 0;
}


HeapType::~HeapType()
{
	delete[]calls;
}

void HeapType::ReheapDown(int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (calls[leftChild].get_relationship() >= calls[rightChild].get_relationship())
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (calls[root].get_relationship() > calls[maxChild].get_relationship()) {
			swap(calls[root], calls[maxChild]);
			ReheapDown(maxChild, bottom);
		}
		else if (calls[root].get_relationship() == calls[maxChild].get_relationship()) {
			if (calls[root].get_durationInSeconds() < calls[maxChild].get_durationInSeconds())
			{
				swap(calls[root], calls[maxChild]);
				ReheapDown(maxChild, bottom);
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
		if (calls[bottom].get_durationInSeconds() > calls[root].get_durationInSeconds()) {
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
