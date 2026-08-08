class EventManager {
public:
    unordered_map<int, int> ep;
    priority_queue<pair<int, int>> pq;
    
    EventManager(vector<vector<int>>& events) {
        for(auto& x : events) {
            int e = x[0], p = x[1];
            ep[e] = p;
            pq.push({p, -e});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        ep[eventId] = newPriority;
        pq.push({newPriority, -eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()) {
            auto [p, ne] = pq.top();
            pq.pop();
            int e = -ne;
            if(ep[e] != p) continue;
            ep.erase(e);
            return e;
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
