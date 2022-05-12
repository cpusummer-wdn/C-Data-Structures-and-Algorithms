算法基础课相关代码模板

单链表 双链表 比较难 需要画图理解

链表的基本操作 
#include<iostream>
using namespace std;
//定义节点的结构体 
struct Node{
    int val;
    Node * next;

    Node(int _val):val(_val),next(NULL){}  //有参构造 
};

int main(){
    Node* p =new Node(1);  //返回的地址，类似java  等价写法：Node node = Node(1); Node *p=&node; 
    Node* q =new Node(2);  //auto，可以自动识别new Node返回值的类型 auto p = new Node(1);
    Node* o =new Node(3);

    p->next=q;  //p指向q 
    q->next=o;  //q指向o

    Node* head=p; //定义头节点，主要是用于记录 

    //添加一个节点（头插法） 
    Node* u =new Node(4);
    u->next=head;   //新加节点指向头节点 
    head=u;         //更新头节点 

    //删除一个节点（链表的删除，不是说将这个节点干掉，而是在原链表遍历的时候，遍历不到即可！） 
    head->next=head->next->next; 

    //遍历链表 
    for(Node* i=head;i;i=i->next){
        cout<<i->val<<endl;
    } 

    return 0;

}

STL提供了两个用来计算排列组合关系的算法，分别是next_permutation和prev_permutation
https://blog.csdn.net/qian2213762498/article/details/79683905

vector中resize()和reserve()的区别 https://www.cnblogs.com/jiu0821/p/4415829.html
1、resize(n) 
调整容器的长度大小，使其能容纳n个元素。
如果n小于容器的当前的size，则删除多出来的元素。
否则，添加采用值初始化的元素。
2、 resize(n，t)
多一个参数t，将所有新添加的元素初始化为t。


C++ STL简介
vector, 变长数组，倍增的思想
头文件：#include <vector>
数组如何变长？
基于此思想：系统为某一程序分配空间时，所需时间与空间大小无关，与申请次数有关。
最开始系统分配一个长度为n(如:32)的预留空间，如果存入的长度超过预留空间，就扩大两倍(64)，将原来的数组copy过来。
初始化：
    vector<int>a(10,3):长度为10的数组，且值均为3
    vector<int> a[10];十个vector数组
    vector<int> a(n,e);//n为分配的空间，e为初始化值。


    size()  返回元素个数 时间复杂度为O(1)
    empty()  返回是否为空
    clear()  清空
    front()/back() 返回第0(指下标)个数/返回最后一个数
    push_back()/pop_back() 在最后面添加一个数/将最后一个数删除
    begin()/end() vector的第0个数/vector的最后一个数的后一个数
    [] 支持随机寻值
    支持比较运算 按字典序
    c++ vector<int> a(4, 3), b(3, 4); if(a < b) cout << "a < b";

    倍增的思想：
    系统为某一程序分配空间是，所需时间，与空间大小无关，与申请次数有关

    遍历方法
    假设有个vector <int> a;
    第一种：
    c++ for(int i = 0; i < a.size(); i ++ ) cout << a[i] << " ";
    第二种：
    for(vector<int>::iterator i = a.begin; i != a.end(); i ++ ) cout << *i << " ";
    第三种：
    c++ for(auto x : a) cout << x << " ";

    
    #include <vector>
    #include <iostream>
    #include <algorithm>
    using namespace std;

    int main()
    {
        vector<int> a;

        //①添加元素
        for (int i = 0;i < 10; i ++) a.push_back(i);

        //②遍历vector
        for (int i = 0;i < a.size(); i ++) cout << a[i] << " ";
        cout << endl;

        for (vector<int>::iterator i = a.begin(); i != a.end(); i ++) cout << *i << endl;
        cout << endl;

        for (vector<int>::iterator i = a.begin(); i != a.end(); i ++) cout << a[i] << endl;
        cout << endl;

        for (auto i = a.begin(); i != a.end(); i ++) cout << *i << endl;
        cout << endl;

        for (auto x : a) cout << x << " ";
        cout << endl;

        //③比较运算,按字典序比较
        vector<int> b(3,4),c(3,5);
        if (b < c) puts("b < c");
        else puts("b > c");

        //随机寻值
        cout << a[9] << endl;
    }
    
pair<int, int>
    可以存储一个二元组。
    我们可以用它来存储两个相关联的元素，将需要排序的元素放在first中。
    first//获取第一个元素
    second//获取第二个元素
    两个元素类型可以不同
    支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
    用途：某件商品的两种属性，按照某种属性进行排序，将要排序的关键字放在first上  first(); second(); 第二个元素
     pair<int pair<int,int>> p 存储三个元素

    #include <iostream>
    #include <algorithm>
    #include <cstdio>
    using namespace std;

    int main()
    {
        pair<int,string> p;
        pair<int,pair<int,int>> p1;//存储三个元素

        //初始化
        p = make_pair(10,"lyw");
        p = (20,"abc");

        return 0;
    }

string，字符串
    size()/length()  返回字符串长度
    empty()
    clear() 把字符串清空
    substr(起始下标，(子串长度))  返回子串
    c_str()  返回字符串所在字符数组的起始地址 该string对应的字符数组的头指针
    
    string a = “abc”;
    cout << a.substr(1, 10);//输出到最大为止，输出abc(起始位置，长度)
    cout << a.substr(1); //输出从1开始的整个子串
    printf(“%s”, a.c_str());//输出字符串
    #include <iostream>
    #include <algorithm>
    #include <cstdio>
    using namespace std;

    int main()
    {
        string str = "lyw";

        //通过"+"实现增长数组
        str += "def";
        str += "c";

        cout << str << endl;

        //substr
        cout << str.substr(1,3) << endl;
        cout << str.substr(1,10) << endl;//当超过字符串实际长度或者没有指定长度时，输出到最后一个字符为止。
        cout << str.substr(1) << endl;

        printf("%s\n",str);//返回字符串的地址
        printf("%s\n",str.c_str());
    }
    
    函数c_str()将C++的string转化为C的字符串数组，c_str()生成一个const char *指针，指向字符串的首地址。
    char *p=s[10];
    string a=“welcome”;
    strcpy(p,a.c_str());
    cout<<p;
    结果为”welcome”.


queue, 队列
    头文件：#include <queue>
    size()
    empty()
    push()  向队尾插入一个元素
    front()  返回队头元素
    back()  返回队尾元素
    pop()  弹出队头元素
    没有clear()函数
    清空queue队列的方法 重新构造一个新的队列： queue<int>()q; q=queue<int>();
    #include <iostream>
    #include <algorithm>
    #include <cstdio>
    #include <queue>
    using namespace std;

    int main()
    {
        queue<int> q;

        q = queue<int>();

        return 0;
    }

priority_queue, 优先队列，默认是大根堆 实现原理是 堆
    size()
    empty()
    push()  插入一个元素
    top()  返回堆顶元素
    pop()  弹出堆顶元素
    无clear()
    小根堆定义方法：插入该数的相反数(负数)
    priority_queue<int, vector<int>, greater<int>> q;
    priority_queue<int>heap; heap.push(-x);

    #include <iostream>
    #include <algorithm>
    #include <cstdio>
    #include <queue>
    using namespace std;

    int main()
    {
        priority_queue<int> heap;

        //没有clear()
        //heap.clear();

        int x = 1;

        //如何定义小根堆
        //方式一：插入数时，插入这个数的负数，然后从大到小排序，其实就是从小到大排序。
        heap.push(-x);
        //方式二：直接定义小根堆。
        priority_queue<int, vector<int>, greater<int>> heap1;

        return 0;
    }
大顶堆和小顶堆的区别
    堆分为大顶堆和小顶堆，满足key[i]>=key[2i+1]&&key>=key[2i+2]称为大顶堆，满足 key[i]<=key[2i+1]&&Key[i]<=key[2i+2]称为小顶堆。
    由上述性质可知大顶堆的堆顶的关键字肯定是所有关键字中最大的，小顶堆的堆顶的关键字是所有关键字中最小的。

stack, 栈
    头文件：#include <stack>
    size()
    empty()
    无clear()
    push()  向栈顶插入一个元素
    top()  返回栈顶元素
    pop()  弹出栈顶元素

deque, 双端队列(效率低)
    头文件：#include <queue>
    size() 双端队列的长度
    empty() 返回这个双端队列是否为空
    clear() 清空这个双端队列
    front()/back() 返回第一个元素
    back(); 返回最后一个元素
    push_back() 队尾插入
    pop_back()弹出队尾
    push_front()队头插入
    pop_front()弹出队头
    begin()/end() 迭代器
    begin(); 双端队列的第0个数
    end(); 双端队列的最后一个的数的后面一个数
    [] 随机寻址

