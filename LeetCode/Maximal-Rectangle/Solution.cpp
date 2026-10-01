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
31    int largestRectangleArea(vector<int>& heights) {
32        int n= heights.size();
33        
34        vector<int> next(n);
35        next = nextSmallerElement(heights, n);
36            
37        vector<int> prev(n);
38        prev = prevSmallerElement(heights, n);
39        
40        int ans = INT_MIN;
41        for(int i=0;i<n;i++){
42            int len=heights[i];
43
44 if(next[i] == -1) {
45                next[i] = n;
46            }
47            int breadth=next[i]-prev[i]-1;
48            int area=len*breadth;
49            ans=max(ans,area);
50            
51        }
52        return ans;
53    }
54    int maximalRectangle(vector<vector<char>>& matrix) {
55        
56     
57        if(matrix.empty())
58            return 0;
59
60        int n = matrix.size();
61        int m = matrix[0].size();
62
63        vector<int> height(m, 0);
64
65        int ans = 0;
66
67        // Process row by row
68        for(int i = 0; i < n; i++) {
69
70            // Build histogram
71            for(int j = 0; j < m; j++) {
72
73                if(matrix[i][j] == '1')
74                    height[j]++;
75                else
76                    height[j] = 0;
77            }
78
79            // Apply LC 84
80            ans = max(ans, largestRectangleArea(height));
81        }
82
83        return ans;
84    }
85};