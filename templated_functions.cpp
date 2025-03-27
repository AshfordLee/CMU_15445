#include<iostream>

template<typename T> 
//这里声明了一个模板函数，T是类型参数，或者可以认为T被声明
//是某种数据类型，从这里开始T就不是一个简单的字母了，而是
//某种数据类型
T add(T a,T b)
//这里的意思就是随便传入两个数据类型一样的a和b，然后返回值的类型也是T
//这里就像一个群，同样的两个数我可以是加法群也可以是乘法群
//假如传入int a和b，那么她就像是一个"加法群"
//如果是两个string,那么就像一个"字符串群"，群的运算方式是把字符串合起来
{
    return a+b;
}

template<typename T,typename U>

void print_two_values(T a,U b)
{
    std::cout<<a<<" and "<<b<<std::endl;
}
//和前面大同小异，只不过这里一次可以接受两个不一样的数据类型

template<typename T>
void print_msg()
{
    std::cout<<"Hello WOrld\n";
}
//这里没有传入参数，所以她可以接受任何数据类型

template<bool T>
int add3(int a)
{
    if(T)
    {
        return a+3;
    }
    return a;
}
//这里是非常搞笑的一个函数，这里的template是什么意思呢？
//意思是T已经被声明为bool，所以T只能是true或者false
//所以这个函数的意思是，如果T是true，那么就返回a+3，否则返回a


int main()
{
    std::cout<<"Printing add<int>(3,5): "<<add<int>(3,5)<<std::endl;
    std::cout<<"Printing add<float>(2.8,3.7)"<<add<float>(2.8,3.7)<<std::endl;
    std::cout<<"Printing add(3,5) "<<add(3,5)<<std::endl;
    std::cout<<"Printing print_two_values<int,float>)(3,3.2):";
    print_two_values<int,float>(3,3.2);
    std::cout << "Calling print_msg<int>(): ";
    print_msg<int>();
    std::cout << "Calling print_msg<float>(): ";
    print_msg<float>();

    std::cout << "Printing add3<true>(3): " << add3<true>(3) << std::endl;
    std::cout << "Printing add3<false>(3): " << add3<false>(3) << std::endl;

    return 0;
}


