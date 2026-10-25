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
TreeNode* fun1(vector<int>& postorder,unordered_map<int,int> &mpp1,int low,int high,int &idx){
    if(low>high)return NULL;
TreeNode* node=new TreeNode(postorder[idx]);
idx--;
int id=mpp1[node->val];
node->right=fun1(postorder,mpp1,id+1,high,idx);
node->left=fun1(postorder,mpp1,low,id-1,idx);


return node;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp1;
        for(int i=0;i<inorder.size();i++){
            mpp1[inorder[i]]=i;
        }
        int idx=postorder.size()-1;
         return fun1(postorder,mpp1,0,inorder.size()-1,idx);
    }
};