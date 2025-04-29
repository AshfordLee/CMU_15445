#include<iostream>
#include<memory>
#include<utility>


class Point{
    public:
        Point():x_(0),y_(0){}
        Point(int x,int y):x_(x),y_(y){}

        inline int GetX(){
            return x_;
        }
        
        inline int GetY()
        {
            return y_;
        }

        inline void SetX(int x)
        {
            x_=x;
        }

        inline void SetY(int y)
        {
            y_=y;
        }
    
    private:
        int x_;
        int y_;

};
//基类，所有的指针都指向这个point类

void modify_ptr_via_ref(std::shared_ptr<Point>& point)
{
    point->SetX(15);
}
//传入一个左值引用，这个引用其实就是某个point类，然后
//直接调用这个类的成员函数设置X变量
//！！！一定注意这里传入的是左值引用，不是指针！
//以下才是传入指针的函数头：
//void modify_ptr_via_ptr(std::shared_ptr<Point>* point)



void modify_ptr_via_rvalue_ref(std::shared_ptr<Point>&& point)
{
    point->SetY(645);
}
//这里传入一个右值引用，其他的和上面一样
//注意，这里传入的一样也不是指针

void copy_shared_ptr_in_function(std::shared_ptr<Point> point)
{
    std::cout<<"Use count of shared pointer is "<<point.use_count()<<std::endl;
}
//这里传入的就是一个std::shared_ptr<Point>类型的变量
//这里是值传递，所以会创建值的拷贝，使用双倍内存
//use_count()返回的是这个指针的引用计数
//注意当这个函数被执行的时候，由于副本被创建，count也会加一
//当被执行完毕后，副本被销毁，count会减一(等于回到原来的了)

int main()
{
    std::shared_ptr<Point> s1;
    //声明一个空的智能指针，指向的类型是Point,当他没指向任何东西

    std::shared_ptr<Point> s2=std::make_shared<Point>();
    //声明一个智能指针，同样是指向一个Point类，但是这个类用make_shared
    //创建了，所以他是指向了真的东西的
    
    std::shared_ptr<Point> s3=std::make_shared<Point>(10,20);
    //同理，这里指向的类也是被创建了的

    std::cout<<"Pointer s1 is "<<(s1? "not empty":"empty")<<std::endl;
    std::cout<<"Pointer s2 is "<<(s2? "not empty":"empty")<<std::endl;
    std::cout<<"Pointer s3 is "<<(s3? "not empty":"empty")<<std::endl;
    //判断是不是空指针

    std::cout
        <<"Number of shared pointer object instances using the data in s3: "
        <<s3.use_count()<<std::endl;

    //检查count


    std::shared_ptr<Point> s4=s3;
    //直接拷贝构造，unique_ptr是不能这样干的，但是
    //shared_ptr是可以的

    std::cout<<"Number of shared pointer object instances using the data in s3 "
            <<"After one copy:"
            <<s3.use_count()<<std::endl;
    //检查count

    std::shared_ptr<Point> s5(s4);
    //这和std::shared_ptr<Point> s5=s4是完全等价的
    //这两个指针现在都指向同一个原始对象
    //也许这就是“共享”的含义

    std::cout << "Number of shared pointer object instances using the data in s3 "
            "after two copies: "
        << s3.use_count() << std::endl;
    //检查count


    s3->SetX(445);
    //直接修改原始对象的值

    std::cout<<"Print x in s3: "<<s3->GetX()<<std::endl;
    std::cout<<"Print x in s4: "<<s4->GetX()<<std::endl;
    std::cout<<"Print x in s5: "<<s5->GetX()<<std::endl;
    //检查修改后的值

    std::shared_ptr<Point> s6=std::move(s5);
    //用移动语义来赋值创造新的指针，注意这里s5的值被
    //"窃取"了

    std::cout<<"Pointer s5 is "<<(s5? "not empty":"empty")<<std::endl;
    //检查s5是否为空

    std::cout << "Number of shared pointer object instances using the data in s3 "
                "after two copies and a move: "
                << s3.use_count() << std::endl;
    //检查count

    modify_ptr_via_ref(s2);
    //通过引用改变成员变量

    modify_ptr_via_rvalue_ref(std::move(s2));
    //通过右值引用改变成员变量

    std::cout<<"Pointer s2 has x="<<s2->GetX()<<" and y="<<s2->GetY()<<std::endl;
    //检查修改后的值
    
    std::cout
        << "Number of shared pointer object instances using the data in s2: "
        << s2.use_count() << std::endl;

    //检查count

    copy_shared_ptr_in_function(s2);
    //检查count

    std::cout << "Number of shared pointer object instances using the data in s2 "
                "after calling copy_shared_ptr_in_function: "
                << s2.use_count() << std::endl;
    //检查count

    return 0;
}