#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
//#include <termios.h>
#include "../until.h"

//char _getch(){
//  char ch;
//  //用于保存原有终端属性和新属性的终端属性
//  static struct termios oldt, newt;
//  //获取终端原有属性并保存在结构体oldt中
//  tcgetattr(1, &oldt); // 1 : STDIN_FILENO -> united.h
//  //设置新的终端属性
//  newt = oldt;
//  newt.c_lflag &= ~(ICANON);
//  tcsetattr(1, TCSANOW, &newt);
//  //取消回显
//  system("stty -echo"); // -> stdlib.h
//  ch = getchar();
//  system("stty echo");
//  //让终端恢复为原来的属性
//  tcsetattr(1, TCSANOW, &oldt);
//  return ch;
//}

int main() {
  const char* str = "How do you do?";
  int len = strlen(str);
  struct timeval start, end;
  init_getputch();
  printf("输入相同的字符串。\n");
  printf("%s\n", str);
  fflush(stdout);
  gettimeofday(&start, NULL);
  for(int i = 0; i < len; ++i){
    char ch;
    do{
      ch = getch();
      if(isprint(ch)){
        putch(ch);
        if(ch != str[i]){
          putch('\b');
        }      
      }
    }while(ch != str[i]);
  }
  gettimeofday(&end, NULL);
  printf("\n用时%ld秒。\n", end.tv_sec - start.tv_sec);
  getch(); //暂停程序
  term_getputch();
  return 0;
}
