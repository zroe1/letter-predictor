#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int START_LINE = 2; // the start line of the original csv to be copied
int END_LINE = 10000; // the end line of the original csv to be copied

void write_csv_header() {
  printf("letter1,letter2,letter3,letter4,letter5,PoS\n");
}

unsigned char len_of_word_from_csv_line(char *line) {
  char word_start = -1;
  char word_end = -1;

  unsigned char line_len = strlen(line);
  
  for (unsigned char i = 0; i < line_len; i++) {
    if (word_start != -1 && word_end == -1 && line[i] == ',')
      word_end = i;
    if (word_start == -1 && line[i] == ',')
      word_start = i;  
  }
  return word_end - word_start - 1;
}

void print_line_to_stdout_as_ASCII(char *line) {
  if (len_of_word_from_csv_line(line) != 5)
    return;
  //printf("%s\n", line);
  //printf("%d\n", 5);
  unsigned char line_len = strlen(line);
  //printf("%d\n", line_len);
  char is_rank = 1; // checks to see if it is in the rank column so the
                    // loop can ignore it
  //printf("final char: %c\n",line[line_len - 1]);
  
  for (unsigned char i = 0; i < line_len; i++) {
    char current_char = line[i];
    if (!is_rank) {
      if (line[i] != ',')
        printf("%d", current_char);
      if (i != line_len - 1 && current_char != ',')
        putchar(',');
    } else {
      if (current_char == ',')
        is_rank = 0;
    }
  }
  putchar('\n');
 
}

int main ()
{
  write_csv_header();

  char current_char = getchar();
  char *current_line = (char *)malloc(sizeof(char) * 30);
  unsigned char current_line_idx = 0;
  char is_first_line = 1;
  unsigned int current_line_num = 1;

  while (current_char != EOF){
    if (current_char != '\n') {
      current_line[current_line_idx] = current_char;
      current_line_idx++;
    } else {
      current_line[current_line_idx - 1] = '\0';
      if (current_line_num >= START_LINE && current_line_num <= END_LINE)
        print_line_to_stdout_as_ASCII(current_line);
      //printf("%d %d %d\n", current_line_num, START_LINE, END_LINE);
      current_line_num++;
      current_line_idx = 0;
    }
    current_char = getchar();
    //current_line_num++;
  }

  if (strlen(current_line) == 0) {
    current_line[current_line_idx] = '\0';
  }

  print_line_to_stdout_as_ASCII(current_line); 
  return 0;
}
