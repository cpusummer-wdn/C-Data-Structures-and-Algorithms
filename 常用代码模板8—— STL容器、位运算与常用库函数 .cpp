迭代器iterator
for (int I = 0; I < a.size(); I ++) cout << a[i] << endl;
for (vector<int>::iterator it = a.begin(); it != a.end(); it ++) cout << *it << endl;

队列
头文件queue主要包括循环队列queue和优先队列priority_queue两个容器
声明
		queue<int> q;
		struct rec{…}; queue<rec> q; 	//结构体rec中必须定义小于号
		priority_queue<int> q;		// 大根堆
		priority_queue<int, vector<int>, greater<int> q;	// 小根堆
		priority_queue<pair<int, int>>q;

	循环队列 queue
		push 从队尾插入
		pop 从队头弹出
		front 返回队头元素
		back 返回队尾元素

	优先队列 priority_queue
		push 把元素插入堆
		pop 删除堆顶元素
		top 	查询堆顶元素（最大值）

栈
#include <stack>
push 向栈顶插入
pop 弹出栈顶元素

双端队列
#include <deque>
// 双端队列deque是一个支持在两端高效插入或删除元素的连续线性存储空间。
// 它就像是vector和queue的结合。
// 与vector相比，deque在头部增删元素仅需要O(1)的时间
// 与queue相比，deque像数组一样支持随机访问。
// [] 随机访问
// begin/end，返回deque的头/尾迭代器
// front/back 队头/队尾元素
// push_back 从队尾入队
// push_front 从队头入队
// pop_back 从队尾出队
// pop_front 从队头出队
// clear 清空队列

集合set 
#include <set>
// 头文件set主要包括set和multiset两个容器，分别是“有序集合”和“有序多重集合”
//即前者的元素不能重复，而后者可以包含若干个相等的元素。set和multiset的内部实现是一棵红黑树，它们支持的函数基本相同。
set<int> s;
struct rec{…}; set<rec> s;	// 结构体rec中必须定义小于号
multiset<double> s;

lower_bound/upper_bound
		这两个函数的用法与find类似，但查找的条件略有不同，时间复杂度为 O(logn)。
s.lower_bound(x) 查找大于等于x的元素中最小的一个，并返回指向该元素的迭代器。
s.upper_bound(x) 查找大于x的元素中最小的一个，并返回指向该元素的迭代器。

映射map
#include <map>
map容器是一个键值对key-value的映射，其内部实现是一棵以key为关键码的红黑树。Map的key和value可以是任意类型，其中key必须定义小于号运算符。
	声明
		map<key_type, value_type> name;
		例如：
		map<long, long, bool> vis;
		map<string, int> hash;
		map<pair<int, int>, vector<int>> test;
find
		h.find(x) 在变量名为h的map中查找key为x的二元组。

	[]操作符
		h[key] 返回key映射的value的引用，时间复杂度为O(logn)。
[]操作符是map最吸引人的地方。我们可以很方便地通过h[key]来得到key对应的value，还可以对h[key]进行赋值操作，改变key对应的value。





AcWing 67. 数字在排序数组中出现的次数
class Solution{
public:
   int getNumberOfk(vector<int>& nums, int k){
     int cnt = 0;
     for (int x : nums)
       if (x == k)
         cnt ++ ;
      return cnt;
   }
};

AcWing 68. 0到n-1中缺失的数字
class Solution {
public:
  int getMissingNumber(vector<int> &nums) {
    unordered_set<int> S;
    for (int i = 0; i <= nums.size(), i ++ ) S.insert(i);

    for (auto x : nums) S.erase(x);//atuo x : nums

    return *S.begin();
  }
};

AcWing 32. 调整数组顺序使奇数位于偶数前面
clas Solution {
public:
   void reOrderArray (vector<int> &array) {
     int i = 0, j = array.size() - 1;
     while (i < j)
     {
       while (i < j && array[i] % 2) i ++ ;
       while (i < j && array[j] % 2 == 0) j -- ;
       if (i < j) swap(array[i], array[j]);
     }
   }
};

AcWing 17. 从尾到头打印链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   vector<int> printListReversingly(ListNode* head) {
     vector<int> res;
     for (auto p = head; p; p = p->next) res.push_back(p->val);
     reverse(res.begin(), res.end());
     return res;
   }
}

AcWing 20. 用两个栈实现队列
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1, s2;

    MyQueue(){


    }
  
   /** Initialize your data structure here. */
   void push(int x) {
     s1.push(x);
   }

   /** Removes the element from in front of queue and returns that element. */
   int pop() {
     while (s1.size() > 1) s2.push(s1.top()), s1.pop();
     int t = s1.top;
     s1.pop();
     while (s2. size()) s1.push(s2.pop()), s2.pop();
     return t;
   }

   /** Returns whether the queue is empty. */
   bool empty()
   {
     return s1.empty();
   }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

AcWing 53. 最小的k个数
class Soltion {
public:
  vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
    sort(input.begin(), input.end());

    vector<int> res;
    for (int i = 0; i < k; k ++ ) res.push_back(input[i]);

    return res;
  }
};

AcWing 75. 和为S的两个数字
class Solution {
public:
   vector<int> findNumberSWithSum(vector<int> &nums, int target) {
     unordered_set<int> S;
     for (auto x : nums)
     {
       if (S.count(target - x)) return {x, targer - x};
       S.insert(x);
     }
   }
};

AcWing 26. 二进制中1的个数
写法1
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        for (int i = 0; i < 32; i ++ )
            if (n >> i & 1)
            //
                res ++ ;
        return res;
    }
};

lowbiot写法
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;

        while (n) n -= n & -n, res ++ ;
        //

        return res;
    }
};

AcWing 51. 数字排列
class Solution {
public:
    vector<vector<int>> permutation(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        //
        do res.push_back(nums); 
        while (next_permutation(nums.begin(), nums.end()));

        //

        return res;
    }
};

AcWing 862. 三元组排序
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;

struct Data
{
    int x;
    double y;
    string z;

    bool operator < (const Data &t) const
    //
    {
        return x < t.x;
    }
}a[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++ ) cin >> a[i].x >> a[i].y >> a[i].z;

    sort(a, a + n);

    for (int i = 0; i < n; i ++ )
        printf("%d %.2lf %s\n", a[i].x, a[i].y, a[i].z.c_str());

    return 0;  
}