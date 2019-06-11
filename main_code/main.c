#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include "until.h"

#define SWAP(a, b) do{ a ^= b; b ^= a; a ^= b; } while(0)

typedef enum {Quit,  //退出程序
              CPractice, //练习C语言关键字
              CppPractice, //练习C++语言关键字
              InValid //输入越界
} Menu;

const char *c_keyword[] = {
	"auto",		"break",	"case",		"char",		"const",	"continue",
	"default",	"do",		"double",	"else",		"enum",		"extern",
	"float",	"for",		"goto",		"if",		"int",		"long",
	"register",	"return",	"short",	"signed",	"sizeof",	"static",
	"struct",	"switch",	"typedef",	"union",	"unsigned",	"void",
	"volatile",	"while",
	"abort",	"abs", "assert",
	"atexit",	"atof",		"atoi",		"atol",
	"calloc",	"clock",
	"ctime",	"difftime",	"exit",
	"fabs",		"fclose",	"feof",		"ferror",	"fflush",	"fgetc",
	"fgetpos",	"fgets",	"floor",	"fmod",		"fopen",	"fprintf",
	"fputc",	"fputs",	"fread",	"free",		"freopen",	"frexp",
	"fscanf",	"fseek",	"fsetpos",	"ftell",	"fwrite",	"getc",
	"getchar",	"getenv",	"gets",	"isalnum",	"isalpha",
	"iscntrl",	"isdigit",	"isgraph",	"islower",	"isprint",	"ispunct",
	"isspace",	"isupper",	"isxdigit",
	"malloc",	"memchr",	"memcmp",	"memcpy",	"memmove",	"memset",
  "perror",	"pow",		"printf",	"putc",
	"putchar",	"puts",		"qsort",	"raise",	"rand",		"realloc",
	"remove",	"rename",	"rewind",	"scanf",	"setbuf",	"setjmp",
	"setlocale","setvbuf",	"signal",	"sin",		"sinh",		"sprintf",
	"sqrt",		"srand",	"sscanf",	"strcat",	"strchr",	"strcmp",
	"strcoll",	"strcpy",	"strcspn",	"strerror",	"strftime",	"strlen",
	"strncat",	"strncmp",	"strncpy",	"strpbrk",	"strrchr",	"strspn",
	"strstr",	"strtod",	"strtok",	"strtol",	"strtoul",	"strxfrm",
	"system",	"time",
	"tolower",	"toupper",	"ungetc",	"va_arg",	"va_end",	"va_start",
	"vfprintf", "vprintf",	"vsprintf"
};

const char* cpp_keyword[] = {"lambda", "placeholder", "tuple", "pair",
                              "decltype", "initializer_list", "volatile", "mutable",
                              "this", "unordered_map", "override", "iterator",
                              "explicit", "typename", "template", "throw", "namespace", 
                              "bool", "const_cast", "dynameic_cast", "reinterpret_cast", 
                              "static_cast", "constexpr", "noexcept", "friend", "true", 
                              "true", "false", "nullptr", "inline", "operator", 
                              "private", "public", "protected", "typeid", "using", 
                              "virtual", "final", "move", "auto", "default", "bind",
                              "shared_ptr", "make_shared", "unique_ptr", "weak_ptr", 
                              "delete", "function", "allocator", "forward", "bitset", 
                              "vector", "deque", "forward_list", "list", "string", 
                              "shrink_to_fit"};

#define C_NUM sizeof(c_keyword) / sizeof(c_keyword[0])
#define CPP_NUM sizeof(cpp_keyword) / sizeof(cpp_keyword[0])

void c_practice() {
  struct timeval start, end;
  int sort[C_NUM] = {0}; //出题顺序
  int mistake = 0; //错误次数
  for(unsigned long i = 0; i < C_NUM; ++i){
    sort[i] = i;
  }
  //打乱出题顺序
  for(int i = C_NUM - 1; i > 0; --i){
    int j = rand() % (i+1);
    if(i != j){
      SWAP(sort[i], sort[j]);
    }
  }
  printf("打字练习程序。（按空格键开始）\r\n\n");
  while(getch() != ' ');
  gettimeofday(&start, NULL);
  for(unsigned long stage = 0; stage < C_NUM; ++stage){

    int len = strlen(c_keyword[sort[stage]]);
    for(int i = 0; i < len; ++i){
      printf("%s \r", &c_keyword[sort[stage]][i]);
      fflush(stdout);
      while(getch() != c_keyword[sort[stage]][i]){
        ++mistake;
      }
    }

  }

  gettimeofday(&end, NULL);
  printf("字符/错误：%d次。\n", mistake);
  printf("打字耗时%ld秒。\n", end.tv_sec - start.tv_sec); 
  getch();
}

void cpp_practice(){
  struct timeval start, end;
  int sort[CPP_NUM] = {0}; //出题顺序
  int mistake = 0; //错误次数
  for(unsigned long i = 0; i < CPP_NUM; ++i){
    sort[i] = i;
  }
  //打乱出题顺序
  for(int i = CPP_NUM - 1; i > 0; --i){
    int j = rand() % (i+1);
    if(i != j){
      SWAP(sort[i], sort[j]);
    }
  }
  printf("打字练习程序。（按空格键开始）\r\n\n");
  while(getch() != ' ');
  gettimeofday(&start, NULL);
  for(unsigned long stage = 0; stage < CPP_NUM; ++stage){

    int len = strlen(cpp_keyword[sort[stage]]);
    for(int i = 0; i < len; ++i){
      printf("%s \r", &cpp_keyword[sort[stage]][i]);
      fflush(stdout);
      while(getch() != cpp_keyword[sort[stage]][i]){
        ++mistake;
      }
    }

  }

  gettimeofday(&end, NULL);
  printf("字符/错误：%d次。\n", mistake);
  printf("打字耗时%ld秒。\n", end.tv_sec - start.tv_sec); 
  getch();
}

Menu select_menu(){
  int choice = 0;
  do {
    printf("\n请选择练习模式。\n");
    printf("(1)C语言关键字      (2)C++语言关键字      (0)结束程序\n");
    scanf("%d", &choice);
  } while(choice < Quit || choice >= InValid);

  return (Menu)choice;
}


int main() {
  Menu menu;
  init_getputch();
  srand(time(NULL));//设置随机数种子
  
  do {
    switch(menu = select_menu()) {

      case CPractice: //C练习
        c_practice();
        break;

      case CppPractice: //Cpp练习
        cpp_practice();
        break;

      default://暂时不做处理
        //TODO
        break;
    }
  } while(menu != Quit);

  term_getputch(); 
  return 0;
}
