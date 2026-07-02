1class Solution {
2public:
3    int maximumSum(vector<int>& arr) {
4        // IN THIS QUESTION WE HAVE TWO CHOICES SO MAKE TO VARIABLE
5        int onedelete=INT_MIN;
6        int nodelete=arr[0];
7        int res=arr[0];
8        for(int i=1;i<arr.size();i++){
9            int prevnodelete=nodelete;
10            int prevonedelete=onedelete;
11            // now choices if we still don't want to delete
12            nodelete=max(prevnodelete+arr[i],arr[i]);// out of 4 choices 2 is used here
13            // for remaining two
14            int v;
15            if(prevonedelete==INT_MIN){
16                v=arr[i];
17            }
18            else{
19                v= prevonedelete+arr[i];
20            }
21            onedelete=max(v,prevnodelete);
22            res=max({res,nodelete,onedelete});
23        }
24        return res;
25    }
26};