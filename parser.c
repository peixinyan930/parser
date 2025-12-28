#include "parser.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//辅助函数：去除字符串两端的空格
static char* trim_whitespace(char *str) {
    char *end;
    
  // 去除前导空格
    while (isspace((unsigned char)*str)) str++;
    
  // 如果字符串全为空格，返回空字符串
    if (*str == '\0') return str;
    
  // 去除尾部空格
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    
  // 在末尾添加空字符
    *(end + 1) = '\0';
    
    return str;
}

int parse_file(const char *filename, Config *config) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1; // 文件打开失败
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
       // 跳过空行
        if (line[0] == '\n') continue;
        
        // 查找等号
        char *equals = strchr(line, '=');
        if (!equals) continue; // 没有等号，跳过
        
       // 分割键和值
        *equals = '\0'; // 用空字符替换等号
        char *key = trim_whitespace(line);
        char *value = trim_whitespace(equals + 1);
        
        //根据键名设置值
        if (strcmp(key, "name") == 0) {
            if (config->name) free(config->name); // 释放旧内存
            config->name = strdup(value);
        } else if (strcmp(key, "age") == 0) {
            config->age = atoi(value);
        }
    }

    fclose(file);
    return 0; // 成功
}

//添加行统计功能

int count_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return -1;
    
    int count = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') count++;
    }
    fclose(file);
    return count;
}
