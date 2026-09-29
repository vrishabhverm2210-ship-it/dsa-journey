1class Solution {
2public:
3vector<int> nextSmallerElement(vector<int> arr, int n) {
4    stack<int>st;
5    st.push(-1);
6    vector<int>ans(n);
7 for(int i=n-1;i>=0;i--){
8    int curr=arr[i];
9    while(st.top()!=-1 && arr[st.top()] >= curr){
10        st.pop();
11    }
12    ans[i]=st.top();
13    st.push(i);
14 }
15 return ans;
16}
17vector<int> prevSmallerElement(vector<int> arr, int n){
18   stack<int>st;
19    st.push(-1);
20    vector<int>ans(n);
21 for(int i=0;i<n;i++){
22    int curr=arr[i];
23    while(st.top()!=-1 && arr[st.top()] >= curr){
24        st.pop();
25    }
26    ans[i]=st.top();
27    st.push(i);
28 }
29 return ans;
30}
31
32    int largestRectangleArea(vector<int>& heights) {
33        int n= heights.size();
34        
35        vector<int> next(n);
36        next = nextSmallerElement(heights, n);
37            
38        vector<int> prev(n);
39        prev = prevSmallerElement(heights, n);
40        
41        int ans = INT_MIN;
42        for(int i=0;i<n;i++){
43            int len=heights[i];
44
45 if(next[i] == -1) {
46                next[i] = n;
47            }
48            int breadth=next[i]-prev[i]-1;
49            int area=len*breadth;
50            ans=max(ans,area);
51            
52        }
53        return ans;
54    }
55};