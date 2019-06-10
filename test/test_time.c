#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int main() {
  //char str[128] = {0};
  struct timeval start, end;
  gettimeofday(&start, NULL);
  //printf("输入相同的字符串。\n");
  //printf("this is a test programming.\n");
  //scanf("%s", str); 
  sleep(2);
  gettimeofday(&end, NULL);
  printf("输入花费的时间：%lds.%ldms\n", (end.tv_sec-start.tv_sec),(end.tv_usec - start.tv_usec) / 1000);
  return 0;
}
