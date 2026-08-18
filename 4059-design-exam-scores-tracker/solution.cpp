class ExamTracker {
public:
    vector<pair<int, int>> records;
    vector<long long> pSum = {0};
    
    ExamTracker() {}
    
    void record(int time, int score) {
        records.push_back({time, score});
        pSum.push_back(pSum.back() + score);
    }
    
    long long totalScore(int startTime, int endTime) {
        int idx1 = lower_bound(records.begin(), records.end(), make_pair(startTime, 0)) - records.begin();
        int idx2 = lower_bound(records.begin(), records.end(), make_pair(endTime + 1, 0)) - records.begin() - 1;
        if(idx2 <= -1) return 0;
        if(idx1 >= records.size()) return 0;
        return pSum[idx2 + 1] - pSum[idx1];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
