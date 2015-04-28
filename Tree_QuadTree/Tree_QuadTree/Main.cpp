#include "Dlist.h"
#include "Stack.h"
#include "Tree.h"



int main(int argc, char** argv)
{
	Tree<char> tree('F');

	tree.Add('B', 'F');
	tree.Add('G', 'F');
	tree.Add('A', 'B');
	tree.Add('D', 'B');
	tree.Add('C', 'D');
	tree.Add('E', 'D');
	tree.Add('I', 'G');
	tree.Add('H', 'I');

	cDlist<tNode<char>*> list;
	tree.PostOrderIterative(&list);

}