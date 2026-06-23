class Solution {
public:
    bool check(vector<int>& bloomDay, int d, int m, int k) {
        int acc = 0, cnt = 0, n = bloomDay.size();
        for(int i = 0; i <= n; i++) {
            if(i == n || d < bloomDay[i]) acc += cnt / k, cnt = 0;
            else cnt++;
        }
        return acc >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long needed = (long long)m * k;
        if(n < needed) return -1;
        int maxDay = -1;
        for(int i = 0; i < n; i++) maxDay = max(maxDay, bloomDay[i]);
        int l = 1, r = maxDay;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(check(bloomDay, mid, m, k)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
