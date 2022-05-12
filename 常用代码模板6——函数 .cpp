2.
#include <iostream>
#include <cstdio>

using namespace std;

int max(int x, int y)
{
    if (y > x) swap(x , y);
    cout << x << endl;
}

int main()
{
   int x, y;
   cin >> x >> y;
   
   max(x, y);
   
   
   return 0;
}

#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    x>y? printf("%d",x):printf("%d",y);
}





3.最大公约数
#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    //for (int i = 1000; i --;) 
    for (int i = 1000; i; i --) 
    {
        if (a % i == 0 && b % i == 0) return i;
    }
    
    return -1;
}


int main()
{
   int a, b;
   
   cin >> a >> b;
   
   cout << gcd(a, b) << endl;
   
   
   return 0;
}

欧几里得算法 最大公约数
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}


**暴力其实很容易，可以从 min(a,b)min(a,b) 到 11 中查找每一个数

for (int i = min (a, b); i; i --)
    if (!(a % i) && !(b % i)) // (a mod i) = (b mod i) = 0 则输出 i 并退出循环
        return printf ("%d\n", i);

O(min(a, b))

**辗转相除法（欧几里得算法）  
前置定理：gcd(a,b)==gcd(b, a mod b) 这个是得证的

?????? while (b) {

    int tmp = a % b;

    a = b;
    b = tmp;
}

O(log2(a, b))

递归的欧几里得算法
int gcd (int a, int b) {

    return b ? gcd (b, a % b) : a;
}

c++自带函数__gcd 
printf ("%d\n", __gcd (a, b));

#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    
    while (b){
    int tmp = a % b;
    a = b; // b的值赋给a
    b = tmp; // tmp的值赋给b
    }
   
    return a;
}

/*这段代码其实是一个递归调用gcd
while循环里面就是相当于写了一个gcd(b, a %b)*/

int main()
{
   int a, b;
   
   cin >> a >> b;
   
   cout << gcd(a, b) << endl;
   
   
   return 0;
}



4.交换数值
#include <iostream>
#include <cstdio>

using namespace std;

void swap(int &x, int &y)
{
    int k = x;
    x = y;
    y = k;
}

int main()
{
   int a, b;
   cin >> a >> b;
   swap(a, b);
   cout << a <<' ' << b << endl; //void 类型的函数 所以输出要放在Main函数 因为cout不能输出void类型值
   return 0;
}

5.  打印数字
#include <iostream>
#include <cstdio>

const int N = 1010; //全局定义N

using namespace std;

void print(int a[], int size)
{
 for (int i = 0; i < size; i ++) 
 cout << a[i] << ' ' ;
 cout << endl;
}


int main()
{
   int n, size;
   int a[N];//定义一个数组a[N]
   
   cin >> n >> size;//数组那块不熟练
   for (int i = 0; i <= n; i ++) cin >> a[i];
   
   
   print(a, size);
   
   return 0;
}

6. 绝对值
#include <iostream>
#include <cstdio>

using namespace std;
int abs(int x)
{
    if (x >= 0) return x;
    else return 0 - x ;
}
int main()
{
   int a;
   cin >> a;
   //abs(a);
  ///printf("%d", a);这样当然输出的是a而不是绝对值
   printf("%d", abs(a));
   
   return 0;
}

7. 两个数的和
#include <iostream>
#include <cstdio>

using namespace std;

double add(double x, double y)
{
    return x + y;
}

int main()
{
   double a, b;
   cin >> a >> b;
   
   printf("%.2lf", add(a, b));
   
   
   return 0;
}

8.区间求和
#include <iostream>
#include <cstdio>

using namespace std;

int sum(int l, int r)
{
    int s = 0;
    for (int i = l; i <= r; i ++)
    {
        
       s += i;
    }
    
    return s;
    
}


int main()
{
   int a, b;
   cin >> a >> b;
   
   cout << sum(a, b) << endl;
   
   return 0;
}


#include<iostream>
using namespace std;

