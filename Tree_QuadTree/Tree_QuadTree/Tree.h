#ifndef _TREE_H_
#define _TREE_H_

#include <stdlib.h>
#include "Dlist.h"
#include "Stack.h"
template <class TYPE>
class tNode
{
public:
	TYPE data;
	tNode* father;
	cDlist<tNode*> sons;

public:
	//Constructors
	tNode(const TYPE& newValue)
	{
		data = newValue;
		father = NULL;
	}
	
	tNode<TYPE>* FindRecursive(const TYPE& node)
	{
		if (node == data)
			return this;

		tNode<TYPE>* ret = NULL;
		Node<tNode<TYPE>*>* tmp = sons.start;
		while (tmp != NULL)
		{
			tNode<TYPE>* son = tmp->value;
			ret = son->FindRecursive(node);

			if (ret != NULL)
				break;

			tmp = tmp->next;
		}

		return ret;
	}
	
	void PreOrderRecursive(cDlist<tNode<TYPE>*>* list)
	{
		list->Add(this);
		Node<tNode<TYPE>*>* node = sons.start;


		while (node != NULL)
		{
			node->value->PreOrderRecursive(list);
			node = node->next;
		}
	}

	void PostOrderRecursive(cDlist<tNode<TYPE>*>* list)
	{

		Node<tNode<TYPE>*>* node = sons.start;

		while (node != NULL)
		{
			node->value->PostOrderRecursive(list);
			node = node->next;
		}
		list->Add(this);
	}

	void InOrderRecursive(cDlist<tNode<TYPE>*>* list)
	{
		Node<tNode<TYPE>*>* node = sons.start;
		unsigned int counter = 0;

		while (node != NULL && counter != sons.GetCapacity() / 2)
		{
			node->value->InOrderRecursive(list);
			node = node->next;
			counter++;
		}
		list->Add(this);
		while (node != NULL)
		{
			node->value->InOrderRecursive(list);
			node = node->next;
		}
	}
};

template <class TYPE>
class Tree
{
public:
	tNode<TYPE>* rootNode;
	
public:
	Tree(const TYPE& value)
	{
		tNode<TYPE>* root = new tNode<TYPE>(value);
		rootNode = root;
	}

	~Tree()
	{

	}
	
	//Add
	tNode<TYPE>* Add(const TYPE& newData)
	{
		tNode<TYPE>* newNode = new tNode<TYPE>(newData);

		rootNode->sons.Add(newNode);
		newNode->father = rootNode;

		return newNode;
	}

	tNode<TYPE>* Add(const TYPE& newData, const TYPE& dad)
	{
		tNode<TYPE>* parent = rootNode->FindRecursive(dad);
		tNode<TYPE>* newNode = new tNode<TYPE>(newData);

		parent->sons.Add(newNode);
		newNode->father = parent;

		return newNode;
	}
	
	//Function that returns all the nodes (recursive)
	void PreOrderRecursive(cDlist<tNode<TYPE>*>* list) const
	{
		rootNode->PreOrderRecursive(list);
	}

	void PostOrderRecursive(cDlist<tNode<TYPE>*>* list) const
	{
		rootNode->PostOrderRecursive(list);
	}

	void InOrderRecursive(cDlist<tNode<TYPE>*>* list) const
	{
		rootNode->InOrderRecursive(list);
	}
	
	//Function that returns all the nodes (iterative)
	void PreOrderIterative(cDlist<tNode<TYPE>*>* list) const
	{
		cStack<tNode<TYPE>*> stack;
		tNode<TYPE>* node = rootNode;
		Node<tNode<TYPE>*>* tmp;

		while (node != NULL)
		{
			list->Add(node);

			tmp = node->sons.end;

			while (tmp != node->sons.start)
			{
				stack.Push(tmp->value);
				tmp = tmp->prev;
			}

			if (tmp != NULL)
			{
				node = tmp->value;
			}
			else
			{
				node = NULL;
				stack.Pop(node);
			}
		}
	}
	
	void PostOrderIterative(cDlist<tNode<TYPE>*>* list) const
	{
		cStack<tNode<TYPE>*> stack;
		tNode<TYPE>* node = rootNode;
		Node<tNode<TYPE>*>* tmp;

		while (node != NULL)
		{
			tmp = node->sons.end;

			if (tmp != NULL && list->end->value != tmp->value)
			{
				first = false;

				stack.Push(node);

				while (tmp != node->sons.start)
				{
					stack.Push(tmp->value);
					tmp = tmp->prev;
				}

				node = tmp->value;
			}
			else
			{
				list->Add(node);
				stack.Pop(node);
			}

		}
	}

	/*void InOrderIterative(cDlist<tNode<TYPE>*>* list) const
	{
	cStack<tNode<TYPE*>*> stack;
	tNode<TYPE>* node = &rootNode;
	Node<tNode<TYPE>*>* tmp;
	while (Node != NULL)
	{
	tmp = node->sons.end;
	if (tmp != NULL && list->end != tmp->value)
	{
	stack.Push(Node);
	while (tmp != node->sons.start)
	{
	stack.Push(tmp->value);
	tmp = tmp->prev;
	}
	node = tmp->value;
	}
	else
	{
	list.add(node);
	stack.Pop(node);
	}
	}
	}
	*/
};





#endif _TREE_H_<