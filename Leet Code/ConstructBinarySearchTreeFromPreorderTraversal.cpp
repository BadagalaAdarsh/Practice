#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};  

// Quadratic Complexity
TreeNode* bstFromPreorder(vector<int>& preorder){
    if(preorder.empty()){
        return NULL;
    }

    int root_value = preorder[0];
    vector<int> smaller, greater;
    for(int i = 1; i < (int)preorder.size(); i++){
        if(preorder[i] < root_value){
            smaller.push_back(preorder[i]);
        }
        else{
            greater.push_back(preorder[i]);
        }
    }

    TreeNode* root = new TreeNode(root_value);
    root->left = bstFromPreorder(smaller);
    root->right = bstFromPreorder(greater);
    return root;
}


// helper method for linear complexity
TreeNode* helper(vector<int>& preorder, int id, int limit){
    if(id == (int)preorder.size() || preorder[id] > limit){
        return NULL;
    }
    int root_value = preorder[id];
    TreeNode* root = new TreeNode(root_value);
    id++;
    root->left = helper(preorder, id, root_value);
    root->right = helper(preorder, id, limit);
    return root;
}

//Linear Complexity
TreeNode* bstFromPreorderLinear(vector<int>& preorder){
    int id = 0;
    return helper(preorder, id, INT_MAX);
}
                
int main(){

    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;

        vector<int> preorder;
        for(int i = 0; i < n; i++){
            cin >> preorder[i];
        }
    }
}