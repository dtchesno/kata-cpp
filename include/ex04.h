/*
 * ex04.h
 *
 *  Created on: Aug 29, 2016
 *      Author: dmitry
 */

#ifndef INCLUDE_EX04_H_
#define INCLUDE_EX04_H_

#include "kata.h"
#include<vector>

//template<class T>
//class TreeNode {
//
//public:
//    TreeNode<T>(const T& avalue) : value(avalue) {}
//
//    ~TreeNode<T>() {
//        if (left != nullptr) {
//            delete left;
//        }
//        if (right != nullptr) {
//            delete right;
//        }
//    }
//
//    void insert(const T& value) {
//        TreeNode<T> *ptr = this;
//        insertRecursive(value, &ptr, nullptr);
//    }
//
//private:
//    void insertRecursive(int value, TreeNode<T> **link, TreeNode<T> *parent) {
//        if (*link == nullptr) {
//            *link = new TreeNode<T>(value);
//            (*link)->parent = parent;
//            return;
//        }
//
//        if (value < (*link)->value) {
//            insertRecursive(value, &((*link)->left), *link);
//        } else {
//            insertRecursive(value, &((*link)->right), *link);
//        }
//    }
//
//public:
//    T value;
//    TreeNode<T> *parent = nullptr;
//    TreeNode<T> *left = nullptr;
//    TreeNode<T> *right = nullptr;
//};

class TreeNode {
public:
    TreeNode(const int avalue) : value(avalue) {}

    ~TreeNode() {
        if (left != nullptr) {
            delete left;
        }
        if (right != nullptr) {
            delete right;
        }
    }

    void insert(const int value);

private:
    void insertRecursive(int value, TreeNode **link, TreeNode *parent);

public:
    int value;
    TreeNode *parent = nullptr;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

void preorder(TreeNode *tree, std::vector<int>& result);
void inorder(TreeNode *tree, std::vector<int>& result);
void postorder(TreeNode *tree, std::vector<int>& result);

void iter_preorder(TreeNode *tree, std::vector<int>& result);
void iter_inorder(TreeNode *tree, std::vector<int>& result);
void iter_postorder(TreeNode *tree, std::vector<int>& result);

void breadth_first_search(TreeNode *tree, std::vector<int>& result);

int max_depth(TreeNode *tree);
int min_depth(TreeNode *tree);
bool is_balanced(TreeNode *tree);

#endif /* INCLUDE_EX04_H_ */
