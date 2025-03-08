type Fn<T> = () => Promise<T>

function promiseAll<T>(functions: Fn<T>[]): Promise<T[]> {
    return new Promise((res, rej) => {
        const results = [];
        let cnt = 0;
        for(let i = 0; i < functions.length; i++) {
            functions[i]().then(v => {
                results[i] = v;
                if(++cnt === functions.length) res(results);
            }).catch(e => rej(e));
        }
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
