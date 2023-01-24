/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    pair<int,int> dfs(TreeNode*root ){
        if(root==NULL)return {0,0};
        pair<int,int> a = dfs(root->left);
        pair<int,int> b = dfs(root->right);
        double avg = (a.first+b.first+ root->val)*1.0/(a.second+b.second+1);
        if(int(avg) == root->val){
            count++;
        }
        return {(a.first+b.first+ root->val),(a.second+b.second+1)};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};