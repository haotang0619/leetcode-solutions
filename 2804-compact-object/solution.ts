type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function compactObject(obj: Obj): Obj {
    const remover = (item: any) => {
        if(Array.isArray(item)) return item.map(remover).filter(Boolean);
        if(typeof item === 'object' && item !== null) {
            return Object.fromEntries(Object.entries(item).map(([key, val]) => [key, remover(val)]).filter(([, val]) => !!val));
        }
        return item;
    }
    return remover(obj);
};
