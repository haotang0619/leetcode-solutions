type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    const toBe = (v: any) => {
       if(v !== val) throw new Error("Not Equal");
       return true;
    }
    const notToBe = (v: any) => {
        if(v === val) throw new Error("Equal");
        return true;
    }
    return { toBe, notToBe };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
