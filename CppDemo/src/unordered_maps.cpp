#include<iostream>
#include<unordered_map>
#include<string>
#include<utility>


int main()
{
    std::unordered_map<std::string,int> map;
    //初始化一个哈希表，指定键和值的数据类型

    map.insert({"foo",2});
    //用insert插入一个键值对，类似python的字典

    std::cout<<"Map size after inserting foo:"<<map.size()<<std::endl;
    //打印哈希表的大小

    map.insert(std::make_pair("jignest",445));
    //这里的std::make_pair会创建一个std::pair<const char*,int>类型的对象,
    //然后被自动转化成一个<std::string,int>类型，
    //注意最终储存在哈希表当中的是<const std::string,int>，
    //因为map容器当中的键是不能被修改的

    map.insert({{"spam",1},{"eggs",2},{"garlic rice",3}});
    //成套的insert,一次insert入多个键值对

    map["bacon"]=5;

    map["spam"]=15;
    //直接指定，新建键和值

    std::unordered_map<std::string,int>::iterator result=map.find("jignest");
    //find函数返回一个迭代器，这个迭代器的数据类型命名是"一个键值对类型分别为string,int的哈希表的迭代器"，
    //所以就是在std::unordered_map<std::string,int>后面加上::iterator就行了

    if (result!=map.end())
    //注意map.end()返回的是一个迭代器，指向哈希表的最后一个元素的下一个位置
    {
        std::cout<<"Found key" << result->first <<"with value"
        <<result->second<<std::endl;
        //注意这里，如何通过迭代器来引用出哈希表的元素的键和值，
        //->first表示键，->second表示值


    std::pair<std::string,int> pair=*result;
    //result是一个迭代器，解引用之后就是一个pair型变量
    //注意声明的时候，要指定类型，这个pair(键值对)的键是std::string,
    //值是int


    std::cout<<"DEREF: Found key "<<pair.first<<" with value "
    <<pair.second<<std::endl;
    //正常的引用，通过pair来"释放"出键和值

    }

    size_t count=map.count("spam");
    //和set一样，count只会返回1和0，表示是否存在

    if (count==1)
    {
        std::cout<<"A key-value pair with key spam exists in the unordered map.\n";
    }

    map.erase("eggs");
    //和set一样，erase函数可以删除一个元素
    if (map.count("eggs")==0)
    {
        std::cout<<"Key-value pair with key eggs does not exist in the unordered map.\n";
    }

    map.erase(map.find("garlic rice"));
    //erase可以有两个参数类型，一个是迭代器，另一个就是直接把键的名字输入

    if (map.count("garlic rice")==0)
    {
        std::cout<<"Key-value pair with key garlic rice does not exist in the unordered map.\n";
    }

    std::cout<<"Printing the elemnts of the iterator:\n";

    for (std::unordered_map<std::string,int>::iterator itr=map.begin();
    itr!=map.end();++itr)
    {
        std::cout<<"Key: "<<itr->first<<"value "<<itr->second<<std::endl;
    }
    //用迭代器遍历哈希表

    std::cout<<"\n";

    std::cout<<"Printing the elements of the iterator with a for-each loop:\n";


    for (const std::pair<const std::string,int> &elem: map)
    {
        std::cout<<"("<<elem.first<<","<<elem.second<<"),";
    }
    //用for-each循环遍历哈希表

    std::cout<<"\n";

    return 0;
}