int sum(int l,int n)
{
    return (n+l)*(n-l+1)/2;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<sum(a,b)<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int sum(int l,int r)
{
    int a=0;
    while(r>=l) 用while循环来解决
    {
       a=a+r;//倒着写 从r右边区间开始加
       r--;
    }
    return a;
}
int main()
{
    int l,r;
    scanf("%d %d",&l,&r);
    cout<<sum(l,r);
}

9.打印字符串

#include <cstdio>

void print(char str[])
{
    printf("%s", str);//可以直接读入一个字符串 不用写循环一个个读 
    char也是字符串不是单个字符 字符串这节不熟
}

int main()
{
    char str[110];先定义及初始化数组 开一个内存空间为110
    fgets(str, 101, stdin);scanf和cin都是读不进空格的，你必须要用getline或者fgets，getline我觉得是读入字符串最好的函数
    读入str 读到101
    print(str);

    return 0;
}


#include <iostream>
#include <string>

using namespace std;

void print(char a[])
{
    for (int i = 0; a[i]; i ++ )
        cout << a[i];
}

int main()
{
    char a[130];
    cin.getline(a, 120);  // 注意这里的数字，如果你只写了100，那么最多只会读99个字符！

    print(a);

    return 0;
}





10.最小公倍数

最小公倍数 = 两数乘积 / 最大公约数
#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
   
   //return b ? a % b : b;
   return b ? gcd(b, a % b) : a; //返回a说明b为空 0 否则b=1
}


int lcm(int a, int b)
{
    int c;
    return c = a * b / gcd(a, b);
}


int main()
{
   int a, b;
   cin >> a >> b;
   
   cout << lcm(a, b) << endl;
   
   
   return 0;
}

暴力求解法

#include <bits/stdc++.h>
using namespace std;
int lcm(int &a,int &b)
{
  int res=a*b;
  for(int i=a; i<=res; i++)
  {
    if((i%a==0)&&(i%b==0)) res=i;
  }
  return res;
}
int main()
{
  int a,b;
  cin>>a>>b;
  cout<<lcm(a,b)<<endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<a*b/__gcd(a,b);//__gcd()：求最大公因数
    return 0;
}


#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int res = a * b;

    while(a && b)
    {
        a = a % b;
        if(!a) break;
        swap(a,b);
    }

    cout << res / b << endl;

    return 0;
}

绝对值 n 0-n abs() 
#include <bits/stdc++.h>

递推法

#include <iostream>
using namespace std;

int gcd(int a, int b)
{  
    do
    {
   int c = a % b;
   a = b; 
   b = a; 

   
   }while(b);
return a;


}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}


int main()
{
    int x, y; 
    cin >> x >> y;
    cout >> lcm(x, y) >> endl;

    return 0;
}

#include <iostream>

using namespace std;

int lcm(int a, int b)
{
    for (int i = 1; i <= b; i ++ )
        if ((a * i) % b == 0) 最小公倍数公式的逆运算
            return a * i;

    return -1;      //一定不会执行
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << lcm(a, b) << endl;

    return 0;
}

11. for循环 while循环怎么转递归



12. 复制数组
#include <iostream>
#include <cstdio>

using namespace std;

****const int N = 110;

void copy(int a[], int b[], int size)
{
    for (int i = 0; i < size; i ++ )
    {
        b[i] = a[i];
    }
}

int main()
{
   int n, m, size;
   cin >> n >> m >> size;
   //int a[n], b[m];不会初始化数组
   **int a[N], b[N];
   for (int i = 0; i < n; i++)  cin >> a[i];
   for (int i = 0; i < m; i++)  cin >> b[i];
   copy(a, b, size);
   
   
  for (int i = 0; i < m; i++)   cout << b[i] << ' '; 
   cout << endl;
   return 0;
}

#include <cstring>
#include <iostream>

using namespace std;

const int N = 110;

void copy(int a[], int b[], int size)
{
    memcpy(b, a, size * 4); 从源a中拷贝size*4个字节 一个int是4个字节 到目标b中。
}

