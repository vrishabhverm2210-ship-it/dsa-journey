1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        int n=nums1.size();
5       vector<int>res;
6         stack<int>st; 
7          int m=nums2.size();
8         st.push(nums2[m-1]);
9         unordered_map<int,int>mpp1;
10         mpp1[nums2[m-1]] = -1;
11        //  vector<int>nxt(m,-1);
12        // unordered_map<int,int>mpp1;
13         for(int i=m-2;i>=0;i--){
14            while(!st.empty()&&nums2[i]>=st.top()){
15             st.pop();
16            }
17            if(st.empty()){
18                   st.push(nums2[i]);
19                   mpp1[nums2[i]]=-1;
20                continue;
21            }
22            else{
23                mpp1[nums2[i]]=st.top();
24            //   nxt[i]=st.top();
25            }
26           st.push(nums2[i]);
27         }
28       for(int i=0;i<n;i++){
29        res.push_back(mpp1[nums1[i]]);
30       }
31       return res;
32//          unordered_map<int,int>mpp1;
33//          for(int i=0;i<m;i++){
34//             mpp1[nums2[i]]=i;
35//          }
36//   vector<int>res(n,-1);
37//          for(int i=0;i<n;i++){
38//         if(mpp1.find(nums1[i])!=mpp1.end()){
39//       res[i] = nxt[mpp1[nums1[i]]];        }
40//          }
41//          return res;
42
43    }
44};