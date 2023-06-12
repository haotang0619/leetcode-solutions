/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */


function guessNumber(n: number): number {
  let start = 1;
  let end = n;
  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    if (guess(mid) === 0) return mid;
    else if (guess(mid) < 0) end = mid;
    else start = mid + 1;
  }
}
