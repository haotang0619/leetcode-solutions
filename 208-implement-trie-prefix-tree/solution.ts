type TrieObj = { [key: string]: boolean | TrieObj };
class Trie {
  private trie: TrieObj = {};

  insert(word: string): void {
    let now = this.trie;
    for (const w of word) {
      if (!now[w]) now[w] = {};
      now = now[w] as TrieObj;
    }
    now.exist = true;
  }

  search(word: string): boolean {
    const result = word
      .split('')
      .reduce((now, w) => now?.[w] as TrieObj, this.trie);
    return !!result?.['exist'];
  }

  startsWith(prefix: string): boolean {
    const result = prefix
      .split('')
      .reduce((now, w) => now?.[w] as TrieObj, this.trie);
    return !!result;
  }
}

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
