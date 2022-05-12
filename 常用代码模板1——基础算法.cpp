算法基础课相关代码模板
活动链接 —— 算法基础课

dp问题就是状态的表示和计算，表示就是集合+属性，
计算就是集合的划分，要不重不漏，怎么划分呢，寻找最后一个不同点
const int N = x + 10
考试是现实的东西，我们都不能先推大部分都是见过类似的变一下形式
其实就是肌肉记忆，现代应试教育考验的其实就是记忆和毅力，学霸都是记忆力和自制力强
dp的初始化要从状态的定义出发
做题一定要想清楚证明啊，做题一定要严谨，对于70%可以通过直觉来做，剩下的30%可能会错，有些时候一个题想不出来，就是做题偷懒了，有些过程没想清楚，直觉上猜对了，稍微变一下就不会了
熟能生巧，加强肌肉记忆，ac saber搞起来
学习方法的话哈就只有一条，一定要提高自制力，这个是万变不离其宗，老生常谈的一个问题，只要自制力上去了，一切都不是问题
要相信科学，不要相信玄学
算法光靠理解是没用的，过两天就忘了，要多写

离散化：1.保序：排序判重二分
2.不需保序：map/hash表
N×N的棋盘，N为奇数时，与八数码问题相同。逆序奇偶同性可互达
N为偶数时，空格每上下移动一次，奇偶性改变。称空格位置所在的行到目标空格所在的行步数为空格的距离（不计左右距离），若两个状态的可相互到达，则有，两个状态的逆序

奇偶性相同且空格距离为偶数，或者，逆序奇偶性不同且空格距离为奇数数。否则不能。
也就是说，当此表达式成立时，两个状态可相互到达：(状态1奇偶性==状态2奇偶性)==(空格距离%2==0)。
推广到三维N×N×N:
当N为奇数时，N-1和N^2-1均为偶数，也就是任意移动空格逆序奇偶性不变。那么逆序奇偶性相同的两个状态可相互到达。
当N为偶数时，N-1和N^2-1均为奇数，也就是令空格位置到目标状态空格位置的y z方向的距离之和，称为空格距离。若空格距离为偶数，两个逆序奇偶性相同的状态可相互到达；

若空格距离为奇数，两个逆序奇偶性不同的状态可相互到达。
原文链接：https://blog.csdn.net/hnust_xiehonghao/article/details/7951173

【模板】vector + __int128压位高精度
数组的函数传参
一维数组
传递数组给函数的3个原则
1.函数调用时只需传递数组名。
2.在函数定义中，形参的类型必须与数组的相同，数组的大小不必指定。
3.函数原型必须定义为参数是一个数组。
二维数组
1.函数调用时只需传递数组名。
2.在函数定义中，必须使用两个方括号以表明数组为二维的。
3.必须指定数组第二个维的大小。
4.函数原型的定义必须与函数头相同。


基础算法
有单调性一定可以二分，没有单调性可能可以二分
二分的本质是边界，区间可以一分为二，一边满足性质，一边不满足性质
求最小的最大，求最大的最小也常用二分

双指针：O(N^2)通过一定性质转化为O(N)

hash:模数取大于hash数组长度的一个质数（可以提前打表寻找合适的模数），且离2的整数次幂尽量远，删除操作一般不真的删除，打个标记即可
开放寻址法 数组需开2~3倍的空间
拉链法
字符串hash ： 1.进制取P=131或13331，模数取Q=2^64（使用unsigned long long自然溢出即可）时，一般不会发生冲突 2.不要把一个字母映射为0 3.可用O(1)时间判断字符串

是否相等
* ≥x的数中最小的一个 最优极小值
while (l < r)
{
    int mid = l + r >> 1;
    if (a[mid] >= x) r = mid;
    else l = mid + 1;
}
return l;

≤x的数中最大的一个 最优极大值
while (l < r)
{
    int mid = l + r + 1 >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
    }
return l;

二分
适用情况：有单调性的，一定可以二分，没有单调性的也有可能能二分。
应用场景：在一个有序的序列中求一个数
直接上y总给的板子

bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
求极小最优解
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
求极大最优解
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

对板子进行分析：
前提须知：大部分语言都是向下取整的，故在选取边界的时候有可能会发生死循环
二分是维护一个可行区间， 然后找到最优解的过程。
（这里就要分为找极大最优解和极小最优解的两个过程），对应y总的两个板子。y总的板子1是求极小最优解，板子2是求极大最优解。
再求极大最优解过程中，由于一般语言是向下取整的，可能会导致死循环。









































快速排序算法模板 —— 模板题 AcWing 785. 快速排序(面试) 
时间复杂度O（N2）平均时间复杂度O(nlogn)
分治 确定分界点
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);// 右边界是j+1
}


// 解题代码
#include <iostream>
#include <algorithm>                                                                                                              
using namespace std;

const int N = 1e +10;

int n;
int q[N];

void quick_sort(int q[], int l, int r){

   if (l >= r) return;
   while (i < j){
       do i++ ; while (q[i] < x);
       do j-- ; while (q[j] > x);
       if (i < j) swap (q[i], q[j]);
   }
  quick_sort(q, l, j);
  quick_sort(q, j+1, r);
}

int main(){
   scanf("%d", &n);
   for (int i = 0; i < n; i++) scanf("%d", &q[i]);

   quick_sort(q, 0 ,n-1);
   //这里的边界是 n-1

    sort(q, q+n)
   for (int i = 0; i < n; i++) scanf("%d", q[i]);

   return 0;
   // return 0 是代表不符合条件都返0,0为假 非0为真

}

//快排第二种解题代码 注意i j 的左右边界问题
#include <iostream>

using namespace std;
const int N = 1e +10;

int n;
int q[N];

void quick_sort(int q[], int l, int r){

   if (l >= r) return;
   while (i < j){
       do i++ ; while (q[i] < x);
       do j-- ; while (q[j] > x);
       if (i < j) swap (q[i], q[j]);
   }
  quick_sort(q, l, i-1);
  quick_sort(q, i, r);//右边界是i
  //注意不要取到右边界
}

int main(){
   scanf("%d", &n);
   for (int i = 0; i < n; i++) scanf("%d", &q[i]);

   quick_sort(q, 0 ,n-1);
   //这里的边界是 n-1

   return 0;
   // return 0 是代表不符合条件都返0,0为假 非0为真

}



算法1
单向划分，我们选取数组最左边的元素q[l]作为pivot，
之后从左到右扫描数组，将数组划分为小于pivot和大于等于pivot两部分，
之后需要将pivot交换到它对应的位置，注意这一步不能忽略，不然q[l]永远都不会被移动。
最后我们对划分好的子数组进行递归求解。这种划分方式保证了划分完后q[j]就是第j - l + 1大的数
void quick_sort(int q[], int l, int r) 
{
    if (l >= r) return;

    int x = q[l], j = l;
    for (int i = l + 1; i <= r; i ++ ) 
        if (q[i] < x) swap(q[ ++ j], q[i]);

    swap(q[l], q[j]);
    quick_sort(q, l, j - 1);
    quick_sort(q, j + 1, r);
}

算法2
快排算法证明
算法证明使用算法导论里的循环不变式方法
快排模板(以j为分界)
快排属于分治算法，分治算法都有三步：
1. 分成子问题
2. 递归处理子问题 
3. 子问题合并
快排属于分治算法，最怕的就是 n分成0和n，或 n分成n和0,这会造成无限划分
这种双向划分方式就是 Hoare 在最开始的论文中提出的方式 Hoare Partition Scheme。
void quick_sort(int q[], int l, int r)
{
    //递归的终止情况
    if(l >= r) return;
    //第一步：分成子问题
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    //第二步：递归处理子问题
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
    //第三步：子问题合并.快排这一步不需要操作，但归并排序的核心在这一步骤
}

