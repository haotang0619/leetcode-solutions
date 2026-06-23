class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diffArr(n + 1, 0);
        for(int i = 0; i < n; i++) {
            int l = lights[i];
            if(l == 0) continue;
            diffArr[max(i - l, 0)] += 1;
            diffArr[min(i + l, n - 1) + 1] -= 1;
        }
        vector<int> status(n);
        for(int i = 0; i < n; i++) {
            status[i] = diffArr[i] + (i > 0 ? status[i - 1] : 0);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(status[i] == 0) {
                ans++;
                status[i] = 1;
                if(i + 1 < n) status[i + 1] = 1;
                if(i + 2 < n) status[i + 2] = 1;
            }
        }
        return ans;
    }
};
