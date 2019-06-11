#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include "until.h"

#define NUM 12
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
	"abort",	"abs",		"acos",		"asctime",	"asin",		"assert",
	"atan",		"atan2",	"atexit",	"atof",		"atoi",		"atol",
	"bsearch",	"calloc",	"ceil",		"clearerr",	"clock",	"cos",
	"cosh",		"ctime",	"difftime",	"div",		"exit",		"exp",
	"fabs",		"fclose",	"feof",		"ferror",	"fflush",	"fgetc",
	"fgetpos",	"fgets",	"floor",	"fmod",		"fopen",	"fprintf",
	"fputc",	"fputs",	"fread",	"free",		"freopen",	"frexp",
	"fscanf",	"fseek",	"fsetpos",	"ftell",	"fwrite",	"getc",
	"getchar",	"getenv",	"gets",		"gmtime",	"isalnum",	"isalpha",
	"iscntrl",	"isdigit",	"isgraph",	"islower",	"isprint",	"ispunct",
	"isspace",	"isupper",	"isxdigit",	"labs",		"ldexp",	"ldiv",
	"localeconv",			"localtime","log",		"log10",	"longjmp",
	"malloc",	"memchr",	"memcmp",	"memcpy",	"memmove",	"memset",
	"mktime",	"modf",		"perror",	"pow",		"printf",	"putc",
	"putchar",	"puts",		"qsort",	"raise",	"rand",		"realloc",
	"remove",	"rename",	"rewind",	"scanf",	"setbuf",	"setjmp",
	"setlocale","setvbuf",	"signal",	"sin",		"sinh",		"sprintf",
	"sqrt",		"srand",	"sscanf",	"strcat",	"strchr",	"strcmp",
	"strcoll",	"strcpy",	"strcspn",	"strerror",	"strftime",	"strlen",
	"strncat",	"strncmp",	"strncpy",	"strpbrk",	"strrchr",	"strspn",
	"strstr",	"strtod",	"strtok",	"strtol",	"strtoul",	"strxfrm",
	"system",	"tan",		"tanh",		"time",		"tmpfile",	"tmpnam",
	"tolower",	"toupper",	"ungetc",	"va_arg",	"va_end",	"va_start",
	"vfprintf", "vprintf",	"vsprintf"
};

const char* cpp_keyword[] = {"lambda", "placeholder", "tuple", "peer",
                              "decltype", "initializer_list", "volatile", "mutable",
                              "reinterpret", "unordered_map", "override", "iterator"};

void c_practice() {
  //clock_t start, end; 无法正常计时
  struct timeval start, end;
  int sort[NUM] = {0}; //出题顺序
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
  printf("打字练习程序。（按空格键开始）\r\n");
  while(getch() != ' ');
  //start = clock();
  gettimeofday(&start, NULL);
  for(int stage = 0; stage < NUM; ++stage){
    int len = strlen(c_keyword[sort[stage]]);
    for(int i = 0; i < len; ++i){
      printf("%s \r", &c_keyword[sort[stage]][i]);
      fflush(stdout);
      while(getch() != c_keyword[sort[stage]][i]);
    }
  }

  //end = clock();
  gettimeofday(&end, NULL);
  //printf("\r打字耗时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);
  printf("\r打字耗时%ld秒。\n", end.tv_sec - start.tv_sec); 
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

  term_getputch(); 
  return 0;
}
