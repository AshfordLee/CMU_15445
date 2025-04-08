#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<unordered_map>

template <typename T,typename U> 
class Abcdefghijklmnopqrstuvwxyz
{
    public:
    Abcdefghijklmnopqrstuvwxyz (T instance1, U instance2):
    instance1_(instance1), instance2_(instance2){}

    void print() const{
        std::cout<<"("<<instance1_<<","<<instance2_<<")"<<std::endl;
    }

    private:
    T instance1_;
    U instance2_;



};
//模板类，先声明两个数据类型T和U，然后定义这个类

template <typename T>
Abcdefghijklmnopqrstuvwxyz<T,T> construct_obj(T instance)
{
    return Abcdefghijklmnopqrstuvwxyz<T,T>(instance,instance);
}
//模板函数，注意只要涉及到"模板"，就一定要有templage <typename T>这种声明
//Abcdefghijklmnopqrstuvwxyz<T,T> 这里指代的是函数的返回值的类型，注意不要忘了
//C++写函数一定要先写返回值类型
//这个函数返回什么？返回的是一个类，准确来说是一个模板类，这个类已经通过return后面的初始化好了
//所以返回一个类的实例

int main()
{
    auto a=1;
    auto b=3.2;
    auto c=std::string("Hello");
    Abcdefghijklmnopqrstuvwxyz<int,int> obj=construct_obj<int>(2);
    //这里返回的就是一个模板类的实例，这个实例的类型是Abcdefghijklmnopqrstuvwxyz<int,int>
    //注意这里的construct_obj后面的<int>可以不写，编译器会自动推断类型的

    auto obj1=construct_obj<int>(2);
    //用auto,编译器会自动推断obj1的类型
    
    std::vector<int> int_values={1,2,3,4};

    auto copy_int_values=int_values;

    auto& ref_int_values=int_values;

    std::unordered_map<std::string,int> map;
    map.insert({{"andy",445},{"jignesh",645}});

    std::cout<<"Printing elements in map:"<<std::endl;

    for(std::unordered_map<std::string,int>::iterator it=map.begin();
    it!=map.end();++it)
    {
        std::cout<<"()"<<it->first<<","<<it->second<<")"<<" ";
    }
    //迭代器遍历

    std::cout<<std::endl;

    for(auto it=map.begin();it!=map.end();++it)
    {
        std::cout<<"()"<<it->first<<","<<it->second<<")"<<" ";
    }
    //迭代器遍历，注意这里不显式指定迭代器数据类型了,
    //实际上迭代器的数据类型是std::unordered_map<std::string,int>::iterator
    //用auto的话编译器会自行推断的
    
    std::cout<<std::endl;

    std::vector<int> vec={1,2,3,4};
    
    std::cout<<"Printing elements in vector with auto...\n";

    for (const auto& element:vec)
    {
        std::cout<<element<<" ";
    }

    std::cout<<std::endl;

    std::set<int> set;
    for (int i=1;i<=10;++i)
    {
        set.insert(i);
    }

    std::cout<<"Printing elements in set with auto...\n";
    for (const auto& element:set)
    {
        std::cout<<element<<" ";
    }

    std::cout<<std::endl;
    return 0;

}