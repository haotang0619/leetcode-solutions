class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans1 = 0;
        // Without reorder
        for(int i = 0; i < arr.size(); i++) ans1 += abs(arr[i] - brr[i]);

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        long long ans2 = k;
        for(int i = 0; i < arr.size(); i++) ans2 += abs(arr[i] - brr[i]);
        
        return min(ans1, ans2);
    }
};
