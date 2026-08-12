class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int len = 0;
        unordered_map<int,int> count;

        while(end < n)
        {
            count[nums[end]]++;
            
            // if frequency > k aya tou window size decrease karo
            while(count[nums[end]] > k)
            {
                count[nums[start]]--;
                start++;
            }


            // as usuallength badao jab tab sab se bada window na mile 
            len = max(len, end -start+1);
            end++;
        }

        return len;
    }
};