class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq, freqCnt;
        for(auto& num : nums) {
            if(freq[num] > 0) freqCnt[freq[num]]--;
            freq[num]++;
            freqCnt[freq[num]]++;
        }
        for(auto& num : nums) {
            if(freqCnt[freq[num]] == 1) return num;
        }
        return -1;
    }
};
