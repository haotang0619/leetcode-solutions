class Solution {
public:
    string maximumTime(string time) {
        for(int i = 0; i < 5; i++) {
            if(time[i] != '?') continue;
            if(i == 0) {
                if(time[1] == '?' || time[1] <= '3') {
                    time[0] = '2';
                } else time[0] = '1';
            } else if(i == 1) {
                if(time[0] == '2') time[1] = '3';
                else time[1] = '9';
            } else if(i == 2) time[2] = ':';
            else if(i == 3) time[3] = '5';
            else if(i == 4) time[4] = '9';
        }
        return time;
    }
};
