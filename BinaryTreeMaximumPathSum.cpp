#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    int answer;
    
    int dfs(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        int x = dfs(root->left);
        int y = dfs(root->right);
        answer = max(answer, x + y + root->val);
        return max(0,root -> val + max(x,y));
    }
    
public:
    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
        dfs(root);
        return answer;
    }
};

int main(){
    int test;
    cin >> test;

    while(test--) {
            // some how create the tree based on the above structure;
    }
}