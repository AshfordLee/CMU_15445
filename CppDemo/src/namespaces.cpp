#include<iostream>

namespace ABC{
    //命名空间ABC，该空间内包含一个函数spam和一个嵌套空间DEF
    void spam(int a)
    {
        std::cout<<"Hello from ABC::spam"<<a<<std::endl;
    }

    namespace DEF{
        //命名空间DEF，这是被嵌套在ABC之下的，里面有三个函数
        void bar(float a)
        {
            std::cout<<"Hello from ABC::DEF::bar"<<a<<std::endl;
        }
    

        void uses_bar(float a)
        {
            std::cout<<"Hello from uses_bar:";
            bar(a);
        }

        void uses_spam(int a)
        {
            std::cout<<"Hello from uses_spam: ";
            ABC::spam(a);
        }
    }

    void uses_DEF_bar(float a)
    {
        std::cout<<"Hello from uses_DEF_bar ";
        DEF::bar(a);
    }
    //这里可以跨空间调用DEF下的bar函数，虽然这个函数自身是在ABC下的

}

namespace A{
    void foo(int a)
    {
        std::cout<<"Hello from A::foo: "<<a<<std::endl;
    }
}

namespace B{
    void foo(int a)
    {
        std::cout<<"Hello from B::foo: "<<a<<std::endl;
    }

    void peloton(int a)
    {
        std::cout<<"Hello from B:peloton"<<a<<std::endl;
    }
}

namespace C{
    void eggs(int a)
    {
        std::cout<<"Hello from C::eggs: "<<a<<std::endl;
    }
}

//上面是另外三个命名空间，他们的函数也可以通过<命名空间>::<函数名>来调用

using namespace B;
//使用命名空间B，这样就可以直接调用B空间下的函数，而不需要加上B::

using C::eggs;
//这里是特别指明可以直接用C空间下的eggs，而不需要加上C::

int main()
//实际上就是差不多把同名函数划分到不同命名空间
//这样就不会混淆，调用的时候加上命名空间就行了

{
    ABC::spam(1);

    ABC::DEF::bar(4.45);

    ABC::DEF::uses_bar(6.45);

    ABC::DEF::uses_spam(37);

    ABC::uses_DEF_bar(3.12);

    A::foo(122);
    B::foo(150);

    foo(440);

    peloton(721);

    eggs(999);

    return 0;
}

