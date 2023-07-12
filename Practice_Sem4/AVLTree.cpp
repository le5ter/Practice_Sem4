#include "AVLTree.h"
#include<iostream>

using namespace std;

AVLTree::AVLTree()
{
    root = nullptr;
}

void AVLTree::makeEmpty(AVLTreeNode t)
{
    if (t == nullptr)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

void AVLTree::Destroy_tree()
{
    Destroy_tree(root);
}

int AVLTree::height(AVLTreeNode t)
{
    return (t == nullptr ? -1 : t->height);
}

AVLTreeNode AVLTree::insert(Student stud, AVLTreeNode t)
{
    if (t == nullptr)
    {
        t = new NODE1;
        t->student = stud;
        t->height = 0;
        t->left = t->right = NULL;
    }
    else if (stud.Get_avarage() < t->student.Get_avarage())
    {
        t->left = insert(stud, t->left);
        if (height(t->left) - height(t->right) == 2)
        {
            if (stud.Get_avarage() < t->left->student.Get_avarage())
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }
    else if (stud.Get_avarage() > t->student.Get_avarage())
    {
        t->right = insert(stud, t->right);
        if (height(t->right) - height(t->left) == 2)
        {
            if (stud.Get_avarage() > t->right->student.Get_avarage())
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }

    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}

AVLTreeNode AVLTree::singleRightRotate(AVLTreeNode& t)
{
    AVLTreeNode u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    u->height = max(height(u->left), t->height) + 1;
    return u;
}

AVLTreeNode AVLTree::singleLeftRotate(AVLTreeNode& t)
{
    AVLTreeNode u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    u->height = max(height(t->right), t->height) + 1;
    return u;
}

AVLTreeNode AVLTree::doubleLeftRotate(AVLTreeNode& t)
{
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

AVLTreeNode AVLTree::doubleRightRotate(AVLTreeNode& t)
{
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}

AVLTreeNode AVLTree::remove(Student stud, AVLTreeNode t)
{
    AVLTreeNode temp;

    // Element not found
    if (t == nullptr)
        return nullptr;

    // Searching for element
    else if (stud.Get_avarage() < t->student.Get_avarage())
        t->left = remove(stud, t->left);
    else if (stud.Get_avarage() > t->student.Get_avarage())
        t->right = remove(stud, t->right);

    // Element found
    // With 2 children
    else if (t->left && t->right)
    {
        temp = findMin(t->right);
        double avg = temp->student.Get_avarage();
        t->student.Set_avarage(avg);
        t->right = remove(t->student, t->right);
    }
    // With one or zero child
    else
    {
        temp = t;
        if (t->left == nullptr)
            t = t->right;
        else if (t->right == nullptr)
            t = t->left;
        delete temp;
    }
    if (t == nullptr)
        return t;

    t->height = max(height(t->left), height(t->right)) + 1;

    // If node is unbalanced
    // If left node is deleted, right case
    if (height(t->left) - height(t->right) == 2)
    {
        // right right case
        if (height(t->left->left) - height(t->left->right) == 1)
            return singleLeftRotate(t);
        // right left case
        else
            return doubleLeftRotate(t);
    }
    // If right node is deleted, left case
    else if (height(t->right) - height(t->left) == 2)
    {
        // left left case
        if (height(t->right->right) - height(t->right->left) == 1)
            return singleRightRotate(t);
        // left right case
        else
            return doubleRightRotate(t);
    }
    return t;
}

AVLTreeNode AVLTree::findMin(AVLTreeNode t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    else
        return findMin(t->left);
}

AVLTreeNode AVLTree::findMax(AVLTreeNode t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->right == nullptr)
        return t;
    else
        return findMax(t->right);
}

void AVLTree::Destroy_tree(AVLTreeNode root)
{
    if (root != nullptr)
    {
        Destroy_tree(root->left);
        Destroy_tree(root->right);
        delete root;
    }

}

void AVLTree::insert(Student stud)
{
    root = insert(stud, root);
}

void AVLTree::remove(Student stud)
{
    root = remove(stud, root);
}