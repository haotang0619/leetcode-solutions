class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, minSum = k * threshold, n = arr.size(), now = 0;
        for(int i = 0, j = 0; j < n; j++) {
            now += arr[j];
            if(j - i >= k) now -= arr[i++];
            if(j >= k - 1 && now >= minSum) ans++; 
        }
        return ans;
    }
};
