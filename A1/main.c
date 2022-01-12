#include "funcs.h"

int main(){
  FILE *fp=fopen("a1_words.txt","r");
  char **words=read_words(fp);
  print_words(words);
  print_alphabetical_word_count(alphabetical_word_count(words));
  char ***wordsSorted=create_alphabetical_array(words);
  printWordsAlphabetically(wordsSorted);
  free_alphabetical_array(wordsSorted);
  fclose(fp);

  FILE *f=fopen("a1_moreWords.txt","r");
  char **moreWords=read_words(f);
  print_words(moreWords);
  print_alphabetical_word_count(alphabetical_word_count(moreWords));
  char ***moreWordsSorted=create_alphabetical_array(moreWords);
  printWordsAlphabetically(moreWordsSorted);
  free_alphabetical_array(moreWordsSorted);
  fclose(f);

  return 0;
}
