class Solution {
public:
int mod = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        unordered_set<int> hDiffs;
        for(int i = 0; i < hFences.size(); i++) {
            for(int j = i + 1; j < hFences.size(); j++) {
                hDiffs.insert(abs(hFences[i] - hFences[j]));
            }
        }
        vFences.push_back(1);
        vFences.push_back(n);
        int maxX = -1;
        for(int i = 0; i < vFences.size(); i++) {
            for(int j = i + 1; j < vFences.size(); j++) {
                int x = abs(vFences[i] - vFences[j]);
                if(hDiffs.contains(x)) maxX = max(maxX, x);
            }
        }
        long long ans = -1;
        if(maxX != -1) ans = (long long)maxX * maxX % mod;
        return ans;
    }
};
