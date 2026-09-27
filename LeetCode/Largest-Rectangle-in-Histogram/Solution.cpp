1class Solution {
2public:
3 vector<int> nextSmallerElement(vector<int> arr, int n) {
4        stack<int> s;
5        s.push(-1);
6        vector<int> ans(n);
7
8        for(int i=n-1; i>=0 ; i--) {
9            int curr = arr[i];
10            while(s.top() != -1 && arr[s.top()] >= curr)
11            {
12                s.pop();
13            }
14            //ans is stack ka top
15            ans[i] = s.top();
16            s.push(i);
17        }
18        return ans;
19    }
20    
21    vector<int> prevSmallerElement(vector<int> arr, int n) {
22        stack<int> s;
23        s.push(-1);
24        vector<int> ans(n);
25
26        for(int i=0; i<n; i++) {
27            int curr = arr[i];
28            while(s.top() != -1 && arr[s.top()] >= curr)
29            {
30                s.pop();
31            }
32            //ans is stack ka top
33            ans[i] = s.top();
34            s.push(i);
35        }
36        return ans; 
37    }
38    int largestRectangleArea(vector<int>& heights) {
39         int n= heights.size();
40        
41        vector<int> next(n);
42        next = nextSmallerElement(heights, n);
43            
44        vector<int> prev(n);
45        prev = prevSmallerElement(heights, n);
46        
47        int area = INT_MIN;
48        for(int i=0; i<n; i++) {
49            int l = heights[i];
50            
51            if(next[i] == -1) {
52                next[i] = n;
53            }
54             int b = next[i] - prev[i] - 1;
55            int newArea = l*b;
56            area = max(area, newArea);
57        }
58        return area;
59
60    }
61};