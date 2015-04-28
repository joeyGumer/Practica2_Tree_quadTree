#ifndef _STACK_H_
#define _STACK_H_

#include <assert.h>
#include <stdlib.h>

#define DYN_ARRAY_BLOCK_SIZE 16

template<class TYPE>
class cStack
{

private:

	TYPE* data;
	unsigned int allocMemory;
	unsigned int numElements;

public:

	//Constructors
	cStack() : data(NULL), allocMemory(0), numElements(0)
	{
		Reallocate(DYN_ARRAY_BLOCK_SIZE);
	}
	cStack(const unsigned int memSize) : data(NULL), allocMemory(0), numElements(0)
	{
		Reallocate(memSize);
	}

	//Destructors
	~cStack()
	{
		delete[] data;
	}

	//Methods

	//Changes the stack size
	void Reallocate(const unsigned int newSize)
	{
		TYPE* tmp = data;

		allocMemory = newSize;
		data = new TYPE[newSize];
		if (newSize < numElements)
		{
			numElements = newSize;
		}

		for (unsigned int i = 0; i < numElements; i++)
		{
			data[i] = tmp[i];
		}

	};

	//Puts an element at the end of the stack
	void Push(const TYPE newElement)
	{
		if (numElements >= allocMemory)
		{
			Reallocate(allocMemory + DYN_ARRAY_BLOCK_SIZE);
		}
		data[numElements] = newElement;
		numElements++;
	}

	//Puts out the last element
	bool Pop(TYPE& value)
	{
		if (numElements > 0)
		{
			value = data[--numElements];
			return true;
		}
		else
			value = NULL;
		
		return false;
	}

	//Chooses an element from the stack
	const TYPE* Peek(const unsigned int index)const
	{
		TYPE* ret = NULL;

		if (index < numElements)
			return ret = &data[index];

		return ret;
	}

	const TYPE PeekLast() const
	{
		if (numElements >= 1)
		{
			return data[numElements - 1];
		}
		return NULL;
	}
	//other util methods
	unsigned int GetCapacity() const
	{
		return allocMemory;
	}

	unsigned int Count() const
	{
		return numElements;
	}

	void Clear()
	{
		numElements = 0;
	}


};

#endif // !_STACK_H_