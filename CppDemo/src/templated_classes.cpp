#include <iostream>

template <typename T> class Foo {
public:
  Foo(T var) : var_(var) {}

  void print() { std::cout << var_ << std::endl; }

private:
  T var_;
};
//这里先声明了一个模板数据类型T，然后构造了一个类Foo
//然后声明了一个构造函数，这个构造函数接受一个T类型的参数
//然后把这个参数赋值给类中的成员变量var_
//然后声明了一个print函数，这个函数接受一个T类型的参数
//然后把这个参数打印出来
//这个"var_"是里面的private变量，所以如果如下访问:
//Foo<int> a(3);
//a.var_ = 3;
//这是会报错的，因为var_是private的
//所以只能通过类中的函数来访问
//a.print()是正确的，因为print是public的类函数
//所以a.print()是正确的，而a.var_ = 3;是错误的

template<typename T, typename U>
class Foo2
{
  public:
    Foo2(T var1, U var2):
      var1_(var1), var2_(var2) {}

    void print()
    {
      std::cout<<var1_<<","<<var2_<<std::endl;
    }

  private:
  T var1_;
  U var2_;
};
//和上面差不多，一个模板类接受两个数据类型参数T和U
//然后声明了一个构造函数，这个构造函数接受两个参数，一个是T类型的，一个是U类型的
//然后把这个参数赋值给类中的成员变量var1_和var2_
//然后声明了一个print函数，这个函数接受两个参数，一个是T类型的，一个是U类型的
//然后把这个参数打印出来
//这个"var1_"和"var2_"是里面的private变量，所以如果如下访问:
//Foo2<int, float> a(3, 3.14);
//a.var1_ = 3;
//这是会报错的，因为var1_和var2_是private的
//所以只能通过类中的函数来访问
//a.print()是正确的，因为print是public的类函数
//所以a.print()是正确的，而a.var1_ = 3;是错误的
//注意到private是必须声明var1_和var2_的，不然public中对var1_和var_2
//的初始化会报错，原因是类里根本就没声明var1_和var2_

template<typename T>
class FooSpecial{
  public:
    FooSpecial(T var):var_(var) {}
    void print()
    {
      std::cout<<var_<<std::endl;
    }

  private:
    T var_;
};
//这里声明了一个模板类FooSpecial，这个类接受一个数据类型参数T
//然后声明了一个构造函数，这个构造函数接受一个T类型的参数
//然后把这个参数赋值给类中的成员变量var_
//然后声明了一个print函数，这个函数接受一个T类型的参数
//然后把这个参数打印出来
//这个"var_"是里面的private变量，所以如果如下访问:
//FooSpecial<int> a(3);
//这个类是给下面这个specialized class做准备的

template<>
class FooSpecial<float>
{
  public:
    FooSpecial(float var):var_(var) {}
    void print()
    {
      std::cout<<"hello float!"<<var_<<std::endl;
    }

  private:
    float var_;
    
};
//这叫做"模板特化"，即指定模板中的一部分(或者是全部)的数据类型
//其余的和通用模板一样

template<int T>
class Bar
{
  public:
    Bar(){}
    void print_int()
    {
      std::cout<<"print int"<<T<<std::endl;
    }
};
//这个时候模板传进去的是一个int类型T，这个值在编译的时候就要确定
//可以理解为先指定一个值，然后生成一个类
//然后把这个类硬传入进去


int main()
{
    Foo<int> a(3);
    std::cout<<"Calling print on Foo<int> a (3)";
    a.print();


    Foo<float> b(3.4F);
    std::cout<<"Calling print on Foo b(3.4f)";
    b.print();

    Foo2<int,float> c(3,3.14);
    std::cout<<"Calling print on Foo2 c(3,3.14)";
    c.print();

    FooSpecial<int> d(5);
    std::cout<<"Calling print on FooSpecial<int> d(5)";
    d.print();

    FooSpecial<float> e(4.5);
    std::cout << "Calling print on FooSpecial<float> e(4.5): ";
    e.print();

    Bar<15> f;
    std::cout << "Calling print_int on Bar f: ";
    f.print_int();



    
}