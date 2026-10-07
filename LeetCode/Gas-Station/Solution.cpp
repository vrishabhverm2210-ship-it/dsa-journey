1class Solution {
2public:
3    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
4        int start=0;
5        int tank=0;
6        int total=0;
7   
8        for(int i=0;i<gas.size();i++){
9            tank+=gas[i]-cost[i];
10            total+=gas[i]-cost[i];
11         if(tank<0){
12            start=i+1;
13          tank=0;
14         }
15
16        }
17        if(total<0)return -1;
18
19        return start;
20    }
21};