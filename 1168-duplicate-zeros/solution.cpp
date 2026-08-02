class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> tmp(n);
        for(int i = 0, j = 0; i < n; i++) {
            if(arr[i] > 0) tmp[j++] = arr[i];
            else {
                tmp[j++] = 0;
                if(j >= n) break;
                tmp[j++] = 0;
            }
            if(j >= n) break;
        }
        for(int i = 0; i < n; i++) arr[i] = tmp[i];
    }
};
