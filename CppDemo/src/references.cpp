#include <iostream>
// 加载头文件:输入输出

void add_three(int &a) { a = a + 3; }
// 这个函数对a的引用进行了加三的操作，不需要返回东西，因为直接把
// 内存当中a的值改变了

int main() {
  int a = 10;
  int &b = a;
  // b是a的引用，b和a共享同一块内存
  // b的值改变，a的值也会改变
  // a的值改变，b的值也会改变
  // b和a的地址相同
  // b和a的值相同
  std::cout << "value of b is " << b << std::endl;
  // 输出b的值
  add_three(a);
  // 调用add_three函数，对a的值进行加三的操作
  std::cout << "value of a is " << a << std::endl;
  // 输出a的值
  std::cout << "value of b is " << b << std::endl;
  // 输出b的值

  return 0;
}
