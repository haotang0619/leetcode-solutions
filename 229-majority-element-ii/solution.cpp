// Asked GPT for O(1) space
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> candidates = {INT_MIN, INT_MAX}, cnts = {0, 0};
        for(int i = 0; i < n; i++) {
            if(candidates[0] == nums[i]) cnts[0]++;
            else if(candidates[1] == nums[i]) cnts[1]++;
            else if(cnts[0] == 0) candidates[0] = nums[i], cnts[0]++;
            else if(cnts[1] == 0) candidates[1] = nums[i], cnts[1]++;
            else cnts[0]--, cnts[1]--;
        }
        vector<int> ans;
        for(auto& num : candidates) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(num == nums[i]) cnt++;
            }
            if(cnt > n / 3) ans.push_back(num);
        }
        return ans;
    }
};
