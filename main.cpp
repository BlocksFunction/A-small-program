#include <cstdio>
#include <cstring>
#include <map>
#include <random>
#include <thread>

#define Clean() printf("\33c");

struct Comap {};

auto sleep(int time) -> void {
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

auto nowtm() -> char * {
  std::chrono::time_point time = std::chrono::system_clock::now();
  time_t nowtime = std::chrono::system_clock::to_time_t(time);
  struct tm *locate = localtime(&nowtime);
  static char crte[9];
  sprintf(crte, "%02d:%02d:%02d", locate->tm_hour, locate->tm_min,
          locate->tm_sec);
  return crte;
}

auto calc() -> void {
  printf("HelloWorld");
  return;
}

auto main() -> int {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> *radn =
      new std::uniform_real_distribution<>(0, 100);
  printf("欢迎使用Program 版本号:0.0.0.1 Alpha\n");
  char *bar = new char[102];
  memset(bar, '\0', sizeof(*bar));
  for (int i = 0; i <= 100;) {
    srand((unsigned)time(NULL));
    printf("[%-100s][%d%%][%c]\r", bar, i, "|/-\\"[i % 4]); // 格式控制
    fflush(stdout);                                         // 刷新
    bar[i++] = '#';                                         // 填充数据
    sleep(static_cast<int>((*radn)(gen)));                  // 休眠
  }
  delete radn;
  delete[] bar;
  sleep(1000);
  Clean();
  printf("现在的时间为 %s\n", nowtm());
  sleep(1500);
  Clean();
  // 我干脆把循环给删了吧
  char command[20];
  printf("请输入您想要使用的功能\n\n");
  printf(" 计算器(calc) \n\n");
  printf(" 2. 退出(exit) \n\n");
  scanf("%s", command);
  ComMap[command]();
  return 0;
}
