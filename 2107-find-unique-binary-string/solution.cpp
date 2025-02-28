class Solution {
public:
    string toBin(int num, int len) {
        string bin = "";
        for (int i = 0; i < len; i++) {
            bin.push_back(num & 1 ? '1' : '0');
            num >>= 1;
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int ans = 0;
        while(true) {
            string s = this->toBin(ans, nums.size());
            if(find(nums.begin(), nums.end(), s) == nums.end()) return s;
            ans++;
        }
    }
};
