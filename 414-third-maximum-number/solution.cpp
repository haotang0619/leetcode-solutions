class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long arr[3] = {LLONG_MIN, LLONG_MIN, LLONG_MIN};
        for(int &x : nums) {
            if(arr[0] == x || arr[1] == x || arr[2] == x) continue;
            if(arr[2] < x) arr[2] = x;
            if(arr[1] < arr[2]) swap(arr[1], arr[2]);
            if(arr[0] < arr[1]) swap(arr[0], arr[1]);
        }
        return arr[2] == LLONG_MIN ? arr[0] : arr[2];
    }
};
