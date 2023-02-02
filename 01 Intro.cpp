useful for dictionaries. (eg: {"abc", "cdgv", "agvbr", "uvfrj"} can be a dictionary)

operations we do on the dictionary:
1. search
2. insert
3. delete
4. prefix search (ie. given a prefix, seach all words in dictionary with that prefix)
5. lexicographical order of words (print all words in dictionary in lexicographical order)


comparision b/w hashing (unordered set/map) and trie:

                                    Trie                                  Hashing

search                  O(length_of_word) in WORST case           O(length_of_word) on AVERAGE
insert                              same                                    same
delete                              same                                    same
prefix search        O(prexif_length + output_word_length)             not supported
lexicographic ordering    O(sum_of_lengths_of_all_words)               not supported

