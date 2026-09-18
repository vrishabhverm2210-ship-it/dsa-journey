1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4         vector<int>res;
5         int n=matrix.size();
6         int m=matrix[0].size();
7         int startrow=0;
8         int endrow=n-1;
9         int startcol=0;
10         int endcol=m-1;
11        int total=n*m;
12        int count=0;
13         while(count < total){
14        // print the starting row
15        for(int i=startcol;i<=endcol && count<total;i++){
16            res.push_back(matrix[startrow][i]);
17            count++;
18        }
19        startrow++;
20        // print last col
21        for(int i=startrow;i<=endrow && count<total ;i++){
22            res.push_back(matrix[i][endcol]);
23            count++;
24        }
25        endcol--;
26        // print end row
27        for(int i=endcol;count<total && i>=startcol;i--){
28         res.push_back(matrix[endrow][i]);
29         count++;
30        }
31        endrow--;
32        // print startcol
33        for(int i=endrow;count<total && i>=startrow;i--){
34            res.push_back(matrix[i][startcol]);
35            count++;
36        }
37        startcol++;
38    }
39    return res;
40    }
41};