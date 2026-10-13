class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>arr;

        for(int i = 0; i< nums.size(); i++)
        {
            long long x = nums[i];
            arr.push_back(x*x);
        }

        sort(arr.begin(),arr.end());
        int n = arr.size();
        long long ans = 0;

        for(int i = 0; i< n/2; i++)
        {
            ans -= arr[i];
        }

        for(int i = n/2; i < n; i++)
        {
            ans += arr[i];
        }

        return ans;
    }
};