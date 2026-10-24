class Solution {
public:
    int dayNumber(string d) {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(d.substr(0, 2));
        int day = stoi(d.substr(3, 2));

        int total = 0;
        for (int i = 0; i < month - 1; i++) total += days[i];
        return total + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(dayNumber(arriveAlice), dayNumber(arriveBob));
        int end = min(dayNumber(leaveAlice), dayNumber(leaveBob));

        if (end < start) return 0;
        return end - start + 1;
    }
};