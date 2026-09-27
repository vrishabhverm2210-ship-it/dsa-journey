1class Solution {
2private:
3    vector<int> nextSmallerElement(vector<int> arr, int n) {
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
38    
39public:
40    int largestRectangleArea(vector<int>& heights) {
41        int n= heights.size();
42        
43        vector<int> next(n);
44        next = nextSmallerElement(heights, n);
45            
46        vector<int> prev(n);
47        prev = prevSmallerElement(heights, n);
48        
49        int area = INT_MIN;
50        for(int i=0; i<n; i++) {
51            int l = heights[i];
52            
53            if(next[i] == -1) {
54                next[i] = n;
55            }
56             int b = next[i] - prev[i] - 1;
57            int newArea = l*b;
58            area = max(area, newArea);
59        }
60        return area;
61    }
62};