set, map, multiset, multimap, 基于平衡二叉树（红黑树），动态维护有序序列
    size()
    empty()
    clear()
    begin()/end()
    迭代器的++, -- 返回前驱和后继，时间复杂度 O(logn)
    一个有序序列的迭代器中，当前元素的前一个元素为前驱，后一个元素为后继

    set/multiset
        set：无重复元素的集合 set不允许元素重复，如果有重复就会被忽略，但multiset允许
        multiset：可以有重复元素的集合
        insert()插入一个数(默认从小到大插入)
       
        find()  查找一个数 返回这个数的迭代器
        count()  返回某一个数的个数 (set返回0,1，multiset返回0~多个)
        erase()
            (1) 输入是一个数x，删除所有x   O(k + logn)  k是x的个数
            (2) 输入一个迭代器，删除这个迭代器
        lower_bound()/upper_bound()
            lower_bound(x)  返回大于等于x的最小的数的迭代器 若不存在返回end
            upper_bound(x)  返回大于x的最小的数的迭代器
        正向迭代器：set<int>::iterator it; for(it=s.begin();it!=s.end;it++)
        反向迭代器：set<int>::reverse_iterator it; for(rit=s.rbegin();rit!=s.rend();rit++)

    map/multimap
        insert()  插入的数是一个pair
        erase()  输入的参数是pair或者迭代器 
        find() 查找一个数
        []  注意multimap不支持此操作。 时间复杂度是 O(logn)
        lower_bound()/upper_bound()
        
        可以像使用数组一样用map,时间复杂度是logn
        #include<iostream>
        #include<map>
        using namespace std;

        int main()
        {
        map<string ,int>a; // logn

        a["yxc"]=1;
        cout<<a["yxc"]<<endl;
        return 0;

        }

unordered_set, unordered_map, unordered_multiset, unordered_multimap, 基于哈希表实现,内部是无序的
    和上面类似，增删改查的时间复杂度是 O(1)
    不支持 lower_bound()/upper_bound()， 不支持迭代器的++，--

unordered_map是C++中的哈希表，可以在任意类型与类型之间做映射。
基本操作
引用头文件(C++11)：#include <unordered_map>
定义：unordered_map<int,int>、unordered_map<string, double> ...
插入：例如将("ABC" -> 5.45) 插入unordered_map<string, double> hash中，hash["ABC"]=5.45
查询：hash["ABC"]会返回5.45
判断key是否存在：hash.count("ABC") != 0 或 hash.find("ABC") != hash.end()
遍历
for (auto &item : hash)
{
    cout << item.first << ' ' << item.second << endl;
}
或

for (unordered_map<string, double>::iterator it = hash.begin(); it != hash.end(); it ++ )
{
    cout << it->first << ' ' << it->second << endl;
}
进阶操作
如果想让自定义的class作为key（unordered_map<key,value>）来使用unordered_map，需要实现：
(1) 哈希函数，需要实现一个class重载operator()，将自定义class变量映射到一个size_t类型的数。一般常用std::hash模板来实现。
(2) 判断两个自定义class类型的变量是否相等的函数，一般在自定义class里重载operator==。
示例代码：
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Myclass
{
public:
    int first;
    vector<int> second;

    // 重载等号，判断两个Myclass类型的变量是否相等
    bool operator== (const Myclass &other) const
    {
        return first == other.first && second == other.second;
    }
};

// 实现Myclass类的hash函数
namespace std
{
    template <>
    struct hash<Myclass>
    {
        size_t operator()(const Myclass &k) const
        {
            int h = k.first;
            for (auto x : k.second)
            {
                h ^= x;
            }
            return h;
        }
    };
}

int main()
{
    unordered_map<Myclass, double> S;
    Myclass a = { 2, {3, 4} };
    Myclass b = { 3, {1, 2, 3, 4} };
    S[a] = 2.5;
    S[b] = 3.123;
    cout << S[a] << ' ' << S[b] << endl;
    return 0;
}
输出:
2.5 3.123

bitset, 圧位 省八倍空间
    C++中bool为一个字节(B)。1024B = 1KB 1MB = 1024KB
    举例说明:开一个1024个bool类型的数组，我们通过压位实现1位存一个bool，这样只需要128个字节。
    应用场景：
    10^8 = 一亿。
    这里有10000x10000的bool矩阵，把该需要100MB空间，而题目限制为64MB,使用压位只需要大约12MB。

    bitset<10000> s;//<>中是个数。
    支持所有位运算
    ~, &, |, ^
    >>, <<
    ==, !=
    []

    count()  返回有多少个1
    any()  判断是否至少有一个1
    none()  判断是否全为0
    set()  把所有位置成1
    set(k, v)  将第k位变成v
    reset()  把所有位变成0
    flip()  等价于~
    flip(k) 把第k位取反

手动开启O2优化：
#pragma GCC optimize(2) 或 #pragma GCC optimize(“O


****************************************************
单链表 —— 模板题 AcWing 826. 单链表
// head存储链表头，
e[]存储节点的值，存放需要存入的数值
ne[]存储节点的next指针，存放下个结点的下标
idx表示当前用到了哪个节点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 在链表头插入一个数a
void insert(int a)
{
    e[idx] = a, ne[idx] = head, head = idx ++ ;
}

// 将头结点删除，需要保证头结点存在
void remove()
{
    head = ne[head];
}

为什么使用数组来模拟链表
如果数据规模很大, 一个一个的new操作太慢了, 会超时, 使用数组会大大加快速度

数组模拟单链表

解题代码 链表在插入的时候可以达到O(1)的复杂度
#include <iostream>

using namespace std;

const int N = 100010;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点

int head, e[N], ne[N], idx;

//初始化
void init()
{
    head = -1;
    //最开始的时候，链表的头节点要指向-1，
    //为的就是在后面进行不断操作后仍然可以知道链表是在什么时候结束
    /*
    插句题外话，我个人认为head其实就是一个指针，是一个特殊的指针罢了。
    刚开始的时候它负责指向空结点，在链表里有元素的时候，它变成了一个指向第一个元素的指针

    当它在初始化的时候指向-1，来表示链表离没有内容。
    */
    idx = 0;
    /*idx在我看来扮演两个角色，第一个是在一开始的时候，作为链表的下标，让我们好找
    //第二在链表进行各种插入，删除等操作的时候，作为一个临时的辅助性的所要操作的元素的下标来帮助操作。并且是在每一次插入操作的时候，给插入元素一个下标，给他一个窝，感动！
    /*
    再次插句话，虽然我们在进行各种操作的时候，元素所在的下标看上去很乱，但是当我们访问的时候，是靠着指针，也就是靠ne[]来访问的，这样下标乱，也就我们要做的事不相关了。另外，我们遍历链表的时候也是这样，靠的是ne[]
    */
}

// 将x插到头结点
在链表头插入一个数x
void add_to_head(int x)
{
    e[idx] = x, //第一步，先将值放进去
    ne[idx] = head, 
    //head作为一个指针指向空节点，现在ne[idx] = head 将元素x的指针指向了head原本指向
    head = idx ++;
    //head现在表示指向第一个元素了，它不在是空指针了。（不指向空气了）//指针向下移一位，为下一次插入元素做准备。
}

//将x插到下标是k的节点的后面
void remove(int k)
{
    ne[k] = ne[ne[k]];
    //让k的指针指向，k下一个人的下一个人，原来k的节点后面的节点 也就是中间的那个节点 就被挤掉了。
}

int main()
{
    int m;
    cin >> m;

    init();//初始化

    while (m --)
    {
        int k, x;
        char op;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k) head = ne[head];//删除头结点
            else remove(k - 1);//注意删除第k个输入后面的数，那函数里放的是下标，k要减去1
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);//同样的，第k个数，和下标不同，所以要减1
        }
    }

    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;

    return 0;
}


head其实是dummy->next
一开始dummy->next = nullptr;
从头插入的时候idx->next <=> ne[idx] = dummy->next <=> head;

单链表 数组实现 java写法
import java.io.*;
import java.util.Scanner;

public class Main {
    private static int N = 100010;  // 数据规模为 10w

    private static int head;                // 表示头结点的下标
    private static int[] e = new int[N];    // 表示结点 i的值
    private static int[] ne = new int[N];   // 表示结点 i的 next指针是多少
    private static int idx;                 // 表示存储当前结点已经使用结点的下一个结点

    // 初始化数据
    private static void init() {
        head = -1;  // 没有头结点
        idx = 0;    // 没有存入数据
    }

    // 将 val插到头结点
    private static void addToHead(int val) {
        e[idx] = val;   // 赋值
        ne[idx] = head; // 插入之前头结点的前面
        head = idx;     // 更新头结点信息
        idx++;          // idx向右移动
    }

    // 将下标是 k的点后面的点删掉
    private static void remove(int k) {
        ne[k] = ne[ne[k]];  // 让下标为 k的结点指向 下个结点的下个结点
    }

    // 将 val插入下标为 k的点的后面
    private static void add(int k, int val) {
        e[idx] = val;
        ne[idx] = ne[k];
        ne[k] = idx;
        idx++;
    }

    // 程序入口
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(reader.readLine());

        init();     // 初始化操作

        // 进行 m次操作
        while (m-- > 0) {
            String[] s = reader.readLine().split(" ");

            if (s[0].equals("H")) {  // 插入头结点操作, 不能使用 ==, 要使用 equals()

                int val = Integer.parseInt(s[1]);
                addToHead(val);
            } else if (s[0].equals("I")) {   // 普通插入操作
                int k = Integer.parseInt(s[1]);
                int val = Integer.parseInt(s[2]);
                add(k - 1, val);    // 第 k个结点的下标为 k-1, 所以插入到下标为 k-1结点的后面
            } else {    // s[0] == "D", 删除操作
                int k = Integer.parseInt(s[1]);

                if (k == 0) {  // 题意: k = 0, 删除头结点
                    head = ne[head];
                } else
                    remove(k - 1);  // 第 k个结点的下标为 k-1, 所以是删除到下标为 k-1后面的后面
            }
        }

        // 打印输出
        for (int i = head; i != -1; i = ne[i]) {
            System.out.print(e[i] + " ");
        }
    }
}


**********************************************

