const vowels = ['a', 'e', 'i', 'o', 'u'];

function spellchecker(wordlist: string[], queries: string[]): string[] {
  return queries.map((query) => {
    const exact = wordlist.find((word) => word === query);
    if (!!exact) return exact;

    const capitalization = wordlist.find(
      (word) => word.toLowerCase() === query.toLowerCase(),
    );
    if (!!capitalization) return capitalization;

    const vowel = wordlist.find((word) => {
      const w = word.toLowerCase();
      const q = query.toLowerCase();

      if (w.length !== q.length) return false;
      for (let i = 0; i < word.length; i++) {
        if (q[i] !== w[i] && (!vowels.includes(q[i]) || !vowels.includes(w[i])))
          return false;
      }
      return true;
    });
    if (!!vowel) return vowel;

    return '';
  });
}