#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100010;
int n, a[N];
void quicksort(int l, int r) {
    // 递归边界条件
    if (l >= r) return;
    // 步骤 ① 中 取中点 方式确定分界点 
    int x = a[l + r >> 1];
    // 步骤 ② 中 设两个指针 i = l - 1, j = r + 1 (处理边界)
    int i = l - 1, j = r + 1;
    // 步骤 ② 中 i左边<=x, j右边>=x 当i,j 相遇时 a[]就被分为2个区间 确定循环条件 i, j 相遇时划分完毕
    while (i < j) {
        // 步骤 ② 中 i向中间走 直到q[i] > x (此时q[i]应该放在右边)
        do i++; while (a[i] < x);
        // 步骤 ② 中 j向中间走 直到q[i] < x (此时q[i]应该放在左边)
        do j--; while (a[j] > x);
        // 步骤 ② 中 此时i, j错位,若i, j未相遇则交换a[i] a[j]
        if (i < j) swap(a[i], a[j]);
    }
    // 递归处理左边区间 边界条件 l >=r 即区间中只剩一个元素时直接返回
    quicksort(l, j);
    // 递归处理右边区间
    quicksort(j + 1, r);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quicksort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}

算法3
c++ STL快速算法
#include <bits/stdc++.h>
using namespace std;
const int N=1000000+100;
int a[N],n,m,i,j;
int main()//C++ Stl使人快乐
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}


算法4
int i = l - 1, j = r + 1 ;
while(i < j)
{
x=q[l];
do i ++; while(q[i] < x);
do j --; while(q[j] > x);
if (i < j) swap(q[i], q[j]);
}
quick_sort(q, l, j);
quick_sort(q, j + 1, r);

想请问下大佬上面这个算法好像也能通过是为什么啊？因为x的值始终在变不会进入死循环吗？（刚学算法的zz无意中打出来的）orz，谢谢！

牛蛙, 无意间就能写出来这种能运行的代码
这个代码第一个 while 循环会选 q[l] 作为轴, 因为 i = l q[i] == q[l]
然后第一个 do while 循环不会执行
然后第二个 do while 循环会从右往左找到第一个 <= q[l] 的值与 q[l] 交换, 然后一直作为新的轴, 因为此时 i > l
相当于你选了从右往左数第一个 <= q[l] 的数作为第二轮及以后循环的轴来划分, 总体上和每次选中间的点来作为轴式一样的
至于更细致的边界情况分析估计也差不多

算法5
将算法改成尾递归，可以使空间严格小于 O(logn)，具体思想是把第一次递归调用改成永远先选长度较小的那一半，第二次递归调用改成循环（即尾递归）。这样由于每次都选较小的那一半，所以每次递归长度至少变小一半，递归栈不会超过 O(logn)
void quick_sort(int q[], int l, int r)
{
    // 将第二次递归改为循环
    while (l < r) {
        int p = partition(q, l, r);
        // 先递归较短的部分,可以把空间优化到O(logn)
        if (p - l < r - p) {
            quick_sort(q, l, p - 1);
            l = p + 1;
        } else {
            quick_sort(q, p + 1, r);
            r = p - 1;
        }
    }
}














快速选择 786. 第k个数
求解第k小的数
1. k <= sl 递归 left 说明第k小的数在左区间 此时递归左区间寻找第k小个的数即可
2. k > sl 递归 right 说明第k小的数在右区间 此时递归右区间寻找第(k-sl)个的数即可
注释：划分完区间后，左区间的数全部<=右区间的数 因为前sl个数都在左边，所以右边的(k-sl)个数就等同于整个序列的第k个小的数
(第k大的数同理)

#include <iostream>
using namespace std;
const int N = 100010;
int n, k, a[N];

int quickfind(int l, int r, int k) {
    // 前半部分和快排完全相同
    if (l >= r) return a[r];
    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    // 求出 SL 的长度（分界点 - 左边界 + 1）
    int SL = j - l + 1;
    // 情况 A
    if (k <= SL) return quickfind(l, j, k);
    // 情况 B
    else return quickfind(j + 1, r, k - SL);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << quickfind(0, n - 1, k) << endl;
    return 0;
}

另外一种快选模板**** 时间复杂度 n
将k值当做物理地址的值，比如第5个数其实就是数组4的位置，第2个数就是数组1的位置.每次只需要判断k在左区间还是右区间，一直递归查找k所在区间
最后只剩一个数时，只会有数组[k]一个数，返回数组[k]的值就是答案
import java.util.Scanner;
public class Main{
    static int N = 100010;
    static int[] A = new int[N];
    static int n, k;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        for(int i = 0; i < n; i++) A[i] = sc.nextInt();

        System.out.println(quickSort(0, n-1, k-1));
    }

    public static int quickSort(int l, int r, int k){
        if(l >= r) return A[k];

        int x = A[l], i = l-1, j = r+1;
        while(i < j) {
            do i++; while(A[i] < x);
            do j--; while(A[j] > x);
            if(i < j) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }

        if(k <= j) return quickSort(l, j, k);
        else return quickSort(j+1, r, k);
    }
}

C++STL实现快选
#include <bits/stdc++.h>
using namespace std;
const int N=1000000 +1000;
int a[N],n,m,i,j,k;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    cout<<a[m];//排序快乐
    return 0;
}
快选和和快排的区别是：
快排每次要递归左右两边
快选每次只要递归一边
这就决定了快排平均 O(NlogN)，快速选择平均 O(N)。






摊还分析
摊还分析是一种分析时间复杂度的方法，主要有三种:
聚合分析(记账法) | 核方法 | 势能法

归并排序算法模板 —— 模板题 AcWing 787. 归并排序
时间复杂度 nlogn
空间复杂度 n
归并属于分治算法，有三个步骤
void merge_sort(int q[], int l, int r)
{
    //递归的终止情况
    if(l >= r) return;

    //第一步：分成子问题
    int mid = l + r >> 1;

    //第二步：递归处理子问题
    merge_sort(q, l, mid ), merge_sort(q, mid + 1, r);

    //第三步：合并子问题
        int k = 0, i = l, j = mid + 1, tmp[r - l + 1];
        while (i <= mid && j <= r)
            if (q[i] <= q[j])
            tmp[k ++] = q[i ++];
            else 
            tmp[k ++] = q[j ++];

        while (i <= mid)
            tmp[k ++] = q[i ++];

        while (j <= r)
            tmp[k ++] = q[j ++];

        for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];

   
}


#include <iostream>
using namespace std;
const int N = 100010;
int n, a[N], temp[N];
void mergesort(int l, int r) {
    // 递归边界 如果区间里面没有元素
    if (l >= r) return;
    // 步骤 ① 确定分界点 mid
    int mid = l + r >> 1;
    // 步骤 ② 递归左右区间
    mergesort(l, mid), mergesort(mid + 1, r);
    // 步骤 ③ 使用2个指针 i = l, j = mid + 1 指向2个数组头  
    int i = l, j = mid + 1;
    // 步骤 ③ 临时数组temp[] 指针k=l（辅助数组temp定义在全局变量里了）
    int k = l;
    // 步骤 ③ 中 比较a[i] a[j] 直到循环终止条件：某个数组到头
    while (i <= mid && j <= r) 
        // 步骤 ③ 若(a[i] <= a[j]) 则temp[k+1] = a[i+1] 使用临时数组记录结果
        if (a[i] <= a[j]) temp[k++] = a[i++];
        // 步骤 ③ 中 若(a[i] > a[j]) 则temp[k+1] = a[i+1] 使用临时数组记录结果
        else temp[k++] = a[j++];
    注释：因为a[l~mid],a[mid+1~r]单调递增 所以两指针指向值的最小值一定是两个序列中的最小值, 此时可以放进临时数组
    // 步骤 ③ 中 当指针未到头，把数组剩余部分接到临时数组后面 当前值插入临时数组（如果左区间还有元素）
    while (i <= mid) temp[k++] = a[i++];
    // 步骤 ③ 当指针未到头，把数组剩余部分接到临时数组后面 当前值插入临时数组（如果右区间还有元素）
    while (j <= r) temp[k++] = a[j++];
    // 步骤 ③ 中 把结果复制回原数组
    for (int i = l; i <= r; i++) a[i] = temp[i];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}