双链表 —— 模板题 AcWing 827. 双链表
// e[]表示节点的值，l[]表示节点的左指针，r[]表示节点的右指针，idx表示当前用到了哪个节点
int e[N], l[N], r[N], idx;

// 初始化
void init()
{
    //0是左端点 head，1是右端点 tail
    r[0] = 1, l[1] = 0;
    idx = 2; //有两个节点 head tail
}

// 在节点a的右边插入一个数x
void insert(int a, int x)
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx ++ ;
}

void insert(int k,int x)//在第k个节点后插入x
{
    //将值赋给新节点
    value[index]=x;
    //将新节点分别指向插入位置的右节点和左节点
    r[index]=r[k];
    l[index]=k;
    //将新节点右边一节点向左指向新节点,将新节点左边一节点向右指向新节点
    l[r[k]]=index;
    r[k]=index;
    //更新节点索引
    index++;
}


// 删除节点a
void remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

void remove(int k)
{
    //这里指的第k个是指第k个插入的数,不是指当前序列的第k个数

    //删除第k个插入的节点,第k-1的右指针指向原先第k个节点的右指针指向的节点
    r[l[k]]=r[k];
    //删除第k个节点,原先第k个节点的右指针指向的节点的 左指针指向 原先第k个节点的左指针指向的节点
    l[r[k]]=l[k];
}


解题代码
#include <iostream>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

//在节点a的右边插入一个数x
void insert(int a, int x)
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx ++;
}

//删除节点a
void remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

int main()
{
    cin >> m;

    // 0是左端点 1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;

    while (m --)
    {
        string op;
        cin >> op;
        int k, x;
        if (op == "L")//最左边插入就是 在指向 0的数的左边插入就可以了 也就是可以直接在 0的右边插入
        {
            cin >> x;
            insert(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            insert(l[1], x);
            // add(l[1], x);  0和 1 只是代表 头和尾  所以最右边插入只要在 指向 1的那个点的右边插入就可以了
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1);
            // idx从2开始， 所以删除的是k+1
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i =r[i] cout << e[i] << ' ');
    cout << endl;
    // !=1 一直遍历到1号节点， 也就是末尾节点
    return 0;
 }

int main()
{
    // 0 是左边界  1是右边界
    //因为0和1都被占用,所以第1个节点也就是2=1+1 ,第2个节点为3=2+1;
    //∴第k个节点也就是k+1
    ini();
    int M,k,x;
    string operation;
    cin>>M;//操作个数
    while(M--)
    {
        cin>>operation;//操作指令
        if(operation=="L")//在链表的最左端插入x
        {
            //也就是在左边界后插入一个节点,就是最左端插入一个节点
            cin>>x;
            insert(0,x);
        }
        else if(operation=="R")//在链表的最右端插入x
        {
            //也就是右边界的左节点后插入一个新节点
            cin>>x;
            insert(l[1],x);
        }
        else if(operation=="D")//把第k个插入的数删除
        {
            cin>>k;
            remove(k+1);
        }
        else if(operation=="IL")//第k个插入的数左侧插入一个数
        {
            //也就是在第k个插入的数的左节点后插入一个数
            cin>>k>>x;
            insert(l[k+1],x);
        }
        else//第k个插入的数右侧插入一个数
        {
            //在第k个节点后插入一个数
            cin>>k>>x;
            insert(k+1,x);
        }
    }
    int pos=r[0];
    while(pos!=1)//当指向右边界节点时,循环结束
    {
        cout<<value[pos]<<" ";
        pos=r[pos];
    }
    return 0;
}

*******************************************
栈 —— 模拟栈 模板题 AcWing 828. 模拟栈

** tt栈顶指针指向栈顶元素
stk[0]不会进行赋值
先栈顶指针++，后赋值 stk[ ++ tt]=x
输出栈顶元素 cout<<stk[tt]<<endl
// tt表示栈顶
int stk[N], tt = 0;

// 向栈顶插入一个数
stk[ ++ tt] = x;

// 从栈顶弹出一个数
tt -- ;// 6-1=5，相当于栈缩小了一个值,即为栈顶弹出了一个值

// 栈顶的值
stk[tt];

// 判断栈是否为空
if (tt > 0)
{

}

// 解题代码
#include <iostream>

using namespace std;

int m;
int stk[N], tt;

int main()
{
    cin >> m;
    while (m --)
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            skt[ ++ tt] = x;
        }
        else if (op == "pop") tt --;
        else if (op == "empty") cout >> (tt ? "NO" : "YES") >> endl;
        else if << stk[tt] << endl;
    }

    return 0;
}


**top 栈顶指针指向栈顶元素的后一个位置
stk[0]会进行赋值
先赋值，后栈顶指针++ stk[top++]=x
输出栈顶元素 cout<<stk[top-1]<<endl
#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int stk[N], top;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x;
            stk[top++] = x;
        } else if (op == "pop") {
            top--;
        } else if (op == "empty") {
            if (top) puts("NO");
            else puts("YES");
        } else {
            cout << stk[top - 1] << endl;
        }
    }
}


模拟栈 —— acwing 3302 表达式求值  这道题很经典
数组模拟栈和map
具体看解析图
https://www.acwing.com/solution/content/40978/

“表达式求值”问题，两个核心关键点：
（1）双栈，一个操作数栈，一个运算符栈，
（2）运算符优先级，栈顶运算符，和，即将入栈的运算符的优先级比较：
        如果栈顶的运算符优先级低，新运算符直接入栈
        如果栈顶的运算符优先级高，先出栈计算，新运算符再入栈

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<char> op;

//优先级表
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval() //求值
{
    int a = num.top();//第二个操作数
    num.pop();

    int b = num.top();//第一个操作数
    num.pop();

    char p = op.top();//运算符
    op.pop();

    int r = 0;//结果 

    //计算结果
    if (p == '+') r = b + a;
    if (p == '-') r = b - a;
    if (p == '*') r = b * a;
    if (p == '/') r = b / a;

    num.push(r);//结果入栈
}

int main()
{
    string s;//读入表达式
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))//数字入栈
        {
            int x = 0, j = i;//计算数字
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j] - '0';
                j++;
            }
            num.push(x);//数字入栈
            i = j - 1;
        }
        //左括号无优先级，直接入栈
        else if (s[i] == '(')//左括号入栈
        {
            op.push(s[i]);
        }
        //括号特殊，遇到左括号直接入栈，遇到右括号计算括号里面的
        else if (s[i] == ')')//右括号
        {
            while(op.top() != '(')//一直计算到左括号
                eval();
            op.pop();//左括号出栈
        }
        else
        {
            while (op.size() && h[op.top()] >= h[s[i]])//待入栈运算符优先级低，则先计算 顺序不能更改 因为如果不先判空而先取栈顶元素的话，栈可能为空，就取不到栈顶而判错
            eval();
            op.push(s[i]);//操作符入栈
        }
    }
    while (op.size()) eval();//剩余的进行计算
    cout << num.top() << endl;//输出结果
    return 0;
}
 
'('不在map中默认对应的值是0

****************************************************

队列 —— 模拟队列 模板题 AcWing 829. 模拟队列
元素从右端进入队列(入队），从左端离开队列（出队）。于是我们称队列的左端为队头，右端为队尾。可以在c++中用一个数组和两个变量（记录队头和队尾的位置）来实现队列结构。

1. 普通队列：
// hh 表示队头，tt表示队尾
int q[N], hh = 0, tt = -1;

// 向队尾插入一个数
q[ ++ tt] = x;

// 从队头弹出一个数
hh ++ ;//相当于1+1=2 所以队列缩小了一个值 相当于弹出

// 队头的值
q[hh];

// 判断队列是否为空
if (hh <= tt)
{

}

算法1：
tt=-1, q[++tt]=x, hh<=tt 表示队列非空

解题代码
#include <iostream>

using namespace std;

int m;
int q[N], hh, tt = -1;

int main()
{
    cin >> m;

    while (m --)
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            q[++ tt] = x;
        }
        else if (op == "pop") hh ++;
        else if (op == "empty") cout << (hh <= tt ? "NO" : "YES") << endl;
        else cout << q[hh] << endl;
    }

    return 0;
}

算法2：
tt=0, q[tt++]=x, hh<tt 表示队列非空

#include<iostream>

using namespace std;
const int N = 1e5 + 10;

int q[N];

int main() {
    int n;
    cin >> n;
    int hh = 0, tt = 0;
    while (n--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x;
            q[tt++] = x;
        } else if (op == "pop") {
            hh++;
        } else if (op == "empty") {
            if (hh < tt) puts("NO");
            else puts("YES");
        } else {
            cout << q[hh] << endl;
        }
    }
}


2. 循环队列
元素进行多次入队，出队后，用于实现队列结构的数组的开头部分空间就会被严重浪费，所以我们经常将其优化为"循环队列"，也就是把队列看作一个首位相接的环，只要队列中的元素个数在任意时刻都不超过环长，那么随着入队和出队操作的进行，存储元素的那一段位置就像沿着环不停地移动，重复利用着历史上曾被占用过的空间。
// hh 表示队头，tt表示队尾的后一个位置
int q[N], hh = 0, tt = 0;

// 向队尾插入一个数
q[tt ++ ] = x;
if (tt == N) tt = 0;

// 从队头弹出一个数
hh ++ ;
if (hh == N) hh = 0;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh != tt)
{

}

队列还有很多变体。
例如两端都能插入或取出元素的 "双端队列（C++ STL deque）"，
给每个元素附带一个评估值，出队时取出估值最大的，等价于一个"二叉堆的优先队列（C++ STL priority_queue）"。

