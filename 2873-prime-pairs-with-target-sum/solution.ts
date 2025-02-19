// Sieve
let composite = new Set<number>([1]);
const findPrime = () => {
    let i = 2;
    while(i * i <= 1e6) {
        if(composite.has(i)){
            i++; continue;
        }
        let j = i * 2;
        while(j < 1e6){
            composite.add(j);
            j += i;
        }
        i++;
    }
}
findPrime();

function findPrimePairs(n: number): number[][] {
    let ans = [];
    for(let i = 2; i <= n / 2; i++) {
        const j = n - i;
        if(!composite.has(i) && !composite.has(j)){
            ans.push([i, j]);
        }
    }
    return ans;
};
