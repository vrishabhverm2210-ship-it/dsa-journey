1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        int n=numbers.size();
5        // 2 pointer approaxch
6        int i=0;
7        int j=n-1;
8        while(i<j){
9            if(numbers[i]+numbers[j] == target){
10                return {i+1,j+1};
11                }
12            else if(numbers[i]+numbers[j]>target){
13                j--;
14            }
15            else{
16                i++;
17            }
18        }
19        return {-1,-1};
20
21    }
22};