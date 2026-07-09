class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0, n = heights.size();
        priority_queue<int> pq;
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i - 1];
            if(diff > 0) {
                bricks -= diff;
                pq.push(diff);
                while(bricks < 0 && ladders > 0 && !pq.empty()) {
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
                if(bricks < 0) break;
            }
            ans = i;
        }
        return ans;
    }
};
