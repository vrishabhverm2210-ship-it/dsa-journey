class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Make pair first
         vector<pair<int,int>>curr;
        for(int i=0;i<profits.size();i++){
            curr.push_back({capital[i],profits[i]});
        }
        sort(curr.begin(), curr.end());
        // make max heap now
        priority_queue<int>pq;
        int idx=0;
        while(k>0){
            while(idx<curr.size()){
              if(w<curr[idx].first)break;
              //otherwise 
              pq.push(curr[idx].second);
              idx++; 
            }
            if(pq.empty())return w;// bankrupt
            int top=pq.top(); // for maximummmmmmmmmmmmmmmmmmmmm
            pq.pop();
            w+=top;
             k--;
        }
    
return w;
    }
};