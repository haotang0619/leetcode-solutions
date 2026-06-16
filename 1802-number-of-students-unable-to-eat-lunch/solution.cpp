class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        for(int i = 0, j = 0; j < n; j++) {
            int now = i;
            while(now < i + n && students[now % n] != sandwiches[j]) now++;
            if(now < i + n) {
                students[now % n] = -1;
                i = (now + 1) % n;
            } else return n - j;
        }
        return 0;
    }
};
