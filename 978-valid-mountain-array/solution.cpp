class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        bool isAsc = true;
        int ascCnt = 1, descCnt = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(isAsc) {
                if(arr[i] > arr[i - 1]) ascCnt++;
                else if(arr[i] == arr[i - 1]) return false;
                else {
                    isAsc = false;
                    descCnt = 2;
                }
            } else {
                if(arr[i] < arr[i - 1]) descCnt++;
                else return false;
            }
        }
        return ascCnt > 1 && descCnt > 1;
    }
};
