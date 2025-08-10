class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[limit[i]].push_back(value[i]);
        for(auto &[l, v] : mp) sort(v.begin(), v.end(), greater<int>());
        long long ans = 0;
        int actCnt = 0;
        vector<bool> inact(n + 1, false);
        for(int i = 1; i <= n; i++) {
            if(!mp.contains(i)) continue;
            int now = 0;
            for(auto x : mp[i]) {
                if(actCnt < i) {
                    actCnt++;
                    now++;
                    ans += x;
                    if(actCnt < i && !inact[actCnt]) {
                        inact[actCnt] = true;
                        actCnt -= mp[actCnt].size();
                    }
                } else break;
            }
            if(actCnt >= i) {
                inact[i] = true;
                actCnt -= now;
            }
        }
        return ans;
    }
};
