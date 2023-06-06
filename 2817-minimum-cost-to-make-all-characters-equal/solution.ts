function minimumCost(s: string): number {
    let cost = 0;
    const n = s.length;
    
    let pointer1 = Math.floor((n - 1) / 2);
    let pointer2 = Math.floor(n / 2);
    let target = parseInt(s[pointer1]);
    let leftInverted = false;
    let rightInverted = false;
    
    while(pointer1 >= 0 || pointer2 <= n - 1) {
        while(parseInt(s[pointer1]) === (leftInverted ? 1 - target : target)) pointer1--;
        while(parseInt(s[pointer2]) === (rightInverted ? 1 - target : target)) pointer2++;
        
        if(pointer1 >= 0) {
            cost += pointer1 + 1;
            leftInverted = !leftInverted;
        }
        if(pointer2 <= n - 1) {
            cost += n - pointer2;
            rightInverted = !rightInverted;
        }
    }
    
    return cost;
};
