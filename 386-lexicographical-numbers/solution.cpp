class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans = {1};
        int now = 1;
        while(ans.size() < n) {
            if(now * 10 <= n) {
                now *= 10;
                ans.push_back(now);
            } else if(now + 1 <= n && ((now + 1) % 10) > (now % 10)) {
                now += 1;
                ans.push_back(now);
            } else {
                now /= 10;
                now += 1;
                while(now % 10 == 0) now /= 10;
                ans.push_back(now);
            }
        }
        return ans;
    }
};
