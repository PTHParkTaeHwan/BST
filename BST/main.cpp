//2ÁøÆ®¸®
#include<iostream>
using namespace std;

struct TreeNode
{
	int Value;
	TreeNode *left, *right;

	TreeNode(int value) : Value(value), left(NULL), right(NULL) {}
};

class Tree
{
public:
	Tree() : root(NULL) {}

public:
	void Insert(int value)
	{
		Insert(root, value);
	}
	void Remove(int value)
	{

	}
	void InOrder()
	{
		InOrder(root);
	}
	void PostOrder()
	{
		PostOrder(root);
	}
	void PreOrder()
	{
		PreOrder(root);
	}

	int Search(int value)
	{
		return Search(root, value);
	}
private:
	void Insert(TreeNode* &node, int value)
	{
		if (node == NULL) node = new TreeNode(value);
		else if (value < node->Value) Insert(node->left, value);
		else if (value > node->Value) Insert(node->right, value);
	}
	void InOrder(TreeNode* node)
	{
		if (node != NULL)
		{
			InOrder(node->left);
			cout << node->Value << " ";

			InOrder(node->right);
		}
	}
	void PostOrder(TreeNode* node)
	{
		if (node != NULL)
		{
			PostOrder(node->left);
			PostOrder(node->right);
			cout << node->Value << " ";
		}
	}
	void PreOrder(TreeNode* node)
	{
		if (node != NULL)
		{
			cout << node->Value << " ";
			PreOrder(node->left);
			PreOrder(node->right);
		}
	}
	int Search(TreeNode* node, int value)
	{
		if (node != NULL)
		{
			if (node->Value != value)
			{
				Search(node->left, value);
				Search(node->right, value);
			}
			else if (node->Value == value)
			{
				return node->Value;
			}
		}
		else return 9999;

	}

private:
	TreeNode * root;
};

int main()
{
	Tree tr;
	tr.Insert(10);
	tr.Insert(20);
	tr.Insert(30);
	tr.Insert(40);
	tr.Insert(50);
	tr.Insert(60);
	tr.Insert(70);

	cout << "inOrder" << endl;
	tr.InOrder();	
	cout << endl << endl;

	cout << "PostOrder" << endl;
	tr.PostOrder();
	cout << endl << endl;

	cout << "PreOrder" << endl;
	tr.PreOrder();
	cout << endl << endl;

	int temp;
	cout << "Search" << endl;
	cin >> temp;
	cout << tr.Search(temp) << endl;
	cout << endl << endl;

	return 0;
}