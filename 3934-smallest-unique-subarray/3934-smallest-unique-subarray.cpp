
class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long modPower(long long base, int exp)
    {
        long long ans = 1;

        while(exp > 0)
        {
            if(exp & 1)
                ans = (ans * base) % MOD;

            base = (base * base) % MOD;
            exp /= 2;
        }

        return ans;
    }

    bool check(vector<int>& nums, int size, int base)
    {
        int n = nums.size();

        unordered_map<long long, int> mp;

        long long hash = 0;
        long long p = modPower(base, size - 1);

        for(int i = 0; i < n; i++)
        {
            hash = (hash * base + nums[i]) % MOD;

            if(i >= size - 1)
            {
                mp[hash]++;

                hash = (hash - (p * nums[i - size + 1]) % MOD + MOD) % MOD;
            }
        }

        for(auto &it : mp)
        {
            if(it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums)
    {
        int n = nums.size();

        int base = *max_element(nums.begin(), nums.end()) + 1;

        int start = 1;
        int end = n;
        int result = n;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(check(nums, mid, base))
            {
                result = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return result;
    }
};
