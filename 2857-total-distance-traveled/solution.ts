function distanceTraveled(mainTank: number, additionalTank: number): number {
    let ans = 0;
    while(mainTank >= 5){
        ans += 50;
        mainTank -= 5;
        if(additionalTank > 0) --additionalTank, ++mainTank;
    }
    return ans + mainTank * 10;
};
