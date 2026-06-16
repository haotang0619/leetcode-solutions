class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(m + 1 >= n || arr[m] >= arr[m + 1]) r = m;
            else l = m + 1;
        }
        return l;
    }
};
