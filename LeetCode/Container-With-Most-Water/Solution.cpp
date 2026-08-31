1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int i=0;
5        int j=height.size()-1;
6        int maxi=INT_MIN;
7        while(i<j){
8            int len=j-i;
9            int breadth=min(height[i],height[j]);
10            int area=len*breadth;
11            maxi=max(maxi,area);
12            if(height[i]>height[j]){
13                j--;
14            }
15            else if(height[i]<height[j]){
16                i++;
17            }
18            else{
19                i++;
20                j--;
21            }
22        }
23        return maxi;
24    }
25};