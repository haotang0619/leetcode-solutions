class Solution {
public:
    tuple<int, int, int> process(string& time) {
        int hour = 0, min = 0, sec = 0;
        for(int i = 0; i < 2; i++) hour = hour * 10 + (time[i] - '0');
        for(int i = 3; i < 5; i++) min = min * 10 + (time[i] - '0');
        for(int i = 6; i < 8; i++) sec = sec * 10 + (time[i] - '0');
        return {hour, min, sec};
    }
    
    int secondsBetweenTimes(string startTime, string endTime) {
        auto [h1, m1, s1] = process(startTime);
        auto [h2, m2, s2] = process(endTime);
        return (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);
    }
};
