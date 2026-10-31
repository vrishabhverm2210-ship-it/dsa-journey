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
bool isbalance=true;
int fun1(TreeNode* root){
    if(root==NULL)return 0;
    int left=1+fun1(root->left);
    int right=1+fun1(root->right);
    if(abs(left-right)>1)isbalance=false;
    return max(left,right);

}
    bool isBalanced(TreeNode* root) {
        fun1(root);
        return isbalance;
    }
};