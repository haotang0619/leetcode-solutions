function suggestedProducts(products: string[], searchWord: string): string[][] {
  products.sort();
  const answer: string[][] = [];
  let idx = 0;
  for (let i = 1; i <= searchWord.length; i++) {
    const prefix = searchWord.slice(0, i);
    while (prefix > products[idx]?.slice(0, i)) idx++;
    answer.push(
      products.slice(idx, idx + 3).filter((p) => prefix === p.slice(0, i)),
    );
  }
  return answer;
}
