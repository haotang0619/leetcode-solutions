class FrequencyTracker {
public:
    unordered_map<int, int> freq, freqCnt;
    
    FrequencyTracker() {}
    
    void add(int num) {
        if(freq[num] > 0) freqCnt[freq[num]]--;
        freqCnt[++freq[num]]++;
    }
    
    void deleteOne(int num) {
        if(freq[num] > 0) {
            freqCnt[freq[num]]--;
            freqCnt[--freq[num]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return freqCnt[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
