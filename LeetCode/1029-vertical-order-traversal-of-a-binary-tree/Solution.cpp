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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int > > >nodes;
        queue<pair<TreeNode*,pair<int ,int>>>q; // we can change the value of nodes(jo upr D.S banaya hai) with hd and lvl
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int ,int>> temp= q.front();
            q.pop();
            TreeNode* frontnode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            nodes[hd][lvl].push_back(frontnode->val);

            if(frontnode->left){
                q.push(make_pair(frontnode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,make_pair(hd+1,lvl+1)));
            }
           

        }
    for (auto &i : nodes) {
    vector<int> colVals;
    for (auto &j : i.second) {
        // sort krna jruri haiiiiiiiiiiiii
        auto &vals = j.second;
        sort(vals.begin(), vals.end());
        for (int v : vals) {
            colVals.push_back(v);
        }
    }
    ans.push_back(colVals);
}
return ans;
    }
};