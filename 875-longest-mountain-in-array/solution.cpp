class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0, status = 0, n = arr.size();
        for(int i = 0, j = 1; j < n; j++) {
            bool isDown = arr[j] < arr[j - 1], isUp = arr[j] > arr[j - 1], isSame = arr[j] == arr[j - 1];
            if(status == 0) {
                if(isDown) {
                    if(j > i + 1) status = 1, ans = max(ans, j - i + 1);
                    else i = j;
                } else if(isSame) i = j;
            } else {
                if(isDown) ans = max(ans, j - i + 1);
                else if(isUp) i = j - 1, status = 0;
                else i = j, status = 0;
            }
        }
        return ans;
    }
};