AcWing 788. 逆序对的数量 用归并排序 分治
逆序对：一个数比它后面的数大，就是逆序对
逆序对分三种情况 
1. 两个都在左区间
2. 两个都在右区间
3. 一左一右
在分治后的每一层合并中顺便求出逆序对数量是这个题想法的由来，归并排序分治我们求的是从小到大的顺序，我们所求的逆序对恰好是逆序数量，与归并排序不谋而合。
while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else
        {
            res += mid - i + 1;
            tmp[k ++ ] = q[j ++ ];
        }
例如[3,4,1,2]中q[0]>q[2],则q[0],q[1]都与q[2]成逆序对,而q[mid]与q[i]有mid-i+1个数字，因此逆序对增加mid-i+1

逆序对的数量res=n*(n-1) /2  n=1e5
res=5e9 >INT_MAX=1e9
则 res 为 long long类型


#include <iostream>

using namespace std;

// 注意逆序对数量 int 存不下，要用 long long
typedef long long LL;

const int N = 1e5 + 10;

int a[N], tmp[N];

LL merge_sort(int q[], int l, int r)
{
    if (l >= r) return 0;

    int mid = l + r >> 1;

    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ]; //此时不是逆序对
        else
        {
            res += mid - i + 1; //在归并排序的模板上增加这一句
            //此时是逆序对，并且形成mid-i+1个逆序对
            tmp[k ++ ] = q[j ++ ];
        }
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];

    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    cout << merge_sort(a, 0, n - 1) << endl;

    return 0;
}






整数二分算法模板 —— 模板题 AcWing 789. 数的范围
二分算法属于分治算法，有三个步骤

bool check(int x) {/* ... */} // 检查x是否满足某种性质

右分界点，区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    //第二步：递归处理子问题，用while循环来实现
    while (l < r)
    {
         //第一步：分解成子问题,这是二分的核心--范围减半
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    //向左边找 if判断mid是否满足性质，注意该性质会划分数组的右边部分
        else l = mid + 1;//向右边找
    }
    //第三步：合并子问题.对二分算法来说，不需要这一步
    return l;//l就是寻找的右分界点,如果数组中没有要找的点，l的值就是r,但这是一个错误答案
} 

左分界点，区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1; // mid 向上取整
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

对于排好序数组 {1 2 3 4 5 6}
右分界点：对于二分的性质 ">=3"，数组分成 {1 2} 和 {3 4 5 6} 两部分，左边部分不满足性质 ">=3"，右边部分满足性质 ">=3"，算法寻找的点是数组元素 3 的下标
左分界点:对于二分的性质 "<3"，数组分成 {1 2} 和 {3 4 5 6} 两部分，右边部分不满足性质 "<3"，左边部分满足性质 "<3"，算法寻找的点是数组元素2的下标


// 解题代码
# include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int q[n];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);

      while (m --)
      {
        int x;
        scanf("&d", &x);
       
        int l = 0; r = n-1;
        // q[mid] >= x找的就是最前面的x 当找到一个小于x的数它的右边就是最前面的x 同样q[mid] <= x找的是最后一位x 当找到一位大于x的 它的左边就是最后一位x 当然 上述都是在x存在的情况下发生的
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= x) r = mid;
            else l = mid + 1;
        }
        
        if (q[l] != x) cout << "-1 -1" << endl;
           // 说明此时 x 不存在 用l 或 r 一样的 因为while循环结束  l和 r相等
           else 
          {
              cout << l  << ' ';
       

            int l = 0; r = n - 1;
            while (l < r)
            {
               int mid = l + r + 1 >> 1;
            //此时l = mid 需要加1 这是背熟的
            //+1 是为了防止指针在区间递归的死循环
               if (q[mid] <= x) l= mid;
               else r = mid - 1;
            }
           cout << l << endl;
          }

            return 0;
      }
    }

}

https://www.acwing.com/solution/content/10783/
#include <iostream>
using namespace std;
const int N = 100010;
int n, m, temp, a[N];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (m--) {
        // temp 为要查找的值
        cin >> temp;
        // 定义边界
        右边界点
        int l = 0, r = n - 1;
        while (l < r) {
            // 做法第 1 步: A: 找中间值 mid = l + r >> 1
            int mid = l + r >> 1;
            // 做法第 1 步: B: 判断mid是否满足>=3的性质
            满足：说明mid~r之间都>=3,此时答案可能包含mid，所以更新区间r=mid 即在l~mid中找到答案
            if (a[mid] >= temp) r = mid;
            不满足：说明l~mid之间都<3 且答案不可能为mid 所以答案不包含mid，更新区间 l=mid+1 即在mid+1~r中找答案
            else l = mid + 1;
        }
        // 如果二分出来的值不等于要找的值，说明不存在
        当二分出答案下标对应数不是要找的值时，无解
        if (a[r] != temp) cout << "-1 -1" << endl;

        else {
            // 输出左边界
            cout << r << " ";
            
            左边界点
            l = 0, r = n - 1;
            while (l < r) {
                
                // 做法第 2 步: A: 找中间值
                int mid = l + r + 1 >> 1;
                // 做法第 2 步: B: 判断mid是否满足<=3的性质
                满足：说明mid~r之间都<=3,此时答案可能包含mid，所以更新区间l=mid 即在mid~r中找到答案
                if (a[mid] <= temp) l = mid;
                不满足：说明l~mid之间都>3 且答案不可能为mid 所以答案不包含mid，更新区间 r=mid+1 即在l~mid+1中找答案 
                else r = mid - 1;
            }
            cout << r << endl;
        }
    }
    return 0;
}


浮点数二分算法模板 —— 模板题 AcWing 790. 数的三次方根
浮点数二分算法和整数的两种算法一摸一样，只不过不需要考虑向上取整还是向下取整，以及边界处理

bool check(double x) {/* ... */} // 检查x是否满足某种性质

浮点数寻找右分界点
double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度 取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;//这里不需要考虑取整，因为是浮点数
        if (check(mid)) r = mid;//这里不需要考虑 +1 -1 之类的，因为是浮点数
        else l = mid;
    }
    return l;
}

浮点数寻找左分界点
double bsearch_4(double l, double r)
{
    while (r - l > 精度)
    {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;    //只有这两个地方与上面的模板相反，其余都一样
        else r = mid;
    }
    return l;
}


#include <iostream>
using namespace std;

// const int N = 1e-8; 如果用int 那么浮点数1e-8就变成0 在之后的判断中 r - l > 0会永远成立 所以会一直循环,TLE

int main()
{
// double和float的计算代价相差无几 事实上 对于某些机器来说 双精度甚至比单精度还快 所以c++一般选择双精度 
    double x;
    cin >> x;
    // 确定边界值
    double l = -100000, r = 100000;
    // 注意循环条件处理精度问题
    while (r - l > 1e-8)
    // 比的是精度 不能用 r > l 因为差小于1e6就可以认为是一个数 比如1.0000001和1.0000002
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        // 一般比较double的时候 都要加上误差 不过这里比较特殊  如果由于精度问题误判了  说明mid已经非常接近答案了  那么不论进到左边还是右边  mid都会在区间里  是没有问题的。
        else l = mid;
    }
