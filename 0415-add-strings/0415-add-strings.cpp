class Solution {
public:
    string Sum(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size() - 1;
        int j = nums2.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = 0;
            int digit2 = 0;

            if (i >= 0) digit1 = nums1[i];
            if (j >= 0) digit2 = nums2[j];

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;                 
            result.push_back((sum % 10) + '0'); 

            i--;
            j--;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }

    string addStrings(string num1, string num2) {
        vector<int> nums1;
        for (int i = 0; i < num1.size(); i++) {
            nums1.push_back(num1[i] - '0');  
        }

        vector<int> nums2;
        for (int i = 0; i < num2.size(); i++) {
            nums2.push_back(num2[i] - '0');
        }

        return Sum(nums1, nums2); 
    }
};