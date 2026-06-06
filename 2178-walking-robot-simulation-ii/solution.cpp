class Robot {
private:
    int w, h, r, x = 0, y = 0;
    string dir = "East";

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        r = (w + h) * 2 - 4;
    }
    
    void step(int num) {
        if(num > 0 && num % r == 0) num = r;
        else num %= r;
        while(num > 0) {
            if(dir == "East") {
                if(w - 1 - x >= num) {
                    x += num;
                    num = 0;
                } else {
                    num -= w - 1 - x;
                    x = w - 1;
                    dir = "North";
                }
            } else if(dir == "North") {
                if(h - 1 - y >= num) {
                    y += num;
                    num = 0;
                } else {
                    num -= h - 1 - y;
                    y = h - 1;
                    dir = "West";
                }
            } else if(dir == "West") {
                if(x >= num) {
                    x -= num;
                    num = 0;
                } else {
                    num -= x;
                    x = 0;
                    dir = "South";
                }
            } else if(dir == "South") {
                if(y >= num) {
                    y -= num;
                    num = 0;
                } else {
                    num -= y;
                    y = 0;
                    dir = "East";
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
