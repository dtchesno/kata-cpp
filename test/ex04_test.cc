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
