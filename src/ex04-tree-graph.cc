/*
 * ex04-tree-graph.cc
 *
 *  Created on: Aug 29, 2016
 *      Author: dmitry
 */

#include "ex04.h"
#include <stack>
#include <queue>

void TreeNode::insert(const int value) {
    TreeNode *ptr = this;
    insertRecursive(value, &ptr, nullptr);
}

void TreeNode::insertRecursive(int value, TreeNode **link, TreeNode *parent) {
    if (*link == nullptr) {
        *link = new TreeNode(value);
        (*link)->parent = parent;
        return;
    }

    if (value < (*link)->value) {
        insertRecursive(value, &((*link)->left), *link);
    } else {
        insertRecursive(value, &((*link)->right), *link);
    }
}

void preorder(TreeNode *tree, std::vector<int>& result) {
    if (tree == nullptr) {
        return;
    }
    result.push_back(tree->value);
    preorder(tree->left, result);
    preorder(tree->right, result);
}

void iter_preorder(TreeNode *tree, std::vector<int>& result) {
    std::stack<TreeNode*> stack;
    if (tree != nullptr) {
        stack.push(tree);
    }
    while (!stack.empty()) {
        TreeNode *node = stack.top();
        stack.pop();
        result.push_back(node->value);
        if (node->right != nullptr) {
            stack.push(node->right);
        }
        if (node->left != nullptr) {
            stack.push(node->left);
        }
    }
}

void inorder(TreeNode *tree, std::vector<int>& result) {
    if (tree == nullptr) {
        return;
    }
    inorder(tree->left, result);
    result.push_back(tree->value);
    inorder(tree->right, result);
}

void iter_inorder(TreeNode *tree, std::vector<int>& result) {
    std::stack<TreeNode*> stack;
    TreeNode *node = tree;

    while (node != nullptr || !stack.empty()) {
        if (node != nullptr) {
            stack.push(node);
            node = node->left;
        } else {
            node = stack.top();
            stack.pop();
            result.push_back(node->value);
            node = node->right;
        }
    }
}

void postorder(TreeNode *tree, std::vector<int>& result) {
    if (tree == nullptr) {
        return;
    }
    postorder(tree->left, result);
    postorder(tree->right, result);
    result.push_back(tree->value);
}

void iter_postorder(TreeNode *tree, std::vector<int>& result) {
    std::stack<TreeNode*> stack;
    TreeNode *node = tree;
    TreeNode *last = nullptr;

    while (node != nullptr || !stack.empty()) {
        if (node != nullptr) {
            stack.push(node);
            node = node->left;
        } else {
            node = stack.top();
            if (node->right != nullptr && node->right != last) {
                node = node->right;
            } else {
                stack.pop();
                result.push_back(node->value);
                last = node;
                node = nullptr;
            }
        }
    }
}

void breadth_first_search(TreeNode *tree, std::vector<int>& result) {
    std::queue<TreeNode*> q;

    if (tree != nullptr) {
        q.push(tree);
    }

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        result.push_back(node->value);
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int max_depth(TreeNode *tree) {
    if (tree == nullptr) {
        return 0;
    }
    int l1 = max_depth(tree->left);
    int l2 = max_depth(tree->right);
    return ((l1 > l2) ? l1 : l2) + 1;
}

int min_depth(TreeNode *tree) {
    if (tree == nullptr) {
        return 0;
    }
    int l1 = min_depth(tree->left);
    int l2 = min_depth(tree->right);
    return ((l1 < l2) ? l1 : l2) + 1;
}

bool is_balanced(TreeNode *tree) {
    return max_depth(tree) - min_depth(tree) <= 1;
}

Graph::Graph(int size, bool isDirected) {
    mNvertices = size;
    mIsDirected = isDirected;

    mEdges = new EdgeNode*[mNvertices];
    memset(mEdges, 0, mNvertices * sizeof(EdgeNode*));

    mDegree = new int[mNvertices];
    memset(mDegree, 0, mNvertices * sizeof(int));

    discovered = new bool[mNvertices];
    processed = new bool[mNvertices];
    parent = new int[mNvertices];
    initSearch();
}

Graph::~Graph() {
    for (int i = 0; i < mNvertices; i++) {
        EdgeNode *ptr = mEdges[i];
        while (ptr != nullptr) {
            EdgeNode *temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
    }
    delete[] mEdges;
    delete mDegree;
}

void Graph::addEdge(int x, int y, int weight, bool isDirected) {

    // no check for dups

    mEdges[x] = new EdgeNode { y, weight, mEdges[x] };
    mDegree[x]++;

    if (isDirected == false) {
        addEdge(y, x, weight, true);
    } else {
        mNedges++;
    }
}

void Graph::initSearch() {
    memset(discovered, false, mNvertices * sizeof(bool));
    memset(processed, false, mNvertices * sizeof(bool));
    memset(parent, -1, mNvertices * sizeof(int));
}

void Graph::bfs(int start) {
    std::queue<int> queue;

    queue.push(start);
    discovered[start] = true;

    while (!queue.empty()) {

        int x = queue.front();
        queue.pop();

        processed[x] = true;

        EdgeNode *e = mEdges[x];
        while (e != nullptr) {
            int y = e->to_vertex;

            // we can process edge if need
            //if (processed[y] == false || mIsDirected) {
            //}

            if (!discovered[y]) {
                discovered[y] = true;
                queue.push(y);
                parent[y] = x;
            }

            e = e->next;
        }
    }
}

void Graph::dfs(int start) {
    discovered[start] = true;
    EdgeNode *e = mEdges[start];
    while (e != nullptr) {
        if (!discovered[e->to_vertex]) {
            parent[e->to_vertex] = start;
            dfs(e->to_vertex);
        }
        e = e->next;
    }
    processed[start] = true;
}
