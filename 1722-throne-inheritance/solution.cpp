class ThroneInheritance {
public:
    string root;
    unordered_map<string, vector<string>> mp;
    unordered_map<string, bool> alive;

    ThroneInheritance(string kingName) {
        root = kingName;
        alive[kingName] = true;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
        alive[childName] = true;
    }
    
    void death(string name) {
        alive[name] = false;
    }

    void findOrder(vector<string>& v, string name) {
        if(alive[name]) v.push_back(name);
        for(auto x : mp[name]) findOrder(v, x);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> v;
        findOrder(v, root);
        return v;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