队列也是实现广度优先搜索的基本结构。对于队列的基本用法，读者应该已经比较熟悉，这里就不再赘述，更多的是应用。


双端队列
https://www.acwing.com/solution/content/27971/
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 10;

typedef pair<int, int> PII;

#define value first
#define before_sort second

PII a[N];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].value;
        a[i].before_sort = i;
    }
    sort(a, a + n);
    int res = 1;  // 最后最少分成的段数
    // last记录一下上一个值(上一段的最后一个值是多少),
    // 初始化为比所有坐标都大即可(>n的数字均可) dir用来记录方向
    // 第一条边一定是下降的, 因此dir初始化为-1(可以理解为是从上面接下来的)
    for (int i = 0, last = n + 1, dir = -1; i < n;) {
        int j = i + 1;
        // 找到一段相等的数值
        // 如果这一段的数字是相等的, 那么这些下标是可以随意变换的
        // 从i-j-1这一段, 都是和a[i].value相同的数字
        while (j < n && a[j].value == a[i].value) {
            j++;
        }
        // 找到这一段中的最大的下标和最小的下标
        // 因为是sort(pair经过sort)过的, 因此minx一定这一段的第一个数的位置
        // maxx一定是这一段的最后一个数的位置
        // 在原序列中的的位置
        // minx=a[i].before_sort, maax = a[j-1].before_sort;
        // 我们处理的时候是一个点一个点进行处理的(如果有相同的, 则处理一段,
        // 因为相同的可以任意插入到一个双端队列)
        int minx = a[i].before_sort, maxx = a[j - 1].before_sort;
        if (dir == -1) {        //如果是下降的, 如何做?
            if (last > maxx) {  //如果上一个位置>当前的最大位置,
                                //那么就可以接到上一个位置的后面
                last =
                    minx;  // 接上了的话, 这一段的最后一个数值(原坐标)应该是minx
            } else {  //如果没有接上, 那么更新方向为上升, last=maxx
                      // 此时不需要res++的原因是 谷是先下降, 后上升的
                      // 上升结束之后, 才需要开启新的谷
                dir = 1, last = maxx;  // 上升的时候last更新为最大值,
            }
        } else {  // 如果是上升的, 如何做?
            if (last <
                minx) {  // 如果last比我当前这一段的最小值还要小, 那么可以接上去
                last = maxx;
            } else {  // 否则开新双端队列+更新last为这一段的最小值,
                      // 更新方向为下降
                res++;
                last = minx;
                dir = -1;
            }
        }
        i = j;
    }
    cout << res << endl;
    return 0;
}



************************************************

单调栈 —— 模板题 AcWing 830. 单调栈
常见模型：找出每个数左边离它最近的比它大/小的数
ax,ay 
if x < y 且 ax >= ay 那么可以删去ax
只要有这样的逆序的关系，就可以把前一个数删除

int tt = 0;
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;
    stk[ ++ tt] = i;
}

https://www.acwing.com/solution/content/27437/ 看图解

#include <iostream>
using namespace std;
const int N = 100010;
int stk[N], tt;

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int x;
        scanf("%d", &x);
        while (tt && stk[tt] >= x) tt -- ;//如果栈顶元素大于当前待入栈元素，则出栈
        if (!tt) printf("-1 ");//如果栈空，则没有比该元素小的值。
        else printf("%d ", stk[tt]);//栈顶元素就是左侧第一个比它小的元素。
        stk[ ++ tt] = x;
    }
    return 0;
}
上面的代码有用到双指针 对吗



********************************************
单调队列 —— 模板题 AcWing 154. 滑动窗口
常见模型：找出滑动窗口中的最大值/最小值

单调队列并不是严格意义上的队列

int hh = 0, tt = -1;
for (int i = 0; i < n; i ++ )
{
    while (hh <= tt && check_out(q[hh])) hh ++ ;  // 判断队头是否滑出窗口
    while (hh <= tt && check(q[tt], i)) tt -- ;
    q[ ++ tt] = i;
}

AcWing 154. 滑动窗口
https://www.acwing.com/solution/content/97229/ 看图理解


遍历数组，然后再遍历每一个窗口
时间复杂度 O(nk)

暴力枚举之后，通过单调性进行优化 ，

#include <iostream>

using namespace std;
 
const int N = 100010;

int a[N], q[N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i =0; i < n; i ++) scanf("%d", &a[i]);

    int hh = 0, tt = -1;
    for (int i = 0; i < n; i ++)
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

        while (hh <= tt && a[q[tt]] >= a[i]) tt -- ;//当入队元素小于等于队尾元素， 队尾元素出队。直到入队元素大于队尾元素a[q[tt]] >= a[i]， 或者队列为空，则停止删除操作。
        q[++ tt] = i;

        if (i >= k - 1) printf("%d", a[q[hh]]);
    }
    puts("");

    hh =0, tt = -1;
    for (int i = 0; i < n; i ++)
    {
        if (hh << tt && i - k + 1 > q[hh]) hh ++ ;//k表示滑动窗口大小， q[N] 存储的是数组下标, 需要保证q数组里面存储的元素小于等于k

        while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
        q[++ tt] = i;

        if (i >= k - 1) printf("%d", a[q[hh]]); //当滑动窗口里面的元素个数等于k个的时候才能输出, 当k=3， 滑动窗口需要有三个元素才能开始输出最值
    }

    puts("");

    return 0;
}



AcWing 131. 直方图中最大的矩形

AcWing 79. 滑动窗口的最大值



 135. 最大子序和
https://www.acwing.com/solution/content/28015/ 看解析
单调队列算法
计算区间和的问题，一般转化成"两个前缀和相减"的形式进行求解。我们先求出S[i]表示序列里前i项的和，则连续子序列[L，R]中数的和就等于S[R]-S[L-1]。那么原问题可以转化为：找出两个位置x，y，使S[y]-S[x-1]最大并且y-x<=m.
首先我们枚举右端点i，当i固定时，问题就变为：找到一个左端点j，其中jE[i-
m，i-1]并且S[j]最小。
不妨比较一下任意两个位置j和k，如果k<j<i并且S[k]>=S[j]，那么对于所有大于等于i的右端点，k永远不会成为最优选择。这是因为不但S[k]不小于S[j]，而且j离i更近，长度更不容易超过M，即j的生存能力比k更强。所以当j出现后，k就完全是一个无用的位置
以上比较告诉我们，可能成为最优选择的策略集合一定是一个下标位置递增、对应的前缀和S的值也递增”的序列。我们可以用一个队列保存这个序列。随着右端点变从前向后扫描，我们对每个i执行一下三个步骤：
1.判断队头决策与i的距离是否超出M的范围，若超出则出队。
2.此时队头就是右端点为i时，左端点j的最优选择。
3.不断删除队尾决策，知道队尾对应的S值小于S[i]。然后把i作为一个新的决策入队
int l = 1, r = 1;
q[1] = 0; 
for (int i = 1; i <= n; i ++)
{
    while (l <= r && q[l] < i - m) l ++;
    ans = max(ans, sum[i] - sum[q[l]]);
    while (l <= r && sum[q[r]] >= sum[i]) r --;
    q[++ r] = i;
}
这就是著名的单调队列算法，因为每个元素至多入队一次，出队一次，所以整个算法的时间复杂度为O（N）。它的思想也是在决策集合（队列）中及时排除一定不是最优解的选择。单调队列是优化动态规划的一个重要的手段。
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>

using namespace std;

const int N = 3e5 + 10;

typedef long long ll;

int n, m;
deque<int> q;

ll s[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    ll res = INT_MIN;
    q.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (!q.empty() && i - q.front() > m) {
            q.pop_front();
        }
        res = max(res, s[i] - s[q.front()]);
        while (!q.empty() && s[q.back()] >= s[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << res << endl;
    return 0;
}


****************************************
KMP —— 模板题 AcWing 831. KMP字符串
s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
https://www.acwing.com/solution/content/27068/ 看解析图


KMP模式匹配
https://www.acwing.com/solution/content/28100/
KMP算法，又称模式匹配算法，能够在线性时间内判定字符串A[1-N]是否为字符串B[1-M]的字串，并求出字符串A在字符串B中各自出现的位置。
首先，一个O（NM）的朴素做法是，尝试枚举字符串B中的每个位置i，把字符串A与字符串B的后缀B[i-M]对齐，向后扫描逐一比较A[1]与B[i]，A[2]与B[i+1]..是否相等。我们把这种比较过程称为A与B尝试进行"匹配"。
其次，这个问题使用字符串Hash也能在线性时间内求解。可以在O（N）的时间内预处理一个字符串的所有前缀Hash值，并在O（1）的时间内查询该字符串任意一个子串的Hash值。所以，一个很直接的想法是：枚举字符串B中的每个位置i（N<=i<=m），检查字符串A的Hash值与字符串B的字串A[i-N+1~i]的Hash值是否相同，即可得到该问题的解。

KMP算法能够更高效，更准确地处理这个问题，并且能为我们提供一些额外的信息。详细地讲，KMP算法分为两步：
1.对字符串A进行自我"匹配"，求出一个数组next，其中next[i]表示"A中以i结尾的非前缀子串"能够匹配地最长长度，即：next[i]=max{j}，其中j<i并EA[i-j+1~i]=A[1~j]
特别地，当不存在这样的j时，令next[i]=0。
2.对字符串A与B进行匹配，求出一个数组f，其中f[i]表示"B中以i结尾的字串"与"A的前缀"能够匹配的最长长度，即：f[i]= max{j}，其中j<=i并EB[i-j+1~i]=A[1~j]
下面讨论next数组的计算方法。根据定义，next[1]=0。接下来我们按照i=2
~N的顺序依次计算next[i]。
假设next[1~i-1]已经计算完毕，当计算next[i]时，根据定义，我们需要找出所有满足j<i且A[i-j+1~i]=A[1~j]的整数j并取最大值。为了方便叙述，我们称满足这两个条件的j为next[]的"候选项"。


求模式串的Next数组：
for (int i = 2, j = 0; i <= m; i ++ )
{
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
}

匹配
for (int i = 1, j = 0; i <= n; i ++ )
{
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == m)
    {
        j = ne[j];
        // 匹配成功后的逻辑
    }
}

解题代码
#include <iostream>

using namespace std;

const int N = 100010, M = 100010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;

    for (int i = 2, j = 0; i <= n; i ++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++ ;
        ne[i] = j; 
    }
    for (int i = 1, j = 0; i <= m; i ++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == n)
        {
            printf("%d", i - n);
            j = ne[i];
        }
    }

    return 0;
}



