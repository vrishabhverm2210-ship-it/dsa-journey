1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int row=matrix.size();
5        int col=matrix[0].size();
6        int rowindex=0;
7        int colindex=col-1;
8        while(rowindex<row&&colindex>=0){
9            int element=matrix[rowindex][colindex];
10            if(element==target){
11                return 1;
12            }
13            if(target>element){
14                rowindex++;
15
16            }
17            else{ 
18                colindex--;
19            }
20        }
21  return 0; 
22     }
23};