/*
 * @Author: AuroraRealm 3398817447@qq.com
 * @Date: 2024-02-03 17:42:31
 * @LastEditors: AuroraRealm 3398817447@qq.com
 * @LastEditTime: 2024-02-03 18:04:01
 * @FilePath: \A-small-program\main.cpp
 */
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include <iostream>

void sleep(int time) {clock_t head = clock();while (clock() - head <= time) { }}

int main()
{
  srand((unsigned)time(NULL));
  printf("欢迎使用Program 版本号:0.0.0.1 Alpha\n");
  sleep(1000);
  const char* str = "|/-\\";
  char bar[102];
  memset(bar, '\0', sizeof(bar));
  for (int i = 0; i <= 100;)
  {
    srand((unsigned)time(NULL));
    printf("[%-100s][%d%%][%c]\r", bar, i, str[i % 4]); // 格式控制
    fflush(stdout); // 刷新
    bar[i++] = '#'; // 填充数据
    sleep(rand() % 50); // 休眠
  }
  sleep(1000);
  time_t ntime = time(0);
  printf("\33c");
  printf("现在的时间为 %s\n", ctime(&ntime));
  sleep(1500);
  printf("\33c");
  while (1)
  {
      int command;
      printf("请输入您想要使用的功能\n\n");
      printf("-> 1. 文本编辑器 <-\n\n");
      printf("-> 2. 退出 <-\n\n");
      scanf("%d", command);
      if (command == 1)
      {
          printf("正在开发中...");
      }
      if (command == 2)
      {
          exit(0);
      }
  }
  return 0;
}
