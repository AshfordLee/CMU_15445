#include<iostream>
#include<memory>
#include<string>
#include<utility>

class Point
//构造Point基类
{
    public:
        Point():x_(0),y_(0){}
        //默认构造，两个成员变量为0

        Point(int x,int y):x_(x),y_(y){}
        //带传入参数的构造，自定义成员变量的值

        inline int GetX() 
        {
            return x_;
        }
        //返回成员变量X

        inline int GetY()
        {
            return y_;
        }
        //返回成员变量Y

        inline void SetX(int x)
        {
            x_=x;
        }
        //设置成员变量X

        inline void SetY(int y)
        {
            y_=y;
        }
        //设置成员变量Y

    private:
        int x_;
        int y_;
    //声明变量
};

//unique_ptr的构造语法:std::unique_ptr<T> &ptr
void SetXTo445(std::unique_ptr<Point> &ptr)
//这里传入的指针是unique_ptr<Point>类型
{
    ptr->SetX(445);
    //由于这个指针指向这个Point类，所以可以调用其类中的函数
}


int main()
{
    std::unique_ptr<Point> u1;
    //粗暴的构造一个u1,这里只声明了指针指向Point类，但没有初始化

    std::unique_ptr<Point> u2=std::make_unique<Point>();
    //这里不但声明了指针指向的类型还初始化了，其实我们是在初始化
    //指针所指的那个具体的类，所以这里可以分别调用
    //类的两种构造方式(默认与传参)

    std::unique_ptr<Point> u3=std::make_unique<Point>(2,3);
    //同上

    Point test=Point(1,2);
    // std::unique_ptr<Point> u5=test;
    //注意这样是不行的，直接用一个初始化好了的类，然后让u5指向它
    //是不行的，因为unique_ptr的构造函数是explicit的，所以不能
    //直接用一个初始化好了的类，然后让u5指向它
    //还是乖乖地用std::make_unique

    std::unique_ptr<Point> u5=std::make_unique<Point>(test);
    //这样是可行的，因为std::make_unique会自动调用Point的构造函数
    //来初始化u5所指向的Point类
    //总之就是一定要用std::make_unique来初始化unique_ptr

    if (u1)
    {
        std::cout<<"u1's value of x is"<<u1->GetX()<<std::endl;
    }
    //这里u1是空的，所以不会输出
    if (u2)
    {
        std::cout<<"u2's value of x is"<<u2->GetX()<<std::endl;
    }
    //这里u2是初始化了的，所以会输出
    std::cout<<"Pointer u1 is "<<(u1 ? "not empty":"empty")<<std::endl;
    std::cout<<"Pointer u2 is "<<(u2 ? "not empty":"empty")<<std::endl;
    std::cout<<"Pointer u3 is "<<(u3 ? "not empty":"empty")<<std::endl;
    //这里u3是初始化了的，所以会输出

    std::unique_ptr<Point> u4=std::move(u3);
    //这里使用移动语义来让u4窃取u3的资源，然后u3自己就变成空指针了
    //注意：

    // std::unique_ptr<Point> u5=u4;
    // //这里是不行的，因为unique_ptr的拷贝构造是delete的

    std::cout<<"Pointer u3 is "<<(u3 ? "not empty":"empty")<<std::endl;
    std::cout<<"Pointer u4 is "<<(u4 ? "not empty":"empty")<<std::endl;

    SetXTo445(u4);
    //这里调用SetXTo445函数，传入u4，然后u4的x值被设置为445
    //调用的时候其实是用了u4所指向的那个类(Point类)的GetX()函数
    //所改变的也是那个类的成员X变量

    std::cout<<"Pointer u4's x value is "<<u4->GetX()<<std::endl;
    //这里输出u4的x值，因为刚刚调用SetXTo445函数的时候，已经改变了u4的x值
    
    return 0;
    
}