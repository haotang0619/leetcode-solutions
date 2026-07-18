class Solution {
public:
    int racecar(int target) {
        map<pair<int, int>, int> mp; // [[pos, speed], minIns]
        mp[{0, 1}] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; // [ins, [pos, speed]]
        pq.push({0, {0, 1}});
        while(!pq.empty()) {
            auto [ins, info] = pq.top();
            pq.pop();
            auto& [pos, speed] = info;
            if(pos == target) return ins;
            if(ins > mp[{pos, speed}]) continue;
            if(pos >= target * 2 || pos < 0) continue;
            
            // Put an 'A'
            if(!mp.contains({pos + speed, speed * 2}) || mp[{pos + speed, speed * 2}] > ins + 1) {
                mp[{pos + speed, speed * 2}] = ins + 1;
                pq.push({ins + 1, {pos + speed, speed * 2}});
            }
            // Put an 'R'
            int newSpeed = speed > 0 ? -1 : 1;
            if(!mp.contains({pos, newSpeed}) || mp[{pos, newSpeed}] > ins + 1) {
                mp[{pos, newSpeed}] = ins + 1;
                pq.push({ins + 1, {pos, newSpeed}});
            }
        }
        return -1;
    }
};
