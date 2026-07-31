1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        // BUILD THE MAX HEAP FIRST
5        priority_queue<int>pq;   // max heap syntax
6
7        // add all the elements of the stones vector into the heap
8        for(int i=0;i<stones.size();i++){
9            pq.push(stones[i]);
10        }
11        // now until our heaps doesn't end run a loop
12        while(!pq.empty()){
13       if(pq.size()==1){
14        return pq.top();
15         break;
16       }
17       int stone1=pq.top();
18       pq.pop();
19         int stone2=pq.top();
20       pq.pop();
21       int diff=stone1-stone2;
22       if(diff>0){
23        pq.push(diff);
24       }
25
26        }
27        return 0;
28
29    }
30};