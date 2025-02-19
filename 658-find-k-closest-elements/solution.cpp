class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> dq;
        for(int num : arr) {
            if(dq.size() < k) dq.push_back(num);
            else {
                int front = dq.front();
                if(abs(front - x) > abs(num - x)) {
                    dq.pop_front();
                    dq.push_back(num);
                }
            }
        }
        
        vector<int> output(dq.begin(), dq.end());
        return output;
    }
};
