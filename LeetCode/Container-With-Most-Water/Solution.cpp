1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int n=height.size();
5        int i=0;
6        int j=n-1;
7        int res=INT_MIN;
8        while(i<j){
9            int len=min(height[i],height[j]);
10            int breath=j-i;
11            int area=len*breath;
12            res=max(res,area);
13            if(height[i]>height[j])j--;
14            else if(height[i]<height[j])i++;
15            else{
16                i++;
17                j--;
18            }
19        }
20        return res;
21    }
22};