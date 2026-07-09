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
13         int area=len*breadth;
14         maxi=max(maxi,area);
15         if(height[i]<height[j])i++;
16         else j--;
17        }
18        return maxi;
19    }
20};