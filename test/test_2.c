#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "../until.h"

int main() {
  const char* str = "hello world"; 
  int len = strlen(str);
  struct timeval start, end;
  init_getputch();
  printf("输入相同的字符串。\n");
  gettimeofday(&start, NULL);
  for(int i = 0; i < len; ++i){
    printf("%s \r", &str[i]);
    fflush(stdout);
    while(getch() != str[i]);
  }
  gettimeofday(&end, NULL);
  printf("\r用时%ld秒。\n", end.tv_sec - start.tv_sec);
  getch();
  term_getputch();
  return 0;
}