// cout默认输出两位小数 可以通过一些方法控制输出的小数位数 但是没有printf方便
    printf("%.6lf\n", l);
    return 0;
}









高精度加法 —— 模板题 AcWing 791. 高精度加法(只有C++需要,笔试偶尔出现)
手动模拟人类在列竖式算加法的过程
竖式计算的方法：
1. 从低位算起。所以我们在把这些字符存进 vector 时要倒叙存储。
2. 注意加法结果要模 10存下来，整十部分进位。
https://www.acwing.com/solution/content/26173/
实际上每次都是3个数相加 A+B+t

C = A + B, A >= 0, B >= 0 两个整数大数相加，长度<=10^6
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}

// 解题代码 
不压位的代码 两个整数大数相加，长度<=10^6
#include <iostream>
#include <vector>

using namespace std;
vector<int> add(vector<int> &A, vector<int> &B) //加上引用是为了提高效率, 就不需要拷贝整个数组了
{
    if (A.size() < B.size()) return add(B, A)

     vector<int> C;
     int t = 0;
     for (int i  = 0; i < A.size(); i ++) 
     {
         t += A[i];
         if (i < B.size()) t += B[i];
         C.push_back(t % 10);
         t /= 10;
     }

     if (t) C.push_back(t);
     return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0';)
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i --) cout << C[i];
    cout << endl;

    return 0;
 }

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-6;

string a, b;
vector<int> A, B;

vector<int> add(vector<int> &A, vector<int> &B) { //加上引用是为了提高效率, 就不需要拷贝整个数组了
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) { // 模拟一个加法的过程
        if (i < A.size()) {
            t += A[i];
        }
        if (i < B.size()) {
            t += B[i];
        }
        // 此时的t是A[i]+B[i]+ (前一位A[i-1]和B[i-1]是否有进位,有就+1,无则0)
        C.push_back(t % 10); //最终答案的当前位为 t的个位
        t /= 10; //用于下一个位(A[i+1],B[i+1]) 是否有进位--> 每次循环, 都用t+A+B
    }
    if (t) { //如果最高位有进位, 那么添上1
        C.push_back(1);
    }
    return C;
}

int main() {
    ios;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0'); //减去一个偏移量 => b[i]这个字符表示的数字
    }
    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--) { //因为是倒着存的, 因此要倒着输出
        cout << C[i];
    }
    cout << endl;
    return 0;
}


压9位的代码 两个整数大数相加，长度<=10^9
#include <iostream>
#include <vector>

using namespace std;

const int base = 1000000000;
//加10是为了防止边界出错

// C = A + B
vector<int> add(vector<int> &A, vector<int> &B)
//& 引用地址 这样就不会copy数组了 减少时间
{
  //if (A.size()< B.size()) return add(B, A);

  vector<int> C;
  int t = 0;//t 是进位的数字
  for (int i = 0; i < A.size() || i < B.size; i ++) // 模拟一个加法的过程,从末位开始进位
  {
      if (i < A.size()) t += A[i];
      if (i < B.size()) t += B[i];
    // 此时的t是A[i]+B[i]+ (前一位A[i-1]和B[i-1]是否有进位,有就+1,无则0)
      C.push_back(t % 10);//最终答案的当前位为 t的个位
      t /= base; //用于下一个位(A[i+1],B[i+1]) 是否有进位--> 每次循环, 都用t+A+B
    //这里已经判断了 A和B 谁更加长 所以可以少一步判断谁长
  }
 if (t) C.push_back(1);// 最高位如果有进位就补上1
 return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b; //a = "123456"

    for (int i = a.size() - 1; s = 0, j = 0, t = 1; i >= 0; i --) //因为是倒着存的, 因此要倒着输出
    {
        s += (a[i] - '0') * t;
        j ++, t *= 10;
        if (j == 9 || i == 0)
        {
            A.push_back(s);
            // 类似整数拆成单个数一样。比如12345 = 1 * 10000 + 2 * 1000 + 3 * 100 + 4 * 10 + 5 * 1. s不断变化  最后把s存进数组。
            s = j = 0;
            t = 1;
        }

    }
   
   // a[i] 现在是字母。要把字母转变为数字 A= [6, 5, 4, 3, 2, 1]
    for (int i = b.size() - 1; s = 0, j = 0, t = 1; i >= 0; i --)
    {
        //类似整数拆成单个数一样。比如12345 = 1 * 10000 + 2 * 1000 + 3 * 100 + 4 * 10 + 5 * 1. s不断变化  最后把s存进数组。
        s += (b[i] - '0') * t;
        j ++ , t *= 10;
        if (j == 9 || i == 0)
        {
            B.push_back(s);
            s = j = 0;
            t = 1;
        }
    }
     
    
    auto C = add(A, B);
    // 通过自动识别 add 函数返回类型来创建对象 C 等价于 vector<int>
    cout << C.back();
    // 用size() - 2 而不是 size() - 1
    //C.back()是最高位 提前输出了
    //因为需要每个数(9位)输出一次 如果不足9位就要补前导0 但是第一个数即使不足9位也不需要补前导0 所以可以直接输出。可以试一下从C.size()-1输出 看一下就明白了
    for (int i = C.size() - 2; i >= 0; i --) printf("%09d", c[i]);
    cout << endl;

    return 0;
}
//压8位的意思是将高精度整数转化成数组时 数组中的每个数存储8位。这样数组的长度会缩小到原来的 1/8 (没个数是8位 空间少了 数组长度位原来的1/8)
//上面的代码中 数组里每一个数存0~9 压8位就是每个数存0~99999999。这样数组长度会缩小到八分之一

#include <iostream>
#include <vector>

using namespace std;

const int base = 1e9;

vector<int> add(vector<int>& A, vector<int>& B)
{
    if (A.size() < B.size()) {
        return add(B, A);
    }

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) {
            t += B[i];
        }
        C.push_back(t % base);
        t /= base;
    }
    if (t) {
        C.push_back(t);
    }

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;

    for (int i = a.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--) {
        s += (a[i] - '0') * t;
        j++, t *= 10;
        if (j == 9 || i == 0) {
            A.push_back(s);
            s = j = 0;
            t = 1;
        }
    }

    for (int i = b.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--) {
        s += (b[i] - '0') * t;
        j++, t *= 10;
        if (j == 9 || i == 0) {
            B.push_back(s);
            s = j = 0;
            t = 1;
        }
    }

    auto C = add(A, B);

    cout << C.back();
    for (int i = C.size() - 2; i >= 0; i--) {
        printf("%09d", C[i]);
    }
    cout << endl;

    return 0;
}


高精度减法 —— 模板题 AcWing 792. 高精度减法
1、模拟减法规则，从个位到高位进行相减，若个位不够减则向上一个高位借1
2、sub(A,B)函数中，C = A - B, 若A >= B 则求A - B，否则A < B 则求(B - A),最后再把'-'号添上
3、若遍历完整个A，需要将最靠左的且为 0 的高位全部去除掉(前导0的处理)
对于 t = A[i] - B[i] - t 可以拆为 t = A[i] - t 如果B[i]合法，再t -= B[i] 这么两步来做
相减后t的处理 ，把 t >=0 和 t < 0 用一个式子来表示 t = (t + 10) % 10

C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

解题代码
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10;
//加10是为了防止边界出错

//判断是否有 A >= B
//现在cmp不加引用号会被一个大数卡住 输出多了一个负号
bool cmp(vector<int> &A, vector<int> &B)
{
   if (A.size() != B.size()) return A.size() > B.size()

   //从高位开始比
   for (int i = A.size() -1; i >= 0; i --)
      if (A[i] != B[i])
      return A[i] > B[i];
    return true;
    // 这里的return true 是表示对于A和B相等的情况 避免输出负号
}

 C = A - B  两个整数大数相减，长度<=10^6
