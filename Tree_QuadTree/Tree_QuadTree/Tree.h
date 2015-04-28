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
	
	//I got this idea from your repository because i wanted to have an easy identifier for each tNode, i mean, to ideantify each tNode by their content. 
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
	
	/*
	Recursive order functions
	*/
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
	
	/*
	Add
	*/
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
	
	/*
	Recursive order functions
	*/
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
	
	/*
	Iterative order functions
	*/
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
		cStack<tNode<TYPE>*> sonStack;
		tNode<TYPE>* node = rootNode;
		Node<tNode<TYPE>*>* tmp;

		while (node != NULL)
		{
			tmp = node->sons.start;
			stack.Push(node);
			
			while (tmp != NULL)
			{
				sonStack.Push(tmp->value);
				tmp = tmp->next;
			}
			sonStack.Pop(node);
		}

		stack.Pop(node);
		while (node != NULL)
		{
			list->Add(node);
			stack.Pop(node);
		}
	}

	void InOrderIterative(cDlist<tNode<TYPE>*>* list) const
	{
		cStack<tNode<TYPE>*> stack;
		cStack<tNode<TYPE>*> stack2;
		tNode<TYPE>* node = rootNode;
		Node<tNode<TYPE>*>* tmp;
		
		while (node != NULL)
		{
			int counter = node->sons.GetCapacity();
			tmp = node->sons.end;
			
			while (tmp != NULL && counter > node->sons.GetCapacity()/2)
			{
				stack.Push(tmp->value);
				
				tmp = tmp->prev;
				counter--;
			}
			
			stack.Push(node);
			stack2.Push(node);
			
			while (tmp != NULL && counter > 0)
			{
				stack.Push(tmp->value);

				tmp = tmp->prev;
				counter--;
			}

			while (stack.PeekLast() == stack2.PeekLast() && stack.PeekLast() != NULL)
			{
				stack.Pop(node);
				stack2.Pop(node);
				list->Add(node);
			}
			
			stack.Pop(node);
		}
	}

	/*
	Clear
	*/
	void Clear(const TYPE& node)
	{
		tNode<TYPE>* delNode = rootNode->FindRecursive(node);
		Node<tNode<TYPE>*>* tmp;
		Node<tNode<TYPE>*>* tmp2;
		unsigned int counter = 0;

		if (delNode == NULL && rootNode != NULL)
		{
			delNode = rootNode;
		}

		if (delNode != NULL)
		{
			tmp = delNode->sons.start;

			if (tmp != NULL)
			{
				while (counter < delNode->sons.GetCapacity())
				{
					tmp2 = tmp;
					Clear(tmp->value->data);
					tmp = tmp2->next;
					
					counter++;
				}
			}
			tmp = delNode->father->sons.start;
			delNode->father->sons.Delete(tmp);
		}
		if (delNode == rootNode)
		{
			rootNode =  NULL;
		}
	}
};

#endif _TREE_H_<