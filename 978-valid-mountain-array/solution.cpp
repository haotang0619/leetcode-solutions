class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int status = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] == arr[i - 1]) return false;
            if(arr[i] > arr[i - 1]) {
                if(status == 0) status = 1;
                else if(status != 1) return false;
            } else {
                if(status == 1) status = 2;
                else if(status != 2) return false;
            }
        }
        return status == 2;
    }
};
