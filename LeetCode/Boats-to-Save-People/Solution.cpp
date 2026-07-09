1class Solution {
2public:
3    int numRescueBoats(vector<int>& people, int limit) {
4        sort(people.begin(),people.end());
5        int count=0;
6        int n=people.size();
7        int i=0;
8        int j=n-1;
9        while(i<=j){
10            int sum=people[i]+people[j];
11            if(sum<=limit){
12                i++;
13                j--;
14            }
15            else{
16                j--;
17            }
18count++;        // for every iteration boat is used
19        }
20        return count;
21    }
22};