****************************************************

Trie树 —— 模板题 字典的形式
核心代码
void insert(char str[])
{
    int p = 0; //从根结点开始遍历
    for (int i = 0; str[i]; i ++ )
    {
        int u =str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx; //没有该子结点就创建一个
        p = son[p][u]; //走到p的子结点
    }

    cnt[p] ++; // cnt相当于链表中的e[idx]
}


Trie树是一种可以高效的存储和查找字符串的数据结构。Trie树查找的时间复杂度近乎O(1)。不管是链表，Trie树还是堆，他们的基本单元都是一个个结点连接构成的，可以成为“链”式结构。这个结点包含两个基本的属性：本身的值和指向下一个结点的指针。

https://www.acwing.com/solution/content/28245/ 解析

Trie（字典树）是一种用于实现字符串快速检索的多叉树结构。Trie的每个节点都拥有若干个字符指针，若在插入或检索字符串时扫描到一个字符c，就沿着当前节点的c字符指针，走向该指针指向的节点。
下面我们来详细讨论Trie的基本操作过程。
*初始化
一颗空Trie仅包含一个根节点，该点的字符指针均指向空。
*插入
当需要插入一个字符串S时，我们令一个指针P起初指向根节点。然后，依次扫描S中的每个字符c：
1.若P的c字符指针指向一个已经存在的节点Q，则令P=Q。
2.若P的c字符指针指向空，则新建一个节点Q，令P的c字符指针指向Q，然后令P=Q。
当S中的字符扫描完毕时，在当前节点P上标记它是一个字符串的末尾。
*检索
当需要"检索"一个字符串S在Trie中是否存在时，我们令一个指针P起初指向根节点，然后依次扫描S中的每个字符c：
1.若P的c字符指针指向空，则说明S没有被插入过Trie，结束检索。
2.若P的c字符指针指向一个已经存在的节点Q，则令P=Q。
当S中的字符扫描完毕时，若当前节点P被标记为一个字符串的结尾，则说明S在Trie中存在，否则说明S没有被插入过Trie。


AcWing 835. Trie字符串统计
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

 解题代码
#include <iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;
char str[N];

void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son [p][u];
    }
    cnt[p] ++;
}

int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son [p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n --)
    {
        char op[2];
        scanf("%s%s", op, str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
} 


AcWing 143. 最大异或对
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 3100010;

int n;
int a[N], son[M][2], idx;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i --)
    {
        int &s = son[p][x >> i & 1];//?
        if (!s) s = ++ idx;
        p = s;
    }
}

int search(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i --)
    {
        int s = x >> i & 1;
        if (som[p][!s])
        {
            res += 1 << i;
            p = son[p][!s];
        }
        else p = son[p][s];
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i ++) res = max(res, search(a[i]));

    printf("%d\n", res);

    return 0;
}



**************************************************
并查集 —— 模板题 面试常出

并查集（Disjoint-Set）是一种可以动态维护若干个不重叠的集合，并支持合并与查询的数据结构。详细的说，并查集包括如下两个基本操作：
1.Get，查询一个元素属于哪一个集合。
2.Merge，把两个集合合并成一个大集合。
为了具体实现并查集这种数据结构，我们首先需要定义集合的表示方法。在并查集中，我们采用"代表元"法，即为每个集合选择一个固定的元素，作为整个集合的"代表"。

其次，我们需要定义归属关系的表示方法。第一种思路是维护一个数组f，用f[x]保存元素x所在的集合的"代表"。这种方法可以快速查询元素的归属集合，但在合并时需要修改大量元素的f值，效率很低。第二种思路是使用一个树形结构存储每个集合，树上的每个节点都是一个元素，树根是集合的代表元素。整个并查集实际上是一个森林（若干棵树）。我们仍然可以维护一个数组fa来记录这个森林，用fa[x]保存x的父节点。特别的，令树根fa值为它自己。这样一来，在合并两个集合时，只需连接两个树根（令其中一个树根为另一个树根的子节点即fa[root，]=fa[rootz]）。不过在查询元素的归属时，需要从该元素开始通过fa存储的值不断递归访问父节点，直至到达树根。为了提高查询的效率，并查集引入了"路径压缩"与"按秩合并"两种思想.
https://www.acwing.com/solution/content/28467/ 具体实现看这个


并查集最核心的操作：
    返回x的祖宗节点 + 路径压缩O(1)
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

(1)朴素并查集：
相关题目：
合并集合 (并查集)
格子游戏 (坐标变换 + 并查集)
程序自动分析 (离散化 + 并查集)

    int p[N]; //存储每个点的祖宗节点

    返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    合并a和b所在的两个集合：
    p[find(a)] = find(b);


(2)维护size的并查集：
相关题目：
连通块中点的数量 (维护size的并查集)
搭配购买 (01背包 + 并查集)

    int p[N], size[N];
    //p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

    返回x的祖宗节点 + 路径压缩
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        size[i] = 1;
    }

    合并a和b所在的两个集合：
    size[find(b)] += size[find(a)];
    p[find(a)] = find(b);


(3)维护到祖宗节点距离的并查集：
银河英雄传说 (维护距离信息的并查集)
奇偶游戏 (前缀和思想简化，离散化 + 带权并查集 / 扩展域)
食物链 (带权并查集 / 扩展域)

    int p[N], d[N];
    //p[]存储每个点的祖宗节点, d[x]存储x到p[x]的距离

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x)
        {
            int u = find(p[x]);
            d[x] += d[p[x]];
            p[x] = u; 
        }
        return p[x];
    }

     初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        d[i] = 0;
    }

     合并a和b所在的两个集合：
    p[find(a)] = find(b);
    d[find(a)] = distance; // 根据具体问题，初始化find(a)的偏移量



并查集：
1.将两个集合合并
2.询问两个元素是否在一个集合当中

基本原理：每个集合用一棵树来表示。树根的编号就是整个集合的编号。每个节点存储它的父节点，p[x]表示x的父节点。

问题1：如何判断树根：if（p[x]== x）
问题2：如何求x的集合编号：while（p[x != x）x = p[x]; 并查集的get操作
问题3：如何合并两个集合：px 是x的集合编号，py是y的集合编号。p[x]=y

AcWing 836. 合并集合
 解题代码
#include <iostream>

using namespace std;

const int N = 100010;

int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) p[i] = i;

    while (m --)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);//scanf读字符串会自动过滤空格和回车

        if (*op == 'M') p[find(a)] = find(b);
        else 
        {
           if (find(a) == find(b)) puts("Yes");
           else puts("No");
        }
    }

    return 0;
}


AcWing 837. 连通块中点的数量
a可以走到b b也可以走到a 就叫连通 
两个连通块连一条边 其实就是将两个集合合并，一般是小树连到大树上

按秩优化 https://www.acwing.com/solution/content/28467/ 具体实现看这个

https://www.acwing.com/solution/content/28470/

#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], cnt[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++)
    {
        p[i] = i;
        cnt[i] = 1;
    }

    while (m --)
    {
        string op;
        int a, b;
        cin >> op;

        if (op == "C")
        {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a != b)
            {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else
        {
            cin >> a;
            cout >> cnt[find(a)] >> endl;
        }
    }

    return 0;
}



***带权并查集 食物链
https://www.acwing.com/solution/content/28481/

只要两个元素在一个集合里面，通过它们与根节点的距离就能知道它们的相对关系
比如食物链一题中，距离% 3 == 0 表示与根节点同类， == 1 表示 被根节点吃， == 2 表示 吃根节点
那么若有 a 与根节点同类， b 也与根节点同类，推出 a 与 b 是同类。
这类带权并查集也可用 并查集扩展域 来做（只要分类不太多的情况下）
此时，p[]数组代表的不是元素，而是 条件

AcWing 240. 食物链 - 维护每个点到根节点的距离
#include <iostream>

using namespace std;

const int N = 50010;

int n, m;
int p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) p[i] = i;

    int res = 0;
    while (m --)
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n) res ++ ;
        if (t == 1)
        {
            if (px == py && (d[x] - d[y] % 3)) res ++ ;
            else if (px != py)
            {
                p[px] = py;
                d[px] = d[y] - d[x];
            }
        }
        else
        {
            if (px == py && (d[x] - d[y] - 1) % 3) res ++ ;
            else if (px != py)
            {
                p[px] = py;
                d[px] = d[y] + 1 - d[x];
            }
        }
    }

    printf("%d\n", res);

    return 0;
}