int main()
{
    int a[N], b[N];
    int n, m, size;
    cin >> n >> m >> size;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < m; i ++ ) cin >> b[i];

    copy(a, b, size);

    for (int i = 0; i < m; i ++ ) cout << b[i] << ' ';
    cout << endl;

    return 0;
}

13 数组翻转
#include <iostream>

const int N = 1010;

void reverse(int a[], int size)
{
    
    for (int i = 0, j = size -1; i < j; i ++, j --) i< y 只需要走一半 如果是i < size j >=0 那就是翻转再翻转
    //用i和j两个不同的变量存储 使用swap交换而不是赋值！赋值会改变数据的值
    //本质上是数组方格那块  i < size , j >= 0 不是交换的条件
    swap(a[i], a[j]);
}


using namespace std;
int main()
{
   int n, size;
   cin >> n >> size;
   int a[N];
   
   for (int i = 0; i < n; i ++) cin >> a[i]; 
   reverse(a, size);
  
   for (int i = 0; i < n; i ++) cout << a[i] << ' ';
   cout << endl;
   
   
   return 0;
}


#include <iostream>

using namespace std;

void reverse(int a[], int size)
{
    for (int i = 0, j = size - 1; i < j; i ++, j -- ) 
        swap(a[i], a[j]);
}

int main()
{
    int a[1000];
    int n, size;

    cin >> n >> size;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    reverse(a, size);

    for (int i = 0; i < n; i ++ ) cout << a[i] << ' ';

    return 0;
}

#include<iostream>
#include<cstring>

using namespace std;

int a[1010];
void reverse(int a[],int size)
{
    for(int i=0; i < size/2; i++)   swap(a[i],a[size-i-1]);
}

int main()
{
    int n,size;

    cin>>n>>size;
    for(int i=0; i < n; i++)    cin>>a[i];

    reverse(a,size);
    for(int i=0; i < n; i++)    cout<<a[i]<<' ';
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
void reverse(int a[], int size,int n)
{
  for(int i=size; i>=1; i--)
    cout<<a[i]<<" ";
  for(int i=size+1; i<=n; i++)
    cout<<a[i]<<" ";
}
int main()
{
  int n,siz;
  cin>>n>>siz;
  int a[n+1];
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
  }
  reverse(a,siz,n);
  return 0;
}


#include <bits/stdc++.h>
using namespace std;
void reverse(int a[], int size,int n)
{
  for(int i=size-1; i>=0; i--)
    cout<<a[i]<<" ";
  for(int i=size; i<n; i++)
    cout<<a[i]<<" ";
}
int main()
{
  int n,siz;
  cin>>n>>siz;
  int a[n];
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  reverse(a,siz,n);
  return 0;
}



14数组去重
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int get_unique_count(int a[], int n)
{
  int k = 0;
  for (int i = 0; i < n; i ++)
  {
      bool is_exist = false;
      //for (int j = 0; j < n; j ++) ///
      for (int j = 0; j<i; j ++) //j必须要遍历没有被i遍历的数
      {
          if (a[i] == a[j]) 
          {
          is_exist = true; //二重循环 遍历两次数组 用于寻找出现n次的数值，不能直接k ++ 不然k的值会累加 最后会很大 远大于n
          break;}
          
      }
      
      
     if (!is_exist) k ++;
  }
   return k;
}

int main()
{
  int n;
  cin >> n;
  int a[N];
  for (int i = 0; i < n; i ++) cin>> a[i];
  
  cout << get_unique_count(a, n) << endl;
  
  return 0;
  
}


一些空间换时间的做法

#include <iostream>

using namespace std;

 // 返回数组前n个数中的不同数的个数
int get_unique_count(int a[], int n)
{
    int b[1100]={0},count = 0;
    for(int i = 0;i<n;i++)  b[a[i]]=1;如果值相同 只返回一次 因此重复的数字只保留一位
    for(int i = 0;i<1099;i++) 
    {
        if(b[i]==1) count++;
    }

    return count;
}
解释b[a[i]]:
a数组保存了2,3,4,3,0,2,3,4,1,3

