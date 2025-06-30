function compareVersion(version1: string, version2: string): number {
    const arr1 = version1.split('.').map(Number);
    const arr2 = version2.split('.').map(Number);
    for(let i = 0; i < Math.max(arr1.length, arr2.length); i++) {
        const v1 = arr1[i] || 0;
        const v2 = arr2[i] || 0;
        if(v1 < v2) return -1;
        if(v1 > v2) return 1;
    }
    return 0;
};
