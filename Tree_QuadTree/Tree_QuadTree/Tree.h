#ifndef _TREE_H_
#define _TREE_H_

#include <stdlib.h>
#include "Dlist.h"
#include "Stack.h"
template <class TYPE>
class tNode
{
	TYPE data;
	tNode* father;//el node previ, el pare
	cDlist<tNode*> sons;//els nodes segueents, ramificacions, els fills

	//Constructors
	tNode() : data(0), father(NULL){};
	tNode(TYPE& newValue) : data(newValue), father(NULL){};
	tNode(TYPE& newValue, tNode* dad) : data(newValue), father(dad){};

	//Functions that gets all the nodes (recursive)
	//fer apunts dels diferents tipus d'ordentacio perque no m'he enterat a casa
	//amb l'arbre fet a clase  la preOrder dona: F,B,A,D,C,E,G,I,H (per montarla)
	//fer les mateixers funcions per iteratives (s'ha d'utilitzar una pila)
	void PreOrderRecursive(cDlist<tNode<TYPE>*>* list)
	{
		list->Add(this);
		Node<tNode*>* item = sons.start;


		while (item != NULL)
		{
			tNode->PreOrderRecursive(list);
			item = item->next;
		}
	}

	void PostOrderRecursive(cDlist<tNode<TYPE>*>* list)
	{

		Node<tNode*>* item = sons.start;

		while (item != NULL)
		{
			tNode->PostOrderRecursive(list);
			item = item->next;
		}
		list->Add(this);
	}

	void InOrderRecursive(cDlist<tNode<TYPE>*>* list)
	{
		Node<tNode*>* item = sons.start;
		unsigned int counter = 0;

		while (item != NULL && counter != sons.GetCapacity() / 2)
		{
			tNode->InOrderRecursive(list);
			item = item->next;
			counter++;
		}
		list->Add(this);
		while (item != NULL)
		{
			tNode->InOrderRecursive(list);
			item = item->next;
		}
	}
};

template <class TYPE>
class Tree
{
	/*
	//Atributes
	*/
public:
	tNode* rootNode;

	/*
	//Methods
	*/

	//Constructor and Destructor
	Tree(const TYPE& value)
	{
		rootNode->data = value;
	}

	~Tree()
	{

	}

	//Add
	tNode<TYPE>* Add(const TYPE& newData)
	{
		tNode<TYPE>* newNode = new tNode(newData);

		rootNode->sons->Add(newNode);
		newNode->father = rootNode;

		return newNode;
	}

	tNode<TYPE>* Add(const TYPE& newData, const TYPE& dad)
	{
		tNode<TYPE>* newNode = new tNode(newData);
		tNode<TYPE>* parent = GetNode(dad);

		parent->sons->Add(newNode);
		newNode->father = parent;

		return newNode;
	}

	//Function that returns all the nodes (recursive)
	void PreOrderRecursive(cDlist<tNode<TYPE>*>* list) const
	{
		root.PreOrderRecursive(list);
	}

	void PostOrderRecursive(cDlist<tNode<TYPE>*>* list) const
	{
		root.PostOrderRecursive(list);
	}

	void InOrderRecursive(cDlist<tNode<TYPE>*>* list) const
	{
		root.InOrderRecursive(list) const;
	}

	//Function that returns all the nodes (iterative)
	void PreOrderIterative(cDlist<tNode<TYPE>*>* list) const
	{
		cStack<tNode<TYPE*>*> stack;
		tNode<TYPE>* node = &rootNode;
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
			else()
			{
				node = NULL;
				pop.stack(node);
			}
		}
	}

	void PostOrderIterative(cDlist<tNode<TYPE>*>* list) const
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
	}*/

	tNode<TYPE>* GetNode(const TYPE& nodeData) const
	{
		cDlist<tNode<TYPE>*>* list;

		PreOrderIterative(list);

		Node<tNode<TYPE>*>* node = list->start;
		tNode<TYPE>* tmp;

		while (node != NULL)
		{
			tmp = node->value

				if (tmp->data = nodeData)
					return tmp;

			node = node->next;
		}
		return NULL;
	}


};





#endif _TREE_H_<