b[a[0]]++就是把b[2]加了1

b[a[1]]++ 就是把b[3]加了1

以次类推。

你的循环里面把b[0]加一是次，b[1]加了一次，b[2]加了两次，b[3]加了4次，b[4]加了两次，

结果就是b[0]=1 b[1]=1 b[2]=2 b[3]=4 b[4]=2

int main()
{
    int n,count=0,b[1100]={0};
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];

    cout<<get_unique_count(a,n)<<endl;
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int get_unique_count(int a[], int n) {
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0, j = 0; i < n; i ++) {
        while (j < n && a[j] == a[i]) j ++;
        cnt ++;
        i = j - 1;
    }
    return cnt;
}

int main() {
    int n, a[N];
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    cout << get_unique_count(a, n) << endl;
    return 0;
}



15 数组排序
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1000;

void sort(int a[], int l, int r)
{
    for (int i = l; i <= r; i ++) 
    //if (a[i] > a[i + 1]) swap(a[i], a[i+1]); //比较两个数组要开两个循环 本质是多重循环不理解
    for (int j = i + 1; j <= r; j ++)
      if (a[i] > a[j]) swap(a[i], a[j]);
    
    
}


int main()
{
   int n, l, r;
   cin >> n >> l >> r;
   int a[N];
   for (int i = 0; i < n ; i ++) cin >> a[i];
   sort(a, l, r);
   
   
   for (int i = 0; i < n ; i ++) cout << a[i] << ' ';
   
   cout << endl;
   
   
   return 0;
}

算法 11
堆排序 O(nlogn)O(nlogn)
构建大根堆，每次将最大的元素放到最后

C++C++ 代码
#include <stdio.h>

int a[1005];

void swap(int i, int j)  // 技巧：手写交换，传入数组下标
{
    if (i ^ j)           // 特判 i = j 的情况，i ^ j 等价于 i != j
    {
        a[i] ^= a[j];    // 交换 a[i], a[j]
        a[j] ^= a[i];
        a[i] ^= a[j];
    }
}

void down(int l, int r, int p) // 将更小的元素
{
    int t = p;
    if ((p << 1) <= r - l && a[t] < a[(p << 1) - l])
        t = (p << 1) - l;
    if ((p << 1) + 1 - l <= r && a[t] < a[(p << 1) + 1 - l])
        t = (p << 1) + 1 - l;
    if (t != p)
    {
        swap(t, p);
        down(l, r, t);
    }
}

void heap_sort(int l, int r)
{
    for (int i = r - l >> 1; i; i -- ) // O(n)建堆
        down(l, r, i);
    while (r ^ l)        // 排序，同样用 r ^ l 代替 r != l
    {
        swap(1, r -- );  // 每次将最大的元素交换至最后，并在堆中删除
        down(l, r, 1);   // 将交换过来的元素向下交换，使剩余元素重构堆
    }
}

int main()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);

    heap_sort(l, r + 1);

    for (int i = 1; i <= n; i ++ )
        printf("%d ", a[i]);

    return 0;
}
算法 22
归并排序 O(nlogn)O(nlogn)
每次将数组划分成两个部分，分别处理

C++C++ 代码
#include <stdio.h>

const int N = 1005;

int a[N];
int t[N];

void merge_sort(int l,int r)
{
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (a[i] < a[j]) t[k ++ ] = a[i ++ ];
        else    t[k ++ ] = a[j ++ ];
    while (i <= mid) t[k ++ ] = a[i ++ ];
    while (j <= r) t[k ++ ] = a[j ++ ];
    for (int i = l, j = 0; i <= r; i ++, j ++ )
        a[i] = t[j];
}

