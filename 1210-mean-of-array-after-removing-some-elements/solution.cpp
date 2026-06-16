class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        double ans = 0;
        for(int i = n / 20; i < n - n / 20; i++) ans += arr[i];
        return ans / (n - n / 10);
    }
};
