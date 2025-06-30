function isCircularSentence(sentence: string): boolean {
    const arr = sentence.split(' ');
    arr.push(arr[0]);
    for(let i = 0; i < arr.length - 1; i++) {
        if(arr[i].at(-1) !== arr[i + 1][0]) return false;
    }
    return true;
};