****************************************
堆 —— 模板题 
完全二叉树
最后一个节点 从左到右依次排布
用一维数组可以存堆
堆在stl就是优先队列

默认为小根堆
越大的数往下压 down
越小的数往上走 up

// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的
int h[N], ph[N], hp[N], size;

// 交换两个点，及其映射关系
void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}



AcWing 838. 堆排序******
先把整个数组建为堆，每次把堆顶输出来，堆顶就是最小值
插入删除logN
求堆顶是O(1)

https://www.acwing.com/solution/content/29416/ 看这个解析

二叉堆是一种支持插入，删除，查询最值的数据结构。他其实是一棵满足"堆性质"的完全二叉树，树上的每个节点带有一个权值。若树中的任意一个节点的权值都小于等于其父节点的权值，则称该二叉树满足"大根堆性质"。若树中任意一个节点的权值都大于等于其父节点的权值，则称该二叉树满足"小根堆性质"。满足"大根堆性质"的完全二叉树就是"大根堆"，而满足"小根堆性质"的二叉树就是"小根堆"，二者都是二叉堆的形态之一。

根据完全二叉树的性质，我们可以采用层次序列存储方式，直接用一个数组来保存二叉堆。层次序列存储方式，就是逐层从左到右为树中的节点依次编号，把此编号作为节点在数组中存储的位置（下标）。在这种存储方式中，父节点编号等于子节点编号除以2，左子节点编号等于父节点编号乘2，右子节点编号等于左子节点编号乘2加1，如下图所示


以大根堆为例探讨堆支持的几种常见操作的实现
Insert 
Insert（val）操作向二叉堆中插入一个带有权值val的新节点。我们把这个新节点直接放在存储二叉堆的数组末尾，然后通过交换的方式向上调整，直至满足堆性质。其时间复杂度为堆的深度，即O（logN）。
int heap[SIZE], n;

void up(int p)//向上调整
{
    if (heap[p] > heap[p / 2])//子节点>父节点，不满足大根堆性质
    {
        swap(heap[p], heap[p / 2]);
        p /= 2;

    }
    else
    {
        break;
    }
}

void Insert(int val)
{
    heap[++n] = val;
    up(n);
}



GetTop 
GetTop操作返回二叉堆的堆顶权值，即最大值heap[1]，复杂度为O（1）。
int GetTop()
{
    return heap[1];
}

Extract 
Extract操作把堆顶从二叉堆中移除。我们把堆顶heap[1]与存储在数组末尾的节点heap[n]交换，然后移除数组末尾节点（令n减小1），最后把堆顶通过交换的方式向下调整，直至满足堆性质。其时间复杂度为堆的深度，即O（logN）。
void down(int p)
{
    int s = p * 2;
    while (s <=n)
    {
        if (heap[s] > heap[p])
        {
            swap(heap[s], heap(p));
            p = s, s= p* 2;

        }
        else 
        {
            break;
        }
    }
}

void Extract()
{
    heap[1] = heap[n --];
    down(1);
}

Remove
Remove（p）操作把存储在数组下标p位置的节点从二叉堆中删除。与Extract相类似，我们先把heap[p]与heap[n]交换，然后令n减小1。注意此时heap[p]既有可能需要向下调整，也有可能需要向上调整，需要分别进行检查和处理。时间复杂度为O（logN）。

C++ STL中的priority_queue（优先队列）为实现了一个大根堆，支持push（Insert），top（GetTop）和pop（Extract）操作，不支持Remove操作。
void Remove(int k)
{
    heap[k] = heap[n --];
    up[k], down(k);
}


如何手写一个堆？小根堆
1.插入一个数         heap[ ++ size] = x; up(size);
2.求集合当中的最小值   heao[1];
3.删除最小值         heap[1] = heap[size]; size --; down(1);
4.删除任意一个元素     heap[k] = heap[size]; size --; down(k); up(k);
5.修改任意一个元素     heap[k] = x; down(k); up(k);


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], cnt;

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }

}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    cnt = n;

    for (int i = n / 2; i; i --) down(i); //递归建堆 O(n) 从n / 2开始down 算法导论有这个证明

    while (m --)
    {
        printf("%d", h[1]);
        h[1] = h[cnt --];
        down(1);
    }

    puts("");

    return 0;
}

AcWing 839. 模拟堆 
stl 不能实现任意插入删除数字
开两个数组 存映射关系 和 维护映射关系
存入第k个插入点 插入 删除
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 100010;

int h[N], ph[N], hp[N], cnt;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);映射所以要交换
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n --)
    {
        char op[5];
        int k, x;
        scanf("%d", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            cnt ++ ;
            m ++ ;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, cnt);
            cnt -- ;
            down(1);     
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, cnt);
            cnt -- ;
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}

O(n)建堆
for (int i = n / 2; i; i -- ) down(i);



*********************************************
一般哈希 —— 模板题 AcWing 840. 模拟散列表

https://www.acwing.com/solution/content/30169/ 解析图

Hash
Hash表又称为散列表，一般由Hash函数（散列函数）与链表结构共同实现。与离散化思想类似，当我们要对若干复杂信息进行统计时，可以用Hash函数把这些复杂信息映射到一个容易维护的值域内。因为值域变简单、范围变小，有可能造成两个不同的原始信息被Hash函数映射为相同的值，所有我们需要处理这种冲突情况。

有一种称为"开散列"的解决方案是，建立一个邻接表结构，以Hash函数的值域作为表头数组head，映射后的值相同的原始信息被分到同一类，构成一个链表接在对应的表头之后，链表的节点上可以保存原始信息和一些统计数据。
Hash表主要包括来两个基本操作：
1.计算Hash函数的值。
2.定位到对应链表中依次遍历、比较。
无论是检查任意一个给定的原始信息在Hash表中是否存在，还是更新它在Hash表中的统计数据，都需要基于这两个基本操作进行。

当Hash函数设计较好时，原始信息会被比较均匀地分配到各个表头之后，从而使每次查找，统计的时间降低到"原始信息总数除以表头数组长度"。若原始信息总数与表头数组长度都是O（N）级别且Hash函数分散均匀，几乎不产生冲突，那么每次查找，统计的时间复杂度期望为O（1）。

例如，我们要在一个长度为N的随机整数序列A中统计每个数出现了多少次。当数列A中的值都比较小时，我们可以直接用一个数组计数（建立一个大小等于值域的数组进行统计和映射，其实就是最简单的Hash思想）。当数列A中的值很大时，我们可以把A排序后扫描统计。这里我们换一个思路，尝试一下Hash表的做法。

设计Hash函数为H（x）=（x mod P）+1，其中P是一个比较大的质数，但不超过N.
显然，这个Hash函数把数列A分成P类，我们可以依次考虑数列中的每个数A[i]，定位到head[H（A[i]）]这个表头所指向的链表。如果该链表中不包含A[i]，我们就在表头后插入一个新节点A[i]，并在该节点上记录A[i]出现了1次，否则我们就在直接找到已经存在的A[i]节点将其出现次数+1。因为整数序列A是随机的，所以最终所有的A[i]会比较均匀地分散在各个表头之后，整个算法的时间复杂度可以近似达到O（N）。

上面的例子是一个非常简单的Hash表的直观应用。对于非随机的数列，我们可以设计更好的Hash函数来保证其时间复杂度。同样的，如果我们需要维护的是比大整数复杂得多得信息的某些特性（如是否存在，出现次数等），也可以用Hash表来解决。字符串就是一种比较一般化的信息，在本节的后半部分，我们将会介绍一个程序设计竞赛中极其常用的字符串Hash算法。

介绍看 https://www.acwing.com/solution/content/30169/



(1) 拉链法
    int h[N], e[N], ne[N], idx;

    // 向哈希表中插入一个数
    void insert(int x)
    {
        int k = (x % N + N) % N;
        e[idx] = x;
        ne[idx] = h[k];
        h[k] = idx ++ ;
    }

    // 在哈希表中查询某个数是否存在
    bool find(int x)
    {
        int k = (x % N + N) % N;
        for (int i = h[k]; i != -1; i = ne[i])
            if (e[i] == x)
                return true;

        return false;
    }

(2) 开放寻址法
    int h[N];

    // 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
    int find(int x)
    {
        int t = (x % N + N) % N;
        while (h[t] != null && h[t] != x)
        {
            t ++ ;
            if (t == N) t = 0;
        }
        return t;
    }


解题代码
开放寻址法
#include <cstring>
#include <iostream>

using namespace std;

//开放寻址法一般开 数据范围的 2~3倍, 这样大概率就没有冲突了
const int N = 2e5 + 3;        //大于数据范围的第一个质数
const int null = 0x3f3f3f3f;  //规定空指针为 null 0x3f3f3f3f

int h[N];

int find(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) {
        t++;
        if (t == N) {
            t = 0;
        }
    }
    return t;  //如果这个位置是空的, 则返回的是他应该存储的位置
}

int n;

int main() {
    cin >> n;

    memset(h, 0x3f, sizeof h);  //规定空指针为 0x3f3f3f3f

    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "I") {
            h[find(x)] = x;
        } else {
            if (h[find(x)] == null) {
                puts("No");
            } else {
                puts("Yes");
            }
        }
    }
    return 0;
}


拉链法
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 3;  // 取大于1e5的第一个质数，取质数冲突的概率最小 可以百度

//* 开一个槽 h
int h[N], e[N], ne[N], idx;  //邻接表

