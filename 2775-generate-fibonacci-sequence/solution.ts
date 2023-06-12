function* fibGenerator(): Generator<number, any, number> {
    let prev = null;
    let now = null;
    while(true) {
        if(prev === null) {
            prev = 0;
            yield 0;
        } else if(now === null) {
            now = 1;
            yield 1;
        } else {
            [prev, now] = [now, prev + now]
            yield now;
        }
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
