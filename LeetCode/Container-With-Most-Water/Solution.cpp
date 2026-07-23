1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int n=height.size();
5        int i=0;
6        int j=n-1;
7        int maxi=INT_MIN;
8        while(i<j){
9         int breadth=j-i;
10         int len;
11       if(height[i]<height[j])len=height[i];
12       else len =height[j] ;
13       
14         int area=len*breadth;
15         maxi=max(maxi,area);
16         if(height[i]<height[j])i++;
17         else j--;
18        }
19        return maxi;
20    }
21};