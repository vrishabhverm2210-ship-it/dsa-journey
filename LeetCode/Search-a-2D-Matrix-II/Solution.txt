1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int n=matrix.size();
5        int m=matrix[0].size();
6        int row=n-1;
7        int col=0;
8        while(row>=0 && col<=m-1){
9            if(matrix[row][col]==target)
10            {
11                return true;
12            }
13            else if(matrix[row][col]>target)
14            {
15                row--;
16            }
17            else
18            {
19                col++;
20            }
21        }
22        return false;
23    }
24};