#include<algorithm>
#include<iostream>
#include<vector>


class Point{
    public:
        Point():x_(0),y_(0){
            std::cout<<"Default constructor for the Point class is called.\n";
        }

        Point(int x,int y):x_(x),y_(y)
        {
            std::cout<<"Custom constructor for the Point class is called.\n";
        }

        inline int GetX() const{
            return x_;
        }

        inline int GetY() const{
            return y_;
        }

        inline void SetX(int x){
            x_=x;
        }

        inline void SetY(int y){
            y_=y;
        }

        void PrintPoint() const{
            std::cout << "Point value is (" << x_ << ", " << y_ << ")\n";
        }

    private:
        int x_;
        int y_;
};
//Point类，有两个成员变量x_和y_，分别表示点的x坐标和y坐标
//类的初始化有两个方式，一个是默认初始化为0，一个是自定义初始化
//想要自定义初始化那么在类实例化的时候写进去就可以
//两个类成员函数GetX和GetY，分别返回x_和y_的值
//这两个成员函数是const，代表它们不会修改类成员变量的值
//两个成员函数SetX和SetY，分别设置x_和y_的值
//成员函数PrintPoint，打印点的坐标
//注意inline是内联，对于短小的函数调用的时候会更快，举个例子
//GetX()被调用的时候可能直接被视作是取类的x_了




void print_int_vector(const std::vector<int> &vec)
{
    for (const int &elem :vec)
    {
        std::cout<<elem<<" ";
    }
    std::cout<<"\n";
} 
//逐个打印vector的元素
//这里有两个const,第一个const修饰的是vec,代表这个参数在函数内不会被修改
//第二个const修饰的是elem,代表elem的值不会被修改





int main()
{
    std::vector<Point> point_vector;
    //创建一个vector,这个vector里面每个元素都是Point类
    //这里没有初始化，所以是默认初始化
    //默认初始化的时候，x_和y_都是0

    std::vector<int> int_vector = {0, 1, 2, 3, 4, 5, 6};
    //创建一个vector,这个vector里面每个元素都是int

    std::cout<<"Appending to the point_vector via push_back:\n";
    point_vector.push_back(Point(35,36));
    //push_back是向量尾部添加一个元素

    std::cout<<"Appending to the point_vector via emplace_back:\n";
    point_vector.emplace_back(37,38);

    point_vector.emplace_back(39,40);
    point_vector.emplace_back(41,42);
    //emplace_back和push_back一样，都是向量尾部添加一个元素
    //但是emplace_back是直接在内存中构造元素，而不是先构造再复制
    //所以emplace_back比push_back更高效

    std::cout<<"Printing the items in point_Vector:\n";

    for (size_t i=0;i<point_vector.size();++i)
    {
        point_vector[i].PrintPoint();
    }
    //注意point_vector[i]是Point类，所以需要调用PrintPoint函数
    //size_t是unsigned int类型

    for (Point &item:point_vector)
    {
        item.SetY(445);
    }
    //这个for循环是遍历point_vector中的每个元素
    //把每个元素(数据类型是Point类)的y_值设置为445
    
    for (const Point &item:point_vector)
    {
        item.PrintPoint();
    }
    //这个for循环是遍历point_vector中的每个元素
    //打印每个元素的坐标

    int_vector.erase(int_vector.begin()+2);
    //erase是删除vector中的一个元素
    //int_vector.begin()返回的是vector的第一个元素的迭代器
    //int_vector.begin()+2返回的是vector的第三个元素的迭代器
    //所以int_vector.erase(int_vector.begin()+2)删除的是vector的第三个元素
    std::cout<<"Printing the elements of int_vector after erasing "
                "int_vector[2](which is 2)\n";

    print_int_vector(int_vector);
    //遍历并打印

    int_vector.erase(int_vector.begin()+1,int_vector.end());
    //前面erase传入了一个参数，实际上是个"位置"(迭代器)
    //这里传入了两个参数，实际上是两个迭代器构成的范围
    //清楚这两个迭代器构成的范围内的元素

    std::cout << "Printing the elements of int_vector after erasing all elements "
                "from index 1 through the end\n";
    print_int_vector(int_vector);
    //遍历并打印
    

    point_vector.erase(
        std::remove_if(point_vector.begin(),point_vector.end(),
        [](const Point &point){
            return point.GetX()==37;
        }),
        point_vector.end()
    );
    // 使用erase-remove惯用法移除X坐标等于37的点
    // 1. std::remove_if算法重排vector元素，将所有X坐标不为37的点移到容器前部
    // 2. remove_if返回一个迭代器，指向最后一个不满足条件元素的下一个位置
    // 3. erase方法删除从该位置到容器末尾的所有元素（即所有X坐标为37的点）
    // 这种方法比遍历并逐个删除更高效，只需要一次遍历容器

    std::cout << "Printing the point_vector after (37, 445) is erased:\n";
    for (const Point &item : point_vector) {
        item.PrintPoint();
    }
    //遍历并打印
    return 0;
            
}