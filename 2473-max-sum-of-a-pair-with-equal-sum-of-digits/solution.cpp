class Solution {
public:
    int getDigitsSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
     }

    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> vpi;
        for(int x : nums) {
            vpi.push_back(make_pair(this->getDigitsSum(x), x));
        }
        sort(vpi.begin(), vpi.end());
        
        int ans = -1;
        int size = vpi.size();
        for(int i = 0; i < size - 1; i++) {
            auto x = vpi[i];
            auto y = vpi[i + 1];
            if(x.first == y.first) {
                ans = max(x.second + y.second, ans);
            }
        }
        
        return ans;
    }
};
