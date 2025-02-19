type StackElement = { h: number; pos: number };

function trap(height: number[]): number {
  let answer = 0;
  const stack: StackElement[] = [];
  const len = height.length;

  for (let i = 0; i < len; i++) {
    let prev: StackElement = { h: -1, pos: -1 };
    while (true) {
      if (stack.slice(-1)[0]?.h <= height[i]) {
        prev = stack.pop() as StackElement;
      } else break;
    }

    if (prev.h !== -1) {
      for (let j = prev.pos; j < i; j++) {
        answer += prev.h - height[j];
        height[j] = prev.h;
      }
    }

    if (height[i] > 0) {
      stack.push({ h: height[i], pos: i });
    }
  }

  const stackLen = stack.length;
  if (stackLen > 0) {
    for (let i = 0; i < stackLen - 1; i++) {
      const h = stack[i + 1].h;
      const start = stack[i].pos;
      const end = stack[i + 1].pos;
      for (let j = start; j < end; j++) {
        answer += Math.max(h - height[j], 0);
      }
    }
  }

  return answer;
}
