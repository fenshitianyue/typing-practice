#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "../until.h"

#define NUM 12

int main() {
  const char* str[NUM] = {"book", "computer", "default", "auto",
                          "decltype", "dynamic", "include", "static",
                          "reinterpret", "unordered_map", "sort", "iterator"};
  struct timeval start, end;
  init_getputch();
  printf("开始打字练习。(按下空格键开始)\n");
  while(getch() != ' ');
  gettimeofday(&start, NULL);
  for(int stage = 0; stage < NUM; ++stage){
    int len = strlen(str[stage]);
    for(int i = 0; i < len; ++i){
      printf("%s \r", &str[stage][i]);
      fflush(stdout);
      while(getch() != str[stage][i]);
    }
  } 
  gettimeofday(&end, NULL);
  printf("\r用时%ld秒。\n", end.tv_sec - start.tv_sec);
  getch();
  term_getputch();
  return 0;
}
