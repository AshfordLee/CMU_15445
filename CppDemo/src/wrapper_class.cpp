#include <cstdint>
#include<iostream>
#include<utility>

//智能指针管理类
//用于动态分配内存的整型指针
class IntPtrManager
{
    public:
        //默认构造函数
        IntPtrManager()
        {
            ptr_=new int;
            *ptr_=0;
            //先开辟内存，再赋值
            //在堆(heap)上开辟内存，内存的大小
            //正好是一个int的大小
            //4字节
            //然后赋值:这块内存地址储存的int变量为0
        }

        IntPtrManager(int val)
        {
            ptr_=new int;
            *ptr_=val;
            //一样的，先开辟内存再赋值
            //只不过这时候赋值不是0
            //是val
        }

        ~IntPtrManager()
        {
            if (ptr_)
            {
                delete ptr_;
            }
            //析构函数，这里检查指针是不是空
            //不是空的话，就释放内存
            //这样的话避免了后面对空指针的引用
        }

        IntPtrManager(IntPtrManager&& other)
        {
            ptr_=other.ptr_;
            other.ptr_=nullptr;
            //通过移动语义来构造
            //这里的other是一个右值
            //然后把other的指针(右值的内容)
            //转移到当前的ptr_
        }

        IntPtrManager &operator=(IntPtrManager &&other)
        {
            if (ptr_==other.ptr_)
            {
                return *this;
            }

            if (ptr_)
            {
                delete ptr_;
            }

            ptr_=other.ptr_;
            other.ptr_=nullptr;
            return *this;
        }
        //这里重载了赋值运算符，原来的赋值运算符
        //默认是左值浅拷贝，现在改成右值来窃取资源
        //函数的目的是把右值other的资源转移给ptr
        //然后other的资源被清空
        //所以如果两个指针本就指向同一块内存
        //直接返回自身就好了
        //如果不是指向同一块内存，那么就把_ptr释放掉
        //然后再接受other的资源
        //最后把other的指针清空

        IntPtrManager(const IntPtrManager &)=delete;
        //通过拷贝来构造，被禁止
        IntPtrManager &operator=(const IntPtrManager &)=delete;
        //通过拷贝来赋值，被禁止

        //禁止通过拷贝来赋值
        //IntPtrManager a(10);
        //IntPtrManager b = a;  // 错误！复制构造函数被禁用
        // IntPtrManager a(10);
        // IntPtrManager b;
        // b = a;  // 错误！复制赋值运算符被禁用
        //这里的const不能去掉，因为右值不能
        //绑定到非const引用

        void SetVal(int val)
        {
            *ptr_=val;
        }
        
        int GetVal() const{
            return *ptr_;
        }

    private:
        int *ptr_;
};

int main()
{
    IntPtrManager a(445);

    std::cout<<"1. Value of a is "<<a.GetVal()<<std::endl;

    a.SetVal(645);

    std::cout<<"2 Value of a is "<<a.GetVal()<<std::endl;

    IntPtrManager b(std::move(a));

    // std::cout<<"3 Value of a is "<<a.GetVal()<<std::endl;
    //这里a的资源已经被转移给b了
    //所以会报错

    return 0;
    
    
}

