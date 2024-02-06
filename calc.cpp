// Framework: None
// Technology stack: None

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string a;
    std::cout << "请输入要计算的算式：";
    std::cin >> a;

    std::vector<int> b;
    std::vector<int> c;
    int x = 0;
    int j = 0;
    
    for (char i : a) {  //分词
        if (i >= '0' && i <= '9') {
            x *= 10;
            x += (int)(i - '0');
        }
        if (i == '+' || i == '-' || i == '*' || i == '/') {
            b.push_back(x);
            b.push_back(i);
            x = 0;
        }
    }
    b.push_back(x);
    
    for (int i = 0; i < b.size(); ++i) {   //处理二级运算
        if (typeid(b[i]) == typeid(std::string)) {
            if (b[i] == "+" || b[i] == "-") {
                if (i == 1 && b.size() - 1 - i != 1) {
                    c.push_back(b[i - 1]);
                } else if (i != 1 && b.size() - 1 - i == 1) {
                    if (b[i - 2] != '*' && b[i - 2] != '/') {
                        c.push_back(b[i - 1]);
                    }
                } else {
                    if (b[i - 2] != '*' && b[i + 2] != '*') {
                        c.push_back(b[i - 1]);
                    }
                }
                c.push_back(b[i]);
            }
            if (b[i] == "*" || b[i] == "/") {
                if (b[i] == '*') {
                    c.push_back(b[i - 1] * b[i + 1]);
                } else {
                    c.push_back(b[i - 1] / b[i + 1]);
                }
            }
        }
    }
    j = c[0];
    
    for (int i = 0; i < c.size(); ++i) {                     //处理一级运算
        if (typeid(c[i]) == typeid(std::string)) {
            if (c[i] == "+" || c[i] == "-") {
                if (c[i] == "+") {
                    j += c[i + 1];
                } else {
                    j -= c[i + 1];
                }
            }
        }
    }
    
    std::cout << "结果为 " << j << std::endl;

    return 0;
}
