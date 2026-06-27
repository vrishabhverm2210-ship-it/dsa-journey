1class Solution {
2public:
3// struct emp{
4//     bool operator()(pair<int,char>&a,pair<int,char>&b){
5//         if(a.first!=b.first){
6//             return a.first<b.first;
7//         }
8//         return a.second<b.second;
9//     }
10// };
11    int lastStoneWeight(vector<int>& stones) {
12        //   priority_queue<pair<int,char>,vector<pair<int,char>>,emp>pq;
13        priority_queue<int>pq;
14        for(int i=0;i<stones.size();i++){
15            pq.push(stones[i]);   // saare elements heap mai dal gye  tc=>  O(nlogn)
16        }
17        while(pq.size()>1){
18            int t1=pq.top();
19            pq.pop();
20            int t2=pq.top();
21            pq.pop();
22            int t3=t1-t2;
23            if(t3==0)continue;
24            pq.push(t3);
25            // if(pq.size()==1)return pq.top();
26            
27        }
28      if(pq.empty()) return 0;
29      return pq.top();
30    }
31};