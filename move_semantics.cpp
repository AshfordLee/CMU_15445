#include<iostream>
#include<vector>
#include<utility>

//三个头文件，提供输入输出流，向量，实用工具

void move_add_three_and_print(std::vector<int> &&vec)
//这里传入的形参std::vector<int> &&,&&表示他是一个右值，他是不能倍取地址的，
//而且不能把平时正常的对象传入这个函数
//一般传入这个函数的是临时对象，或者是用std::move转换的对象
{
    std::vector<int> vec1=std::move(vec);
    //vec这个临时对象的值被赋值给vec1,然后vec自己被清空
    vec1.push_back(3);
    //装一个3给这个vec
    for (const int &item:vec1)
    {
        std::cout<<item<< " ";
    }
    //这里这个for循环使用了常量引用而不是直接int item,
    //这样做的一个好处是利用引用而不是另外创建一个对象,
    //这样做可以节省一些内存开销
    //除此之外，由于是const引用，所以编译器会阻止任何人改变item
    std::cout<<"\n";

}

void add_three_and_print(std::vector<int> &&vec)
{
    vec.push_back(3);
    for (const int &item:vec)
    {
        std::cout<<item<<" ";

    }
    std::cout<<"\n";
    //这里和上面的区别是什么？
    //最大的区别就是他直接操作传入的参数，而不是创建一个临时的对象
    //而用move会让原来的参数被清空
} 

int main()
{
    int a=10;
    std::vector<int> int_array={1,2,3,4};
    std::vector<int> stealing_ints=std::move(int_array);
    //这里int_array被移动到了stealing_ints,然后int_array被清空
    std::vector<int> &&rvalue_stealing_ints=std::move(stealing_ints);
    //这里是不一样的，这里是搞了一个右值引用接受move传过来的stealing_ints
    //所以stealing_ints不会被清空
    //如果改成std::vector<int> new=std::move(stealing_ints)
    //那么stealing_ints会被清空
    std::cout << "Printing from stealing_ints: " << stealing_ints[1] << std::endl;

    std::vector<int> int_array2={1,2,3,4};
    std::cout<<"Calling move_add_three_and_print...\n";
    move_add_three_and_print(std::move(int_array2));
    //这里int_array2被移动到了move_add_three_and_print函数中
    //然后int_array2被清空
    std::cout<<"After move, int_array2 is empty: ";
    for (const int &item:int_array2)
    {
        std::cout<<item<<"\n";
    }

    std::vector<int> int_array3={1,2,3,4};
    std::cout<<"Calling add_three_and_print...\n";
    add_three_and_print(std::move(int_array3));
    //这里int_array3被移动到了add_three_and_print函数中
    //然后int_array3被清空
    std::cout<<"After move, int_array3 is empty: ";
    for (const int &item:int_array3)
    


    
    return 0;
}