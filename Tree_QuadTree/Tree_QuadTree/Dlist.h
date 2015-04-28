#ifndef _DLIST_H_
#define _DLIST_H_

#include <stdlib.h>

template<class TYPE>
struct Node
{
	TYPE value;
	Node<TYPE>* next;
	Node<TYPE>* prev;

	inline Node<TYPE>(const TYPE& _value)
	{
		value = _value;
		next = prev = NULL;
	}
};

template<class TYPE>
class cDlist
{

public:

	Node<TYPE>* start;
	Node<TYPE>* end;//with the end it goes faster

private:

	unsigned int size;

public:
	/*
	Constructor
	*/
	inline cDlist()
	{
		start = end = NULL;
		size = 0;
	}
	/*
	Destructor
	*/
	~cDlist()
	{
		Clear();
	}

	/*
	Methods
	*/
	//Add
	void Add(const TYPE& newValue)
	{
		Node<TYPE>* newNode;
		newNode = new Node<TYPE>(newValue);

		if (start == NULL)
		{
			start = end = newNode;
		}
		else
		{
			end->next = newNode;
			newNode->prev = end;
			end = newNode;
		}

		size++;
		
	}

	bool Delete(Node<TYPE>* delNode)
	{
		if (delNode == NULL)
		{
			return (false);
		}

		if (delNode != start)
		{
			delNode->prev->next = delNode->next;

			if (delNode != end)
			{
				delNode->next->prev = delNode->prev;
			}
			else
			{
				end = delNode->prev;
			}
		}
		else
		{
			if (delNode != end)
			{
				delNode->next->prev = NULL;
				start = delNode->next;
			}
			else
			{
				end = start = NULL;
			}
		}

		delete[] delNode;
		size--;
		return (true);
	}

	void Clear()
	{
		Node<TYPE>* tmp = start;
		Node<TYPE>* tmp2;

		while (tmp != NULL)
		{
			tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}

		start = end = NULL;

		size = 0;
	}
	/*
	other utils
	*/

	unsigned int GetCapacity() const
	{
		return size;
	}

	Node<TYPE>* GetFirst() const
	{
		return start;
	}

	Node<TYPE>* GetLast() const
	{
		return end;
	}

	Node<TYPE>* GetByIndex(const unsigned int index) const
	{
		Node<TYPE>* tmp = start;
		unsigned int counter = 0;

		while (counter != index && tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}

		if (tmp != NULL)
			return tmp;

		return NULL;
	}

	/*
	operator
	*/
	TYPE& operator  [](const unsigned int index)
	{
		long                  pos;
		Node<TYPE>*   tmp;
		pos = 0;
		tmp = start;

		while (tmp != NULL)
		{
			if (pos == index)
			{
				break;
			}

			++pos;
			tmp = tmp->next;
		}

		return(tmp->value);
	}

	/*
	Method for the exercise 3
	*/
	unsigned int delNodes(const unsigned int index, const unsigned int delSize)
	{
		Node<TYPE>* tmp = GetByIndex(index);
		Node<TYPE>* tmp2;

		unsigned int counter = 0;

		while (counter != delSize && tmp != NULL)
		{
			tmp2 = tmp->next;
			Delete(tmp);
			tmp = tmp2;

			counter++;
		}

		return counter;
	}
};

#endif // !_DLIST_H_