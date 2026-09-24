class Solution {
public:

    int SumofDigits(int n)
    {
        int sum = 0;
        while(n)
        {
            int last = n % 10;
            sum = sum + last;
            n = n / 10;
        }

        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i< n; i++)
        {
            int sum = SumofDigits(nums[i]);

            if(sum == i)
            {
                return i;
            }
        }

        return -1;
    }
};