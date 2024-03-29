#pragma once
/* 用于getch/putch的通用头文件"until.h" */

#if defined(_MSC_VER) || (__TURBOC__) || (LSI_C)

	/* MS-Windows／MS-DOS（Visual C++, Borland C++, LSI-C 86 etc ...）*/

#include <conio.h>

	static void init_getputch(void) { /* 空 */ }

	static void term_getputch(void) { /* 空 */ }


#else

	/* 提供了Curses库的UNIX/Linux/OS X环境 */

#include <curses.h>

#undef putchar
#undef puts
#undef printf
  static char __buf[4096];

	/*--- __putchar：相当于putchar函数（用“换行符+回车符”代替换行符进行输出）---*/
	static int __putchar(int ch)
	{
		if (ch == '\n')
			putchar('\r');
		return putchar(ch);
	}

	/*--- putch：显示1个字符，清除缓冲区 ---*/
	static int putch(int ch)
	{
		int result = putchar(ch);

		fflush(stdout);
		return result;
	}

	/*--- __printf：相当于printf函数（用“换行符+回车符”代替换行符进行输出）---*/
	static int __printf(const char *format, ...)
	{
		va_list	ap;
		int 	count;

		va_start(ap, format);
		vsprintf(__buf, format, ap);
		va_end(ap);

		for (count = 0; __buf[count]; count++) {
			putchar(__buf[count]);
			if (__buf[count] == '\n')
				putchar('\r');
		}
		return count;
	}

	/*--- __puts：相当于puts函数（用“换行符+回车符”代替换行符进行输出）---*/
	static int __puts(const char *s)
	{
		int i, j;

		for (i = 0, j = 0; s[i]; i++) {
			__buf[j++] = s[i];
			if (s[i] == '\n')
				__buf[j++] = '\r';
		}
		return puts(__buf);
	}

	/*--- 库初始处理 ---*/
	static void init_getputch(void)
	{
		initscr(); //初始化 curses
		cbreak(); //开启 cbreak 模式，除了DELETE和CTRL等仍被视为特殊字符外的一切输入将立刻被一一读取
		noecho(); //从键盘输入字符时默认不将字符显示在终端上
		refresh(); //清空当前屏幕
	}

	/*--- 库终止处理 ---*/
	static void term_getputch(void)
	{
		endwin(); //终止 curses
	}

#define putchar	__putchar
#define	printf	__printf
#define puts	__puts

#endif

