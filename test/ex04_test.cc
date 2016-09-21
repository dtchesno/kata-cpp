#include "ex04.h"
#include "gtest/gtest.h"

TreeNode* create_tree(int *array, int size) {
    if (size <= 0) {
        return nullptr;
    }
    TreeNode *tree = new TreeNode(array[0]);
    for (int i = 1; i < size; i++) {
        tree->insert(array[i]);
    }
    return tree;
}

// test stack implementation
TEST(Ex04, create_tree) {
//           6
//        4         10
//     2     5    8    11
//   1   3       7 9
    int values[] = {6, 4, 10, 2, 5, 8, 11, 1, 3, 7, 9};
    TreeNode *tree = create_tree(values, sizeof(values) / sizeof(int));

    EXPECT_EQ(6, tree->value);
    EXPECT_EQ(4, tree->left->value);
    EXPECT_EQ(10, tree->right->value);

    delete tree;
}

TEST(Ex04, delete_node) {
    int values[] = {6, 4, 10, 2, 5, 8, 11, 1, 3, 7, 9};
    TreeNode *tree = create_tree(values, sizeof(values) / sizeof(int));

    // TODO

    delete tree;
}

TEST(Ex04, preorder) {
    int values[] = {6, 4, 10, 2, 5, 8, 11, 1, 3, 7, 9};
    int expected[] = {6, 4, 2, 1, 3, 5, 10, 8, 7, 9, 11};
    int size = sizeof(values) / sizeof(int);
    TreeNode *tree = create_tree(values, size);
    std::vector<int> result;

    //printf("sizeof(values) = %d, size = %d\n", sizeof(values), size);

    preorder(tree, result);
    ASSERT_EQ(size, result.size());
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(expected[i], result[i]);
    }

    result.clear();

    iter_preorder(tree, result);
    ASSERT_EQ(size, result.size());
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(expected[i], result[i]);
    }

    delete tree;
}

TEST(Ex04, inorder) {
    int values[] = {6, 4, 10, 2, 5, 8, 11, 1, 3, 7, 9};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int size = sizeof(values) / sizeof(int);
    TreeNode *tree = create_tree(values, size);
    std::vector<int> result;

    inorder(tree, result);
    ASSERT_EQ(size, result.size());
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(expected[i], result[i]);
    }

    result.clear();
    iter_inorder(tree, result);
    ASSERT_EQ(size, result.size());
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(expected[i], result[i]);
    }

    delete tree;
}

TEST(Ex04, postorder) {
    int values[] = {6, 4, 10, 2, 5, 8, 11, 1, 3, 7, 9};
    int expected[] = {1, 3, 2, 5, 4, 7, 9, 8, 11, 10, 6};

    int size = sizeof(values) / sizeof(int);
    TreeNode *tree = create_tree(values, size);
    std::vector<int> result;

    postorder(tree, result);
    ASSERT_EQ(size, result.size());
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(expected[i], result[i]);
    }

    result.clear();
    iter_postorder(tree, result);
    ASSERT_EQ(size, result.size());
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(expected[i], result[i]);
    }

    delete tree;
}

TEST(Ex04, breadth_first_search) {
    int values[] = {6, 4, 10, 2, 5, 8, 11, 1, 3, 7, 9};
    int expected[] = {6, 4, 10, 2, 5, 8, 11, 1, 3, 7, 9};

    int size = sizeof(values) / sizeof(int);
    TreeNode *tree = create_tree(values, size);
    std::vector<int> result;

    breadth_first_search(tree, result);
    ASSERT_EQ(size, result.size());
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(expected[i], result[i]);
    }

    delete tree;
}

TEST(Ex04, is_balanced) {
    int values[] = {6, 4, 10, 2, 5, 8, 11, 1, 3, 7, 9};

    int size = sizeof(values) / sizeof(int);
    TreeNode *tree = create_tree(values, size);
    std::vector<int> result;

    EXPECT_EQ(3, min_depth(tree));
    EXPECT_EQ(4, max_depth(tree));
    EXPECT_EQ(true, is_balanced(tree));

    delete tree;
}

Graph *create_graph() {
    int size = 6;
    Graph *graph = new Graph(size, false);
    graph->addEdge(0, 1, 1, false);
    graph->addEdge(1, 3, 1, false);
    graph->addEdge(3, 5, 1, false);
    graph->addEdge(5, 4, 1, false);
    graph->addEdge(4, 2, 1, false);
    graph->addEdge(2, 0, 1, false);
    graph->addEdge(0, 5, 1, false);
    return graph;
}

TEST(Ex04, create_graph_empty) {
    int size = 6;
    Graph *graph = new Graph(size, false);

    EXPECT_EQ(size, graph->mNvertices);
    EXPECT_EQ(false, graph->mIsDirected);
    EXPECT_EQ(0, graph->mNedges);
    for (int i = 0; i < size; i++) {
        EXPECT_EQ(0, graph->mDegree[i]);
        EXPECT_EQ(nullptr, graph->mEdges[i]);
    }

    delete graph;
}

TEST(Ex04, create_graph) {
    Graph *graph = create_graph();

    EXPECT_EQ(6, graph->mNvertices);
    EXPECT_EQ(false, graph->mIsDirected);
    EXPECT_EQ(7, graph->mNedges);

    EXPECT_EQ(3, graph->mDegree[0]);
    EXPECT_EQ(2, graph->mDegree[1]);
    EXPECT_EQ(2, graph->mDegree[2]);
    EXPECT_EQ(2, graph->mDegree[3]);
    EXPECT_EQ(2, graph->mDegree[4]);
    EXPECT_EQ(3, graph->mDegree[5]);

    delete graph;
}

TEST(Ex04, breadth_first_traversal) {
    int size = 6;
    Graph *graph = create_graph();

    graph->initSearch();
    graph->bfs(0);

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(true, graph->discovered[i]);
        EXPECT_EQ(true, graph->processed[i]);
    }

    EXPECT_EQ(0, graph->parent[1]);
    EXPECT_EQ(5, graph->parent[3]);
    EXPECT_EQ(0, graph->parent[2]);
    EXPECT_EQ(5, graph->parent[4]);
    EXPECT_EQ(0, graph->parent[5]);

    delete graph;
}

TEST(Ex04, depth_first_traversal) {
    int size = 6;
    Graph *graph = create_graph();

    graph->initSearch();
    graph->dfs(0);

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(true, graph->discovered[i]);
        EXPECT_EQ(true, graph->processed[i]);
    }

    EXPECT_EQ(-1, graph->parent[0]);
    EXPECT_EQ(3, graph->parent[1]);
    EXPECT_EQ(4, graph->parent[2]);
    EXPECT_EQ(5, graph->parent[3]);
    EXPECT_EQ(5, graph->parent[4]);
    EXPECT_EQ(0, graph->parent[5]);

    delete graph;
}
