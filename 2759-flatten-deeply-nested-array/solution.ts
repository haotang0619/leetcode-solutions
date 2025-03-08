type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr: MultiDimensionalArray, n: number):  MultiDimensionalArray {
    var flatOnce = (a) => a.reduce((acc, curr) => {
        if(Array.isArray(curr)) acc.push(...curr);
        else acc.push(curr);
        return acc;
    }, []);

    return arr.reduce((acc: MultiDimensionalArray, curr) => {
        if(Array.isArray(curr) && n > 0) {
            for(let i = 1; i < n; i++) curr = flatOnce(curr);
            acc.push(...(curr as MultiDimensionalArray));
        } else acc.push(curr);
        return acc;
    }, [])
};
