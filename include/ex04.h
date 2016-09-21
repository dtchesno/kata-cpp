/*
 * ex04.h
 *
 *  Created on: Aug 29, 2016
 *      Author: dmitry
 */

#ifndef INCLUDE_EX04_H_
#define INCLUDE_EX04_H_

#include "kata.h"
#include <vector>
#include <memory.h>


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


// Graph definitions

struct EdgeNode {
    int to_vertex;
    int weight;
    EdgeNode *next;
};

class Graph {
public:
    Graph(int size, bool isDirected);
    ~Graph();
    void addEdge(int x, int y, int weight, bool isDirected);

    void initSearch();
    void bfs(int start);
    void dfs(int start);

public:
    bool mIsDirected;
    int mNvertices; // number of vertices
    int mNedges = 0; // number of edges

    // lists/arrays holding properties for every vertex, size is nvertices
    EdgeNode **mEdges;
    int *mDegree;

    // graph traversal
    bool *discovered;
    bool *processed;
    int *parent;
};

#endif /* INCLUDE_EX04_H_ */
