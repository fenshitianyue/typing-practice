# Typing Program



## 项目简介

---

这是一个用C语言实现的跨平台简单打字练习程序。目前版本的词库只支持对C / C++关键字的练习。

后面版本会添加可控制词库装载、卸载功能。

## 项目描述

---

- 开发环境
  - 编辑器：nvim
  - 编译器：gcc
  - 调试器：gdb
- 支持平台：Windows 7+ 、Centos 7、Ubuntu

## 如何使用

---

### Linux端：

#### 准备工作

本项目Linux端需要预先安装 curses 库

- CentOS安装：`sudo yum install ncurses-devel`

- Ubuntu安装：`sudo apt-get install libncurses5-dev`

#### 运行程序

1. `git clone https://github.com/fenshitianyue/typing-practice.git`
2. `cd typing-practice/main_code`
3. 编译程序：`make`
4. 运行程序：`./main`

### Windows端：

#### 运行程序

1. 克隆本项目到本地
2. 在本地项目中包含本项目`main_code`文件夹中的头文件`until.h`和源文件`main.c`
3. 编译并运行源文件`main.c`即可

## 项目截图

---

![project screenshots](https://github.com/fenshitianyue/repositpry/master/typing-practice/demo/screenshots.jpg)

