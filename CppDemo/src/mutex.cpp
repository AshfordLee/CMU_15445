#include<iostream>
#include<mutex>
#include<thread>


int count=0;

std::mutex m;
//声明一个全局锁m

void add_count()
{
    m.lock();
    //一个线程获取锁
    count+=1;
    m.unlock();
    //一个线程释放锁

}
//lock和unlock之间的被称之为临界区
//同一时间，只有一个线程可以访问临界区

int main()
{
    std::thread t1(add_count);
    //创建线程t1 执行add_count函数，在此过程中锁属于t1

    std::thread t2(add_count);
    //创建线程t2 执行add_count函数，若执行的时候t1还未释放锁，则t2会阻塞等待t1释放锁
    
    t1.join();
    t2.join();
    //等待t1和t2执行完毕
    std::cout<<"Printing count: "<<count<<std::endl;
    return 0;
}