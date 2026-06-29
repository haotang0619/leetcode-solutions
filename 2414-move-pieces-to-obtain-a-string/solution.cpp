class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0, n1 = start.size(), n2 = target.size();
        int cnt1 = 0, cnt2 = 0;
        while(j < n2) {
            while(i < n1 && start[i] == '_') i++, cnt1++;
            while(j < n2 && target[j] == '_') j++, cnt2++;
            if(i >= n1 && j >= n2) return cnt1 == cnt2;
            if(i >= n1 || j >= n2) return false;
            if(start[i] != target[j]) return false;
            char now = start[i];
            if(now == 'L') {
                if(cnt1 < cnt2) return false;
                swap(start[i], start[j]);
                i++, j++, cnt1 -= cnt2, cnt2 = 0;
            } else { // now == 'R'
                if(cnt1 > cnt2) return false;
                if(i != j) {
                    int rcnt = 0;
                    start[i++] = '_';
                    while(i <= j) {
                        if(start[i] == 'L') return false;
                        if(start[i] == 'R') rcnt++, start[i] = '_';
                        i++;
                    }
                    start[i - 1] = 'R';
                    while(rcnt > 0) {
                        if(i >= n1) return false;
                        if(start[i] == 'L') return false;
                        if(start[i] == '_') rcnt--, start[i] = 'R';
                        i++;
                    }
                }
                i = j = j + 1, cnt1 = 0, cnt2 = 0;
            }
        }
        return true;
    }
};
