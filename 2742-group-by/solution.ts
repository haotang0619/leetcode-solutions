interface Array<T> {
    groupBy(fn: (item: T) => string): Record<string, T[]>
}


Array.prototype.groupBy = function(fn) {
    return this.reduce((acc, curr) => {
        let k = fn(curr);
        if(!acc[k]) acc[k] = [];
        acc[k].push(curr);
        return acc;
    }, {});
}

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
