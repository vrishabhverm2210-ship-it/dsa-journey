1class Solution {
2public:
3int sum(int no){
4    int sum1=0;
5    while(no>0){
6        int digit=no%10;
7        sum1+=digit;
8        no/=10;
9    }
10    return sum1;
11}
12    int addDigits(int num) {
13     while (num >= 10) {
14            num = sum(num);
15        }
16        return num;
17    }
18};