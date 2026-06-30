1class Solution {
2public:
3    bool canConstruct(string ransomNote, string magazine) {
4         map<char,int>mpp1;
5         for(int i=0;i<magazine.size();i++){
6            mpp1[magazine[i]]++;
7         }
8
9         // now scan ransomNote  (Direct check ho ra hai iss method se cool hai yeh map vala method , map ki indexing ko utilise krna sikho) 
10           for (char c : ransomNote) {
11            if (mpp1[c] > 0) {  // check if available
12                mpp1[c]--;     // use it
13            } else {
14                return false;  // not enough letters
15            }
16        }
17            // don't use find vala method , instead use above method
18            // if(mpp1.find(ransomNote[i])!= mpp1.end()){
19            // count++;
20            // mpp1[ransomNote[i]]--;
21            // }
22         
23      
24   return true;
25    }
26};