1class Solution {
2public:
3    int countPrimes(int n) {
4        int count=1;
5        vector<bool>res(n,0);  // 0 means all prime
6if(n <= 2) return 0;
7       
8        for(int i=3;i*i<n; i += 2){       
9            if(res[i]==0){
10            for(int j=i*i;j<n;j+=2*i){
11                res[j]=1;
12            }
13        }
14        }
15        for(int i=3;i<res.size(); i += 2){
16            if(res[i]==0){
17                count++;
18            }
19        }
20        return count;
21    }
22};