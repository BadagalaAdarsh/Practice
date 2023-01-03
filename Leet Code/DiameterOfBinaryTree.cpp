/*
  Diameter of Binary Tree

Solution
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    
    pair<int,int> dfs(TreeNode* root){

        if(root == NULL){
            return {0,0};
        }

        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);

        int diam = max({left.first, right.first, left.second + right.second});
        return {diam, max(left.second, right.second) + 1};
    }

    public:

    int diameterOfBinaryTree(TreeNode* root){
        return dfs(root).first;
    }
};

