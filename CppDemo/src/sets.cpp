#include<iostream>
#include<set>

int main()
{
    std::set<int> int_set;
    //创建一个集合，元素的数据类型是int


    for (int i=1;i<=5;i++)
    {
        int_set.insert(i);
    }
    //插入元素1到5

    for (int i=6;i<=10;i++)
    {
        int_set.emplace(i);

    }
    //插入元素6到10

    std::set<int>::iterator search=int_set.find(2);
    //查找元素2
    //std::set<int>::iterator是双向迭代器
    //find会返回一个迭代器，如果找到了这个迭代器就
    //指向该元素
    //没找到这个迭代器就是(注意不是指向)int_set.end()

    if (search!=int_set.end())
    {
        std::cout<<"Element 2 is in int_set.\n";
    }
    //如果找到了元素2，就打印"Element 2 is in int_set."

    if (int_set.count(11)==0)
    {
        std::cout<<"Element 11 is not in int_set\n";
    }
    //如果元素11不在集合中，就打印"Element 11 is not in int_set"
    //count比find简单得多，count只返回1或者0，代表
    //存在与不存在

    if (int_set.count(3)==1)
    {
        std::cout<<"Element 3 is in the set.\n";
    }
    //如果元素3在集合中，就打印"Element 3 is in the set."

    int_set.erase(4);
    //删除元素4
    //erase会返回1或者0，如果元素存在(那么就会被删除)
    //就返回1
    //如果元素不存在，就返回0

    if (int_set.count(4)==0)
    {
        std::cout<<"Element 4 is not in the set.\n";
    }
    //如果元素4不在集合中，就打印"Element 4 is not in the set."

    int_set.erase(int_set.begin());
    //删除第一个元素
    //这里erase的传入参数是一个迭代器
    //在这种情况下，erase不返回东西

    if(int_set.count(1)==0)
    {
        std::cout<<"Element 1 is not in the set.\n";
    }
    //如果元素1不在集合中，就打印"Element 1 is not in the set."

    int_set.erase(int_set.find(9),int_set.end());
    //删除元素9到集合的最后一个元素
    //这里erase的传入参数是两个迭代器
    //在这种情况下，erase返回一个迭代器
    //指向被删除的最后一个元素的下一个元素

    if (int_set.count(9)==0 && int_set.count(10)==0)
    {
        std::cout<<"Elements 9 and 10 are not in the set.\n";
    }
    //如果元素9和10不在集合中，就打印"Elements 9 and 10 are not in the set."
    std::cout<<"Printing the elements of the iterator:\n";

    for(std::set<int>::iterator it =int_set.begin();it!=int_set.end();
    it++)
    {
        std::cout<<*it<<" ";
    }
    //打印集合中的元素
    std::cout<<"\n";

    std::cout << "Printing the elements of the iterator with a for-each loop:\n";
    for (const int &elem : int_set) {
        std::cout << elem << " ";
    }
    //打印集合中的元素
    std::cout << "\n";

    return 0;
    
    

}