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
bool isvalid=true;
void fun1(TreeNode* root,TreeNode* &prev){
    if(root==NULL)return ;
    fun1(root->left,prev);
    if(prev==NULL)prev=root;
    else {
        if(prev->val>=root->val){
     isvalid=false;

    }
    prev=root;
    }


    fun1(root->right,prev);
    return ;
}
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        fun1(root,prev);
        return isvalid;
    }
};