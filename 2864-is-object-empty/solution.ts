function isEmpty(obj: Record<string, any> | any[]): boolean {
    return JSON.stringify(obj).length === 2;
};
