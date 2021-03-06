#pragma once
#include "Call.h"
const int MAXIMUM_SIZE = 2;
class HeapType
{
private:
	Call* calls = nullptr;
	int queuedCallsSize = 0;
	int queuedCallsMaxSize = MAXIMUM_SIZE;
public:
	HeapType();
	~HeapType();
	void ReheapDown(int, int);
	void ReheapUp(int, int);
	void swap(Call&, Call&);
	void enqueue(Call);
	void dequeue(Call&);
	bool is_empty();
	bool is_full();
	int get_size();
	void make_empty();
	bool hasNextCall();
	Call* increased_array(Call*,int);
};