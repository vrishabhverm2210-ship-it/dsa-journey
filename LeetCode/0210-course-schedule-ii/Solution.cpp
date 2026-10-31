class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // let's create adj list first
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            vector<int>edge=prerequisites[i];
            int src=edge[1];
            int dest=edge[0];
            adj[src].push_back(dest);
            indegree[dest]++;
        }
       
        //pussh the zero indegree element into the queue
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)q.push(i);
        } 
        vector<int>res;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                int neigh=adj[node][i];
                 indegree[neigh]--;
                 if(indegree[neigh]==0)q.push(neigh);
            }
        }
        if(res.size()!=numCourses){
            return {};
        }
        return res;
    }
};