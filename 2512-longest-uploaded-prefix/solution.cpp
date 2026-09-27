class LUPrefix {
public:
    int now = 0, n;
    vector<bool> uploaded;

    LUPrefix(int n1) {
        n = n1;
        uploaded.assign(n + 1, false);
        uploaded[0] = true;
    }
    
    void upload(int video) {
        uploaded[video] = true;
    }
    
    int longest() {
        while(now <= n && uploaded[now]) now++;
        return now - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
