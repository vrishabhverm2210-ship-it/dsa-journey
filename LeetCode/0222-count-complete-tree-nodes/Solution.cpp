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
int fun1(TreeNode* root){
    TreeNode* temp=root;
    int h=0;
    while(temp){
       h++;
       temp=temp->left;
           }
           return h;
}
int fun2(TreeNode* root){
    TreeNode* temp=root;
    int h=0;
    while(temp){
       h++;
       temp=temp->right;
           }
           return h;
}
// int fun3(TreeNode* root){
//     if(root==NULL)return 0;
//     int left=fun3(root->left);
//     int right=fun3(root->right);
//     return 1+left+right;
// }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        // use complete binary tree property
        int lh=fun1(root);
        int rh=fun2(root);
       

       // if lh == rh (means jo hmara tree hai vo complete hain puri tarah se toh hum O(1) mai nikal skte hain)
       if(lh==rh){
        return (1 << lh) -1;
       }
       // else normal method
       return 1+countNodes(root->left)+countNodes(root->right);
    }
};