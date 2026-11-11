class Solution {
public:
int distance(int point, int x){
    return abs(x - point); 
   
}
struct emp{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
};
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
          priority_queue<pair<int ,int >,vector<pair<int, int >>,emp>pq;
        for(int i=0;i<arr.size();i++){
          int dist=distance(arr[i],x);
          int value=arr[i];
          pair<int ,int> curr={dist,value};
    if(pq.size()<k){
        pq.push(curr);
        continue;
    }
    pq.push(curr);
    pq.pop();
          }
       // now we have to return the answer
           vector<int>res;
           while(!pq.empty()){
                 res.push_back(pq.top().second);
                 pq.pop();
           }
//    reverse(res.begin(), res.end());
sort(res.begin(),res.end());
     return res;
    }
};