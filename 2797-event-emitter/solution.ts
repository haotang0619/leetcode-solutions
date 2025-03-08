type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void
}

class EventEmitter {
    private cb = {};
    private idx = 0;

    subscribe(eventName: string, callback: Callback): Subscription {
        if(!this.cb[eventName]) this.cb[eventName] = [];
        let idx = this.idx++;
        this.cb[eventName].push({ callback, idx });

        return {
            unsubscribe: () => {
                this.cb[eventName] = this.cb[eventName].filter((c) => c.idx !== idx);
            }
        };
    }
    
    emit(eventName: string, args: any[] = []): any[] {
        return this.cb[eventName]?.map(({callback}) => callback(...args)) || [];
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
