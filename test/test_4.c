#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include "../until.h"

#define NUM 12
#define SWAP(a, b) do{ a ^= b; b ^= a; a ^= b; } while(0)

int main() {
  const char* str[NUM] = {"lambda", "placeholder", "tuple", "peer",
                          "decltype", "initializer_list", "volatile", "mutable",
                          "reinterpret", "unordered_map", "override", "iterator"};
  //clock_t start, end; 无法正常计时
  struct timeval start, end;
  int sort[NUM] = {0}; //出题顺序
  init_getputch();
  srand(time(NULL));//设置随机数种子
  for(int i = 0; i < NUM; ++i){
    sort[i] = i;
  }
  //打乱出题顺序
  for(int i = NUM - 1; i > 0; --i){
    int j = rand() % (i+1);
    if(i != j){
      SWAP(sort[i], sort[j]);
    }
  }
  printf("打字练习程序。（按空格键开始）\n");
  while(getch() != ' ');
  //start = clock();
  gettimeofday(&start, NULL);
  for(int stage = 0; stage < NUM; ++stage){
    int len = strlen(str[sort[stage]]);
    for(int i = 0; i < len; ++i){
      printf("%s \r", &str[sort[stage]][i]);
      fflush(stdout);
      while(getch() != str[sort[stage]][i]);
    }
  }

  //end = clock();
  gettimeofday(&end, NULL);
  //printf("\r打字耗时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);
  printf("\r打字耗时%ld秒。\n", end.tv_sec - start.tv_sec); 
  getch();
  term_getputch(); 
  return 0;
}
