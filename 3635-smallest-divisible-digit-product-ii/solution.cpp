class Solution {
public:
    vector<int> primes = {2, 3, 5, 7};

    long long addPows(map<int, int>& pows, long long t, int add = 1) {
        while(t > 1) {
            bool flag = false;
            for(auto& p : primes) {
                if(t % p == 0) flag = true, pows[p] += add, t /= p;
            }
            if(!flag && t > 1) return t;
        }
        return t;
    }

    map<int, int> getNeed(map<int, int>& pows1, map<int, int>& pows2, bool add6 = false) {
        map<int, int> diff, need;
        for(auto& p : primes) diff[p] = max(pows1[p] - pows2[p], 0);
        if(add6 && diff[2] > 0 && diff[3] > 0) {
            need[6]++, diff[2]--, diff[3]--;
        }

        need[8] += diff[2] / 3, diff[2] %= 3;
        need[4] += diff[2] / 2, diff[2] %= 2;
        need[2] += diff[2];

        need[9] += diff[3] / 2, diff[3] %= 2;
        need[3] += diff[3];

        need[5] = diff[5];
        need[7] = diff[7];
        return need;
    }

    void buildAns(string& ans, map<int, int>& need, int fill1) {
        for(int x = 0; x < fill1; x++) ans += '1';
        for(auto& [d, cnt] : need) {
            for(int x = 0; x < cnt; x++) ans += ('0' + d);
        }
    }

    string smallestNumber(string num, long long t) {
        map<int, int> powsT;
        long long res = addPows(powsT, t);
        if(res > 1) return "-1";

        map<int, int> powsNum;
        int cnt0 = 0, n = num.size();
        for(int i = 0; i < n; i++) {
            if(num[i] == '0') cnt0++;
            addPows(powsNum, num[i] - '0');
        }

        auto need = getNeed(powsT, powsNum);
        int totalNeed = 0;
        for(auto& [d, cnt] : need) totalNeed += cnt;
        if(cnt0 == 0 && totalNeed == 0) return num;

        for(int i = n - 1; i >= 0; i--) {
            int now = (num[i] - '0');
            addPows(powsNum, now, -1);
            if(now == 0) cnt0--;
            if(cnt0 > 0) continue;
            
            for(int d = now + 1; d <= 9; d++) {
                addPows(powsNum, d);
                auto need1 = getNeed(powsT, powsNum, false);
                auto need2 = getNeed(powsT, powsNum, true);
                
                int totalNeed1 = 0, positionLeft = n - 1 - i;
                for(auto& [d1, cnt] : need1) totalNeed1 += cnt;
                int totalNeed2 = 0;
                for(auto& [d2, cnt] : need2) totalNeed2 += cnt;
                
                if(totalNeed1 > positionLeft && totalNeed2 > positionLeft) {
                    addPows(powsNum, d, -1);
                    continue;
                }

                string ans1(num.begin(), num.begin() + i);
                ans1 += ('0' + d);
                string ans2 = ans1;
                buildAns(ans1, need1, positionLeft - totalNeed1);
                buildAns(ans2, need2, positionLeft - totalNeed2);
                if(ans1.size() < ans2.size()) return ans1;
                if(ans1.size() > ans2.size()) return ans2;
                return min(ans1, ans2);
            }
        }

        // Now powsNum is empty
        auto need1 = getNeed(powsT, powsNum, false);
        auto need2 = getNeed(powsT, powsNum, true);

        int totalNeed1 = 0;
        for(auto& [d1, cnt] : need1) totalNeed1 += cnt;
        int totalNeed2 = 0;
        for(auto& [d2, cnt] : need2) totalNeed2 += cnt;

        string ans1, ans2;
        buildAns(ans1, need1, max(0, n + 1 - totalNeed1));
        buildAns(ans2, need2, max(0, n + 1 - totalNeed2));
        if(ans1.size() < ans2.size()) return ans1;
        if(ans1.size() > ans2.size()) return ans2;
        return min(ans1, ans2);
    }
};
