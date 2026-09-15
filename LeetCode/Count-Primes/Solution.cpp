1class Solution {
2public:
3    int countPrimes(int n) {
4       int count=0;
5       vector<bool>prime(n+1,true);
6       prime[0]=prime[1]=false;
7       for(int i=2;i<n;i++){
8        if(prime[i]){
9            count++;
10        }
11           for(int j=2*i;j<n;j+=i){
12             prime[j]=0;
13   }
14       } 
15 return count;
16     }
17};