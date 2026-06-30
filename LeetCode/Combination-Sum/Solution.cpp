1class Solution {
2public:
3void fun(vector<int>& cand, int idx,vector<vector<int>>&ans,vector<int>temp,int target,int n,int sum){
4    // base condition
5    if( idx==n ){
6        if(sum==target){
7        ans.push_back(temp);
8        }
9         return;// yeh return miss nhi krna hai 
10    }
11        // choices no. lena hai ya nahi , koi condition toh nahi hai
12    fun(cand,idx+1,ans,temp,target,n,sum); // lena nahi hai , directly increase the index
13    if(cand[idx]+sum <= target){
14    temp.push_back(cand[idx]); 
15    sum+=cand[idx];
16    fun(cand,idx,ans,temp,target,n,sum); // idx aage ni krna because dubara bhi le skte hain
17    temp.pop_back();
18    sum-=cand[idx];
19    }
20
21    return;
22
23}
24    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
25         vector<vector<int>>ans;
26         vector<int>temp;
27         fun(candidates,0,ans,temp,target,candidates.size(),0);
28         return ans;
29    }
30};