vector<int> sub(vector<int> &A, vector<int> &B)
{
  vector<int> C;
  for (int i = 0, t =0; i < A.size(); i ++)
  {
      t = A[i] - t;
      //判断是否借位
      if (i < B.size() ) t -= B[i];//要判断A和B的大小
      C.push_back((t + 10) % 10);//t>= 0时 t为t t < 0 时 t为 t+10
      if (t < 0) t = 1;//判断 t < 0时 为真 反之为假 if是真假判断
      else t = 0;
  }

  while (C.size() > 1 && C.back() == 0) C.pop_back();
  //如果C为101-100 则把开头的两个0去掉 去掉前导0
  
  return C;
}

int main()
{
    string a, b;// a, b 是要相加的数
    vector<int> A, B;// A, B是倒置过来的vector容器

    cin >> a >> b;// a = "123456" 由于边界是 1e6 因此a最多是6位的数字

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');//A = [6, 5, 4, 3, 2, 1]
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    //string 直接比较不是按照字典序比较的 这样判断的话 51是大于211的

    vector<int> C;

    if (cmp(A, B)) C = sub(A, B);
    else C = sub(B, A), cout << '-';

    for (int i = C.size() - 1; i >= 0; i --) cout << c[i];
    cout << endl;

    return 0;  

}

如果有负数 一定可以转换为绝对值的比较 |A| |B|
绝对值的相减相加，再加标志，标志由输入来决定，判断一下字符串的首字符的类型

if (cmp(A, B))
{
    auto C = sub(A, B);

    for (int i = C.size() - 1; i >= 0; i --) printf ("%d",c[i]);
}
    else
{
    auto C = sub(B, A);
    printf("-");
    for (int i = C.size() - 1; i >= 0; i --) printf ("%d",c[i]);
// %d 有范围 是 int的范围
}

for (int i = C.size() - 1; i >= 0; i --) printf ("%d",c[i]);
return 0;

加减乘除都是可以压位的 比如压8位 就把代码里所有的 10^6 改成 10^8 就可以了
照着压位加法 将“C.push_back((t + 10) % 10);” 改成“C.push_back((t + base) % base);”然后读数据压位就可以了。



高精度乘低精度 —— 模板题 AcWing 793. 高精度乘法
算法分析
此处 A 是高精度的字符串， B 是整数
1、模拟乘法规则，从A的个位到高位与B相乘，乘得的结果放入t中，则此位的数为t % 10.把t/10剩余给下一个高位
2、若遍历完整个A，t > 0,则表示还有剩余的数，则需要将剩余的数继续补到下一个高位

C = A * b, A >= 0, b >= 0 一个大整数乘上一个小整数
A<=10^9, b <= 10^6
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10); https://www.acwing.com/solution/content/26181/ 看图
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    //用来考虑b=0的情况 如果b!=0是不是就不用加

    return C;
}

 解题代码
#include<iostream>
#include<vector>

using namespace std;

vector<int> mul(vector<int> &A,int b)
{
    int t=0;
    vector<int> C;
    for(int i=0;i<A.size();i++)
    {
        t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    while(t) //t有很大可能会留有剩余
    {
        C.push_back(t%10);
        t/=10;
    }

    return C;
}

int main()
{
    string a;
    int b;
    cin>>a>>b;

    vector<int> A,C;
    for(int i=a.size()-1;i>=0;i--)
    A.push_back(a[i]-'0');

    //考虑b等于的零的情况
    if(b) C=mul(A,b);
    else C.push_back(0);

    for(int i=C.size()-1;i>=0;i--)
    printf("%d",C[i]);

    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || t; i ++)//要么是i < A.size()  要么是 t
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;//接下来要对t 进行讨论 多种情况 
    }
    
}
//最开始个位是没有进位的  t 的数字为0

int main()
{
    string a;// a很长 用string b 很短 用int
    int b;//把较小的数字当成是一个整体 对其整体进行乘法

    cin >> a >> b;

    vector<int> A;

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');//a[i]是一个字符 要把他转变成一个真实的数字 所以用'9' - '0' 来表达真实的字符

    auto C = mul(A,b);

    for (int i = C.size() -1; i >= 0; i --) printf("%d", C[i]);

    return 0;
}


高精度除以低精度 —— 模板题 AcWing 794. 高精度除法
https://www.acwing.com/solution/content/26192/ 看图

// A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

// 解题代码
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A / b 商是C 余数是r
vector<int> div(vector<int> &A, int b, int &r)//r是通过引用传回去的 直接引用r 在函数里r会改变 在主函数里r也会随之改变 传入r的地址，便于直接对余数r进行修改
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i --)//从最高位开始算
    {
        r = r * 10 + A[i];//为了从123和4构造1234 将上次的余数*10在加上当前位的数字，便是该位需要除的被除数
        C.push_back(r / b); //所得的值就是商在这一位的数字
        r %= b;
    }
    //由于在除法运算中，高位到低位运算，因此C的前导零都在vector的前面而不是尾部，vector只有删除最后一个数字pop_back是常数复杂度，而对于删除第一位没有相应的库函数可以使用，而且删除第一位，其余位也要前移，
    //因此我们将C翻转，这样0就位于数组尾部，可以使用pop函数删除前导0
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back == 0) C.pop_back();//商可能存在先导0, 将0去掉

    return C;
}

int main()
{
    string a;
    vector<int> A;

    int B;
    cin >> a >> B;

    
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');//注意这次的A是由高为传输至低位，在除法的运算过程中从高位进行处理

    int r;
    auto C = div(A, B, r);

    for (int i = C.size() - 1; i >= 0; i --) 
    cout << C[i]; //将C从最高位传给最低位
    //printf("%d", C[i]);

    cout << endl << r << endl;//输出余数r

    return 0;
}

大数相加A+B和大数相乘A*B通用模板
https://www.acwing.com/solution/content/13694/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> add(vector<int> A, vector<int> B) {
    // A: 4 3 2 1
    // B: 6 5
    vector<int> C(max(A.size(), B.size()) + 7, 0);  // 数组C开大一点没事，反正可以去前导零的
    for (int i = 0; i < A.size(); i ++) C[i] += A[i];
    for (int i = 0; i < B.size(); i ++) C[i] += B[i];

    // 处理进位
    for (int i = 0; i + 1 < C.size(); i ++) {
        C[i + 1] += C[i] / 10;
        C[i] %= 10;
    }

    // 处理前导零
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    reverse(C.begin(), C.end());
    return C;
}

vector<int> mul(vector<int> A, vector<int> B) {
    // A: 4 3 2 1
    // B: 6 5
    vector<int> C(A.size() + B.size() + 7, 0);  // 数组C开大一点没事，反正可以去前导零的
    for (int i = 0; i < A.size(); i ++) {
        for (int j = 0; j < B.size(); j ++) {
            C[i + j] += A[i] * B[j];
        }
    }

    // 处理进位
    for (int i = 0; i + 1 < C.size(); i ++) {
        C[i + 1] += C[i] / 10;
        C[i] %= 10;
    }

    // 处理前导零 "0000" 去掉前导零
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    reverse(C.begin(), C.end());
    return C;
}

int main() {
    string s1 = "9899", s2 = "100";

    vector<int> A, B;
    for (int i = s1.size() - 1; i >= 0; i --) A.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i --) B.push_back(s2[i] - '0');

    vector<int> C = add(A, B);
    cout << s1 << "+" << s2 << "=";
    for (int i = 0; i < C.size(); i ++) cout << C[i];
    cout << endl;

    C = mul(A, B);
    cout << s1 << "*" << s2 << "=";
    for (int i = 0; i < C.size(); i ++) cout << C[i];
    cout << endl;

    return 0;
}

















