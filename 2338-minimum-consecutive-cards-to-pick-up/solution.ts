function minimumCardPickup(cards: number[]): number {
    const records = {};
    cards.forEach((card, i) => {
        if(!records[card]) records[card] = [1e9, i];
        else {
            records[card] = [Math.min(records[card][0], i - records[card][1] + 1), i];
        }
    })
    
    const result = [...Object.keys(records)].sort((a, b) => records[a][0] - records[b][0]);
    const answer = records[result[0]][0]
    return answer === 1e9 ? -1 : answer
};