void insert(int x) {
    // c++中如果是负数 那他取模也是负的 所以 加N 再 %N 就一定是一个正数
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x) {
    //用上面同样的 Hash函数 讲x映射到 从 0-1e5 之间的数
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) {
            return true;
        }
    }
    return false;
}

int n;

int main() {
    cin >> n;

    memset(h, -1, sizeof h);  //将槽先清空 空指针一般用 -1 来表示

    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "I") {
            insert(x);
        } else {
            if (find(x)) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
    return 0;
}


字符串哈希 —— 模板题 AcWing 841. 字符串哈希
核心思想：将字符串看成P进制数，P的经验值是131或13331，取这两个值的冲突概率低
小技巧：取模的数用2^64，这样直接用unsigned long long存储，溢出的结果就是取模的结果

typedef unsigned long long ULL;
ULL h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64

// 初始化
p[0] = 1;
for (int i = 1; i <= n; i ++ )
{
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}

// 计算子串 str[l ~ r] 的哈希值
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}


https://www.acwing.com/solution/content/30232/ 看这个解析
下面介绍的字符串Hash函数把一个任意长度的字符串映射成一个非负整数，并且其冲突的概率几乎为0。
取一固定值P，把字符串看作P进制数，并分配一个大于0的数值，代表每种字符。一般来说，我们分配的数值都远小于P。例如，对于小写字母构成的字符串，可以令a=1，b=2，...，z=26，取一固定值M，求出该P进制数对M的余数，作为该字符串的Hash值。

解题代码
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 131;

int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", str + 1);

    p[0] = 1;
    for (int i = 1; i <= n; i ++)
    {
        h[i] = h[i - 1] * p + str[i];
        p[i] = p[i - 1] * p;
    }

    while (m --)
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d", &l1, &r1, &l2, &r2);

        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}







***********************************************
由数据范围反推算法复杂度以及算法内容***
一般ACM或者笔试题的时间限制是1秒或2秒。
在这种情况下，C++代码中的操作次数控制在 107~108 为最佳。
下面给出在不同数据范围下，代码的时间复杂度和算法该如何选择：
n≤30 指数级别, dfs+剪枝，状态压缩dp
n≤100 => O(n3)，floyd，dp，高斯消元
n≤1000 => O(n2)，O(n2logn)，dp，二分，朴素版Dijkstra、朴素版Prim、Bellman-Ford
n≤10000 => O(n∗n√)，块状链表、分块、莫队
n≤100000 => O(nlogn) => 各种sort，线段树、树状数组、set/map、heap、拓扑排序、dijkstra+heap、prim+heap、Kruskal、spfa、求凸包、求半平面交、二分、CDQ分治、整体二分、后缀数组、树链剖分、动态树
n≤1000000 => O(n), 以及常数较小的 O(nlogn) 算法 => 单调队列、 hash、双指针扫描、并查集，kmp、AC自动机，常数比较小的 O(nlogn)的做法：sort、树状数组、heap、dijkstra、spfa
n≤10000000 => O(n)，双指针扫描、kmp、AC自动机、线性筛素数
n≤109=> O(n√)O(n)，判断质数
n≤1018=> O(logn)，最大公约数，快速幂，数位DP
n≤101000=> O((logn)2)，高精度加减乘除
n≤10100000 => O(logk×loglogk)，k表示位数O(logk×loglogk)，k表示位数，高精度加减、FFT/NTT

在01区间中求从后往前第一个为0的位置可以用并查集优化
并查集常见操作：1.在根节点记录每个集合大小
2.用带权并查集记录每个点到根节点距离(相当于每个点出度为1的有向图)
inline int find(int X){
    if (fa[X] == X) return X;
    int root = find(fa[X]);//防止多次合并成一条链的情况，必须先更新父节点
    d[X] += d[fa[X]]; //d[X]是 X 到 fa[X] 的距离，再加上fa[X] 到 root的距离即可
    return fa[X] = root;
}

if (fx != fy){
    f[fx] = fy;
    d[px] = -d[x] + d[y] + s;
} //注意这里x -> y长为s的边转换成了fx -> fy的一条边
将元素分成k类：1.带边权并查集 记录每个点到根节点距离 维护元素相对关系 时间复杂度与k无关，k较大时宜选择
2.扩展域并查集 将每个元素按分类拆成多个条件，同一个集合中一个条件成立则其它条件也成立 相当于枚举各类情况 每次操作O(k)
区间染色问题：长为n的序列，每次将l到r的数全染成c色，求最终的序列颜色。
我们考虑将染色反着来，则一个数若被染色一次，则这就是它的最终颜色，不会改变。
所以下次若在遇到这个数则需要跳过，也就是对已经染色的区间[l,r]，我们令其中的所有数都有一个指针，以指向右边第一个还没有操作的数。
于是我们令fa[i]表示i右边（包括i）第一个没有染色的数，将i染色后，令fa[i] = find(i + 1)，用并查集操作即可。
具有无向（或者说双向）的传递性关系（若已知A与B，B与C的关系，则可以推出A与C的关系）可以用并查集或传递闭包，而具有有向的传递性关系只能用传递闭包
敌人的敌人是朋友（例：[NOIP2010 提高组] 关押罪犯）在对敌人进行合并时，注意一定要将find其祖先进行合并，即f[x] = find(enemy[y])
* 循环队列

int hh = 0, tt = 0;
Q[tt++] = X;
...
while(hh != tt){
    int U = Q[hh++];
    if (hh == maxn) hh = 0;
    ...
    Q[tt++] = V;
    if (tt == maxn) tt = 0;
} 
对顶堆：1.小根堆的所有元素大于等于大根堆的所有元素
2.大根堆的元素个数与小根堆元素个数相等或多1

ST表建议预处理log函数省时间，for (int i = 2 ; i <= N ; i++) lg[i] = lg[i >> 1] + 1;
对于st[i][j]=f(st[i][j-1],st[i+(1<<j-1)][j-1])，我们将i,j的顺序调换一下可以提高效率

BIT（树状数组）的原数组下标一定要从1开始,它只支持满足“区间减法”的操作，即知道[1, r] [1, l - 1]的信息，就可以推出[l,r]的信息，如区间和，区间异或和，乘积。
树状数组初始化：
1.用update操作 O(NlogN)

先求前缀和数组S，tr[x] = S[x] - S[x - lowbit(x)] O(N)
tr[x] = a[x] + [x - lowbit(x) + 1, x - 1]的区间和
for(int x = 1;x <= n;x ++) {
    tr[x] = a[x];
    for(int i = x - 1;i >= x - lowbit(x) + 1;i -= lowbit(i))
         tr[x] += tr[i];
}
二分 + 树状数组可以同时实现平衡树的删除元素和查询第k大元素的操作
线段树是否需要维护额外信息：通过左右子区间的属性能不能算出父区间的属性？
可持久化的前提：本身的拓扑结构不变
Trie的trick，如果空间限制不太够的话，可以根据根据空间限制开trie数组（注意数组空间略小于空间限制）
单词A中单词B出现的次数，其实就是看在A所有的前缀中以单词B为后缀的次数，与next数组类似

双队列优化：对一个单调队列中的数进行修改操作后再放入队列，如果修改后不一定是队列最大值最小值（不能确定放队头还是队尾），同时多次操作得到的一系列新数都有序的话，可以再开一个单调队列存储新数，每次的最大值即为单调两队列队尾的最大值
例如“合并果子”问题（哈夫曼树）中的O(nlogn)堆做法就可以优化为O(n)桶排 + 双队列做法
一般区间操作首先要想差分

其它
字符
字符串函数
#include<cctype>
1、isalpha(x) 判断x是否为字母
2、isdigit(x) 判断x是否为数字
3、islower(x) 判断x是否为小写字母
4、isupper(x) 判断x是否为大写字母
5、isalnum(x) 判断x是否为字母或数字
6、ispunct(x) 判断x是否为标点符号
7、isspace(x) 判断x是否为空格
8、toupper(x) 如果x是小写字母，将其转换成大写字母
9、tolower(x) 如果x是大写字母，将其转换成小写字母
#include<string>
1、s.erase(x,y) 表示将字符串s从x位置起删除y个字符
2、s.insert(x,y) 表示将字符串y（或字符y）插入到s的x位置处
3、s.push_back(x) 表示在s的末尾插入字符x

reverse(s.begin(),s.end()) 将字符串s翻转
str.replace(2,4, "ABCD"); //从下标为2的位置,替换4个字节,为"ABCD"
C++字符串摘录
s.substr(pos, n)中若pos的值超过了string的大小，则函数会抛出一个out_of_range异常；若pos+n的值超过了string的大小，只拷贝到string的末尾
char数组函数整理
memcpy(d + 1,s + 2,3); 从字符数组d的第1位（最前面一位为第0位）开始，用s字符数组从第2位开始的3位字符覆盖
相当于memcpy(d + 1,s+2sizeof(char),3sizeof(char));

