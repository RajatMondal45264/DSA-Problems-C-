class Solution {
public:
    bool canAliceWin(int n) {

        if(n < 10)
        {
            return false;
        }

        bool turn = 1; // Alice
        int steps = 10;
        n = n - steps;
        steps--;

        while(n >= steps)
        {
            n = n - steps;
            turn = !(turn);
            steps--; 
        }

        if(turn)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};