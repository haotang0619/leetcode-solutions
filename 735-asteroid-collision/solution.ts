function asteroidCollision(asteroids: number[]): number[] {
  const stack: number[] = [];
  const answer: number[] = [];
  for (let ast of asteroids) {
    if (ast > 0) stack.push(ast);
    else {
      while (stack[stack.length - 1] < -ast) stack.pop();
      if (stack.length === 0) answer.push(ast);
      if (stack[stack.length - 1] === -ast) stack.pop();
    }
  }
  answer.push(...stack);
  return answer;
}
