class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < nums[minIdx])
            {
               minIdx = i;
            }
            if(nums[i] > nums[maxIdx])
            {
                maxIdx = i;
            }
        }

        int a = max(minIdx, maxIdx) + 1; 
        int b = n - min(minIdx, maxIdx);            
        int c = min(minIdx, maxIdx) + 1 + n - max(minIdx, maxIdx); 

        return min({a, b, c});
    }
};