前缀和 和 差分 是逆运算
 Sr - Sl-1 
[1-10] S10 - S0
[1-x] Sx - S0
设前缀和数组为s，原数组为a 则s是a的前缀和数组，a为s的差分数组


一维前缀和 —— 模板题 AcWing 795. 前缀和
一维前缀和，多用于求区间和，能将O(n)的时间复杂度转换为O(1)
关键代码在于求区间和：

S[i]代表数组a中前i个数的和
S[i] = a[1] + a[2] + ... a[i]// 下标从a[1]开始

S[r] = a[1] + a[2] + a[3] + ... + a[r]
s[l-1] = a[1] + a[2] + ... + a[l - 1]
** S[r] - S[l - 1] = a[l] + ... + a[r] 
l 和 r的区间和为：s[r] - s[l - 1] 

// 解题代码
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main()
{


    scanf("%d%d", &n, &m);
    前缀和与差分的for循环 i的下标从1开始
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    //构造前缀和 
    for (int i = 1; i <= n; i ++) s[i] = s [i - 1] + a[i];
    // 前缀和的初始化 初始化 s[i] S[i] = a[1] + a[2] + ... a[i]

    while (m --)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - r]);
        //区间和的计算
    }

    return 0;
}

天梯爱好者可以采用以下快速模板，能把时间减少至40秒以内。
#include<iostream>
using namespace std;
const int N = 100010;
int n,m,a[N],s[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    while(m--)
    {
        int l,r;cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
    }
}


二维前缀和 —— 模板题 AcWing 796. 子矩阵的和
看图 https://www.acwing.com/solution/content/27301/
S[i, j] = 第i行j列格子左上部分所有元素的和
以(x1, y1)为左上角 (x2, y2)为右下角的子矩阵的和为：
S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]

// 解题代码
#include <iostream>

using namespace std;

const int N = 1010;

int n, m, q;
int s[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i ++)
       for (int j = 1; j <= m; j ++)
         scanf("%d", &s[i][j]);

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j++)
          s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    while (q --)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d", &x1, &y1, &x2, &y2);
        printf("&d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }     
           
    return 0;     
}


快速写法
#include<iostream>
using namespace std;
const int N = 1010;
int n,m,q,a[N][N],s[N][N];
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<s[x2][y2]-s[x1 - 1][y2]-s[x2][y1-1]+s[x1-1][y1-1] << endl;
    }
}

 135. 最大子序和
https://www.acwing.com/solution/content/28015/ 看解析
单调队列算法


一维差分 —— 模板题 AcWing 797. 差分
解析
https://www.acwing.com/solution/content/26588/
b[]是差分矩阵
a[0] = 0;
b[1] = a[1] - a[0];
b[2] = a[2] - a[1];
b[3] = a[3] - a[2];
...
b[n] = a[n] - a[n-1];
只要有b数组，通过前缀和运算，就可以在O(n) 的时间内得到a数组 。


给定区间[l ,r ]，让我们把a数组中的[ l, r]区间中的每一个数都加上c,即 a[l] + c , a[l+1] + c , a[l+2] + c ,,,,,, a[r] + c;

只需对差分数组b做 b[l] + = c, b[r+1] - = c。时间复杂度为O(1), 大大提高了效率。给区间[l, r]中的每个数加上c：B[l] += c, B[r + 1] -= c  这段解析看https://www.acwing.com/solution/content/26588/

差分 时间复杂度 o(m)
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i] - a[i - 1];      //构建差分数组
    }
    int l, r, c;
    while (m--)
    {
        scanf("%d%d%d", &l, &r, &c);
        b[l] += c;     //将序列中[l, r]之间的每个数都加上c
        b[r + 1] -= c; // [r+1, ]区间的每个数都减去c
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] + a[i - 1];    //前缀和运算
        printf("%d ", a[i]);
    }
    return 0;
}

y总解题代码
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    scanf("&d&d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) insert(i, i, a[i]);
    while (m --)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r,&c);
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i ++) b[i] += b[i - 1];
    for (int i = 1; i <= n; i++) printf("%d", b[i]);

    return 0;
}

快速模板：
#include<iostream>
using namespace std;
const int N = 100010;
int n,m,a[N],s[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]+=a[i];
        s[i+1]-=a[i];
    }
    while(m--)
    {
        int l,r,c;
        cin>>l>>r>>c;
        s[l]+=c;
        s[r+1]-=c;
    }
    for(int i=1;i<=n;i++)
    {
        s[i]+=s[i-1];
        cout<<s[i]<<' ';
    }
}


二维差分 —— 模板题 AcWing 798. 差分矩阵
解析 https://www.acwing.com/solution/content/27325/

a[][]数组是b[][]数组的前缀和数组，那么b[][]是a[][]的差分数组
原数组： a[i][j]
构造差分数组： b[i][j] 使得a数组中a[i][j]是b数组左上角(1,1)到右下角(i,j)所包围矩形元素的和。


始终要记得，a数组是b数组的前缀和数组，比如对b数组的b[i][j]的修改，会影响到a数组中从a[i][j]及往后的每一个数。

假定我们已经构造好了b数组，类比一维差分，我们执行以下操作
来使被选中的子矩阵中的每个元素的值加上c
b[x1][y1] + = c;
b[x1,][y2+1] - = c;
b[x2+1][y1] - = c;
b[x2+1][y2+1] + = c;
该过程等价于
for(int i=x1;i<=x2;i++)
  for(int j=y1;j<=y2;j++)
    a[i][j]+=c;

给以(x1, y1)为左上角 (x2, y2)为右下角的子矩阵中的所有元素加上c：
S[x1, y1] += c, S[x2 + 1, y1] -= c, S[x1, y2 + 1] -= c, S[x2 + 1, y2 + 1] += c

解题代码
#include <iostream>

using namespace std;

int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
    // 对b数组执行插入操作，等价于对a数组中的(x1,y1)到(x2,y2)之间的元素都加上了c
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
  
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i ++)
      for (int j = 1; j <= m; j ++)
         scanf("%d", &a[i][j]);
    
    for (int i = 1; i <= n; i ++)
      for (int j = 1; j <= m; j ++)
          insert(i, j, i, j, a[i][j]); //构建差分数组
          //每次让以(i,j)为左上角到以(i,j)为右下角面积内元素(其实就是一个小方格的面积)去插入 c=a[i][j]，等价于原数组a中(i,j) 到(i,j)范围内 加上了 a[i][j] ,因此执行n*m次插入操作，就成功构建了差分b数组.

    while (q --)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i ++)
      for (int j = 1; j <= m; j ++)
         b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++) printf("%d", b[i][j]);
        puts("");
    }

    return 0;
}


快速模板：
#include<iostream>
using namespace std;
const int N = 1010;
int n,m,q,a[N][N],b[N][N];
void add(int x1,int y1,int x2,int y2, int c)
{
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main()
{
    cin >> n >> m >> q;
    for(int i = 1; i<= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            cin >> a[i][j];
            add(i,j,i,j,a[i][j]);
        }
    while(q --)
    {
        int x1,y1,x2,y2,c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        add(x1, y1, x2 ,y2,c);
    }
    for(int i = 1; i <= n; i ++, cout<<endl)
        for(int j = 1; j <= m; j ++)
        {
            b[i][j] += b[i-1][j] + b[i][j - 1] -b[i - 1][j - 1];
            cout<<b[i][j]<<' ';
        }
}
抽风大佬提供超短板子：
#include <iostream>
using namespace std;
const int N=1005;
int a[N][N],b[N][N];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    while(k--)
    {
        int x1,x2,y1,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        b[x1][y1]+=c;
        b[x2+1][y1]-=c;
        b[x1][y2+1]-=c;
        b[x2+1][y2+1]+=c;
    }
    for(int i=1;i<=n;i++,puts("")) // 牛逼
        for(int j=1;j<=m;j++)
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1],printf("%d ",a[i][j]+b[i][j]);
    return 0;
}















