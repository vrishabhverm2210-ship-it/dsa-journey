1class Solution {
2public:
3    string fractionToDecimal(int numerator, int denominator) {
4        if(numerator==0)return "0";
5                string ans = "";
6
7        // Handle sign
8        if ((numerator < 0) ^ (denominator < 0))
9            ans += "-";
10
11        // Convert to positive
12        long long num = abs((long long)numerator);
13        long long den = abs((long long)denominator);
14
15
16            ans += to_string(num / den);
17
18   // Remainder
19        long long rem = num % den;
20
21        // Exact division
22        if (rem == 0)
23            return ans;
24
25  ans += ".";
26
27        // remainder -> position in answer
28        unordered_map<long long, int> mp;
29          while (rem != 0) {
30
31            // Repeating remainder found  
32            if (mp.count(rem)) {
33                ans.insert(mp[rem], "(");
34                ans += ")";
35                break;
36            }
37
38            // Store position of this remainder  // important this step bracket lagane vale time use hoga bohot
39            mp[rem] = ans.size();
40
41            // Generate next decimal digit
42            rem *= 10;
43
44            ans += to_string(rem / den);
45
46            // Get new remainder
47            rem %= den;
48        }
49
50        return ans;
51    }
52};