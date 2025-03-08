type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type ArrayType = { "id": number } & Record<string, JSONValue>;

function join(arr1: ArrayType[], arr2: ArrayType[]): ArrayType[] {
    const obj = {};
    arr1.forEach((a) => obj[a.id] = a);
    arr2.forEach((b) => obj[b.id] = {...obj[b.id], ...b});
    return Object.keys(obj).sort((a, b) => Number(a) - Number(b)).map((k) => obj[k]);
};
