/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
void dfs(Node* &node,unordered_map<Node*,Node*>&mpp1,Node* &clone){

for(int i=0; i<node->neighbors.size(); i++){
    Node* neigh = node->neighbors[i];
        if(mpp1.find(neigh)==mpp1.end()){
            Node* newNode = new Node(neigh->val);
             mpp1[neigh]=newNode;
             clone->neighbors.push_back(newNode);
               dfs(neigh, mpp1, newNode);
        }
        else{
            clone->neighbors.push_back(mpp1[neigh]);
        }
    }
}

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*,Node*>mpp1;   // original vs clone
        Node* clone= new Node(node->val);
      mpp1[node]=clone;
            dfs(node,mpp1,clone);
            return clone;
      
    }
};