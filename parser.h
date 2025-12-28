#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

// 定义配置结构体
typedef struct {
   	char *name;
        int age;
    } Config;
// 解析函数声明
int parse_file(const char *filename, Config *config);
#endif 
