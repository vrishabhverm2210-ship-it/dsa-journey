1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& intervals) {
4        // visualise it as a vector matrix typoo
5        // important step is to sort it
6        sort(intervals.begin(),intervals.end());
7         vector<vector<int>>res;
8         int n=intervals.size();
9         int start1=intervals[0][0];
10         int end1=intervals[0][1];
11         for(int i=1;i<n;i++){
12            int start2=intervals[i][0];
13            int end2=intervals[i][1];
14            // write merging  condititon
15            if(end1>=start2){
16                start1=start1;
17                end1=max(end1,end2);
18                continue;
19            }
20            else{
21                res.push_back({start1,end1});
22                start1=start2;
23                end1=end2;
24            }
25         } 
26         // last mai jo bacha hoga use bhi result mai daal do
27         res.push_back({start1,end1});
28         return res;
29    }
30};