#pragma once
#include "Student.h"

struct NODE
{
	Student student;
	NODE* left, * right;
};

using BinaryTreeNode = NODE*;

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void Insert(Student student);
	void Destroy_tree();
	BinaryTreeNode root;
private:
	void Insert(BinaryTreeNode& root, Student student);
	void Destroy_tree(BinaryTreeNode root);
};