int main()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; i ++ )
        scanf("%d", &a[i]);

    merge_sort(l, r);

    for (int i = 0; i < n; i ++ )
        printf("%d ", a[i]);

    return 0;
}
// 懒得注释了
算法 33
快速排序 O(nlogn)O(nlogn)
每次将数组划分成两个部分，分别处理

C++C++ 代码
#include <stdio.h>

const int N = 1005;

int a[N];

void swap(int i, int j) // 由于当 i < j 的时候才会 swap，所以不用特判
{
    a[i] ^= a[j];
    a[j] ^= a[i];
    a[i] ^= a[j];
}

void quick_sort(int l,int r)
{
    if (l >= r) return;
    int x = a[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        while (a[ ++ i] < x);
        while (a[ -- j] > x);
        if (i < j) swap(i, j);
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; i ++ )
        scanf("%d", &a[i]);

    quick_sort(l, r);

    for (int i = 0; i < n; i ++ )
        printf("%d ", a[i]);

    return 0;
}
这就完了？

算法 44
三向切分快排 O(nlogn)O(nlogn)
用 ii，jj，kk 三个下标将数组切分成四部分。
a[l,i−1]a[l,i−1] 表示小于 xx 的部分，a[i,k−1]a[i,k−1]表示等于 xx 的部分，a[j+1]a[j+1] 表示大于 xx 的部分，而 a[k,j]a[k,j] 表示未判定的元素（即不知道比 xx 大，还是比中轴元素小）。
同时要注意 a[i]a[i] 始终位于等于 xx 部分的第一个元素，a[i]a[i] 的左边是小于 xx 的部分。

C++C++ 代码
#include <stdio.h>

const int N = 1005;

int a[N];

void swap(int i, int j)
{
    if (i ^ j)
    {
        a[i] ^= a[j];
        a[j] ^= a[i];
        a[i] ^= a[j];
    }
}

void quick_sort_3way(int l, int r)
{
    if(l >= r) return;
    int x = a[l];
    int i = l, j = r, k = l + 1;
    while(k <= j)
        if(a[k] < x)swap(i ++ , k ++ );
        else if(a[k] == x) k ++ ;
        else
        {
            while(a[j] > x)
                if( -- j < k)break;
            if (j < k) break;
            if(a[j] == x)
                swap(k ++ , j -- );
            else
            {
                swap(i ++ , j);
                swap(j -- , k ++ );
            }
        }
    quick_sort_3way(l, i - 1);
    quick_sort_3way(j + 1, r);
}

int main()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; i ++ )
        scanf("%d", &a[i]);

    quick_sort_3way(l, r);

    for (int i = 0; i < n; i ++ )
        printf("%d ", a[i]);

    return 0;
}
算法 55
双轴快排 O(nlogn)O(nlogn)
同样，使用 ii，jj，kk 三个变量将数组分成四部分
同时，使用两个轴，通常选取最左边的元素作为 x1x1 和最右边的元素作 x2x2。
首先要比较这两个轴的大小，如果 x1>x2x1>x2，则交换最左边的元素和最右边的元素，以保证 x1<=x2x1<=x2。

神奇的是y总快排那题的数据把这两种优化过但不取中的快排都卡掉了。。。

C++C++ 代码
#include <stdio.h>

const int N = 1005;

int a[N];

void swap(int i, int j)
{
    if (i ^ j)
    {
        a[i] ^= a[j];
        a[j] ^= a[i];
        a[i] ^= a[j];
    }
}

void quick_sort_2(int l, int r)
{
    if(l >= r) return;
    if(a[l] > a[r]) swap(l, r);
    int x1 = a[l], x2 = a[r];
    int i = l, k = l + 1, j = r;
    while(k < j)
        if(a[k] < x1) swap( ++ i, k ++ );
        else if(a[k] >= x1 && a[k] <= x2) k ++ ;
        else
        {
            while(a[ -- j] > x2)
                if(j <= k) break;
            if (j <= k) break;
            if(a[j] >= x1 && a[j] <= x2)
                swap(k ++ , j);
            else
            {
                swap(j, k);
                swap( ++ i, k ++ );
            }
        }
    swap(l, i),swap(r, j);
    quick_sort_2(l, i - 1);
    quick_sort_2(i + 1, j - 1);
    quick_sort_2(j + 1, r);
}

