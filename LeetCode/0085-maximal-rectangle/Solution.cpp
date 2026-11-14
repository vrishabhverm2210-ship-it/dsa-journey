class Solution {
public:
vector<int> nextSmallerElement(vector<int> arr, int n) {
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
 for(int i=n-1;i>=0;i--){
    int curr=arr[i];
    while(st.top()!=-1 && arr[st.top()] >= curr){
        st.pop();
    }
    ans[i]=st.top();
    st.push(i);
 }
 return ans;
}
vector<int> prevSmallerElement(vector<int> arr, int n){
   stack<int>st;
    st.push(-1);
    vector<int>ans(n);
 for(int i=0;i<n;i++){
    int curr=arr[i];
    while(st.top()!=-1 && arr[st.top()] >= curr){
        st.pop();
    }
    ans[i]=st.top();
    st.push(i);
 }
 return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int len=heights[i];

 if(next[i] == -1) {
                next[i] = n;
            }
            int breadth=next[i]-prev[i]-1;
            int area=len*breadth;
            ans=max(ans,area);
            
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
     
        if(matrix.empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);

        int ans = 0;

        // Process row by row
        for(int i = 0; i < n; i++) {

            // Build histogram
            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Apply LC 84
            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};