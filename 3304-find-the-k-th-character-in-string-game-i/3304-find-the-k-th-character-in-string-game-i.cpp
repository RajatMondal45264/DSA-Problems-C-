class Solution {
public:
    char kthCharacter(int k) {
        int pos = k - 1;   // 0-based position
        int shifts = 0;

        // Count set bits manually
        while (pos > 0) {
            shifts += pos % 2;   // or: shifts += (pos & 1);
            pos /= 2;            // or: pos >>= 1;
        }

        return (char)('a' + (shifts % 26));
    }
};