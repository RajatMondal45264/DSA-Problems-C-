class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        long long even = 1;
        long long odd = 0;
        long long prefix = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++)
        {
            prefix += arr[i];

            if(prefix % 2 == 0)
            {
                ans = (ans + odd) % mod;
                even++;
            }

            else
            {
                ans = (ans + even) % mod;
                odd++;
            }

        }

        return ans % mod;
    }
};