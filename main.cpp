#include <time.h>
#include <windows.h>
#include <cstdio>
#include <cstring>

int main()
{
  srand((unsigned)time(NULL));
  printf("欢迎使用用于视窗系统的Pro 版本号:0.0.0.1 Alpha\n");
  Sleep(1000);
  const char* str = "|/-\\";
  char bar[102];
  memset(bar, '\0', sizeof(bar));
  for (int i = 0; i <= 100;)
  {
    srand((unsigned)time(NULL));
    printf("[%-100s][%d%%][%c]\r", bar, i, str[i % 4]); // 格式控制
    fflush(stdout); // 刷新
    bar[i++] = '#'; // 填充数据
    Sleep(rand() % 50); // 休眠
  }
  Sleep(1000);
  system("clear");
  time_t ntime = time(0);
  printf("现在的时间为 %s\n", ctime(&ntime));
  Sleep(1500);
  system("clear");
  while (1){}
}
