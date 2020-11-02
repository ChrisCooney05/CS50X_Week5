# CS50X_Week5

All files are from week 5 of Harvard CS50X - Data Structures

- **Speller** - A program that spell-checks a file using a hash table 📚
  - You may change the value of N in dictionary.c, so that your hash table can have more buckets.
  - You may alter dictionary.h, but you may not alter the declarations of load, hash, size, check, or unload.
  - Your implementation of check must be case-insensitive. In other words, if foo is in dictionary, then check should return true given any capitalization thereof; none of foo, foO, fOo, fOO, fOO, Foo, FoO, FOo, and FOO should be considered misspelled.
  - Capitalization aside, your implementation of check should only return true for words actually in dictionary. Beware hard-coding common words (e.g., the), lest we pass your implementation a dictionary without those same words. Moreover, the only possessives allowed are those actually in dictionary. In other words, even if foo is in dictionary, check should return false given foo's if foo's is not also in dictionary.
  - you may assume that any dictionary passed to your program will be structured exactly like ours, alphabetically sorted from top to bottom with one word per line, each of which ends with \n. You may also assume that dictionary will contain at least one word, that no word will be longer than LENGTH (a constant defined in dictionary.h) characters, that no word will appear more than once, that each word will contain only lowercase alphabetical characters and possibly apostrophes, and that no word will start with an apostrophe.
  - You may assume that check will only be passed words that contain (uppercase or lowercase) alphabetical characters and possibly apostrophes.
  - Your spell checker must not leak any memory.