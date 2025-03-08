type Counter = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): Counter {
    let n1 = init, n2 = init;
    return {
        increment: () => ++n1,
        decrement: () => --n1,
        reset: () => (n1 = n2),
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
