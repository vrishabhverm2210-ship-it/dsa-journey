1class Solution {
2public:
3
4void fun1(vector<int>& cand, int target,int idx, vector<vector<int>>& res,vector<int>&temp,int currsum){
5    if(idx==cand.size()){
6    if(currsum==target){
7        res.push_back(temp);
8        }
9        return ;
10    }
11    fun1(cand,target,idx+1,res,temp,currsum);
12 if(cand[idx]+currsum <= target){
13    temp.push_back(cand[idx]); 
14    currsum+=cand[idx];
15    fun1(cand,target,idx,res,temp,currsum); // idx aage ni krna because dubara bhi le skte hain
16    temp.pop_back();
17    currsum-=cand[idx];
18    }
19return;
20}
21    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
22         vector<vector<int>> res;
23         vector<int>temp;
24         fun1(candidates,target,0,res,temp,0);
25         return res;
26    }
27};