双指针算法 —— 模板题 
常见问题分类：
    (1) 对于一个序列 用两个指针维护一段区间
    (2) 对于两个序列 维护某种次序 比如归并排序中合并两个有序序列的操作
双指针算法有两类：
    (1) 两个指针指向一个序列(快排)  快慢指针
    (2) 两个指针分别指向不同的序列(归并排序) 对撞指针

for (int i = 0, j = 0; i < n; i ++ )
{
    while (j < i && check(i, j)) j ++ ;

    // 具体问题的逻辑
}

所有的双指针算法都是O（n）的，将朴素算法优化到O（n）

一般写双指针的时候， 可以先写一个朴素做法
有思路之后再对暴力解法进行优化



AcWIng 799. 最长连续不重复子序列
此题i指针是快指针，j指针是慢指针 
i 指针在 j 指针的后面， i是遍历的整个数组的，j 是遍历 0 到 i 的
i 和 j 指针都是从前移到后，也就是计算2n次。时间复杂度是O(2n)

引出一个check函数：对于寻找是否有重复数字，一般用hash，没人用暴力。所以用hash就可以计算。

(1)每当i指针右移一位的时候，
  其对应的元素的个数就需要++，可以看出此处需要一个计数的数组或者unordered_map<int, int>，
  如果是字符串或者字符等元素的话 建议用unordered_map<int, int>

(2)check函数 实现功能是，当s[a[i]]>1，就持续j++，
  并且将s[a[j]]--，这一步绝对不能省。

(3) res = max(res, i - j + 1)


核心思路：
(1)遍历数组a中的每一个元素a[i], 对于每一个i，找到j使得双指针[j, i]维护的是以a[i]结尾的最长连续不重复子序列，长度为i - j + 1, 将这一长度与r的较大者更新给r。
(2)对于每一个i，如何确定j的位置：由于[j, i - 1]是前一步得到的最长连续不重复子序列，所以如果[j, i]中有重复元素，一定是a[i]，因此右移j直到a[i]不重复为止（由于[j, i - 1]已经是前一步的最优解，此时j只可能右移以剔除重复元素a[i]，不可能左移增加元素，因此，j具有“单调性”、本题可用双指针降低复杂度）。
(3)用数组s记录子序列a[j ~ i]中各元素出现次数，遍历过程中对于每一个i有四步操作：
    cin元素a[i] -> 
    将a[i]出现次数s[a[i]]加1 -> 
    若a[i]重复则右移j（s[a[j]]要减1） -> 
    确定j及更新当前长度i - j + 1给r。
(4)当a[i]重复时，先把a[j]次数减1，再右移j。


记 最长连续不重复子序列 为C，
[j, i]表示当前C，长度是i - j + 1。
i指针用于遍历数组a，当发生重复，一定是a[i]与前面的a[k]相等，其中j <= k <= i - 1。
若发生重复，用i指针来清除[j, k]范围内的数组a的值在数组count中的标记，确保数组count只记录[j, i]即当前C中出现的数字。
由于无从得知这个C的起始下标和结束下标，因此每轮循环对ans的值与当前C的长度i - j + 1取max。

解题代码
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], s[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);

    int res = 0;
    for (int i = 0, j = 0; i < n; i ++);****
    {
        s[q[i]] ++ ;每次新加入一个数 新加数有重复 肯定是q[i]
        while (j < i && s[q[i]] > 1) s[q[j ++]] -- ; *****// 先减次数后右移 j一定是向前走的 区间[j, i] 具有单调性
        res = max(res, i - j +1);

    }

    cout >> res >> endl;

    return 0;
}


双指针经典例子：输出单词
输入： I love you
输出： I 
      love 
      you

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getline(cin, str);
    for (int i = 0; i <str.size(); i ++)
    {
        int j = i;
        while (j <str.size() && str[j] != ' ')
        {
            j ++;
        }
        for (int k = i; k < j; k ++)
        {
            cout << str[k];
        }
        cout << endl;
        i = j;
    }
    return 0;
}
j从0~n-1枚举
i表示往左最远可以到达的地方

一般写双指针的时候， 可以先写一个朴素做法
for (int i = 0; i < n; i ++)
{
    for (int j = i; j < n; j ++)
    {
        if (check(j, i))
        {
            res = max(res, i - j + 1);
        }
    }
}

AcWing 800. 数组元素的目标和
A，B单调递增，则显然，A[i+1]+B[j]>A[i]+B[j]>X。因此，指针j应该向j-1方向搜索
本题具有单调性
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

int main()
{
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i ++) scanf("%d", &b[i]);

    for  (int i = 0, j = m - 1; i < n; i ++)
    {
        while (j >= 0 && a[i] + b[j] > x) j -- ;
        if (j >= 0 && a[i] + b[j] == x) cout << i << ' ' << j << endl; 
    }
    
    return 0;
}

acwing 2816. 判断子序列
双指针算法
1.j指针用来扫描整个b数组，i指针用来扫描a数组。若发现a[i]==b[j]，则让i指针后移一位。
2.整个过程中，j指针不断后移，而i指针只有当匹配成功时才后移一位，若最后若i==n，则说明匹配成功。
为什么双指针做法是正确的？
整个过程中j指针不断扫描b数组并且向后移动，相当于不断给i指针所指向的a数组创建匹配的机会，只有匹配成功时i指针才会向后移动一位，当i==n时，说明全部匹配成功。
int i = 0;
for (int j = 0; j < m; j ++)
{
    if (i < n && a[i] == b[j]) i ++;
}
if (i == n) puts("Yes");
else puts("NO");
https://www.acwing.com/solution/content/25506/ 看解析图

#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n; i++) scanf("%d",&a[i]);
    for(int j = 0;j < m; j++) scanf("%d",&b[j]);

    int i = 0;
    for(int j = 0;j < m; j++)
    {
        if(i < n&&a[i] == b[j])  i++;
    }
    if(i == n) puts("Yes");
    else puts("No");
    return 0;
}









位运算 —— 模板题 AcWing 801. 二进制中1的个数

算法1 暴力枚举
思路：对于每个数字a，a&1得到了该数字的最后一位，之后将a右移一位，直到位0，就得到了1的个数
#include<iostream>
using namespace std;
int n;
int a,k;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        k=0;
        while(a){
            k+=a&1;
            a=a>>1;
        }
        printf("%d ",k);
    }
    return 0;
}


算法2： lowbit  O(nlogn)
在程序运行时，数据用的都是补码
原码：用最高位表示符号位，‘1’表示负号，‘0’表示正号。其他位存放该数的二进制的绝对值 1010 即（0*2^2）+（1*2^1）+（0*2^0）=2  最高位为‘1’,表示这是一个负数则 1010为-2
反码：正数的反码还是等于原码，负数的反码就是他的原码除符号位外，按位取反。
1010为-2 去掉最高位的1，为010，再取反，101，再加上最高位的1 1101
补码：正数的补码等于他的原码， 负数的补码等于反码+1。也等于正数反码+1。

lowbit(x)是x的二进制表达式中最低位的1所对应的值。

假设 x = 9 即 0 1001
对二进制每个数取反（取反不等于反码）再+1
1 0111= 1 0110 + 1
-x = ~x + 1
此时只有lowbit与原二进制相同，
此时再与原数字相与
x & -x = x & (~x + 1)
即可得到lowbit(n)
int lowbit(int x)
{
    return x & -x;
    //-x = ~x + 1 //(x取反加1)
}

