function longestString(x: number, y: number, z: number): number {
    let ans = 0;
    if(x > 0 && y > 0 && z > 0) {
        const min = Math.min(x, y, z);
        ans += min * 6;
        x -= min; y -= min; z -= min;
    }
    if(x > 0 || y > 0) { 
        const min = Math.min(x, y);
        ans += min * 4;
        ans += (x > min || y > min) ? 2 : 0;
    }
    ans += z * 2;
    return ans;
};
