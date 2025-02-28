class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int size = nums.size();
        set<int> st;
        for(int i = 0; i < size; i++) {
            int curr = i;
            bool valid = true;
            set<int> st1;
            while(true) {
                valid = valid && (nums[i] * nums[curr] > 0);
                if(st1.find(curr) != st1.end()) {
                    if(valid) return true;
                    break;
                }
                st1.insert(curr);
                int next = ((curr + nums[curr]) % size + size) % size;
                if(next == curr) break;
                curr = next;
            }
        }
        return false;
    }
};
