#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

TreeNode* invert(TreeNode* root) {

    if (root == NULL) {
        return root;
    }

    TreeNode* leftTree = invert(root->left);
    TreeNode* rightTree = invert(root->right);

    root->left = rightTree;
    root->right = leftTree;

    return root;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    while(test--) {
        //constructing the tree
    }
}