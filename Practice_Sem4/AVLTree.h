#pragma once
#include "Student.h";

struct NODE1
{
    Student student;
    NODE1* left;
    NODE1* right;
    int height;
};

using AVLTreeNode = NODE1*;

class AVLTree
{
public:
    AVLTreeNode root;
    AVLTree();
    void insert(Student stud);
    void remove(Student stud);
    void Destroy_tree();
private:
    void makeEmpty(AVLTreeNode t);
    AVLTreeNode insert(Student stud, AVLTreeNode t);
    int height(AVLTreeNode t);
    AVLTreeNode singleRightRotate(AVLTreeNode& t);
    AVLTreeNode singleLeftRotate(AVLTreeNode& t);
    AVLTreeNode doubleLeftRotate(AVLTreeNode& t);
    AVLTreeNode doubleRightRotate(AVLTreeNode& t);
    AVLTreeNode remove(Student stud, AVLTreeNode t);
    AVLTreeNode findMin(AVLTreeNode t);
    AVLTreeNode findMax(AVLTreeNode t);
    void Destroy_tree(AVLTreeNode root);
};

