class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixsum = 0;
        int total = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;

        for(int i = 0;i< n;i++)
        {
            prefixsum += nums[i];
            if(mp.count(prefixsum-k))
            {
                total += mp[prefixsum-k];
                mp[prefixsum]++;
            }
            else
            {
                mp[prefixsum]++;
            }
        }

        return total;
    }
};