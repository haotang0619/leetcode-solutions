class UndergroundSystem {
public:
    unordered_map<string, pair<int, int>> mp1;
    unordered_map<int, pair<string, int>> mp2;

    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        mp2[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& [st, t1] = mp2[id];
        string s = st + "-" + stationName;
        if(!mp1.contains(s)) mp1[s] = {0, 0};
        auto& rec = mp1[s];
        rec.first += t - t1, rec.second++;
        mp2.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s = startStation + "-" + endStation;
        auto& [sum, times] = mp1[s];
        return (double)sum / times;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
