class LFUCache {
public:
    int cap, time = 0, cnt = 0;
    unordered_map<int, int> cache, freqs, times; // [key, val/freq/time]
    map<int, deque<pair<int, int>>> freqKeys; // [freq, [time, key]]

    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.contains(key)) {
            freqs[key]++, times[key] = time++;
            freqKeys[freqs[key]].push_back({times[key], key});
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cnt == cap && !cache.contains(key)) {
            while(true) {
                auto& [freq, dq] = *(freqKeys.begin());
                pair<int, int> sel = {-1, -1};
                while(!dq.empty()) {
                    auto& [time, k] = dq.front();
                    if(times[k] != time) dq.pop_front();
                    else {
                        sel = {time, k};
                        dq.pop_front();
                        break;
                    }
                }
                if(dq.empty()) freqKeys.erase(freq);
                auto& [time, k] = sel;
                if(k == -1) continue;
                cache.erase(k), freqs.erase(k), times.erase(k);
                break;
            }
        }

        if(cache.contains(key)) {
            freqs[key]++, times[key] = time++;
            freqKeys[freqs[key]].push_back({times[key], key});
        } else {
            freqs[key] = 1, times[key] = time++;
            freqKeys[freqs[key]].push_back({times[key], key});
            if(cnt < cap) cnt++;
        }
        cache[key] = value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
