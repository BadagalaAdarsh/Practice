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

TreeNode* bstFromPreorder(vector<int>& preorder){
    return NULL;
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