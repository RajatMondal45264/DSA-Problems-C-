class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        long long ans = 0;

        for(int i = 0; i< n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        for(auto it = mp.begin(); it != mp.end();it++)
        {
            if(it->second.size() >= 3)
            {
                int diff1 = it->second[1] - it->second[0];
                bool flag = true;
                int i = 0;
                while(i+1 < it->second.size())
                {
                    int diff2 = it->second[i+1] - it->second[i];

                    if(diff1 != diff2)
                    {
                        flag = false;
                        break; 
                    }

                    i++;
                }

                if(flag)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};