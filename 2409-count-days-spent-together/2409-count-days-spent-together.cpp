class Solution {

    int toDayOfYear(string date) {
        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int total = day;
        for (int i = 0; i < month - 1; i++) {
            total += daysInMonth[i];
        }
        return total;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

    int aliceArrive = toDayOfYear(arriveAlice);
    int aliceLeave  = toDayOfYear(leaveAlice);
    int bobArrive   = toDayOfYear(arriveBob);
    int bobLeave    = toDayOfYear(leaveBob);
    
    int start = max(aliceArrive, bobArrive);

    int end = min(aliceLeave, bobLeave);
    
    if (start > end) {
        return 0;
    }

        return end - start + 1;
    }
};