#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode* root, const vector<int>& array, int depth) {

    if (root == NULL){
        return false;
    }

    if(depth >= (int) array.size() || root -> val != array[depth] ) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return depth == (int)array.size() - 1;
    }

    return dfs(root->left, array, depth + 1) || dfs(root->right, array, depth+1);
}

bool isValidSequence(TreeNode* root, vector<int>& array) {
    return dfs(root, array, 0);
}

int main() {

    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;

        vector<int> array(n);
        for(int i = 0; i < n; i++) {
            cin >> array[i];
        }

        //Construction of the tree

    }
}