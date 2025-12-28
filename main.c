#include "parser.h"
#include <stdio.h>

int main() {
    Config config = {0}; // 初始化结构体
    
   // 尝试解析文件
    if (parse_file("tmpfile", &config) == 0) {
        printf("解析成功!\n");
        printf("姓名: %s\n", config.name);
        printf("年龄: %d\n", config.age);
        
     //   释放分配的内存
        free(config.name);
    } else {
        printf("解析失败! 文件可能不存在或格式错误.\n");
    }
    
    return 0;
}
