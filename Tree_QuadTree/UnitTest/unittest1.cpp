#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Tree_QuadTree\Tree.h"
#include "..\Tree_QuadTree\Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		// TREE -------------------------------------------
		TEST_METHOD(TreeAdd)
		{
			Tree<int> tree(1);

			Assert::AreEqual((int)tree.rootNode->data, 1);
			
			tree.Add(2);
			tree.Add(3);

			Assert::AreEqual((int)tree.rootNode->sons.start->value->data, 2);
			Assert::AreEqual((int)tree.rootNode->sons.end->value->data, 3);
			
			tree.Add(4, 2);
			tree.Add(5, 2);

			Assert::AreEqual((int)tree.rootNode->sons.start->value->sons.start->value->data, 4);
			Assert::AreEqual((int)tree.rootNode->sons.start->value->sons.end->value->data, 5);
		}
		
		TEST_METHOD(TreePreOrder)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('X', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			cDlist<tNode<char>*> list;
			tree.PreOrderRecursive(&list);

			Assert::AreEqual((int)list.GetCapacity(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		
		TEST_METHOD(TreePostOrder)
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
			tree.PostOrderRecursive(&list);

			Assert::AreEqual((int)list.GetCapacity(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(TreeInOrder)
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
			tree.InOrderRecursive(&list);

			Assert::AreEqual((int)list.GetCapacity(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');

			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}
		
		TEST_METHOD(TreePreOrderIterative)
		{
		Tree<char> tree('F');

		tree.Add('B', 'F');
		tree.Add('G', 'F');
		tree.Add('A', 'B');
		tree.Add('D', 'B');
		tree.Add('X', 'B');
		tree.Add('C', 'D');
		tree.Add('E', 'D');
		tree.Add('I', 'G');
		tree.Add('H', 'I');

		cDlist<tNode<char>*> list;

		tree.PreOrderIterative(&list);
		
		Assert::AreEqual((int)list.GetCapacity(), 10);

		Assert::AreEqual((char)list[0]->data, 'F');
		Assert::AreEqual((char)list[1]->data, 'B');
		Assert::AreEqual((char)list[2]->data, 'A');
		Assert::AreEqual((char)list[3]->data, 'D');
		Assert::AreEqual((char)list[4]->data, 'C');
		Assert::AreEqual((char)list[5]->data, 'E');
		Assert::AreEqual((char)list[6]->data, 'X');
		Assert::AreEqual((char)list[7]->data, 'G');
		Assert::AreEqual((char)list[8]->data, 'I');
		Assert::AreEqual((char)list[9]->data, 'H');
		}
		
		TEST_METHOD(TreePostOrderIterative)
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

		Assert::AreEqual((int)list.GetCapacity(), 9);

		Assert::AreEqual((char)list[0]->data, 'A');
		Assert::AreEqual((char)list[1]->data, 'C');
		Assert::AreEqual((char)list[2]->data, 'E');
		Assert::AreEqual((char)list[3]->data, 'D');
		Assert::AreEqual((char)list[4]->data, 'B');
		Assert::AreEqual((char)list[5]->data, 'H');
		Assert::AreEqual((char)list[6]->data, 'I');
		Assert::AreEqual((char)list[7]->data, 'G');
		Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(TreeInOrderIterative)
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
		tree.InOrderIterative(&list);

		Assert::AreEqual((int)list.GetCapacity(), 9);

		Assert::AreEqual((char)list[0]->data, 'A');
		Assert::AreEqual((char)list[1]->data, 'B');
		Assert::AreEqual((char)list[2]->data, 'C');
		Assert::AreEqual((char)list[3]->data, 'D');
		Assert::AreEqual((char)list[4]->data, 'E');
		Assert::AreEqual((char)list[5]->data, 'F');
		Assert::AreEqual((char)list[6]->data, 'G');
		Assert::AreEqual((char)list[7]->data, 'I');
		Assert::AreEqual((char)list[8]->data, 'H');
		}

		TEST_METHOD(Clear)
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

			tree.Clear('B');


			cDlist<tNode<char>*> list;

			tree.PreOrderIterative(&list);

			Assert::IsTrue(list.GetCapacity() == 4);
			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'G');
			Assert::AreEqual((char)list[2]->data, 'I');
			Assert::AreEqual((char)list[3]->data, 'H');


		}
			
		
		//STACK------------------------------------------------
		TEST_METHOD(Stack_test)
		{
			cStack<int> lifo;

			lifo.Push(10);
			lifo.Push(20);
			lifo.Push(30);
			lifo.Push(40);

			Assert::AreEqual((int)lifo.Count(), 4);
			Assert::AreEqual((int)*(lifo.Peek(1)), 20);

			int result;
			bool r = lifo.Pop(result);

			Assert::AreEqual((int)result, 40);
			Assert::AreEqual((int)lifo.Count(), 3);
		}
	};
}
