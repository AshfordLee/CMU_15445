#include<iostream>

struct Node{
    Node(int val):
        value_(val),
        prev_(nullptr),
        next_(nullptr){}
    //结构体定义，相当于一个双向链表
    //节点有一个值，有一个指向下一个节点的指针
    //还有一个指向上一个节点的指针

    Node* prev_;
    Node* next_;
    int value_;
    //声明Node结构体包含的变量
};


class DLLIterator{
    public:
        DLLIterator(Node* head):
            curr_(head) {}

        //构造函数，传入一个指向Node的指针head，并且把head赋值给curr_

        DLLIterator& operator++(){
            curr_=curr_->next_;
            return *this;
        }
        //重载++运算符，使迭代器指向下一个节点
        //这里是前向递增，也就是++iter的格式先移动再使用
        //而且这里返回的是类的引用

        DLLIterator operator++(int){
            DLLIterator temp= *this;
            ++*this;
            return temp;
        }
        //重载++运算符，这里是后向递增，也就是iter++的格式先使用再移动
        //用来区别前后递增的是函数中的参数，也就是这里的(int)
        //实际上这个参数并没有被使用

        //注意这里是怎么实现"先使用，再移动"的
        //DLLIterator temp=*this的意思是创建一个迭代器副本
        //++*this的意思是移动正本
        //返回副本，自然返回的就是没有移动的东西
        //而正本(我们需要的那个)已经被移动了

        bool operator==(const DLLIterator &itr) const{
            return itr.curr_==this->curr_;
        }
        //重载了==运算符，判定两个迭代器是不是相等
        //所以传入的是一个DLLIterator类的对象

        bool operator!=(const DLLIterator &itr) const{
            return itr.curr_!=this->curr_;
        }
        //重载了!=运算符，判定两个迭代器是不是不相等

        int operator*(){
            return curr_->value_;
        }
        //重载了*运算符，返回当前迭代器指向的节点的值

    private:
        Node* curr_;
        //声明一个指向Node的指针curr_

};

class DLL{
    //类似于一个双向链表
    public:
        DLL()
        :head_(nullptr),
        size_(0) {}
        //初始化头指针为空
        //链表大小为0

        ~DLL(){
            Node *current=head_;
            while(current!=nullptr)
            {
                Node *next=current->next_;
                delete current;
                current=next;
            }
            head_=nullptr;
        }
        //析构函数，遍历整个链表，删除每个节点
        //最后把头指针设为空

        void InsertAtHead(int val)
        {
            Node *new_node=new Node(val);
            new_node->next_=head_;

            if (head_!=nullptr)
            {
                head_->prev_=new_node;
            }

            head_=new_node;
            size_+=1;
        }
        //头插法加入节点

        DLLIterator Begin()
        {
            return DLLIterator(head_);
        }
        //返回一个指向头节点的迭代器
        //注意在迭代器的构造当中，只要传入一个指向Node的指针就好了(head_)
        //所以这里把head_传入进去之后，当然就是指向head的迭代器

        DLLIterator End()
        {
            return DLLIterator(nullptr);
        }
        //同理

        Node *head_{nullptr};
        size_t size_;
        //声明变量

};

int main()
{
    DLL dll;
    dll.InsertAtHead(6);
    dll.InsertAtHead(5);
    dll.InsertAtHead(4);
    dll.InsertAtHead(3);
    dll.InsertAtHead(2);
    dll.InsertAtHead(1);

    for (DLLIterator iter = dll.Begin(); iter != dll.End(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}