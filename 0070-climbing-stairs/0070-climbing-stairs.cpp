class Solution {
public:
    int climbStairs(int n) {
        int curr , next = 1, next2 = 0;

        for(int i = n-1;i>= 0;i--)
        {
            curr = next + next2;
            next2 = next;
            next = curr;
        } 

        return curr;
    }
};