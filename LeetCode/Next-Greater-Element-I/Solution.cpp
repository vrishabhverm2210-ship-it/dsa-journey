1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        int n=nums1.size();
5       
6         stack<int>st; 
7          int m=nums2.size();
8         st.push(nums2[m-1]);
9         vector<int>nxt(m,-1);
10         for(int i=m-2;i>=0;i--){
11            while(!st.empty()&&nums2[i]>=st.top()){
12             st.pop();
13            }
14            if(st.empty()){
15                   st.push(nums2[i]);
16                continue;
17            }
18            else{
19              nxt[i]=st.top();
20            }
21           st.push(nums2[i]);
22         }
23         unordered_map<int,int>mpp1;
24         for(int i=0;i<m;i++){
25            mpp1[nums2[i]]=i;
26         }
27  vector<int>res(n,-1);
28         for(int i=0;i<n;i++){
29        if(mpp1.find(nums1[i])!=mpp1.end()){
30res[i] = nxt[mpp1[nums1[i]]];        }
31         }
32         return res;
33
34    }
35};