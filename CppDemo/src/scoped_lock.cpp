#include<iostream>
#include<mutex>
#include<thread>


int count=0;
std::mutex m;
//声明互斥锁m

void add_count()
{
    std::scoped_lock slk(m);
    //创建了一个叫做slk的scoped_lock对象，
    //创建的时候自动获得锁
    //当slk对象销毁(这里就是函数结束)的时候
    //自动释放锁
    count+=1;
}

int main()
{
    std::thread t1(add_count);
    //创建线程t1，执行add_count函数,执行的时候就会创建slk对象，从而使得
    //锁m为t1占有
    std::thread t2(add_count);
    //创建线程t2，执行add_count函数,执行的时候就会创建slk对象，从而使得
    //锁m为t2占有
    t1.join();
    t2.join();
    //等待t1和t2执行完毕
    std::cout<<"Printing count: "<<count<<std::endl;
    return 0;
}