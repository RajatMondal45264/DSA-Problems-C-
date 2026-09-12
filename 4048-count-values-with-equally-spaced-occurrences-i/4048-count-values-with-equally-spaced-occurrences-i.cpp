class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,vector<int>> mp;
        

        for(int i = 0; i< n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second.size() == 3)
            {
                int i1 = it->second[0];
                int i2 = it->second[1];
                int i3 = it->second[2];

                int diff1 = i2 - i1;
                int diff2 = i3 - i2;

                if(diff1 == diff2)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};