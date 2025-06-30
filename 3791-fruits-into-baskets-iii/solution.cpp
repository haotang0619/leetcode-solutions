class Solution {
public:
    // Checked a weird solution:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        deque<int> b(baskets.begin(), baskets.end());
        int maxB = *max_element(baskets.begin(), baskets.end());

        for(auto x : fruits) {
            if(x > maxB) continue;
            stack<int> sk;
            while(!b.empty() && b.front() < x) {
                sk.push(b.front());
                b.pop_front();
            }
            if(!b.empty()) b.pop_front();
            while(!sk.empty()) {
                b.push_front(sk.top());
                sk.pop();
            }
        }
        return b.size();
    }
};
