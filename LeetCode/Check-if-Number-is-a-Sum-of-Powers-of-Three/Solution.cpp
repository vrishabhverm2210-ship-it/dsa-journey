1class Solution {
2public:
3    bool checkPowersOfThree(int n) {
4        while(n>0){
5            if(n%3==2)return false;
6            n=n/3;
7        }
8        return true;
9    }
10};