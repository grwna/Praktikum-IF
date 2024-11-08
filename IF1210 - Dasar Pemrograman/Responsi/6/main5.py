import tester
def count_words(row):
  words = row.split()
  word_count = []

  for word in words:
    found = False

    for wc in word_count:
      if wc[0] == word:
        wc[1] += 1
        found = True
        break
    if not found:
        word_count.append([word, 1])
  return word_count
  
def find_common_words(list1, list2):
  common_words = []
  for word1, freq1 in list1:
        for word2, freq2 in list2:
            if word1 == word2:
                common_words.append((word1, freq1, freq2))

  return common_words

def main():
  file = open("input.txt", "r")

  row1 = file.readline().strip()
  row2 = file.readline().strip()

  file.close()

  list1 = count_words(row1)
  list2 = count_words(row2)

  common_words = find_common_words(list1, list2)
  if not common_words:
        print("Tidak ada kata yang sama")
  else:
        for word, freq1, freq2 in common_words:
            print("{},{},{}".format(word, freq1, freq2))


tester.start("input.txt")
main()
tester.end("input.txt")
