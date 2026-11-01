class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1;

        int prime = value;

        for (int i = 2; 1LL * i * i <= value; i++) {
            if (value % i == 0) {
                prime = i;
                break;
            }
        }

        int leftCount = (value - prime) / 2;
        if (index > leftCount) return -1;

        int rightCount = n - index - 1;

        if (rightCount == 0) return value;

        return 1LL * value + prime + 2LL * (rightCount - 1);
    }
};