int main()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; i ++ )
        scanf("%d", &a[i]);

    quick_sort_2(l, r);

    for (int i = 0; i < n; i ++ )
        printf("%d ", a[i]);

    return 0;
}


1.快速排序 quick_sort

#include<iostream>
using namespace std;
const int N=1010;
int a[N];
void quick(int *a,int l,int r)
{
    if(l>=r) return;
    int l1=l-1,r1=r+1;
    int x=a[(l+r)>>1];
    while(l1<r1)
    {
        do l1++;while(a[l1]<x);
        do r1--;while(a[r1]>x);
        if(l1<r1) swap(a[l1],a[r1]);
    }
    quick(a,l,r1),quick(a,r1+1,r);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++) cin>>a[i];
    quick(a,l,r);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}
2.希尔排序 shell_sort

#include<iostream>
using namespace std;
const int N=1010;
int a[N];
void shell(int *a,int l,int r)
{
    int step=1;
    if(step<(r-l+1)/3) step=3*(r-l+1)+1;
    while(step>=1)
    {
        for(int i=l+step;i<=r;i++)
        {
            for (int ii = i; ii - step >= l && a[ii-step]>a[ii]; ii -= step)
                swap(a[ii-step],a[ii]);
        }
        step/=2;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++) cin>>a[i];
    quick(a,l,r);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}
3.冒泡排序(未优化版) bubble_sort

#include<iostream>
using namespace std;
const int N=1010;
int a[N];
void bubble(int *a,int l,int r)
{
    for(int i=0;i<r;i++)//第i+1轮
        for(int j=l;j<r-i;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++) cin>>a[i];
    bubble(a,l,r);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}
4.冒泡排序(优化版) bubble_sort

#include<iostream>
using namespace std;
const int N=1010;
int a[N];
void bubble(int *a,int l,int r)
{
    bool is_order=true;
    for(int i=0;i<r;i++)//第i+1轮
    {
        for(int j=l;j<r-i;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]),is_order=false;
        if(is_order) break;//数组有序,不需要再排
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++) cin>>a[i];
    bubble(a,l,r);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}
5.选择排序 select_sort

#include<iostream>
using namespace std;
const int N=1010;
int a[N];
void select(int *a,int l,int r)
{
  for(int i=l;i<r;i++) 
  {
      int min=i;
      for(int j=i+1;j<=r;j++)
      {
          if(a[j]<a[min]) min=j;
      }
      if(min!=i) swap(a[min],a[i]);
   }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++) cin>>a[i];
    select(a,l,r);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}
6.插入排序 insert_sort

#include<iostream>
using namespace std;
const int N=1010;
int a[N];
void insert(int *a,int l,int r)
{
    for(int i=l+1;i<=r;i++)
    {
        for(int j=i;j-1>=l && a[j-1]>a[j];j--)
            swap(a[j-1],a[j]);
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++) cin>>a[i];
    insert(a,l,r);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}
7.归并排序 merge_sort

#include<iostream>
using namespace std;
const int N=1010;
int a[N],temp[N];
void merge(int a[], int l, int r)
{
    if (l >= r) return ;
    int mid = l+r>>1;
    int t = 0, l1 = l, r1 = mid + 1;
    merge(a, l, mid), merge(a, mid + 1, r);
    while (l1 <= mid && r1 <= r)
        if (a[l1]<a[r1]) temp[t++] = a[l1++];
        else temp[t++] = a[r1++];
    while (l1 <= mid)  temp[t++] = a[l1++];
    while (r1 <= r) temp[t++]=a[r1++];
    for(int i=l,j=0;i<=r;i++,j++) a[i]=temp[j];
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++) cin>>a[i];
    merge(a,l,r);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}


16




