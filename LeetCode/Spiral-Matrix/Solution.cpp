1
2class Solution {
3public:
4    vector<int> spiralOrder(vector<vector<int> >& matrix) {
5        
6        
7        vector<int> ans;
8        int row = matrix.size();
9        int col = matrix[0].size();
10        
11        int count = 0;
12        int total = row*col;
13        
14        //index initialisation
15        int startingRow = 0;
16        int startingCol = 0;
17        int endingRow = row-1;
18        int endingCol = col-1;
19        
20        
21        while(count < total) {
22            
23            //print starting row
24            for(int index = startingCol; count < total && index<=endingCol; index++) {
25                ans.push_back(matrix[startingRow][index]);
26                count++;
27            }
28            startingRow++;
29            
30            //print ending column
31            for(int index = startingRow; count < total && index<=endingRow; index++) {
32                ans.push_back(matrix[index][endingCol]);
33                count++;
34            }
35            endingCol--;
36            
37            //print ending row
38            for(int index = endingCol; count < total && index>=startingCol; index--) {
39                ans.push_back(matrix[endingRow][index]);
40                count++;
41            }
42            endingRow--;
43            
44            //print starting column
45            for(int index = endingRow; count < total && index>=startingRow; index--) {
46                ans.push_back(matrix[index][startingCol]);
47                count++;
48            }
49            startingCol++;
50        } 
51        return ans;
52    }
53};
54   