x>>k表示右移k位
x&1代表最低位的值(最右位的值)

核心：
(1)先把第k位移到最后一位 x = n >> k
(2) 看最后一位是多少 x & 1
结合以上 n >> k & 1
返回n的最后一位1：lowbit(n) = n & -n
解题代码
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int x, s = 0;
        scanf("%d", &x);

        for (int i = x; i; i -= i & -i) s ++ ;

        printf("%d", s);

    }

    return 0;
}

算法2 
(位运算) 接近O(1)
时间复杂度分析：运算次数<32次 ,快于计算32次的解法
#include <iostream>
using namespace std;

int cnt(int b){
 int res = 0;
 while (b>0) {
    b = b & (b-1);
    res++;
 }
 return res;
}


int main(){
int n, b;
cin >> n;
for (int i=0;i<n;i++) {
    cin >> b;
    cout << cnt(b)<<" ";
}

return 0;
}






离散化 —— 模板题 AcWing 802. 区间和
时间复杂度分析：
快排O(nlogn)
去重O(n)
前缀和O(n)
m次询问二分O(mlogn)

为什么要离散化呢，因为存储的下标实在太大了，如果直接开这么大的数组，根本不现实，第二个原因，本文是数轴，要是采用下标的话，可能存在负值，所以也不能.
所以有人可能会提出用哈希表，哈希表可以吗？答案也是不可以的，因为哈希表不能像离散化那样缩小数组的空间，导致我们可能需要从-e9遍历到1e9（此处的含义就是假如我们需要计算1e-9和1e9区间内的值，那我们需要从前到后枚举，无论该值是否存在），因为哈希表不能排序，所以我们一般不能提前知道哪些数轴上的点存在哪些不存在，所以一般是从负的最小值到正的最大值都枚举一遍，时间复杂度太高，于是就有了本题的离散化。

离散化的本质，是映射，将间隔很大的点，映射到相邻的数组元素中。减少对空间的需求，也减少计算量。

其实映射最大的难点是前后的映射关系，如何能够将不连续的点映射到连续的数组的下标。此处的解决办法就是开辟额外的数组存放原来的数组下标，或者说下标标志，本文是原来上的数轴上的非连续点的横坐标。

此处的做法是是对原来的数轴下标进行排序，再去重

vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());   去掉重复元素

C++实现unique函数的方法
vector<int>::iterator unique(vector<int> &a)
{
    int j = 0;
    for (int i = 0; i <a.size(); i ++)
       if (!i || a[i] != a[i - 1])
           a[j ++] = a[i];//把重复的数都放在a[j]数组 a[0] ~ a[j - 1] 所有a中不重复的数
    return a.begin() + 1;
}

二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}


解题代码
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N=300010;//坐标x的数量上限为1e5，两个坐标l,r的数量上限也为1e5,所以加起来为3*le5;
typedef pair<int, int> PII;
//pair<int,int>类似于结构体的简写版，typedef定义了一个新的类型PII(跟结构体定义了一个结构体类型然后使用相似)

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;
//使用二分查找x所在的位置，此时是alls(x,l,r)排好序的,返回的坐标也会是按照x的大小所给出的；
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (all[mid] >= x) r = mid;
        else l = mid +1;  
    }
    return r + 1;//因为后续要使用前缀和，所以返回的坐标要加上1；
}

int main()
{
    cin >> n >> m;
    //分别将要操作的四组数据记录在add和query中，将l，r，x的坐标值保存在alls中；
    for (int i = 0; i < n; i ++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});

        alls.push_back(x);
    }

    for (int i = 0; i < m; i ++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }
    // 去重 将alls进行排序，并将重复的操作删除掉(如进行了两次在x的增值操作，应该去掉一个x保持平衡)；
    sort(alls.begin(), alls.end());
    //一个迭代器从1开始直到末尾结束，itdm.first是x，second是r(在上方循环中可知)；
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    //处理插入
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    //预处理前缀和 
    //只循环x是因为x的坐标加上了值，而l，r可能有(l或r与x的值相同)，且定义全局变量数组，其余值默认为0，故可以方便计算；
    for(int i=1;i<=alls.size();i++) s[i]=s[i-1]+a[i];
    for (int i = 1; i <= alls.size(); i ++) s[i] = s[i - 1] + a[i];

    // 处理询问
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);////找出l，r在a中的坐标
        cout << s[r] - s[l - 1]  << endl;//前缀和上方已计算，所以可直接输出，记得加上换行符
    }
    }

    return 0;

}


vector<int> q;//初始化vector数组。
q.push_back(3);//在q里插入3。
int x = q.size();//将x设为q的长度。
q.pop_back();//弹出元素
题目详解。
这道题目看似很难，其实只需几步。

一、读入与插入。
将所有信息读入并插入vector数组
二、数组去重。
二行STL：
sort(alls.begin(), alls.end());
alls.erase(unique(alls.begin(), alls.end()), alls.end());
三、处理加法。
离散化思路。
四、预处理前缀和。
利用上期介绍的前缀和模板即可。
五、输出
离散化思路





***********
区间合并算法

看y总视频和 https://www.acwing.com/solution/content/2661/
803. 区间合并
(1)将所有l, r 存入vector<PII>
(2)sort 默认先左再右
(3)更新右端点(合并)
(4)ans++ 更新右端点 (左端点用不到)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

int n;

void merge(vector<PII> &interval)
{
    vector<PII> ans;

    sort(interval.begin(), interval.end()); //! pair排序 优先左端点， 再以右端点排序

    int st = -1e9-10, ed = -1e9-10;  //! 只要比 -1e9 小就可以
    for(auto item:interval)
    {
        if(ed<item.first) //! 第一段区间一定是  ed< item.first
        {
            if(st!=-1e9-10) ans.push_back({st,ed}); //! 第一次在这里初始化
            st = item.first, ed = item.second;//! 第一段区间从这里开始
        }
        else ed = max(ed, item.second);
    }//todo 这个循环结束之后还会剩下一个区间
    if(st!=-1e9-10) ans.push_back({st,ed});  //! 如果不是空的  那我们就加上一段

    interval = ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin >> n;

    vector<PII> interval;
    while(n--)
    {
        int l, r;
        cin >> l >> r;

        interval.push_back({l, r});
    }

    merge(interval);

    cout << interval.size() << endl;

    return 0;


区间合并 —— 模板题 AcWing 803. 区间合并

// 将所有存在交集的区间合并
void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}
// 解题代码
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
      if (ed < seg.first)
      {
          if (st != -2e9) res.push_back({st, ed});
          st = seg.first, ed = seg.second;
      }
      else ed = max(ed, seg.second);

   if (st != -2e9) res.push_back({st, ed});

   segs = res;

}

int main()
{
    int n;
    scanf("%d", &n);

    vector<PII> segs;
    for (int i = 0; i < n; i ++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});

    }

    merge(segs);

    cout << segs.size() << endl;

    return 0;
}

AcWing 2816. 判断子序列
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    for (int i = 0; i < m; i ++ ) scanf("%d", &b[i]);

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j]) i ++ ;
        j ++ ;
    }

    if (i == n) puts("Yes");
    else puts("No");

    return 0;
}

AcWing 481. 津津的储蓄计划
#include<iostream>
using namespace std;
int main()
{
    int now = 0, store = 0, add_money = 300;
    int a[12];
    for(int i = 0; i < 12; i ++) cin >> a[i];
    for(int i = 0; i < 12; i ++)
    {
        if(a[i] > now + add_money)
        {
            cout << "-" << i + 1 << endl;
            return 0;
        }
        now += add_money - a[i];
        store += now / 100 * (1.2 * 100);
        now %= 100;
    }
    cout << store + now << endl;
    return 0;
}
