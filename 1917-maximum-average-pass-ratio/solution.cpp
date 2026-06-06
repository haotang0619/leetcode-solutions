class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < classes.size(); i++) {
            auto c = classes[i];
            double diff = (double)(c[0] + 1) / (c[1] + 1) - (double)c[0] / c[1];
            pq.push({diff, i});
        }
        while(extraStudents--) {
            auto [diff, i] = pq.top();
            pq.pop();
            classes[i][0]++, classes[i][1]++;
            auto c = classes[i];
            double newDiff = (double)(c[0] + 1) / (c[1] + 1) - (double)c[0] / c[1];
            pq.push({newDiff, i});
        }
        double sum = 0;
        for(auto c : classes) sum += (double)c[0] / c[1];
        return sum / classes.size();
    }
};
