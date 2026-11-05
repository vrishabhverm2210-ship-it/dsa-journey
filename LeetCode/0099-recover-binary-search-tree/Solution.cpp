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
TreeNode*  wrong1first=NULL;
TreeNode* wrong2first=NULL;
TreeNode* wrong1second=NULL;
TreeNode* wrong2second=NULL;
int count=0;
void fun1(TreeNode*  root,TreeNode*  &prev){
    // base case
    if(root==NULL)return;
    fun1(root->left,prev);
    if(prev==NULL){
        prev=root;
    }
    else{  // we have to handle mistake in this case itself
         if(prev->val>=root->val){
            if(count==0){
                wrong1first=prev;
                wrong1second=root;
                count++;
            }
            else{
                wrong2first=prev;
                wrong2second=root;
                count++;
            }
         }
         prev=root;  // must condition required to maintain the regular flow
    }
    fun1(root->right,prev);
}

    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        fun1(root,prev);
        if(count==1){
            // means ek hi wrong pair hai adjacent (normally swap them)
            swap(wrong1first->val,wrong1second->val);
        }
        else{
            swap(wrong1first->val,wrong2second->val);
        }
    }
};