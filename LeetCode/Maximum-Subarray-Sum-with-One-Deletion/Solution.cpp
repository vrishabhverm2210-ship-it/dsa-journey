1class Solution {
2public:
3    int maximumSum(vector<int>& arr) {
4        int onedelete=INT_MIN;
5        int nodelete=arr[0];
6        int res=arr[0];
7        int v;
8        for(int i=1;i<arr.size();i++){
9            int prevnodelete=nodelete;
10            int prevdelete=onedelete;
11            nodelete=max(prevnodelete+arr[i], arr[i]);
12            if(prevdelete==INT_MIN){
13                v=arr[i];   // means let's start with deleting this itself
14            }
15            else{
16                v=prevdelete+arr[i];
17            }
18            onedelete=max(v,prevnodelete);//+ delete hora hai yeh current vala);
19           res=max({res,onedelete,nodelete});
20        }
21        return res;
22    }
23};
24