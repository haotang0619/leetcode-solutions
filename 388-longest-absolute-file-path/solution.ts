function lengthLongestPath(input: string): number {
  const directories: string[] = [];
  const paths = input.split('\n');
  let longest = 0;

  for (let i = 0; i < paths.length; i++) {
    const path = paths[i].split('\t');
    const name = path.slice(-1)[0];
    const depth = path.length - 1;
    while (depth < directories.length) directories.pop();

    if (name.includes('.')) {
      // file
      const nowPath = [...directories, name].join('/');
      longest = Math.max(longest, nowPath.length);
    } else {
      // directory
      directories.push(name);
    }
  }
  return longest;
}
