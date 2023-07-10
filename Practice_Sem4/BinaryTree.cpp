#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    Destroy_tree();
}

void BinaryTree::Insert(Student student)
{
	Insert(root, student);
}

void BinaryTree::Insert(BinaryTreeNode& root, Student student)
{
	if (root == nullptr)
	{
		root = new NODE;
		root->student = student;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
	{
		if (root->student.Marks_sum() != student.Marks_sum())
		{
			if (root->student.Marks_sum() > student.Marks_sum())
				Insert(root->left, student);
			else Insert(root->right, student);
		}
	}
}

void BinaryTree::Destroy_tree()
{
	Destroy_tree(root);
}

void BinaryTree::Destroy_tree(BinaryTreeNode root)
{
	if (root != nullptr) 
	{
		Destroy_tree(root->left);
		Destroy_tree(root->right);
		delete root;
	}
}
