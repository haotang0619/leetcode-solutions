class RideSharingSystem {
public:
    int t = 0;
    unordered_map<int, int> riderTime;
    map<int, int> timeRider, timeDriver;
    
    RideSharingSystem() {}
    
    void addRider(int riderId) {
        riderTime[riderId] = t;
        timeRider[t] = riderId;
        t++;
    }
    
    void addDriver(int driverId) {
        timeDriver[t++] = driverId;
    }
    
    vector<int> matchDriverWithRider() {
        if(timeDriver.size() > 0 && timeRider.size() > 0) {
            int d = (*timeDriver.begin()).second;
            int r = (*timeRider.begin()).second;
            timeDriver.erase(timeDriver.begin());
            timeRider.erase(riderTime[r]);
            riderTime.erase(r);
            return {d, r};
        }
        return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        if(!riderTime.contains(riderId)) return;
        timeRider.erase(riderTime[riderId]);
        riderTime.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
