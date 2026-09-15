1class Solution {
2public:
3    int countPrimes(int n) {
4        int count=1; // except two all even numbers are comosite sono need to check them
5        vector<bool>res(n,1);  // 1 means prime
6        if(n==0||n==1)return 0;
7        res[0]=0;
8        res[1]=0;
9        if(n==2)return 0;
10        // res[2]=1;
11        for(int i=3;i*i<n;i+=2){
12            if(res[i]==1){
13            for(int j=i*i;j<n;j=j+2*i){
14
15                res[j]=0;
16            }
17            }
18        }
19        for(int i=3;i<n;i+=2 ){
20        if(res[i]==1){
21            count++;
22        }
23        }
24        return count;
25    }
26};