#include<condition_variable>
#include<iostream>
#include<mutex>
#include<thread>

int count=0;
std::mutex m;
//声明变量和锁

std::condition_variable cv;
//声明条件变量

void add_count_and_notify()
{
    std::scoped_lock slk(m);
    //直接创建锁并且加锁
    //当slk对象销毁的时候自动释放锁
    count+=1;
    if (count==2)
    {
    cv.notify_one();
    //唤醒正在等待的线程
    //如果有很多线程在等待，
    //那么就会随机唤醒一个
    }
}

void waiter_thread()
{
    std::unique_lock lk(m);
    //加锁
    cv.wait(lk,[]{return count==2;});
    //等待条件变量被唤醒
    //如果条件不满足，则阻塞等待
    //如果条件满足，则继续执行

    std::cout<<"Printing count: "<<count<<std::endl;
}

int main()
{
    std::thread t1(add_count_and_notify);
    //创建线程t1，执行add_count_and_notify函数
    std::thread t2(add_count_and_notify);
    //创建线程t2，执行add_count_and_notify函数
    std::thread t3(waiter_thread);
    //创建线程t3，执行waiter_thread函数

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

//注意这个主程序是一个线程，然后t1又是一个线程，所以当t1被创建的时候
//他自己就会去执行add_count_and_notify去了，
//主程序仍然是同时向下执行的
//并不是说主程序要等t1执行完了再执行