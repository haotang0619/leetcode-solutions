class Solution {
public:
    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrMonA = 0, arrDayA = 0, lefMonA = 0, lefDayA = 0;
        int arrMonB = 0, arrDayB = 0, lefMonB = 0, lefDayB = 0;
        for(int i = 0; i < 5; i++) {
            if(i < 2) {
                arrMonA = arrMonA * 10 + (arriveAlice[i] - '0');
                lefMonA = lefMonA * 10 + (leaveAlice[i] - '0');
                arrMonB = arrMonB * 10 + (arriveBob[i] - '0');
                lefMonB = lefMonB * 10 + (leaveBob[i] - '0');
            } else if(i > 2) {
                arrDayA = arrDayA * 10 + (arriveAlice[i] - '0');
                lefDayA = lefDayA * 10 + (leaveAlice[i] - '0');
                arrDayB = arrDayB * 10 + (arriveBob[i] - '0');
                lefDayB = lefDayB * 10 + (leaveBob[i] - '0');
            }
        }
        pair<int, int> intA = {0, 0}, intB = {0, 0};
        for(int i = 1; i < arrMonA; i++) intA.first += days[i]; intA.first += arrDayA;
        for(int i = 1; i < arrMonB; i++) intB.first += days[i]; intB.first += arrDayB;
        for(int i = 1; i < lefMonA; i++) intA.second += days[i]; intA.second += lefDayA;
        for(int i = 1; i < lefMonB; i++) intB.second += days[i]; intB.second += lefDayB;
        return max(0, min(intA.second, intB.second) - max(intA.first, intB.first) + 1);
    }
};
