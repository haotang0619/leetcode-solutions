class Solution {
public:
    bool check(vector<int>& houses, vector<int>& heaters, int& radius) {
        int n = houses.size(), m = heaters.size();
        for(int i = 0, j = 0; i < n; i++) {
            while(j < m && houses[i] > heaters[j] + radius) j++;
            if(j >= m) return false;
            if(houses[i] < heaters[j] - radius) return false;
        }
        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = 1e9;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(check(houses, heaters, m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};
