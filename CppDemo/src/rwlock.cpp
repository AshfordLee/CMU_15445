#include<iostream>
#include<mutex>
#include<shared_mutex>
#include<thread>


int count=0;
std::shared_mutex m;

void read_value()
{
    std::shared_lock lk(m);
    count+=3;
    std::cout<<"Read Value"<<std::endl;
}
//读数据可以是共享锁

void write_value()
{
    std::unique_lock lk(m);
    count+=3;
    std::cout<<"Write Value"<<std::endl;
}
//写数据必须是独占锁

int main()
{
  std::thread t1(read_value);
  std::thread t2(write_value);
  std::thread t3(read_value);
  std::thread t4(read_value);
  std::thread t5(write_value);
  std::thread t6(read_value);
  //创建线程，并让这些线程去做这些事情

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  //每个join负责阻塞当前线程
  //比如t1.join()就是阻塞现在的线程
  //等待t1线程完场

  return 0;


}