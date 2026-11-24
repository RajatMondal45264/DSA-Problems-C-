class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            long long p = 1, g = 0, l = 1;
            for (int j = i; j < n; j++) {
                long long x = nums[j];
                p *= x;
                if (p > 25200) break; 
                g = __gcd(g, x);
                l = l / __gcd(l, x) * x;
                if (p == l * g) {
                    best = max(best, j - i + 1);
                }
            }
        }
        return best;
    }
};