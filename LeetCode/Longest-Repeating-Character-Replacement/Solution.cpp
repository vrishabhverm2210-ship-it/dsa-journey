1class Solution {
2public:
3int maxcnt(vector<int>& freq){
4    int maxi=INT_MIN;
5    for(int i=0;i<26;i++){
6        maxi=max(maxi,freq[i]);
7    }
8    return maxi;
9}
10    int characterReplacement(string s, int k) {
11        // let;s build vector instead of map now because we have to keep the track of the count also
12    vector<int> freq(26, 0); // for frequencies and also there are only the uppercase letters
13    int low=0;
14    int res=0;
15    for(int high=0;high<s.size();high++){
16        freq[s[high]- 'A']++;    // new thing  
17        // shrinking phase
18        while((high-low+1)-maxcnt(freq) > k){
19             freq[s[low]-'A']--;
20             low++;
21        }
22        // update the res
23        res=max(res,high-low+1);
24    }
25return res;
26    }
27};