“空格+%c”或“%s”能够忽略getchar缓冲区的空白字符
scanf的格式匹配字符串中空格表示空白字符的占位符(任何空白字符都会自动匹配上这个空格,所以相当于这个空白字符被getchar掉了）
而%s则会忽略前导的空白字符
【为了防止空白字符的干扰，即使读入一个字符也建议用%s】

字母’A’的ASCII码是41H（0100 0001B），字母’a’的ASCII码是61H（0110 0001B），字母’A’与’a’的二进制后5位是相同的，所以无论是大写字母还是小写字母x，x & 31（1 1111B）的值就是x在字母表里的顺序。

对于输入有很多字符的模拟题，如果在线操作比较复杂，可以尝试用字符串保存输入再进行处理

输入输出
快读快输
template <typename TT> 
void inline rd(TT &x){
    x = 0;
    TT f = 1;
    char ch = getchar();
    for ( ; ch < '0' || ch > '9' ; ch = getchar()) if (ch == '-') f = -1;
    for ( ; ch >= '0' && ch <= '9' ; x = (x<<3) + (x<<1) + (ch^48), ch = getchar());
    x *= f;
}

template <typename TT> 
void inline wt(TT x){
    if (x < 0) x = ~(x - 1), putchar('-');
    if (x > 9) wt(x / 10);
    putchar(x % 10 + '0');
}
ios::sync_with_stdio(false) 需特别注意无输出的错位输出的比赛常见错误

cin解锁（ios::sync_with_stdio(false)）不要和scanf 、getchar、puts、gets等混用（会因为缓冲区出现问题）
ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
sstream库:stringstream ss 赋值有两种方式， 1. ss(s) ; 2. ss << s; 使用ss可以先接收字符串，再将字符串作为 输入流 >> 转化成整型（会忽略字符串里 的空格、回车、tab）。 缓冲区中，getline(cin, s) 遇到回车会结束接收，并且删掉的回车。

对于一些题目需要注意输入数据是否已经排好了顺序*，有时候输入数据并没有说明保证有序，可能需要先sort一遍。建图注意是否有自环重边。注意如果输入（x，y）时需要x<y，数据会不会出现x>y的情况

快读适用于数据量大的，比如 10^6及以上 级别的数据，scanf对中等数据比快读快
快读快输注意0和负数的情况
数据类型
能用int尽量不用long long，容易MLE，在计算过程中int强转ll即可

unsigned long long的范围是[0,2^64-1],越界以后相当于对2^64求模(遇到范围是2^63，取模2^64的这种题目,要想到用unsigned long long类型)
long long的范围是[-2^63,2^63-1]，越上界后会从-2^63开始计数，越下界则从2^63-1开始计数

double可以存储比unsigned long long更大的数字
原因是无符号 long long 会存储精确整数，而 double 存储尾数有限的精度和一个指数。
这允许 double 存储非常大的数字（大约10^308 ），一个 double 中有大约15个（近16个）有效的十进制数字，
也就是说double的精度（15或16位）比long long(19位）位要小，但是double取值范围为 -1.7976E+308 到到-4.94065645841246544E-324，正值取值范围为 4.94065645841246544E-324 到 1.797693E+308。
对于long long
其64位的范围应该是[-2^63 ，2^63],既-9223372036854775808~9223372036854775807。
long double 会保存二进制最高 64 位和指数
double的这种存储方式也就意味着 2 的幂是不会对精度产生影响的

double fmod(double x,double y) 返回x除以y的余数。
fmod()用来对浮点数进行取模，设x=k*n+h，则返回值为h（h和x的符号相同）。
%只用于整型的计算，后一个数不能为0;
fmod()可以对浮点型数据进行取模运算，后一个数可以为0，返回NaN(NaN，是Not a Number的缩写,用于处理计算中出现的错误情况，比如 0.0 除以 0.0 或者求负数的平方根)。

对于超出unsigned long long范围不是很多的数，可以尝试用long double（取模可以用fmod，注意精度损失，cout默认只保留6位有效数字，应当使用printf(“%LF”)，F小写和大写没影响，但是 l 必须大写成L,如果”%LF”无输出，则只好强转double保留15位有效数字）或两个unsigned long long代替高精度

lcm为防止溢出，不可先乘后除，而且为保证精度应尽量整除

四舍五入可以用<cmath>中的round函数（保留几位小数可以先乘10的幂再round再除以10的幂）也可以用%.0lf输出，若强转int的话小数部分会直接舍弃

通常取eps的值为：1e-10~1e-8，判断正数的条件改为x > -eps

STL
非C++11可以用map，但是使用unordered_map（数据存储无序，不保证与插入顺序一致）需要#include<tr1/unordered_map和using namespace tr1;
unordered_multimap,unordered_set和unordered_multiset同理

set的insert不支持返回迭代器，需要二分查找，但multiset可以

typedef multiset<int>::iterator iter;
iter it=s.insert(x);//插入x，并返回x在s中的位置（迭代器）
set专有的s.lower_bound(x)比lower_bound(s.begin(), s.end(), x)会更快

对于结构体/pair 赋值，a={x,y}是C++11开始才有的语法
旧版本可以这样写：
1.转化为pair类型
a=(pair[HTML_REMOVED]){x,y};
2.调用pair的构造函数
a=pair[HTML_REMOVED](x,y);
3.使用STL中的make_pair函数
a=make_pair(x,y);

iostream包含<string>和<utility>（可以使用pair类型）头文件，包含swap，max，min，getline（接收一行字符串，忽略回车符。），不包含freopen（只在[HTML_REMOVED]库中）

end()指向的是最后一个元素的下一个位置，back()返回的是最后一个元素.类比字符串，end( )返回的是’\0’，back( )返回的是字符串的最后一个字符

优化技巧
越在内层循环的数组维度在定义数组时越靠后，能提高运行效率（在连续的存储空间内）（例如ST表的数组，倍增数组注意把指数的一维放在前面）

ST表建议预处理log函数省时间，for (int i = 2 ; i <= N ; i++) lg[i] = lg[i >> 1] + 1;
对于st[i][j]=f(st[i][j-1],st[i+(1<<j-1)][j-1])，我们将i,j的顺序调换一下可以提高效率

noip可以用exit(0)和goto，但是请谨慎使用。goto 语句可用于跳出深嵌套循环，可以往后跳，也可以往前跳，且一直往后执行。goto只能在函数体内跳转，不能跳到函数体外的函数。即goto有局部作用域，需要在同一个栈内。

万能头 include<bits/stdc++.h>（注意有些比赛可能不允许使用） 会增加编译时间，但是比赛评测程序的时间限制指的是运行时间限制，而不是编译时间限制，所以包含万能头文件不会影响到评分。

memset使用时要小心，在给char以外的数组赋值时，一般初始化为0或者-1或者0x3f或者-0x3f。
memset -1其实是赋值为NaN，NaN在任何比较运算都返回false

CLOCKS_PER_SEC可以返回1s内clock()对应值，注意clock()运算速度慢，可以每多少次循环执行一次clock()

iostream库中有rand()可以产生0~0x7fff(32367)的随机数，初始化种子srand((unsigned int)time(0))（使用time函数获取系统时间，得到的值是一个时间戳，即从1970年1月1日0点到现在时间的秒数，然后将得到的time_t类型数据转化为(unsigned int)的数

建议一次性写好常用头文件，这样就不用写到一半再补加，打断思路）

分配空间比较慢，用static可以防止每次重新分配空间

解题技巧
编程：思维（数学），编程能力（实践，即手速【非常重要，需要自己练】+正确率）

解题注意尝试逆向思维

别忘了打表也是一种颇有妙用的算法

noip一定要把暴力分部分分拿足

看到题目可以先考虑暴力模拟的方法，理解题意，理清思路，然后再根据理想的时间复杂度找到复杂度的瓶颈，对代码各步不断进行优化直到满足要求，注意在空间足够的情况下最好不要为省空间而压缩数组减少变量，在时间复杂度足够的情况下不要使用太多不一定正确而又复杂的优化，码风应清晰，不要压行，尽可能防止自己出错

考试注意事项：
保持心态，可以带口香糖之类食物缓解压力，简单题要看清题意先做，很久没有思路就要想方设法写暴力

在做题前把细节想清楚，怎么写比较简便

对于较大数据范围，如果自己的做法会超时，当数据比较随机时可以尝试trick：减少操作次数，比如人为限定循环执行的次数以保证不超时，期望能得到正确答案

对于多个变量的数据范围，可以尝试从小的数据范围找突破口

对于O(N ^ 2)优化为O(N)：尝试能不能从多层循环枚举多个变量 改为 （使用一些数组存储答案）只枚举一个变量
例如要枚举左右边界，可以考虑通过记录前缀和、记录最后一个合法左边界的位置等方法，使得只需枚举右边界即可解出答案

注意部分分，当题目有多个条件时可以考虑满足其中部分条件的做法，再尝试添加一个条件的做法应该如何改进

想学好算法，要提高打代码的速度
想学好数学，要提高写字速度，多练习多计算，提高计算能力与熟练度，尤其是高中生
——yxc
暴力强解很重要，与其去想很多技巧，不如去强解，因为强解很快，计算能力足够强就可以掩盖掉很多劣势，技巧跳跃性强，发挥不稳定，不容易想到，而暴力可以规避掉这些风险
——yxc

其它
在把数组作为参数传递给函数时，函数的数组参数相当于指向该数组第一个元素的指针，所以不可以通过sizeof运算符得到函数数组的大小，直接用数组大小 * 字节数即可。而对于全局变量和局部变量（如函数内新建的数组）可以直接用sizeof

strict weak ordering
stl的相关容器要求严格弱序。
即 a>b 和 b>a 不能同时为真。
stl判断等价用的是 !(a<b) && !(b<a)
所以重载<运算符的时候应判断<，不可判断<=

矩阵乘法具有结合律不具有交换律
具有结合律的问题可以尝试倍增优化

y1, next, prev, has, hash在非c++11中可能会与保留字冲突

NP问题常识

noip已将栈空间开至内存空间的大小，不需担心爆栈的问题

对于二维数组数组名作为形参，函数形参声明一定要至少给出第二个维度的大小


