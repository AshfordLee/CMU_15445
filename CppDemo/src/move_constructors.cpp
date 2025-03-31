#include<iostream>
#include<utility>
#include<string>
#include<cstdint>
#include<vector>


class Person{
    public:
        Person():age_(0),nicknames_({}),valid_(true) {}
        //这是Person类的默认构造函数
        //类里面有三个变量，age_被初始化为0
        //nicknames_被初始化为空vector
        //valid_被初始化为true
        //特别注意{}是空vector的意思

        Person(uint32_t age,std::vector<std::string> &&nicknames)
            :age_(age),nicknames_(std::move(nicknames)),valid_(true) {}
        //这是Person类的另一个(非默认)构造函数
        //传入两个参数给他，一个uint32_t类型的age
        //uint32_t类型是无符号整数，他是固定长度的，32位=4个字节
        //另一个参数是一个"右值引用"，他可以接受一个临时对象
        //这里这个nicknames被传进Person类后，用std::move把他的内容传递到Person的
        //类变量nicknames_当中
        //valid_初始化为true
        

        Person(Person &&person)
            :age_(person.age_),nicknames_(std::move(person.nicknames_)),valid_(true)
            {
                std::cout<<"Calling the move constructor for class Person.\n";
                person.valid_=false;
            }
        //这是上面的"扩展版"
        //这里直接把一个现存的Person类当作右值引用传进来
        //然后把他的类变量一一赋值给新的Person类
        //特别注意nicknames_作为一个std::vector<std::string>，为了节省
        //内存开销，利用的是移动语义，而不是粗暴的赋值
        //这样就会使原来的那个person类的nicknames_"陷入虚无"
        //因为他的内容已经被移动到新的Person类当中了
        //所以原来的那个person类就变成了一个空壳
        //这里就体现了移动构造函数的一个作用：
        //避免不必要的深拷贝


        Person &operator=(Person &&other){
            std::cout<<"Calling the move assignment operator for class Person.\n";
            age_=other.age_;
            nicknames_=std::move(other.nicknames_);
            valid_=true;
            other.valid_=false;
            return *this;
        }
        //这是有一个通过右值来更改类的函数
        //有必要解释一下这个函数头
        //Person& 是函数的返回值类型，代表他会返回一个Person类的引用
        //operator= 是函数名，注意这是C++的特殊语法，他其实重载了"="这个运算符
        //(Person &&other) 是函数的参数，代表他会接受一个右值引用
        //example:
        //Person p1(25,{"Nick"})
        //Person p2(30,{"Bob"})
        //p2.operator=(std::move(p1))
        //分解一下这句话，p2是一个Person类对象，这是显然的
        //这里的函数名字叫做"operator="，对的，"="也被加到这个函数
        //的名字里面去了，那么根据我们的构造，这个函数要接受一个右值引用作为参数
        //而且必须是Person类的引用右值，那么这个右值从哪里来呢？
        //猜对了，因为std::move(p1),因为移动语义会"返回"一个右值引用
        //所以它可以被传入这个函数，更新p2当中的类变量
        //最后一行return *this，代表返回p2的引用，也就是更新后的p2
        //注意，这里p2的nicknames_被更新了，p1的nicknames_被"清空"了
        //这就是移动赋值运算符的实现

        Person(const Person&)=delete;
        Person &operator=(const Person&)=delete;
        //我们来翻译一下这两个句子
        //Person(const Person&)的意思是"用一个常量Person对象的引用来拷贝
        //构造另一个Person对象
        //=delete的意思是"删除"这个函数，也就是说，这个函数不能被调用
        //example:
        //Person p1(25,{"Nick"})
        //Person p2(p1), 这个构造是非法的，因为前面已经设定为delete
        //第二句话的意思是"用一个常量Person对象的引用来赋值给另一个Person对象"
        //这个也是非法的，因为前面已经设定为delete
        //所以，这两个函数都不能被调用
        //注意 operator= 是我们之前重载的一个函数
        //example:
        //Person p1(25,{"Nick"})
        //Person p2(30,{"Bob"})
        //p2=p1, 这个赋值是非法的，因为前面已经设定为delete
        //所以，这个赋值也不能被调用

        uint32_t GetAge()
        {
            return age_;
        }
        //这个函数很简单，就是返回age_的值
        //注意到age_的变量一开始就被定义为uint32_t类型
        //所以这里理所当然应该返回这个数据类型的age_

        std::string &GetNicknameAtI(size_t i)
        {
            return nicknames_[i];
        }
        //这个函数就是返回类变量nicknames_的第i个元素
        //注意，这里返回的是一个引用，而不是值
        //size_t是一种数据类型，是一个无符号整数
        //他在32位系统上是4字节，64位系统上是8字节

        void PrintValid()
        {
            if (valid_)
            {
                std::cout<<"Object is valid.\n"<<std::endl;
            }
            else {
            {
                std::cout<<"Object is invalid."<<std::endl;
            }
            }
        }
        //非常简单，不做解释

    private:
        uint32_t age_;
        std::vector<std::string> nicknames_;
        bool valid_;
    //声明数据类型
};


int main()
{
    Person andy(15445,{"andy","pavlo"});
    std::cout<<"Printing andy's validity:";
    andy.PrintValid();

    Person andy1;
    andy1.operator=(std::move(andy));

    std::cout<<"Printing andy1's validity:";
    andy1.PrintValid();
    std::cout<<"Printing andy's validity:";
    andy.PrintValid();

    Person andy2(std::move(andy1));
    std::cout<<"Printing andy2's validity:";
    andy2.PrintValid();

    std::cout<<"Printing andy1's validity:";
    andy1.PrintValid();
    
    Person andy3;
    // andy3=andy2;
    //这里这种赋值被我们delete掉了，所以编译会报错
    //所以不要这样干
    return 0;
}