1class Solution {
2public:
3    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
4        // Make pair first
5         vector<pair<int,int>>curr;
6        for(int i=0;i<profits.size();i++){
7            curr.push_back({capital[i],profits[i]});
8        }
9        sort(curr.begin(), curr.end());
10        // make max heap now
11        priority_queue<int>pq;
12        int idx=0;
13        while(k>0){
14            while(idx<curr.size()){
15              if(w<curr[idx].first)break;
16              //otherwise 
17              pq.push(curr[idx].second);
18              idx++; 
19            }
20            if(pq.empty())return w;// bankrupt
21            int top=pq.top(); // for maximummmmmmmmmmmmmmmmmmmmm
22            pq.pop();
23            w+=top;
24             k--;
25        }
26    
27return w;
28    }
29};