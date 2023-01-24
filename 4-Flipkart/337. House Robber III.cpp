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
    map<pair<TreeNode*,bool>,int> t;
    int solve(TreeNode*root, bool prev){
        if(root==NULL)return 0;
        if(t.find({root,prev})!=t.end())return t[{root,prev}];
        int a =0,b=0;
        a = solve(root->left,false) + solve(root->right,false);
        if(!prev)b = solve(root->left,true)+solve(root->right,true);
        t[{root,prev}]=max(a , b+(prev?0:root->val));
        return t[{root,prev}];
    }
    int rob(TreeNode* root) {
        return solve(root,false);
    }
};