function intToRoman(num: number): string {
  let answer = '';
  const M = Math.floor(num / 1000);
  for (let i = 0; i < M; i++) answer += 'M';
  num = num % 1000;

  const C = Math.floor(num / 100);
  if (C === 9) answer += 'CM';
  else if (C >= 5) {
    answer += 'D';
    for (let i = 0; i < C - 5; i++) answer += 'C';
  } else if (C === 4) answer += 'CD';
  else {
    for (let i = 0; i < C; i++) answer += 'C';
  }
  num = num % 100;

  const X = Math.floor(num / 10);
  if (X === 9) answer += 'XC';
  else if (X >= 5) {
    answer += 'L';
    for (let i = 0; i < X - 5; i++) answer += 'X';
  } else if (X === 4) answer += 'XL';
  else {
    for (let i = 0; i < X; i++) answer += 'X';
  }
  num = num % 10;

  if (num === 9) answer += 'IX';
  else if (num >= 5) {
    answer += 'V';
    for (let i = 0; i < num - 5; i++) answer += 'I';
  } else if (num === 4) answer += 'IV';
  else {
    for (let i = 0; i < num; i++) answer += 'I';
  }

  return answer;
}
