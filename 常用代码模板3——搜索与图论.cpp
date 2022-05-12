算法基础课相关代码模板
活动链接 —— 算法基础课

搜索
dfs使用stack，空间为O(h)
bfs使用queue空间为O(2^h)

BFS 算法框架就是二叉树层序遍历代码的衍生。
BFS 算法和 DFS（回溯）算法的一大区别就是，BFS 第一次搜索到的结果是最优的，这个得益于 BFS 算法的搜索逻辑，可见详细题解。


BFS具有两段性，单调性 => 最短路性质（当边权相等时，队列递增，相当于dijkstra的优先队列，将其转化为dijkstra即可证明其正确性，第一次搜到即为最短路）,适用于求
最小，基于迭代，不会爆栈
当边权不相等时，如0和1，用deque + bfs做时每个点可能入队多次，第一次入队不一定为最优解，当做特殊的dijkstra做即可
当状态空间很大时，bfs的优化（双向bfs和A）才有效果
除朴素bfs每个点只入队一次之外，deque+bfs，A，dijkstra都可能入队多次

dfs求最小步数：
1.记一个全局最小值
2.迭代加深

Floodfill 在线性时间内找到某点所在连通块

meet in the middle 适用于状态数量很大的题目，一般是指数级别，复杂度从O(x^n)优化为O(2*x^(n/2))，注意要求搜索图中的节点状态都是可逆的

bfs第一次入队为最优解（第一次入队后判重）
dijkstra第一次出队为最优解（第一次出队后判重）
A*：（不需判重）
只有终点能保证第一次出队时为最短距离
除终点之外的点可能被扩展多次

栈空间默认是1MB
走迷宫模型，每个点只走一次，不需回溯,走状态模型，需要回溯后再走到下一个状态
搜索顺序：按“组合”的方式来搜，而不是按“排列”的方式，可以避免重复，比如按下标升序搜索
尽量减少搜索树的分支，如“把x加到之前任意一组”改为“每一组都尽量枚举完，把x加到最后一组中”
先保证正确性再优化
剪枝：
1.优化搜索顺序（一般优先选择搜索分支较少的节点，要求能搜索到所有方案）
2.排除等效冗余（如按“组合”顺序进行枚举）
3.可行性剪枝（如上下界剪枝）
4.最优性剪枝
5.记忆化搜索
迭代加深：适用于分支较深，但答案所在层数较浅，且比bfs所用空间少，且IDA*可以配合迭代加深使用


图论
Dijkstra-朴素O(n^2)
初始化距离数组, dist[1] = 0, dist[i] = inf;
for n次循环 每次循环确定一个min加入S集合中，n次之后就得出所有的最短距离
将不在S中dist_min的点->t
t->S加入最短路集合
用t更新到其他点的距离

Dijkstra-堆优化O(mlogm)
利用邻接表，优先队列
在priority_queue[HTML_REMOVED], greater[HTML_REMOVED] > heap;中将返回堆顶
利用堆顶来更新其他点，并加入堆中类似宽搜

Bellman_fordO(nm)
注意连锁想象需要备份, struct Edge{inta,b,c} Edge[M];
初始化dist, 松弛dist[x.b] = min(dist[x.b], backup[x.a]+x.w);
松弛k次，每次访问m条边

Spfa O(n)~O(nm)
利用队列优化仅加入修改过的地方
for k次
for 所有边利用宽搜模型去优化bellman_ford算法
更新队列中当前点的所有出边

Floyd O(n^3)
初始化d
k, i, j 去更新d



一个图是二分图当且仅当图中不含奇数边的环
半欧拉图：只有欧拉路径，没有欧拉回路的图。
判定：
首先是个连通图
如果所有点的度数都是偶数则为欧拉图。
如果只有两个点的度数为奇数，其它点的度数都是偶数，该图为半欧拉图。
寻找欧拉路径和欧拉回路的方法：
从起点出发，若当前点是x，递归走与x点所有相连的没有走过的路径，走完把x按顺序存起来， 最后倒序输出就是欧拉回路。
在半欧拉图中，要求欧拉路径的话，从度数为奇数的点出发就行了。

邻接表建图最好先memset(head, -1, sizeof head);
不过memset比较费时

乘法最短路
对w1w2w3取log,log(w1w2w3) = logw1 + logw2 + logw3，可转化为一般的最短路问题
当0<=w<1时，logw<0，求log(w1w2w3)的最大值可变形为求(-logw1) + (-logw2) + (-logw3)的最小值，即非负权图上的最短路问题，可用dijkstra
当w>=0时，边权可正可负，用spfa即可

邻接表忘记初始化表头可能会导致TLE
对于拓扑图最短路， 不管边权正负，均可按拓扑序搜索
dp大多相当于拓扑图上的最短路问题
当依赖关系存在环不可以用dp，但可以转化为最短路,dp和最短路都可用看成在集合上的最优化问题。
一些dp可以用高斯消元
dijkstra的适用前提：点第一次出堆即为最优解，不会再被其它点更新，也只有这样才能保证其时间复杂度
bellman-ford的适用前提：最短路经过边数小于n - 1
多源多汇最短路可以用超级源点超级汇点
分层最短路可以从dp的角度考虑
对于边权0和1的最短路，deque+bfs可以保证在最坏情况下仍是线性复杂度
求方案数：先求出最优解，再分别求出每个子集中等于最优解的元素个数。DP类型的问题状态更新必须满足拓扑序。对于最短路求解方案数，考虑最短路树（简单考虑可以认为边权都大于0），图上不可能有权值和为0的环（会导致方案数无数种）
求解单源最短路径的算法可以分为三大类：
（1）BFS：每次扩展一层，只入队一次，出队一次，被更新的点的父节点一定已经是最短距离了，并且这个点的条数已经被完全更新过了，一定可以得到拓扑图。
（2）Dijkstra（包含双端队列广搜）：每个点只出队一次，第一次出队的时候一定已是最小值了，且已确定最短距离的点不可能再被更新，可以构成拓扑性质
（3）Bellman_ford（spfa）：不一定满足拓扑序。因为某个点可能入队多次，出队多次，被更新距离的点也是不确定的。
如果图中存在负权边，可以先使用spfa求出最短路径；然后建立最短路径树，用dis[v] == dis[u] + w[i]在这个树上统计最短路径次数，注意u的最短路径数应当提前算完
（最小生成树）如何证明当前边一定可以被选：
假设不选当前边，最终得到一棵树，再把当前边加上，必然出现一个环，在环上一定可以找出一条长度不小于当前边的边，那么将当前边替换上去，结果一定不会变差

DAG常用拓扑排序得到遍历顺序，有向有环图可以想到缩点，利用DAG的特性，许多算法在 DAG 上可以有更优/更方便的解。

无向图的最小生成树一定是最小瓶颈生成树

如果边权可正可负，求将所有点连通的最小边权和，可以把负权边先全部选上再kruskal
一定存在一棵次小生成树和最小生成树只有一条边不同，对最小生成树插入非树边删除环上树边的方法可以求严格次小生成树和非严格次小生成树
判断负环：常用cnt[x]记录1到x的最短路所包含的边数，若cnt[x] >= N则说明有负环，注意初始化时将所有点都加入队列，dis可初始化成任意值（可以从虚拟源点的角度考虑）。
优化：❶trick：当更新次数超过2 * N时，图中还有可能存在负环，可以直接判断存在，如果N比较小而M比较大的话可能考虑将更新次数上限调大，这是损失一定正确性来优化时间
❷将队列换成栈（不要用stl，用手写，队列下标是递增的，进队次数可能会很多，所以访问到的下标可能很大，需要循环队列。但栈不管插入多少次，最多只会用前n个位置，不需要循环。），或把基于bfs的spfa改成基于dfs，但注意可能严重降低负环不存在时计算最短路的效率

差分约束
❶求不等式组的可行解
源点需要满足的条件:从源点出发可以走到所有的边。
步骤:
[1]先将每个不等式xi <= xj + c,转化成一条从xj走到xi,长度为c的一条边
[2]找一个超级源点，一定可以遍历到所有边(可以遍历到所有点则可遍历所有边，反之不一定成立)
[3]从源点求一遍单源最短路
如果存在负环，则无解；如果没有负环,则dis[i]就是原不等式组的一个可行解
❷求最大值或者最小值（这里的最值指的是每个变量的最值）
结论:如果求的是最小值，则应该求最长路;如果求的是最大值,则应该求最短路;（xi <= xj + c可直接用最短路，负环无解；xi >= xj + c可直接用最长路，正环无解，也可转化为xj <= xi + (-c) ; xi = xj可转化为xi <= xj且xi >= xj ; xi < xj可转化为xi <= xj - 1）
可行解只能满足相对大小关系，如果不等式中有绝对值条件xi <= C才可以求最值，对于这样的条件建立一个超级源点0，然后建立0->i,长度是c的边即可。
以求xi的最大值为例:对于所有xi在左边的关系x_i <= x_i-1 + c_i-1都可以放缩：x_i <= x_i-2 + c_i-2 + c_i-1<=…<=x_0 + c_0 + c_1 +…+c_i-1，即x_i <= c_0 + c_1 + c_2 +..+c_i-1，这里的c_0~c_i-1即为从0到i的一条路径上的边，边权和即为xi的一个上界，xi的最大值即为所有上界的最小值，也就是从0到x的最短路；同理，xi的最小值即为从0到x的最长路（若从0到不了i，dis[i] = inf，意味着不等式链有残缺，xi可以取任何值）
若既要判断负环又要求最短路，可以初始化把所有的点都压入队列，但除了dis[1] = 0之外dis都为inf

tarjan、缩点（可建图）、依据拓扑序递推（用tarjan缩点所得连通分量编号递减的顺序一定是拓扑序）
将有向图变为一个SCC最少需要加max{入度为0的点数，出度为0的点数}条边

e-DCC性质
不管删掉哪条边图依然联通
e-DCC <=> 任意两点之间都存在两条不相交（没有公共边）的路径
桥的两个端点不一定是割点
e_DCC中，每个边只会属于一个e_DCC，且桥不会属于任何e_DCC
e-DCC不一定是v-DCC
将无向图变为一个e-DCC最少需要加 cnt + 1 / 2 条边，其中cnt是叶子节点个数（度为1）
e-DCC缩点后是一棵树（将一棵树变为一个e-DCC 至少增加的边数 =（ 这棵树总度数为1的结点数 + 1 ）/ 2）

v-DCC性质
每个割点至少属于两个v-DCC
两个割点之间的边不一定是桥
v-DCC不一定是e-DCC
一个点也是一个v-DCC
->关于Tarjan算法中用dfn不能用low的问题

二分图(一般都是无向图，但两点之间只建一条有向边)
一个图是二分图 <=> 图中不存在奇数环 <=> 染色不存在矛盾
最大匹配数 = 最小点覆盖 = 总点数 - 最大独立集 = 总点数 - 最小路径点覆盖

字典序拓扑排序可以用优先队列
查分约束 求最小值（最长路）
边权可正可负 spfa O(KM)
边权非负 tarjan O(N + M) 若有解，每个SCC内的边都为0，一旦有正边就会构成正环
边权为正 拓扑排序 O(N + M) 一旦有环则无解
如果对于两个图N， M，一个图的所有结点都要向另一张图的所有结点连边，总共要连N * M条边，但如在中间加一个虚拟点，左图所有结点向虚拟点连边，右图所有结点向虚拟点连边，则可优化为总共只需要N + M边
宽搜的倒序就是拓扑序


树的重心
定义：
一棵具有n个节点的无向树，若以某个节点为整棵树的根，他的每个儿子节点的大小（即子树的节点数）都<=n/2 ，则这个节点即为该树的重心
性质：
删除重心后所得的所有子树，节点数不超过原树的1/2，一棵树最多有两个重心
树中所有节点到重心的距离之和最小，如果有两个重心，那么他们距离之和相等
两个树通过一条边合并，新的重心在原树两个重心的路径上
树删除或添加一个叶子节点，重心最多只移动一条边

若图中每个点的出度均为1，则只能构成三种情况：1、一条链; 2、一个环;3、一条链连接着一个环。此时求最小环除了Floyd之外还可以用并查集（记录到根的距离，唯一可以

形成环的情况就是链头的元素连到了链中的元素上，每次连边操作都是将一个链头连到另一条链上），搜索，tarjan等方法
在遍历过程中若遇到走过的点，用当前走到的步数减去在此节点原先记录的步数，便得到这个环的长度

最短路注重问题的转化和抽象（使原问题的方案和图上的路径一一对应）


AcWing 842. 排列数字

dfs 深度优先遍历: 一条路走到底，走到最深点处再回退一步，再看有没有路可以走，没有的话再回退一步，重复此步骤
算法：
用 path 数组保存排列，当排列的长度为 n 时，是一种方案，输出。
用 state 数组表示数字是否用过。当 state[i] 为 1 时：i 已经被用过，state[i] 为 0 时，i 没有被用过。
dfs(i) 表示的含义是：在 path[i] 处填写数字，然后递归的在下一个位置填写数字。
回溯：第 i 个位置填写某个数字的所有情况都遍历后， 第 i 个位置填写下一个数字。
实现dfs的递归思想
递归在于不断调用自己的函数，层层深入，直到遇到递归终止条件后层层回溯，其思想与dfs的思想不谋而合，因此，可以使用递归来实现dfs。
递归的进入比较容易理解，但是递归的回溯是在计算机底层执行的，我们无法看到。因此，递归究竟是如何完成的，成为了理解递归的一大难点，也是理解递归的唯一一个难点。
#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N]; // 用path数组保存路径上的值

void dfs(int u, int state)
{
    if (u == n) // 到叶子节点时
    {
        for (int i = 0; i < n; i ++ ) printf("%d ", path[i]); // 输出路径上的值
        puts(""); // 换行

        return;
    }

    // 在每一层选取没有被用过的数，然后进入下一层
    for (int i = 0; i < n; i ++ )
        if (!(state >> i & 1)) // 选择一个没有被用过的值放在path[u]中
        {
            path[u] = i + 1; 
            dfs(u + 1, state + (1 << i));  // 进入下一层
        }
}

int main()
{
    scanf("%d", &n);

    dfs(0, 0);

    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 10;

int n;
int path[N];       // 从0到n-1共n个位置 存放一个排列
bool state[N];     // 存放每个数字的使用状态 true表示使用了 false表示没使用过

void dfs(int u)
{
    if (u == n)    // 一个排列填充完成
    {
        for (int i = 0; i < n; i ++) printf("%d ",path[i]);  // 注意格式 别忘了每两个数字间用空格隔开
        puts("");  // 相当于输出一个回车
        return;
    }

    for (int i = 1; i <= n; i ++)
    {
        if (!state[i])
        {
            path[u] = i;       // 把 i 填入数字排列的位置上
            state[i] = true;   // 表示该数字用过了 不能再用
            dfs(u + 1);        // 这个位置的数填好 递归到右面一个位置
            state[i] = false;  // 恢复现场 该数字后续可用
        }
    }
    // for 循环全部结束了 dfs(u)才全部完成 回溯

    return;        // 可写可不写
}

int main()
{
    scanf("%d", &n);

    dfs(0);    // 在path[0]处开始填数

    return 0;
}


AcWing 843. n-皇后问题 深度优先遍历dfs

按行枚举 时间复杂度O(n!) 12!=479001600
把棋盘看做坐标轴 则对角线为 y=x+b y=-x+c 推出b=y-x c=y+x 
dg[b]=dg[y-x]属于[-n,n] 则 dg[y-x+n]属于[0,2n]
udg[c]=udg[y+x]属于[0,2n]的区间

#include <iostream>
using namespace std;
const int N = 20; 

// bool数组用来判断搜索的下一个位置是否可行
// col列，dg对角线，udg反对角线
// g[N][N]用来存路径

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
    // u == n 表示已经搜了n行，故输出这条路径
    if (u == n) {
        for (int i = 0; i < n; i ++ ) puts(g[i]);   // 等价于cout << g[i] << endl;
        puts("");  // 换行
        return;
    }

    // 枚举u这一行，搜索合法的列
    int x = u;
    for (int y = 0; y < n; y ++ )
        // 剪枝(对于不满足要求的点，不再继续往下搜索)  
        if (col[y] == false && dg[y - x + n] == false && udg[y + x] == false) {
            col[y] = dg[y - x + n] = udg[y + x] = true;
            g[x][y] = 'Q';
            dfs(x + 1);
            g[x][y] = '.';  // 恢复现场
            col[y] = dg[y - x + n] = udg[y + x] = false;
        }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '.';

    dfs(0);

    return 0;
}   

（旧的写法）
过去的写法（DFS按行枚举） 时间复杂度O(n!)O(n!)

代码分析

对角线 dg[u+i]，反对角线udg[n-u+i]中的下标 u+i和 n-u+i 表示的是截距

下面分析中的(x,y)相当于上面的(u,i)
反对角线 y=x+b, 截距 b=y-xx，因为我们要把 bb 当做数组下标来用，显然 b 不能是负的，所以我们加上 +n （实际上+n+4,+2n都行），来保证是结果是正的，即 y - x + n
而对角线 y=-x+b, 截距是 b=y+x，这里截距一定是正的，所以不需要加偏移量
核心目的：找一些合法的下标来表示dgg或udg是否被标记过，所以如果你愿意，你取 udg[n+n-u+i] 也可以，只要所有(u,i)对可以映射过去就行

C++ 代码
#include <iostream>
using namespace std;
const int N = 20; 

// bool数组用来判断搜索的下一个位置是否可行
// col列，dg对角线，udg反对角线
// g[N][N]用来存路径

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
    // u == n 表示已经搜了n行，故输出这条路径
    if (u == n) {
        for (int i = 0; i < n; i ++ ) puts(g[i]);   // 等价于cout << g[i] << endl;
        puts("");  // 换行
        return;
    }

    //对n个位置按行搜索
    for (int i = 0; i < n; i ++ )
        // 剪枝(对于不满足要求的点，不再继续往下搜索)  
        // udg[n - u + i]，+n是为了保证下标非负
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false; // 恢复现场 这步很关键
            g[u][i] = '.';

        }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '.';

    dfs(0);

    return 0;
}   

算法2 
DFS按每个元素枚举 时间复杂度O(2的n2次方)
时间复杂度分析：每个位置都有两种情况，总共有 n2个位置
按元素位置枚举是要比按位置枚举慢很多的

// 不同搜索顺序 时间复杂度不同  所以搜索顺序很重要！
#include <iostream>
using namespace std;
const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N]; // 因为是一个个搜索，所以加了row

// s表示已经放上去的皇后个数
void dfs(int x, int y, int s)
{
    // 处理超出边界的情况
    if (y == n) y = 0, x ++ ;

    if (x == n) { // x==n说明已经枚举完n^2个位置了
        if (s == n) { // s==n说明成功放上去了n个皇后
            for (int i = 0; i < n; i ++ ) puts(g[i]);
            puts("");
        }
        return;
    }

    // 分支1：放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }

    // 分支2：不放皇后
    dfs(x, y + 1, s);
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '.';

    dfs(0, 0, 0);

    return 0;
}

y总
第一种搜索顺序 按每个元素枚举
#include <iostream>

using namespace std;

const int N = 10;

int n;
bool row[N], col[N], dg[N * 2], udg[N * 2];
char g[N][N];

void dfs(int x, int y, int s)
{
    if (s > n) return;
    if ( y == n) y = 0, x ++;
    
    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i ++ ) puts(g[i]);
            puts("";)
        }
        return;
    }

    g[x][y] = '.';
    dfs(x, y + 1, s);

    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        g[x][y] = 'Q';
        dfs(x, y + 1, s + 1);
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
    }
}

int main()
{
    cin >> n;

    dfs(0, 0, 0);

    return 0;
}

第二种搜索顺序 按行枚举 时间复杂度更低
#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i ++) puts(g[i]);
        puts("");
        return;// 不是应该放在if循环外面吗?
    }

    for (int i = 0; i < n; i ++ ) 
    //for 不是一个函数 不要写成函数的形式 即{}
    if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
      for (int j = 0; j < n; j ++ )
         g[i][j] = '.';
    

    dfs(0);

    return 0;
}


AcWing 844. 走迷宫 广度优先遍历bfs 队列实现
思路：
用 g[n][m] 存储地图，f[n][m] 存储起点到 n,m 的距离。
从起点开始广度优先遍历地图。
当地图遍历完，就求出了起点到各个点的距离，输出f[n][m]即可。

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N];

int bfs()
{
    queue<PII> q;

    memset(d, -1, sizeof d);
    d[0][0] = 0;
    q.push({0,0});

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }

    return d[n - 1][m - 1];
} 

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n ; i ++)
      for (int j = 0; j < m; j ++)
        cin >> g[i] [j];

    cout << bfs() << endl;

    return 0;        
}

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int g[N][N];//存储地图
int f[N][N];//存储距离 标记搜索到的点的距离
int n, m; //标记搜索到的点的距离
void bfs(int a, int b)//广度优先遍历
{
    queue<PII> q;
    q.push({a, b});
    while(!q.empty())
    {
        PII start = q.front();
        q.pop();
        g[start.first][start.second] = 1;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
        for(int i = 0; i < 4; i++)//往四个方向走
        {
            int x = start.first + dx[i], y = start.second + dy[i];
            if(g[x][y] == 0)//如果还没有走过
            {
                g[x][y] = 1;
                f[x][y] = f[start.first][start.second] + 1;//从当前点走过去，则距离等于当前点的距离+1.
                q.push({x, y});
            }

        }
    }
    cout << f[n][m];
}

int main() 
{
    memset(g, 1, sizeof(g));  //初始化d
    cin >> n >>m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    bfs(1,1);

}

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=110;


int g[N][N];    //存储地图
int d[N][N];    //标记搜索到的点的距离
int n,m;        //地图的长宽

struct elem{
    int x;
    int y;
};

struct elem q[N*N]; //队列用于BFS操作
int bfs()
{
    memset(d,-1,sizeof d);  //初始化d

    int hh=0,tt=0;
    d[0][0]=0;  //左上角第一个点开始搜索

    q[hh]={0,0};    //将第一个点入队

    int dx[4]={-1,0,1,0};   //方向盘用于对个方向进行尝试
    int dy[4]={0,-1,0,1};

    while(hh<=tt)   //
    {
        struct elem j=q[hh++];  //获取队头元素 然后将其出队

        for(int i=0;i<4;i++)
        {
            int x=j.x+dx[i];
            int y=j.y+dy[i];
            if(x>=0&&y>=0&&x<n&&y<m&&g[x][y]==0&&d[x][y]==-1)     //点未出界 该点可走 且未走过
            {
                d[x][y]=d[j.x][j.y]+1;
                q[++tt]={x,y};
            }
        }
    }

    return    d[n-1][m-1];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];

    cout<<bfs()<<endl;
    return 0;

}

数组模拟队列
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 110; 
typedef pair<int, int> PII;
int n, m;
int g[N][N];//存放地图
int d[N][N];//存 每一个点到起点的距离
PII q[N * N];//手写队列
int bfs()
{
    int hh = 0, tt = 0;
    q[0] = {0, 0};

    memset(d, - 1, sizeof d);//距离初始化为- 1表示没有走过

    d[0][0] = 0;//表示起点走过了

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//x 方向的向量和 y 方向的向量组成的上、右、下、左

    while(hh <= tt)//队列不空
    {
        PII t = q[hh ++ ];//取队头元素

        for(int i = 0; i < 4; i ++ )//枚举4个方向
        {
            int x = t.first + dx[i], y = t.second + dy[i];//x表示沿着此方向走会走到哪个点
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)//在边界内 并且是空地可以走 且之前没有走过
            {
                d[x][y] = d[t.first][t.second] + 1;//到起点的距离
                q[ ++ tt ] = {x, y};//新坐标入队
            }
        }
    }
    return d[n - 1][m - 1]; //输出右下角点距起点的距离即可
}
int main() 
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < m; j ++ )
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}

C++ queue
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

int n, m;
int g[N][N], d[N][N];

int bfs()
{
    queue< pair<int, int> > q;

    q.push({0, 0});

    memset(d, -1, sizeof(d));

    d[0][0] = 0;


    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())//队列不为空
    {
        PII t = q.front();//取队头元素

        q.pop();//出队

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;//当前点到起点的距离
                q.push({x, y});//将新坐标入队
            }
        }
    }

    return d[n - 1][m -1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}

打印路径
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 110;
typedef pair<int, int> PII;
PII q[N*N],Prev[N][N];
int g[N][N], d[N][N];
int n, m;
int bfs()
{
    int hh = 0, tt = 0;
    q[0] = {0, 0};
    memset(d, -1, sizeof d);

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    d[0][0] = 0;
    while(hh <= tt)
    {
        PII t = q[hh ++ ];
        for(int i = 0; i < 4; i ++ )
        {
            int x = dx[i] + t.first, y = t.second + dy[i];

            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                Prev[x][y] = t;
                q[++ tt] = {x, y};
            }
        }
    }
    int x = n - 1, y = m - 1;
    while(x || y)//有一个不d等于0
    {
        cout << x << ' ' << y << endl;
        PII t = Prev[x][y];
        x = t.first, y = t.second;
    }

    return d[n - 1][m - 1];
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < m;j ++)
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}

python
def bfs():
    d[0][0] = 0
    queue = [(0, 0)]
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    while queue : #队列不为空
        x, y = queue.pop(0)
        for i in range(4):
            a = x + dx[i];
            b = y + dy[i];
            if a >= 0 and a < n and b >= 0 and b < m and g[a][b] == 0 and d[a][b] == -1:
                queue.append((a,b))#入队
                d[a][b] = d[x][y] + 1
    print(d[n - 1][m - 1])
#main
n, m = map(int, input().split())#map函数对分割输入后的字符列表转换成整型
g = [[-1 for j in range(m)] for i in range(n)] # 存储地图

for i in range(n):
    in_li = list(map(int, input().split()))
    for j in range(m):
        g[i][j] = in_li[j];
d = [[-1 for i in range(m)] for j in range(n)]#初始化为 - 1
bfs()

问题2:走迷宫升级版——边的权值不同
一天，sunny 不小心进入了一个迷宫，不仅很难寻找出路，而且有的地方还有怪物，但是 sunny 有足够的能力杀死怪物，但是需要一定的时间，但是 sunny 想早一点走出迷宫，所以请你帮助他计算出最少的时间走出迷宫，输出这个最少时间。

我们规定每走一格需要时间单位 1, 杀死怪物也需要时间 1, 如果不能走到出口，则输出 impossible. 每次走只能是上下左右 4 个方向。
(BFS + 优先队列)
题意：走迷宫，求最短路径，上下左右走一格花费1，走到有怪的格子花费2.

思路：将每一点的坐标和由起点到该点的距离存入结构体.
由起点开始，将该点存入优先队列，以到起点的距离dis为优先级，每次取出dis最小的，向外扩散。
相当于第一轮得出所有到起点距离为1的点，第二轮得出所有到起点距离为2的点。
注意：对普通的最短路问题，由于每个各自的花费相同，因此每次存入的点优先级都相同.
故不需要使用优先队列，但本题存在有无怪物的区别，每次存入的格子的优先级可能不同，故使用优先队列。

C++ 代码

#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
char maze[201][201];
int sx, sy, tx, ty;
//左右上下4个方向
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m, n;

struct node {
    int x,  y, dis;
};

bool operator < (const node & a, const node & b) {
    return a.dis > b.dis;
}

void bfs() {
    priority_queue<node> que;
    node st { sx,sy,0 };
    maze[sx][sy] = '#';
    que.push(st);

    while (!que.empty()) {
        node p = que.top();
        que.pop();
        //若已找到，则退出
        if (p.x == tx && p.y == ty) {
            cout << p.dis << endl;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            node np{ nx,ny, 0};

            if (nx >= 0 && nx < n&&ny >= 0 && ny < m&&maze[nx][ny] != '#') {
                if (maze[nx][ny] == 'X')
                    np.dis = p.dis + 2;
                else
                    np.dis = p.dis + 1;
                maze[np.x][np.y] = '#';
                que.push(np);

            }
        }
    }
    printf("impossible\n");
}
int main() {
    while (cin>>n>>m) {
        for (int i = 0; i < n; i++)
            scanf("%s", maze[i]);
        for(int i=0; i<n; i++)
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'S')
                    sx = i, sy = j;
                else if (maze[i][j] == 'T')
                    tx = i, ty = j;
            }
        bfs();
    }
    return 0;
}


AcWing 845. 八数码
最小步数 BFS
移动方式 dx[4] = {1, -1, 0, 0} dy[4] = {0, 0, 1, -1} 下 上 右 左
则a = x + dx[i], b = y + dy[i].
思想：将每一种情况作为1个节点，目标情况即为终点
从初始状况移动到目标情况 —> 求最短路
3、问题
第一点：怎么表示一种情况使其能作为节点？
第二点：如何记录每一个状态的“距离”（即需要移动的次数）？
第三点：队列怎么定义，dist数组怎么定义？

4、解决方案
将 “3*3矩阵” 转化为 “字符串”
    1, 2, 3,
    x, 4, 6,
    7, 5, 8,
化为 123x46758
队列可以用 queue<string>
//直接存转化后的字符串
dist数组用 unordered_map<string, int>
//将字符串和数字联系在一起，字符串表示状态，数字表示距离
5、矩阵与字符串的转换方式
下标 = x * 3 + y

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(string start)
{
    //定义目标状态
    string end = "12345678x";
    //定义队列和dist数组
    queue<string> q;
    unordered_map<string, int> d;
    //初始化队列和dist数组
    q.push(start);
    d[start] = 0;
    //转移方式
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    while(q.size())
    {
        auto t = q.front();
        q.pop();
        //记录当前状态的距离，如果是最终状态则返回距离
        int distance = d[t];
        if(t == end) return distance;
        //查询x在字符串中的下标，然后转换为在矩阵中的坐标
        int k = t.find('x');
        int x = k / 3, y = k % 3;

        for(int i = 0; i < 4; i++)
        {
            //求转移后x的坐标
            int a = x + dx[i], b = y + dy[i];
            //当前坐标没有越界
            if(a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                //转移x
                swap(t[k], t[a * 3 + b]);
                //如果当前状态是第一次遍历，记录距离，入队
                if(!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                //还原状态，为下一种转换情况做准备
                swap(t[k], t[a * 3 + b]);
            }
        }
    }
    //无法转换到目标状态，返回-1
    return -1;
}

int main()
{
    string c, start;
    //输入起始状态
    for(int i = 0; i < 9; i++)
    {
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string state)
{
    queue<string> q;
    unordered_map<string, int> d;

    q.push(state);
    d[state] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        if (t == end) return d[t];

        int distance = d[t];
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i ++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a <3 && b >= 0 && b <3)
            {
                swap(t[a * 3 + b], t[k]);
                if (!d.count(t))
                {
                   d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[a * 3 + b], t [k]);
            }

        }
    }
    return -1;
}

int main()
{
    char s[2];
    string state;
    for (int i = 0; i < 9; i ++)
    {
        cin >> s;
        state += *s;
    }

    cout << bfs(state) << endl;

    return 0;
}

BFS/康托展开
本题求最少步数，所以应当用bfs来做
首先定义一个能表示矩阵状态的结构体，每次把由当前状态更新的合法的新状态压入队列
如果状态为目标状态，那么返回步数，如果更新不到目标状态，返回-1
我们可以想到，这个3*3的矩阵可以表示为一个长度为9的字符串
但是我们知道，bfs需要把遍历过的状态标记，以防止死循环
那么，如何开辟一个数组
使得这个数组中的元素，能够和矩阵的所有状态（长度为9的字符串的全排列）一一对应
这才是难点
*** 全排列哈希
变进制数，用来表示字符串的排列状态
这是一个最大的9位变进制数
876543210
它对应的十进制数为
8 * 8! + 7 * 7! + 6 * 6! + …… + 1 * 1! + 0 * 0! = 9! - 1 = 362879
我们可以找到一个9位变进制数，与一个9位无重复串的某种排列一一对应
用d[i]表示字符串中的第i位与其前面的字符组成的逆序对个数
这是字符串123x46758的与d[i]的对应关系
  i     0 1 2 3 4 5 6 7 8
s[i]    1 2 3 x 4 6 7 5 8
d[i]    0 0 0 0 1 1 1 3 1

可以用以下函数求字符串的一种排列对应的哈希值
int permutation_hash(char s[], int n)       //求长度为n的字符串某种排列的哈希值
{
    int ans = 0;
    for(int i = 0; i < n; i ++)
    {
        int d = 0;
        for(int j = 0; j < i; j ++)
            if(s[j] > s[i])  d ++;          //求s[i]与其前面的字符组成的逆序对个数
        ans += d * fact[i];
    }
    return ans;
}
n不能太大，通常不超过12，否则会溢出
时间复杂度为O(n²)

全排列哈希 + BFS
C++ 代码
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

int fact[9];
bool vis[362880];

int permutation_hash(char s[])          //求长度为9的字符串某种排列的哈希值
{
    int ans = 0;
    for(int i = 0; i < 9; i ++)
    {
        int d = 0;
        for(int j = 0; j < i; j ++)
            if(s[j] > s[i])  d ++;      //求s[i]与其前面的字符组成的逆序对个数
        ans += d * fact[i];
    }
    return ans;
}

typedef struct{
    char s[10];
    int step;
    int k;          //'x'在第k位
}Point;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0,-1, 0, 1};
int bfs(Point p)
{
    vis[permutation_hash(p.s)] = true;
    queue<Point> q;
    q.push(p);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        /*
        printf("%d ",p.step);       //print调试法
        puts(p.s);
        */
        if(!strcmp(p.s , "12345678x"))  return p.step;

        int x = p.k / 3;      //'x'的行数
        int y = p.k % 3;      //'x'的列数
        Point next;
        next.step = p.step + 1;
        for(int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx <= 2 && ny >= 0 && ny <= 2)
            {
                next.k = nx * 3 + ny;           //求出'x'在字符串中的的新位置

                strcpy(next.s, p.s);
                next.s[9] = 0;
                next.s[p.k] = p.s[next.k];      //先用即将和'x'交换的字符覆盖'x'之前的位置
                next.s[next.k] = 'x';           //再给'x'的新位置赋值'x'

                int hash = permutation_hash(next.s);
                if(!vis[hash])
                {
                    vis[hash] = true;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main()
{
    fact[0] = 1;
    for(int i = 1; i < 9; i ++)  fact[i] = fact[i - 1] * i;    //预处理fact[i] = i!

    char c[2],str[10];
    Point start;
    for(int i = 0; i < 9; i ++)
    {
        scanf("%s",&c);
        if(c[0] == 'x')  start.k = i;
        start.s[i] = c[0];
    }
    start.s[9] = 0;
    start.step = 0;
    printf("%d",bfs(start));
    return 0;
}

(手写hash)
注：蓝桥杯可使用map(有序)函数，但此题测试用例会超时
在蓝桥杯里需要加上这两个头文件以及文件命名空间才能使用。
有时用不了unordered_map或者unordered_set时，加上
#include<tr1/unordered_set>
#include<tr1/unordered_map>
using namespace std::tr1;

#include<bits/stdc++.h>
using namespace std;
//该结点是将二维数组状态压缩成一个字符串
typedef unsigned long long ULL;
const int M=10000000;
const int N=100010,P=13331;
ULL h[N];//h[]存放字符串的前缀值
int d[M];
ULL hash_CSM(string a)
{
    h[0]=0;
    for(int i=1;i<=9;i++)
    {
        h[i]=h[i-1]*P+(a[i-1]-'0'+1);

    }
    return h[9]%M;
    //y总讲hash时用ULL实现自动取余，但是此题hash值需要作为数组下标，对该结点进行标记，所以通过多次试验，找到M可实现不冲突，且数组可开辟这些空间
}
int bfs(string state)
{
    queue<string>q;//队列存放节点 
    //unordered_map<string,int>d;//存放到达该结点的最短步数(d[string]的值) 

    q.push(state); //节点入队 
    //cout<<hash(state);
    d[hash_CSM(state)]=0;//到达该结点的步数为零步 
    string end="12345678x";
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};//遍历当前状态下该结点上下左右四个方向 
    while(q.size())//队列中有节点 
    {
        string t=q.front();//临时变量t等于队列中的头结点 
        q.pop();//出队 
        if(t==end)return d[hash_CSM(t)];//找到答案，返回最短路径 
        int distance=d[hash_CSM(t)];//临时变量distance存放到达当前节点的最短路径 
        /*为什么需要distance临时变量？ 
        因为下面改变字符串后，字符串t更新，找不到该状态下的上一个状态*/ 
        int k=t.find('x');//找到可变换节点的坐标 
        int x=k/3,y=k%3;//转换为二维，为了寻找其上下左右四个节点 
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i];
            int b=y+dy[i];
            if(a>=0&&a<3&&b>=0&&b<3)
            {


                swap(t[a*3+b],t[k]);
                //在一维中将符合条件的节点和可变换节点进行位置交换 
                //cout<<t<<endl;
                //cout<<"字符串的哈希值"<<hash(t)<<endl;
                //cout<<"到该节点的步数"<<d[hash(t)]<<endl;
                if(!d[hash_CSM(t)])//d数组初始化时0，是0代表该结点 未被访问过 
                {

                    d[hash_CSM(t)]=distance+1;
                    q.push(t);  
                } 
                swap(t[a*3+b],t[k]);//字符串恢复到原来，继续遍历下种状态是否可行 
            }

        }
    }
    return -1; 
}
int main()
{
    string state;

    char c;
    for(int i=0;i<9;i++)
    {
        cin>>c;
        state+=c;
    }

    cout << bfs(state) << endl;

    return 0;
}


算法2
(用unordered_map函数)
#include<bits/stdc++.h>
using namespace std;
//该结点是将二维数组状态压缩成一个字符串 
int bfs(string state)
{
    queue<string>q;//队列存放节点 
    unordered_map<string,int>d;
    //存放到达该结点的最短步数(d[string]的值) 
    q.push(state); //节点入队 
    d[state]=0;//到达该结点的步数为零步 
    string end="12345678x";
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    //遍历当前状态下该结点上下左右四个方向 
    while(q.size())//队列中有节点 
    {
        string t=q.front();//临时变量t等于队列中的头结点 
        q.pop();//出队 
        if(t==end)return d[t];
        //找到答案，返回最短路径 
        int distance=d[t];
        //临时变量distance存放到达当前节点的最短路径 
        /*为什么需要distance临时变量？ 
        因为下面改变字符串后，字符串t更新，找不到该状态下的上一个状态*/ 
        int k=t.find('x');
        //找到可变换节点的坐标 
        int x=k/3,y=k%3;
        //转换为二维，为了寻找其上下左右四个节点 
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i];
            int b=y+dy[i];
            if(a>=0&&a<3&&b>=0&&b<3)
            {
                swap(t[a*3+b],t[k]);
                //在一维中将符合条件的节点和可变换节点进行位置交换 
                if(!d.count(t))
                {
                    d[t]=distance+1;
                    q.push(t);  
                } 
                swap(t[a*3+b],t[k]);
                //字符串恢复到原来，继续遍历下种状态是否可行 
            }

        }
    }
    return -1; 
}
int main()
{
    string state;
    char c;
    for(int i=0;i<9;i++)
    {
        cin>>c;
        state+=c;
    }

    cout << bfs(state) << endl;

    return 0;
}

python解法 八数码
这题用的是队列, 不能用栈 用栈等于做了dfs，搜不到最短路径了
from collections import deque

def bfs(start):
    end = "12345678x"
    d = {start : 0} # 该字典存放每个状态距离初始状态的距离
    q = deque() # 存放将要验证的状态
    q.append(start)
    dx = [0, 1, 0, -1] # 用于"x"上下左右移动
    dy = [1, 0, -1, 0]
    while q:
        t = q.popleft()
        distance = d[t]
        if t == end:
            return distance
        k = t.index('x')
        x = k // 3 # 字符串的索引转换成3x3矩阵后的坐标
        y = k % 3

        tl = list(t) # 由于字符串不是不可变量，因而把字符串变为数组，用于交换字符串中的字符位置
        for i in range(4): # "x"上下左右移动
            a = x + dx[i]
            b = y + dy[i]
            if a >=0 and a < 3 and b >=0 and b < 3: # 若坐标未超出矩阵范围
                nk = a * 3 + b #3x3矩阵的坐标转换成字符串的索引
                tl[nk], tl[k] = tl[k], tl[nk] # 交换字符串中的字符位置
                t = "".join(tl)
                if t not in d: # 如果t这个状态是新状态(之前未出现过)
                    q.append(t)
                    d[t] = distance + 1
                tl[nk], tl[k] = tl[k], tl[nk] # 还原现场
    return -1

start = input().replace(" ", "")
ans = bfs(start)
print(ans)



树与图的存储
树是一种特殊的图，与图的存储方式相同。
对于无向图中的边ab，存储两条有向边a->b, b->a。
因此我们可以只考虑有向图的存储。

(1) 邻接矩阵：g[a][b] 存储边a->b

(2) 邻接表：

// 对于每个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
int h[N], e[N], ne[N], idx;

// 添加一条边a->b
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

// 初始化
idx = 0;
memset(h, -1, sizeof h);
树与图的遍历
时间复杂度 O(n+m), nn 表示点数，mm 表示边数
(1) 深度优先遍历 —— 模板题 

AcWing 846. 树的重心 dfs
//数据建立邻接表
int h[N], e[N * 2], ne[N * 2], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 需要标记数组st[N],  遍历节点的每个相邻的点
int dfs(int u)
{
    st[u] = true; // 标记一下 st[u] 表示点u已经被遍历过

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}

本题的本质是树的dfs， 每次dfs可以确定以u为重心的最大连通块的节点数，并且更新一下ans。也就是说，dfs并不直接返回答案，而是在每次更新中迭代一次答案。这样的套路会经常用到，在 树的dfs 题目中

// 解题代码

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10; //数据范围是10的5次方
const int M = 2 * N; //以有向图的格式存储无向图，所以每个节点至多对应2n-2条边

int h[N]; //邻接表存储树，有n个节点，所以需要n个队列头节点
int e[M]; //存储元素
int ne[M]; //存储列表的next值
int idx; //单链表指针
int n; //题目所给的输入，n个节点
int ans = N; //表示重心的所有的子树中，最大的子树的结点数目

bool st[N]; //记录节点是否被访问过，访问过则标记为true

//a所对应的单链表中插入b  a作为根 
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// dfs 框架
/*
void dfs(int u){
    st[u]=true; // 标记一下，记录为已经被搜索过了，下面进行搜索过程
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]) {
            dfs(j);
        }
    }
}
*/

//返回以u为根的子树中节点的个数，包括u节点
int dfs(int u) {
    int res = 0; //存储 删掉某个节点之后，最大的连通子图节点数
    st[u] = true; //标记访问过u节点
    int sum = 1; //存储 以u为根的树 的节点数, 包括u，如图中的4号节点

    //访问u的每个子节点
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        //因为每个节点的编号都是不一样的，所以 用编号为下标 来标记是否被访问过
        if (!st[j]) {
            int s = dfs(j);  // u节点的单棵子树节点数 如图中的size值
            res = max(res, s); // 记录最大联通子图的节点数
            sum += s; //以j为根的树 的节点数
        }
    }

    //n-sum 如图中的n-size值，不包括根节点4；
    res = max(res, n - sum); // 选择u节点为重心，最大的 连通子图节点数
    ans = min(res, ans); //遍历过的假设重心中，最小的最大联通子图的 节点数
    return sum;
}

int main() {
    memset(h, -1, sizeof h); //初始化h数组 -1表示尾节点
    cin >> n; //表示树的结点数

    // 题目接下来会输入，n-1行数据，
    // 树中是不存在环的，对于有n个节点的树，必定是n-1条边
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a); //无向图
    }

    dfs(1); //可以任意选定一个节点开始 u<=n

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

const int N=100010;
bool state[N];

//因为是双向边
int h[N],e[2*N],ne[2*N],idx,ans=N;
int n;
int add(int a,int b){
   e[idx]=b;
   ne[idx]=h[a];
   h[a]=idx++;
}

//返回的是以u为根的子树中点的数量
int dfs(int u){
    //标记u这个点被搜过
    state[u]=true;
    //size是表示将u点去除后，剩下的子树中数量的最大值；
    //sum表示以u为根的子树的点的多少，初值为1，因为已经有了u这个点
    int size=0,sum=1;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(state[j]) continue;
        //s是以j为根节点的子树中点的数量
        int s=dfs(j);
        //
        size=max(size,s);
        sum+=s;
    }
    //n-sum表示的是减掉u为根的子树，整个树剩下的点的数量
    size=max(size,n-sum);
    ans=min(size,ans);
    return sum;
}

int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1);
    cout<<ans;
    return 0;
}


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int ans = N;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dsf(int u)
{
    st[u] = true;

    int size = 0, sum = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (st[j]) continue;

        int s = dfs(j);
        size = max(size, s);
        sum += s;
    }

    size = max(size, n - sum - 1);
    ans = min(ans, size);

    return sum + 1;
}

int main()
{
    scanf("%d", &n);

    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    dfs(1);

    printf("%d\n", ans);

    return 0;
}


(2) 宽度优先遍历 —— 模板题 

AcWing 847. 图中点的层次 bfs 队列

queue<int> q;
st[1] = true; // 表示1号点已经被遍历过
q.push(1);

while (q.size())
{
    int t = q.front();
    q.pop();

    for (int i = h[t]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true; // 表示点j已经被遍历过
            q.push(j);
        }
    }
}

// 解题代码

判断1号节点能否走到n号节点，广度优先遍历即可。
***思路：
用 dist 数组保存1号节点到各个节点的距离，初始时，都是无穷大。
用 st 数组标记各个节点有没有走到过。
从 1 号节点开始，广度优先遍历：
1 号节点入队列，dist[1] 的值更新为 0。
如果队列非空，就取出队头，找到队头节点能到的所有节点。如果队头节点能到走到的节点没有标记过，就将节点的dist值更新为队头的dist值+1，然后入队。
重复步骤 2 直到队列为空。
这个时候，dist数组中就存储了 1 号节点到各个节点的距离了。如果距离是无穷大，则不能到达，输出 -1，如果距离不是无穷大，则能到达，输出距离。
***图的存储：邻接表
用 h 数组保存各个节点能到的第一个节点的编号。开始时，h[i] 全部为 -1。
用 e 数组保存节点编号，ne 数组保存 e 数组对应位置的下一个节点所在的索引。
用 idx 保存下一个 e 数组中，可以放入节点位置的索引
插入边使用的头插法，例如插入：a->b。首先把b节点存入e数组，e[idx] = b。然后 b 节点的后继是h[a]，ne[idx] = h[a]。最后，a 的后继更新为 b 节点的编号，h[a] = idx，索引指向下一个可以存储节点的位置，idx ++ 。

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;//邻接表数据结构
int d[N];//存储距离
int st[N];//标记点是否走到过

void add(int a, int b)//邻接表存储图
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs()
{
    memset(d, -1, sizeof d);//初始都没有走到过，距离无穷大
    //memset(dist, 0x3f, sizeof(dist));//初始都没有走到过，距离无穷大

    queue<int> q;
    d[1] = 0;//从1号节点开始，距离为0

    q.push(1);//1号节点入队列

    st[1] = 1;//1到1的距离为0，已经求出

    while (q.size()); //队列非空，就一直往后搜索
    {
        int t = q.front();//队头出队，找该点能到的点
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i]) //遍历所有t节点能到的点，i为节点索引
        {
            int j = e[i];//通过索引i得到t能到的节点编号
            if (d[j] == -1)//如果没有遍历过
            {
                d[j] = d[t] + 1;//距离为t号节点的距离+1
                q.push(j);//节点入队
                st[j] = 1;//入队后标记，已经遍历过了
            }
        }
    }

    return d[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);//初始化，所有节点没有后继，后继都是-1

    for (int i = 0; i < m; i ++ ) //读入所有边
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);//加入邻接表
    }
    // << 尖尖指向的地方代表数据的地方
    cout << bfs() << endl; ////广度优先遍历
     

    // cout << (d[n] == 0x3f3f3f3f ? -1 : d[n]);//如果到n号节点的距离不是无穷大，输出距离，如果是无穷大，输出-1.
    return 0;
}

y总
思路：用广度优先搜索的思想，每当队列pop出一个元素时，将于其距离为1的节点都加到队列中（即层次遍历的思想）。

如果对层次遍历的思想有疑问的同学，建议先看bfs的习题 走迷宫（C++实现）。

本题最大的难点就在于如何进行层次遍历，我们来看这样一个例子，有这样一幅图，我已经将其转换成了邻接表进行存储。（不知道如何转换成邻接表存储的同学，建议先看bfs的习题，在给出的链接中复习一下如何用邻接表存储图）

图中的数组是一个存储头结点的数组，我们给定一个节点1，那么在h[1]指向的这条链表上，都是与节点1相邻的节点（即距离为1）因此，在pop出一个节点t时，只需使用h[t]指向它的链表，再通过for(int i = h[t]; i != -1; i = ne[i])，就可以遍历一整条链表上的节点。然后在遍历时将其加到队列中，并将其的长度置位h[t]+1即可

上述文字转换成代码如下（d数组用来存储节点1到节点j的距离）：

for (int i = h[t]; i != -1; i = ne[i]) // ne[i]上的点都是与i节点距离为1的点
        {
            int j = e[i]; // 向外走一步
            if (d[j] == -1) // 如果j没有被遍历过
            {
                d[j] = d[t] + 1; // 因为路径长度都是1，所以直接在上一步的基础上加上1即可
                q.push(j); // 将j加到队列中
            }
        }

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];// 保存1号点到各个点的距离
//A1开始
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
//A1结束
int bfs()
{
    //A2开始
    memset(d, -1, sizeof d);

    queue<int> q;
    d[1] = 0;
    q.push(1);

    while (q.size())
    {
        int t = q.front();
        q.pop();
        //---------------------------------------A2结束--------------------------------

        // ---------------核心代码开始---------------------------------------
        // 循环遍历所有与t相距为1的节点
        for (int i = h[t]; i != -1; i = ne[i]) // ne[i]上的点都是与i节点距离为1的点
        {
            int j = e[i]; // 向外走一步
            if (d[j] == -1) // 如果j没有被遍历过
            {
                d[j] = d[t] + 1; // 因为路径长度都是1，所以直接在上一步的基础上加上1即可
                q.push(j); // 将j加到队列中
            }
        }
    }
    return d[n]; // 返回的d[n]即是节点1到节点n的距离

    // ---------------核心代码结束---------------------------------------
}


// ---------------A3开始---------------------------------------
int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}

- A1和A3代码来自于[AcWing]846. 树的重心（C++实现）树与图的dfs模板题具体指的是邻接表的存储和main函数的输入输出
- A2块代码来自于 [AcWing]844. 走迷宫（C++实现）bfs的思想 ，其展现了层次遍历的思想以及队列是如何实现该思想的。

#include <cstring>
#include <iostream>

using namespace std;

const int N=1e5+10;

int h[N], e[N], idx, ne[N];
int d[N]; //存储每个节点离起点的距离  d[1]=0
int n, m; //n个节点m条边
int q[N]; //存储层次遍历序列 0号节点是编号为1的节点

void add(int a, int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int bfs()
{
    int hh=0,tt=0;

    q[0]=1; //0号节点是编号为1的节点

    memset(d,-1,sizeof d);

    d[1]=0; //存储每个节点离起点的距离

    //当我们的队列不为空时
    while(hh<=tt)
    {
        //取出队列头部节点
        int t=q[hh++];

        //遍历t节点的每一个邻边
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            //如果j没有被扩展过
            if(d[j]==-1)
            {
                d[j]=d[t]+1; //d[j]存储j节点离起点的距离，并标记为访问过
                q[++tt] = j; //把j结点 压入队列
            }
        }
    }

    return d[n];
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }

    cout<<bfs()<<endl;
}



拓扑排序 —— 模板题 AcWing 848. 有向图的拓扑序列
只适用于 AOV网 （有向无环图）
拓扑排序: 
一个有向图，如果图中有入度为 0 的点，就把这个点删掉，同时也删掉这个点所连的边。一直进行上面出处理，如果所有点都能被删掉，则这个图可以进行拓扑排序。
算法流程：
用队列来执行，初始化讲所有入度为0的顶点入队。

主要由以下两步循环执行，直到不存在入度为 0 的顶点为止
1. 选择一个入度为 0 的顶点，并将它输出
2. 删除图中从顶点连出的所有边。
循环结束，若输出的顶点数小于图中的顶点数，则表示该图存在回路，即无法拓扑排序，否则，输出的就是拓扑序列 （不唯一）

首先记录各个点的入度
然后将入度为 0 的点放入队列
将队列里的点依次出队列，然后找出所有出队列这个点发出的边。删除边，同时 边的另一侧的点的入度为 -1。
如果所有点都进过队列，则可以拓扑排序，输出所有顶点。否则输出-1，代表不可以进行拓扑排序。

时间复杂度 O(n+m), nn 表示点数，mm 表示边数
bool topsort()
{
    int hh = 0, tt = -1;

    // d[i] 存储点i的入度
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }

    // 如果所有点都入队了，说明存在拓扑序列 否则不存在拓扑序列。
    return tt == n - 1;
}

// 解题代码
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int e[N], ne[N], idx;//邻接矩阵存储图
int h[N];
int q[N], hh = 0, tt = -1;//队列保存入度为0的点，也就是能够输出的点，
int n, m;//保存图的点数和边数
int d[N];////保存各个点的入度

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    for(int i = 1; i <= n; i++){//遍历一遍顶点的入度。
        if(d[i] == 0)//如果入度为 0, 则可以入队列
            q[++tt] = i;
    }
    while(tt >= hh){//循环处理队列中点的
        int a = q[hh++];
        for(int i = h[a]; i != -1; i = ne[i]){//循环删除 a 发出的边
            int b = e[i];//a 有一条边指向b
            d[b]--;//删除边后，b的入度减1
            if(d[b] == 0)//如果b的入度减为 0,则 b 可以输出，入队列
                q[++tt] = b;
        }
    }
    if(tt == n - 1){//如果队列中的点的个数与图中点的个数相同，则可以进行拓扑排序
        for(int i = 0; i < n; i++){//队列中保存了所有入度为0的点，依次输出
            cout << q[i] << " ";
        }
    }
    else//如果队列中的点的个数与图中点的个数不相同，则可以进行拓扑排序
        cout << -1;//输出-1，代表错误
}


int main(){
    cin >> n >> m;//保存点的个数和边的个数
    memset(h, -1, sizeof h);//初始化邻接矩阵
    while (m -- ){//依次读入边
        int a, b;
        cin >> a >> b;
        d[b]++;//顶点b的入度+1
        add(a, b);//添加到邻接矩阵
    }
    topsort();//进行拓扑排序
    return 0;
}


#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N =100010;

int n, m; //m个节点n条边
int h[N], e[N], ne[N], idx;//邻接矩阵存储图
int d[N]; //存储i号节点的入度
int q[N]; //队列存储层次遍历序列

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool topsort() //返回布尔序列是否存在， 若存在，则存储在q数组中
{
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i ++)  //遍历每一个节点, 入度为零则入队
      if (!d[i])
        q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++];  //队列不空，则取出头节点

        for (int i = h[t]; i != -1; i = ne[i]) //遍历头节点的每一个出边
        {
            int j = e[i];  //出边能到达的节点，入度减1
            if ( -- d[j] == 0) //如果结点j，入度为0则入队
                 q[ ++ tt] = j;
        }
    }

    return tt == n - 1;
}

int main()
{
    scanf(%d%d, &n, &m);

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b); //b节点入度加1

        d[b] ++ ;
    }
    if (!topsort() puts("-1"));
    else
    {
        for (int i = 0; i < n; i ++ ) printf("%d", q[i]);
        puts("");
    }

    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int e[N],ne[N],h[N],idx,d[N],n,m,top[N],cnt = 1;
// e,ne,h,idx 邻接表模板
// d 代表每个元素的入度
// top是拓扑排序的序列，cnt代表top中有多少个元素
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
bool topsort(){
    queue<int> q;
    int t;
    for(int i = 1;i <= n; ++i)// 将所有入度为0的点加入队列
        if(d[i] == 0) q.push(i);
    while(q.size()){
        t = q.front();//每次取出队列的首部
        top[cnt] = t;//加入到 拓扑序列中
        cnt ++; // 序列中的元素 ++
        q.pop();
        for(int i = h[t];i != -1; i = ne[i]){
            // 遍历 t 点的出边
            int j = e[i];
            d[j] --;// j 的入度 --
            if(d[j] == 0) q.push(j); //如果 j 入度为0，加入队列当中
        }
    }
    if(cnt < n) return 0;
    else return 1;

}
int main(){
    int a,b;
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--){
        cin >> a >> b;
        add(a,b);
        d[b] ++;// a -> b , b的入度++
    }
    if(topsort() == 0) cout << "-1";
    else {
        for(int i = 1;i <= n; ++i){
            cout << top[i] <<" ";
        }
    }
    return 0;
}




朴素dijkstra算法 —— 模板题 AcWing 849. Dijkstra求最短路 I
迪杰斯特拉算法(Dijkstra)是由荷兰计算机科学家狄克斯特拉于1959 年提出的，因此又叫狄克斯特拉算法。是从一个顶点到其余各顶点的最短路径算法，解决的是有权图中最短路径问题。迪杰斯特拉算法主要特点是从起始点开始，采用贪心算法的策略，每次遍历到始点距离最近且未访问过的顶点的邻接节点，直到扩展到终点为止。

贪心算法策略

时间复杂是 O(n2+m), nn 表示点数，mm 表示边数
int g[N][N];  // 存储每条边
int dist[N];  // 存储1号点到每个点的最短距离
bool st[N];   // 存储每个点的最短路是否已经确定

// 求1号点到n号点的最短路，如果不存在则返回-1

最短路：单源最短路
朴素：Dijkstra时间复杂度O（n^2）
1. 初始化 dist[1]=0，dist[i]=0x3f S：当前已确定最短距离的点
2. for(int i=1; i<=n; i++)
{
    1. 寻找不在s中的距离最近的点t
    2. 将t加到s中
    3. 用t更新其他点的距离
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);//除1号结点外，其他均初始为无穷大
    dist[1] = 0;

    for (int i = 0; i < n - 1; i ++ )//n次迭代，每次寻找不在s中距离最近的点t
    {
        int t = -1;     // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j; 
                st[t]=true;  //将t加到s中

        // 用t更新其他点的距离
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);

    }

    if (dist[n] == 0x3f3f3f3f) return -1; //路径不存在
    return dist[n];
}

// 解题代码
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N =510;

int n, m;
int g[N][N];//稠密图一般使用邻接矩阵
int dist[N]; //dist存储的是最短的距离,g存储的是邻接矩阵 记录每个节点距离起点的距离
bool st[N]; //表示该点是否已经确定了最短距离

int dijkstra()
{
  memset(dist, 0x3f, sizeof dist); //初始化距离 所有节点距离起点的距离初始化为无穷大
  dist[1] = 0;//起点到起点的距离为0

  for (int i = 0; i < n - 1; i ++ )//因为每次循环中都可以确定一个最短距离的点,因为总共有n个点,1这个点的距离已经确定了,所以循环n-1次
  {
      int t = -1;//t=-1的作用是可以找出第一个点
      for (int j = 1; j <= n; j ++ ) //第一轮循环,寻找与起点最短距离的点
         if (!st[j] && (t == -1 || dist[t] > dist[j]))
         t = j;
      for (int j = 1; j <= n; j ++ )
         dist[j] = min(dist[j], dist[t] + g[t][j]);
      
      st[t] = true; //标记该点的最短距离已经确定了,然后用确定的点更新其他点的最短距离

  }

  if (dist[n] == 0x3f3f3f3f) return -1;/
  如果n到起点的距离为0x3f说明走不到n这个点
    //注:不能写成0x3f,只有清空操作时才能用0x3f,其他操作时需要写成0x3f3f3f3f,否则会报错
  return dist[n];//返回起点到n的最短距离
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);;//将所有边的权值更新为一个非常大的数字
    while (m -- ) //输入边与边之间的权值
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        g[a][b] = min(g[a][b], c);//可能存在重边,而本题追求的是最短距离,所以选择重边中最短的那条边
    }

    printf("%d\n", dijkstra());

    return 0;
}

Dijkstra 的整体思路比较清晰
即进行n（n为n的个数）次迭代去确定每个点到起点的最小值 最后输出的终点的即为我们要找的最短路的距离
所以按照这个思路除了存储图外我们还需要存储两个量
dist[n] //用于存储每个点到起点的最短距离
st[n]   //用于在更新最短距离时 判断当前的点的最短距离是否确定 是否需要更新
每次迭代的过程中我们都先找到当前未确定的最短距离的点中距离最短的点
（至于为什么是这样那么这就涉及到Dijkstra算法的具体数学证明了 有兴趣的同学可以百度一下）
int t=-1;       //将t设置为-1 因为Dijkstra算法适用于不存在负权边的图
for(int j=1;j<=n;j++)
{
    if(!st[j]&&(t==-1||dist[t]>dist[j])    //该步骤即寻找还未确定最短路的点中路径最短的点
        t=j;
}
通过上述操作当前我们的t代表就是剩余未确定最短路的点中 路径最短的点
而与此同时该点的最短路径也已经确定我们将该点标记
st[t]=true;
然后用这个去更新其余未确定点的最短距离

for(int j=1;j<=n;j++)
    dist[j]=min(dist[j],dist[t]+g[t][j]);
//这里可能有同学要问j如果从1开始的话 会不会影响之前已经确定的点的最小距离
//但其实是不会 因为按照我们的Dijkstra算法的操作顺序 先确定最短距离的点的距离已经比后确定的要小 所以不会影响
//当然你也可以在循环判断条件里加上if(!st[i])
//这里j从1开始只是为了代码的简洁

进行n次迭代后最后就可以确定每个点的最短距离
然后再根据题意输出相应的 要求的最短距离

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=510;
int g[N][N];    //稠密图用邻接矩阵存储比较节省空间
int dist[N];    //dist[i] i结点到起始点(1号结点)的距离
bool st[N] ;    //st[i] 用于标记i结点的最短路是否确定，若确定st[i]=true;
int n,m;

int Dijkstra()
{
    memset(dist,0x3f,sizeof dist);//除1号结点外，其他均初始为无穷大
    dist[1]=0;
    for(int i=0;i<n;i++) //n次迭代，每次寻找不在s中距离最近的点t
    {
        int t=-1;// 便于更新第一个点
        for(int j=1;j<=n;j++)
          if(!st[j]&&(t==-1||dist[j]<dist[t])) t=j;
        st[t]=true;  //将t加到s中
        for(int j=1;j<=n;j++)  //用t更新其他点的距离
          dist[j]=min(dist[j],dist[t]+g[t][j]);
    }
    if(dist[n]==0x3f3f3f3f) return -1; //路径不存在
    else return dist[n];
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);   //邻接矩阵的初始化，由于求的是最小值，因此初始为无穷大

    while(m--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[x][y]=min(g[x][y],z); //重边中去取最小值
    }
    printf("%d\n",Dijkstra());
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int n, m;
int g[N][N]; //稠密图一般使用邻接矩阵
int dist[N]; //记录每个节点距离起点的距离
bool st[N]; //True表示已经确定最短路 属于s集合

int dijkstra() {
    //所有节点距离起点的距离初始化为无穷大
    memset(dist, 0x3f, sizeof dist);
    //起点距离自己的距离为零
    dist[1] = 0;

    //迭代n次，每次可以确定一个点到起点的最短路
    for (int i = 0; i < n; ++i) {
        int t = -1;
        //t的作用？

        for (int j = 1; j <= n; ++j) {
            //不在s集合，并且
            //如果没有更新过，则进行更新， 或者发现更短的路径，则进行更新
            if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }

        //加入到s集合中
        st[t] = true;

        //找到了距离最小的点t，并用最小的点t去更新其他的点到起点的距离
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }

    // 如果起点到达不了n号节点，则返回-1
    if (dist[n] == 0x3f3f3f3f) return -1;
    // 返回起点距离n号节点的最短距离
    return dist[n];
}

int main() {
    cin >> n >> m;
    //所有节点之间的距离初始化为无穷大
    memset(g, 0x3f, sizeof g);
    // 0x3f 0x3f3f3f3f 的区别？

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c); //如果有重边，请保留权值最小的一条边
    }

    cout << dijkstra() << endl;

    return 0;
}


0x3f为什么赋值的时候可以memset(dist,0x3f,sizeof dist)但是到后面验证的时候必须是if(dist[n]==0x3f3f3f3f)而不能是if(dist[n]==0x3f)
回答: memset是按字节来初始化的，int包含4个字节，所以初始化之后的值就是0x3f3f3f3f。

为什么要用memset(dist,0x3f,sizeof dist)来初始化
回答:0x3f3f3f3f的十进制是1061109567，是1e9级别的（和0x7fffffff一个数量级，0x7fffffff代表了32-bit int的最大值），而一般场合下的数据都是小于1e9的，所以它可以作为无穷大使用而不致出现数据大于无穷大的情形。 另一方面，由于一般的数据都不会大于10^9，所以当我们把无穷大加上一个数据时，它并不会溢出（这就满足了“无穷大加一个有穷的数依然是无穷大”），事实上0x3f3f3f3f+0x3f3f3f3f=2122219134，这非常大但却没有超过32-bit int的表示范围，所以0x3f3f3f3f还满足了我们“无穷大加无穷大还是无穷大”的需求。

for(int i=0;i<n;i++) { t=-1 } 这里为什么t要赋值为 -1
回答: 由于每一次都要找到还没有确定最短路距离的所有点中，距离当前的点最短的点。t = - 1是为了在st这个集合中找第一个点更新时候的方便所设定的。

如果是问编号a到b的最短距离该怎么改呢? （好问题）
回答： 初始化时将 dist[a]=0,以及返回时return dist[b]。

自环和重边对 Dijkstrea算法有影响吗？
回答： 自环在朴素版dijkstra算法中是没有任何影响的，所以自环的权值是多少都可以，只要不是负数就行。而重边时，我们去取重边中的最小值 即代码g[x][y]=min(g[x][y],z)。

为什么要用邻接矩阵去存贮，而不是邻接表？
回答： 我们采用邻接矩阵还是采用邻接表来表示图，需要判断一个图是稀疏图还是稠密图。稠密图指的是边的条数|E|接近于|V|²，稀疏图是指边的条数|E|远小于于|V|²（数量级差很多）。本题是稠密图，显然稠密图用邻接矩阵存储比较节省空间，反之用邻接表存储。


朴素版与堆优化版时间复杂度比较
朴素版时间复杂度O(n2)
for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++) {
        if (!st[j] && (t == -1 || dist[j] < dist[t]))
            t = j; // O(n) * O(n) -> O(n^2)
    }
    st[t] = true; // O(n) * O(1) -> O(n)
    for (int j = 1; j <= n; j++) {
        dist[j] = min(dist[j], dist[t] + g[t][j]); //O(n) * O(n) -> O(n^2)
    }
}


堆优化版时间复杂度O(mlog(n))
//遍历大部分的边
while (heap.size()) {
    auto t = heap.top(); //O(m) * O(1) -> O(m)
    heap.pop();
    int ver = t.second, distance = t.first;
    if (st[ver])continue;
    st[ver] = true;  //O(m) * O(1) -> O(m)
    for (int i = h[ver]; i != -1; i = ne[i]) {
        int j = e[i];
        if (dist[j] > distance + w[i]) {
            dist[j] = distance + w[i];
            heap.push({dist[j], j});
            // 堆的插入操作时间复杂度是 O(log(n))
            // O(m) * O(log(n)) -> O(mlog(n))
        }
    }
}


堆优化版dijkstra —— 模板题 AcWing 850. Dijkstra求最短路 II
c++有个stl容器，priority_queue默认大根堆，你在后面加个vector<类型>,greater<类型>就可以设置成小根堆，这个是别人设定好了的，就直接照着写拿来用就是了，不需要了解底层原理

稠密图是指点:边 = n : n ^2
稀疏图是指点:边 = n : n

朴素版dijkstra适合稠密图
思路
集合S为已经确定最短路径的点集。
1. 初始化距离
一号结点的距离为零，其他结点的距离设为无穷大（看具体的题）。
2. 循环n次，每一次将集合S之外距离最短X的点加入到S中去（这里的距离最短指的是距离1号点最近。点X的路径一定最短，基于贪心，严格证明待看）。然后用点X更新X邻接点的距离。

时间复杂度分析
寻找路径最短的点：O(n2)
加入集合S：O(n)
更新距离：O(m)
所以总的时间复杂度为O(n2)
具体问题
稠密图用邻接矩阵存。

堆优化版dijkstra适合稀疏图
思路
堆优化版的dijkstra是对朴素版dijkstra进行了优化，在朴素版dijkstra中时间复杂度最高的寻找距离最短的点O(n^2)可以使用最小堆优化。
1. 一号点的距离初始化为零，其他点初始化成无穷大。
2. 将一号点放入堆中。
3. 不断循环，直到堆空。每一次循环中执行的操作为：
    弹出堆顶（与朴素版diijkstra找到S外距离最短的点相同，并标记该点的最短路径已经确定）。
    用该点更新临界点的距离，若更新成功就加入到堆中。
时间复杂度分析
寻找路径最短的点：O(n)
加入集合S：O(n)
更新距离：O(mlogn)
具体问题

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010; // 把N改为150010就能ac

// 稀疏图用邻接表来存
int h[N], e[N], ne[N], idx;
int w[N]; // 用来存权重
int dist[N];
bool st[N]; // 如果为true说明这个点的最短路径已经确定

int n, m;

void add(int x, int y, int c)
{
    w[idx] = c; // 有重边也不要紧，假设1->2有权重为2和3的边，再遍历到点1的时候2号点的距离会更新两次放入堆中
    e[idx] = y; // 这样堆中会有很多冗余的点，但是在弹出的时候还是会弹出最小值2+x（x为之前确定的最短路径），并
    ne[idx] = h[x]; // 标记st为true，所以下一次弹出3+x会continue不会向下执行。
    h[x] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap; // 定义一个小根堆
    // 这里heap中为什么要存pair呢，首先小根堆是根据距离来排的，所以有一个变量要是距离，其次在从堆中拿出来的时候要知道知道这个点是哪个点，不然怎么更新邻接点呢？所以第二个变量要存点。
    heap.push({ 0, 1 }); // 这个顺序不能倒，pair排序时是先根据first，再根据second，这里显然要根据距离排序
    while(heap.size())
    {
        PII k = heap.top(); // 取不在集合S中距离最短的点
        heap.pop();
        int ver = k.second, distance = k.first;

        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i]; // i只是个下标，e中在存的是i这个下标对应的点。
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({ dist[j], j });
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);

    while (m--)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        add(x, y, c);
    }

    cout << dijkstra() << endl;

    return 0;
}


时间复杂度 O(mlogn), n表示点数，m表示边数
typedef pair<int, int> PII;

int n;      // 点的数量
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储所有点到1号点的距离
bool st[N];     // 存储每个点的最短距离是否已确定

// 求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});      // first存储距离，second存储节点编号

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

// 解题代码
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII; //<离起点的距离， 节点编号>

const int N = 1e6 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

//在a节点之后插入一个b节点，权重为c
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a]. h[a] = idx ++ ;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist); //所有距离初始化为无穷大
    dist[1] = 0;//1号节点距离为0
    priority_queue<PII, vector<PII>, greater<PII>> heap;// 建立一个小根堆 c++有个stl容器，priority_queue默认大根堆，你在后面加个vector<类型>,greater<类型>就可以设置成小根堆，这个是别人设定好了的，就直接照着写拿来用就是了，不需要了解底层原理

    // 稠密图是指点:边 = n : n ^2
    // 稀疏图是指点:边 = n : n
    heap.push({0,1});// 1号节点插入堆

    while (heap.size())//取出堆顶顶点
    {
        auto t = heap.top();//并删除
        heap.pop();// 取出节点编号和节点距离

        int ver = t.second, distance = t.first; //如果节点被访问过，则跳过

        if (st[ver]) continue;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
           int j = e[i];// 取出节点编号
           if (dist[j] > dist[ver] + w[i]) // dist[j] 大于从t过来的距离
           {
               dist[j] = dist[ver] + w[i];
               heap.push({dist[j], j});
           }
        }
    } 

    if (dist[n] == 0x3f3f3f) return -1;
    return dist[n]; 
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m -- )
    { 
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    cout << dijkstra() << endl;

     return 0;
}


#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int,int> PII;
const int N=1000010;
int h[N],ne[N],e[N],w[N],dist[N],idx;//w表示权重
int n,m;
bool st[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    //小根堆的定义方式,PII的第一个变量存储的是距离,第二个变量存储的是该点的编号,内部按照第一个变量排序,即按距离排序
    dist[1]=0;
    heap.push({0,1});
    while(heap.size())
    {
        auto t=heap.top();//选择最小的距离的点
        heap.pop();//利用完该点之后要弹出
        int ver=t.second;//表示该点的编号
        if(st[ver]) continue;
        /*
        堆优化版的是将距离直接加入到堆中.
        例如:dist[5]=9(在堆中{9,5},第一次更新时加入),dist[5]=7(在堆中{7，5},第二次更新时加入)
        使用时用的是dist[5]=7,将该点({7,5})弹出后,在下一次循环中,如果{9,5}在堆顶的话,使用时
        两者间肯定要选距离要小的那个,不能使用{9,5}重复更新,所以要用st数组进行标记
        */
        st[ver]=true;//标记该点已经使用过了
        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[ver]+w[i])//如果j到起点的距离大于ver到1的距离加上ver到j的距离，就更新值的大小；
            {
                dist[j]=dist[ver]+w[i];
                heap.push({dist[j],j});
                /*
                更新距离之后将该点的距离加入到堆中,这也是上述为何要进行标记的原因,
                因为一个点的距离加入堆的次数可能有两次甚至更多,这样会影响到其他的点
                例如:
                {9,5},{7,5},{10,6},如果{7,5}被弹出后,堆中剩余的是{9,5},{10,6},堆顶
                的元素是{9,5}而5这个点的距离已经被使用过了,所以要将{9,5}这个点忽视掉
                */
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    memset(h,-1,sizeof(h));
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    cout<<dijkstra()<<endl;
    return 0;
}


Dijkstra求最短路 II 使用stl邻接表(比数组邻接表代码好读一些)
使用双重vector 来表示邻接表 比数组的邻接表好读一点 开销差不多

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> PII;

const int N = 100010;
vector<vector<pair<int, int>>> gra;
int dist[N];
int st[N];
int n, m;

int solve()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    //这里是距离在前 节点号在后
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({ 0, 1 });      // first存储距离，second存储节点编号

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int node = t.second; int distance = t.first;

        if (st[node]) continue;
        st[node] = true;
        //查看每个出边
        for (int i = 0; i < gra[node].size(); i++) {
            int newnode = gra[node][i].first;
            int len = gra[node][i].second;
            if (dist[newnode] > dist[node] + len) {
                dist[newnode] = dist[node] + len;
                heap.push({ dist[newnode],newnode });
            }
        }


    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    //cin >> n >> m;
    scanf("%d %d",&n,&m);
    gra.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        //cin >> a >> b >> c;
        scanf("%d %d %d",&a,&b,&c);
        //这里是 目的节点号在前 边长在后
        gra[a].push_back({ b,c });
    }

    printf("%d\n",  solve() );

    return 0;
}

在一组数中每次能很快的找到最小值，很容易想到使用小根堆。可以使用库中的小根堆（推荐）或者自己编写
使用小根堆后，找到 t 的耗时从 O(n^2) 将为了 O(1)。每次更新 dist 后，需要向堆中插入更新的信息。所以更新dist的时间复杂度有 O(e) 变为了 O(e*logn)。总时间复杂度有 O(n^2) 变为了 O(n + e*longn)。适用于稀疏图。
迪杰斯特拉算法适用于求正权有向图中，源点到其余各个节点的最短路径。注意：图中可以有环，但不能有负权边。



Bellman-Ford算法 —— 模板题 AcWing 853. 有边数限制的最短路
明确一下松弛的概念。
考虑节点u以及它的邻居v，从起点跑到v有好多跑法，有的跑法经过u，有的不经过。
经过u的跑法的距离就是distu+u到v的距离。
所谓松弛操作，就是看一看distv和distu+u到v的距离哪个大一点。
如果前者大一点，就说明当前的不是最短路，就要赋值为后者，这就叫做松弛。

1问题：为什么Dijkstra不能使用在含负权的图中？
Dijkstra算法的3个步骤
1、找到当前未标识的且离源点最近的点t
2、对t号点点进行标识
3、用t号点更新其他点的距离

结果：
dijkstra算法在图中走出来的最短路径是1 -> 2 -> 4 -> 5，算出 1 号点到 5 号点的最短距离是2 + 2 + 1 = 5，然而还存在一条路径是1 -> 3 -> 4 -> 5，该路径的长度是5 + (-2) + 1 = 4，因此 dijkstra 算法失效

dijkstra详细步骤
初始dist[1] = 0
找到了未标识且离源点1最近的结点1，标记1号点，用1号点更新其他所有点的距离，2号点被更新成dist[2] = 2，3号点被更新成dist[3] = 5
找到了未标识且离源点1最近的结点2，标识2号点，用2号点更新其他所有点的距离，4号点被更新成dist[4] = 4
找到了未标识且离源点1最近的结点4，标识4号点，用4号点更新其他所有点的距离，5号点被更新成dist[5] = 5
找到了未标识且离源点1最近的结点3，标识3号点，用3号点更新其他所有点的距离，4号点被更新成dist[4] = 3
结束
得到1号点到5号点的最短距离是5，对应的路径是1 -> 2 -> 4 -> 5，并不是真正的最短距离

2、什么是bellman - ford算法？
Bellman - ford 算法是求含负权图的单源最短路径的一种算法，效率较低，代码难度较小。其原理为连续进行松弛，在每次松弛时把每条边都更新一下，若在 n-1 次松弛后还能更新，则说明图中有负环，因此无法得出结果，否则就完成。
(通俗的来讲就是：假设 1 号点到 n 号点是可达的，每一个点同时向指向的方向出发，更新相邻的点的最短距离，通过循环 n-1 次操作，若图中不存在负环，则 1 号点一定会到达 n 号点，若图中存在负环，则在 n-1 次松弛后一定还会更新)
dist[b] = min(dist[b], backup[a] + w);

3、bellman - ford算法的具体步骤
for n次
for 所有边 a,b,w (松弛操作)
dist[b] = min(dist[b],back[a] + w)
注意：back[] 数组是上一次迭代后 dist[] 数组的备份，由于是每个点同时向外出发，因此需要对 dist[] 数组进行备份，若不进行备份会因此发生串联效应，影响到下一个点

4、在下面代码中，是否能到达n号点的判断中需要进行if(dist[n] > INF/2)判断，而并非是if(dist[n] == INF)判断，原因是INF是一个确定的值，并非真正的无穷大，会随着其他数值而受到影响，dist[n]大于某个与INF相同数量级的数即可

5、bellman - ford算法擅长解决有边数限制的最短路问题
时间复杂度 O(nm), n 表示点数，m 表示边数
注意在模板题中需要对下面的模板稍作修改，加上备份数组，详情见模板题。

bellman_ford算法
1)初始化所有点到源点的距离为∞,把源点到自己的距离设置为0
2)不管3721遍历n次;每次遍历m条边，用每一条边去更新各点到源点的距离。

值得注意的是
1) 需要把dist数组进行一个备份，这样防止每次更新的时候出现串联
2) 由于存在负权边，因此return -1的条件就要改成dist[n]>0x3f3f3f3f/2;： 
1] 重边：由于遍历了所有的边，总会遍历到较短的那一条; 2] 自环: 有自环就有自环啊，反正又不会死循环;
5) 令人愉悦的是，该算法无非就是循环n次然后遍历所有的边，因此不需要做什么特别的存储，只要把所有的边的信息存下来能够遍历就行;
6）bellman_ford算法可以存在负权回路，因为它求得的最短路是有限制的，是限制了边数的，这样不会永久的走下去，会得到一个解
7)SPFA算法各方面优于该算法，但是在碰到限制了最短路径上边的长度时就只能用bellman_ford了，此时直接把n重循环改成k次循环即可


int n, m;  // n表示点数，m表示边数
int dist[N];   // dist[x]存储1到x的最短路距离

struct Edge // 边，a表示出点，b表示入点，w表示边的权重
{
    int a, b, w;
}edges[M];

// 求1到n的最短路距离，如果无法从1走到n，则返回-1。
int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < m; j ++ )
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if (dist[b] > dist[a] + w)
                dist[b] = dist[a] + w;
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

算法步骤
0.初始化dist数组为正无穷，dist[1]=0;

1.（外重循环）循环i从1到n，遍历n次指的：是不经过i条边到达终点的最短距离
经过n次操作n个点的最短距离也就确定了

2.（内重循环）循环j从1到m，遍历m条边，把所有边都进行松弛操作
每次取出两点以及他们连接的边的权重（a,b,w表示a—>b的一条边）
用从起点到a的当前最短距离+权重来更新从起点到b的当前最短距离
dist[b]=min(dist[b],dist[a]+w);

3.返回答案

为什么跑完算法就能算出最短距离呢
因为第二重循环遍历了m条边，每条都被遍历了n次
所以这n个点的所有他的前驱后继相对应的边权一定都被遍历到了
又因为他是有松弛操作的，所以只要上一个点（前驱）的当前最短路求出来了
这个点就可以用他的前驱来更新他的最短距离，从而他的后继又可以用它来更新最短距离了
// 解题代码

#include<iostream>
#include<cstring>

using namespace std;

const int N = 510, M = 10010;

struct Edge {
    int a;
    int b;
    int w;
} e[M];//把每个边保存下来即可
int dist[N];//dist[N]表示从起点到当前点的当前最短距离
int back[N];//备份数组防止串联
int n, m, k;//k代表最短路径最多包涵k条边

int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++) {//k次循环
        memcpy(back, dist, sizeof dist);
        for (int j = 0; j < m; j++) {//遍历所有边
            int a = e[j].a, b = e[j].b, w = e[j].w;
            dist[b] = min(dist[b], back[a] + w);
            //使用backup:避免给a更新后立马更新b, 这样b一次性最短路径就多了两条边出来
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    else return dist[n];

}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        e[i] = {a, b, w};
    }
    int res = bellman_ford();
    if (res == -1) puts("impossible");
    else cout << res;

    return 0;
}

java解法 bellman - ford算法

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static int N = 510;
    static int M = 100010;
    static int n;//总点数
    static int m;//总边数
    static int k;//最多经过k条边
    static int[] dist = new int[N];//从1到点到n号点的距离
    static Node[] list = new Node[M];//结构体
    static int INF = 0x3f3f3f3f;
    static int[] back = new int[N];//备份dist数组
    public static void bellman_ford()
    {
        Arrays.fill(dist, INF);

        dist[1] = 0;
        for(int i = 0;i < k;i++)
        {
            back = Arrays.copyOf(dist, n + 1);//由于是从1开始存到n
            for(int j = 0;j < m;j++)
            {
                Node node = list[j];
                int a = node.a;
                int b = node.b;
                int c = node.c;
                dist[b] = Math.min(dist[b], back[a] + c);
            }
        }
        if(dist[n] > INF/2) System.out.println("impossible");
        else System.out.println(dist[n]);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] str1 = reader.readLine().split(" ");
        n = Integer.parseInt(str1[0]);
        m = Integer.parseInt(str1[1]);
        k = Integer.parseInt(str1[2]);
        for(int i = 0;i < m;i++)
        {
            String[] str2 = reader.readLine().split(" ");
            int a = Integer.parseInt(str2[0]);
            int b = Integer.parseInt(str2[1]);
            int c = Integer.parseInt(str2[2]);
            list[i] = new Node(a,b,c);
        }
        bellman_ford();

    }

}
class Node
{
    int a, b, c;
    public Node(int a,int b,int c)
    {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}


spfa 算法（队列优化的Bellman-Ford算法） —— 模板题 
AcWing 851. spfa求最短路
时间复杂度 平均情况下 O(m)，最坏情况下 O(nm), n 表示点数，m 表示边数
spfa算法文字说明：
建立一个队列，初始时队列里只有起始点。
再建立一个数组记录起始点到所有点的最短路径（该表格的初始值要赋为极大值，该点到他本身的路径赋为0）。
再建立一个数组，标记点是否在队列中。
队头不断出队，计算始点起点经过队头到其他点的距离是否变短，如果变短且被点不在队列中，则把该点加入到队尾。
重复执行直到队列为空。
在保存最短路径的数组中，就得到了最短路径。

spfa和bellman-ford的区别，以及和djikstra的区别
首先，三者都是用来求最短路，但是思想和复杂度不相同。
bellman-ford 和spfa的区别
1.Bellman-ford算法中，循环n次，每次遍历m条边，每次遍历的时候，把入度的点的距离更新成最小。
然而，这样就循环遍历了很多用不到的边。比如第一次遍历，只有第一个点的临边是有效的。

2.因此，spfa算法中，采用邻接表的方式，只用到有效的点（更新了临边的点），直到每个点都是最短距离为止。采用队列优化的方式存储每次更新了的点，每条边最多遍历一次。如果存在负权回路，从起点1出发，回到1距离会变小， 会一直在三个点中循环。

Question:Question: 不用队列，遍历所有的点可以吗？
Ans:Ans:似乎不行，因为是更新了点之后，这个点的临边才可以用，如果没有更新到循环的点，那么循环的点也是不可用的。

spfa和dijkstra的区别：
st用来检验队列中是否有重复的点
spfa从队列中使用了当前的点，会把该点pop掉，状态数组st[i] = false(说明堆中不存在了) ，更新临边之后，把临边放入队列中， 并且设置状态数组为true，表示放入队列中 。如果当前的点距离变小，可能会再次进入队列，因此可以检验负环：

每次更新可以记录一次，如果记录的次数 > n,代表存在负环（环一定是负的，因为只有负环才会不断循环下去）。

st是一个集合，不是检验队列中的点。
dijkstra使用当前点更新临边之后，把该点加入到一个集合中，使用该点更新临边，并把临边节点和距离起点的距离置入堆中（不设置状态数组）。下一次从堆中取最小值，并把对应的节点放入集合中，继续更新临边节点，直到所有的点都存入集合中。因此dijkstra不判断负环。

从上述描述中能看出，dijkstra存放节点的堆，具有单调性，而spfa的队列不需要具有单调性。

dijkstra是基于贪心的思想，每次选择最近的点去更新其它点，过后就不再访问。
而在spfa算法中，只要有某个点的距离被更新了，就把它加到队列中，去更新其它点，所有每个点有被重复加入队列的可能。

SPFA算法的流程如下
1.建立一个队列，最初队列中只含有起点1.
2.取出队头节点x，扫描它的所有出边（x，y，z），若dist[y]>dist[x]+z，则使用dist[x]+z更新dist[y]，同时，若y不在队列中，则把y入队.
3.重复上述步骤，直到队列为空。
在任意时刻，该算法的队列都保存了待扩展的节点。每次入队相当于完成一次dist数组的更新操作，使其满足三角形不等式。一个节点可能会入队、出队多次。最终，图中节点收敛到全部满足三角形不等式的状态。这个队列避免了Bellman-
Ford算法中对不需要扩展的节点的冗余扫描，在稀疏图上运行效率较高，为O（km）级别，其中k是一个较小的常数。但在稠密图或特殊构造的网格图上该算法仍可能退化为O（nm）

SPFA算法在随机图上运行的效率为O（km），但是在特殊构造的图上，该算法很可能会退化为O（nm），必须谨慎使用。

spfa算法是bellman_ford的队列优化版本, bfs实现
优化的是dist[b] = min(dist[b], dist[a]+w)
因为只有dist[a]更新之后变小, dist[b]更新之后才有可能变小
需要st[i]数组，保证队列里面只有一个i;

明确一下松弛的概念。
考虑节点u以及它的邻居v，从起点跑到v有好多跑法，有的跑法经过u，有的不经过。
经过u的跑法的距离就是distu+u到v的距离。
所谓松弛操作，就是看一看distv和distu+u到v的距离哪个大一点。
如果前者大一点，就说明当前的不是最短路，就要赋值为后者，这就叫做松弛。

int n;      // 总点数
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储每个点到1号点的最短距离
bool st[N];     // 存储每个点是否在队列
// 求1号点到n号点的最短路距离，如果从1号点无法走到n号点则返回-1
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])     // 如果队列中已存在j，则不需要将j重复插入
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}



// 解题代码
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[N], w[N], ne[N], idx;//邻接表，存储图
int st[N];//标记顶点是不是在队列中
int dist[N];//保存最短路径的值
int q[N], hh, tt = -1;//队列

void add(int a, int b, int c){//图中添加边和边的端点
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa(){
    q[++tt] = 1;//从1号顶点开始松弛，1号顶点入队
    dist[1] = 0;//1号到1号的距离为 0
    st[1] = 1;//1号顶点在队列中
    while(tt >= hh){//不断进行松弛
        int a = q[hh++];//取对头记作a，进行松弛
        st[a] = 0;//取完队头后，a不在队列中了
        for(int i = h[a]; i != -1; i = ne[i])//遍历所有和a相连的点
        {
            int b = e[i], c = w[i];//获得和a相连的点和边
            if(dist[b] > dist[a] + c){//如果可以距离变得更短，则更新距离

                dist[b] = dist[a] + c;//更新距离

                if(!st[b]){//如果没在队列中
                    q[++tt] = b;//入队
                    st[b] = 1;//打标记
                }
            }
        }
    }
}
int main(){
    memset(h, -1, sizeof h);//初始化邻接表
    memset(dist, 0x3f, sizeof dist);//初始化距离
    int n, m;//保存点的数量和边的数量
    cin >> n >> m;
    for(int i = 0; i < m; i++){//读入每条边和边的端点
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);//加入到邻接表
    }
    spfa();
    if(dist[n] == 0x3f3f3f3f )//如果到n点的距离是无穷，则不能到达 
        cout << "impossible";
    else cout << dist[n];//否则能到达，输出距离
    return 0;
}


#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;//从队列中取出来之后该节点st被标记为false,代表之后该节点如果发生更新可再次入队

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])//当前已经加入队列的结点，无需再次加入队列，即便发生了更新也只用更新数值即可，重复添加降低效率
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m --)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    int t = spfa();

    if (t == 0x3f3f3f3f) puts("impossible");
    else printf("%d\n", t);

    return 0;
}

Bellman_ford算法会遍历所有的边，但是有很多的边遍历了其实没有什么意义，我们只用遍历那些到源点距离变小的点所连接的边即可，只有当一个点的前驱结点更新了，该节点才会得到更新 因此考虑到这一点，我们将创建一个队列每一次加入距离被更新的结点。

值得注意的是
1) st数组的作用：判断当前的点是否已经加入到队列当中了,已经加入队列的结点就不需要反复的把该点加入到队列中了，就算此次还是会更新到源点的距离，那只用更新一下数值而不用加入到队列当中。
即便不使用st数组最终也没有什么关系，但是使用的好处在于可以提升效率。
2) SPFA算法看上去和Dijstra算法长得有一些像但是其中的意义还是相差甚远的:

1] Dijkstra算法中的st数组保存的是当前确定了到源点距离最小的点，且一旦确定了最小那么就不可逆了(不可标记为true后改变为false),SPFA算法中的st数组仅仅只是表示的当前发生过更新的点，且spfa中的st数组可逆(可以在标记为true之后又标记为false)。顺带一提的是BFS中的st数组记录的是当前已经被遍历过的点。
2] Dijkstra算法里使用的是优先队列保存的是当前未确定最小距离的点，目的是快速的取出当前到源点距离最小的点,SPFA算法中使用的是队列(你也可以使用别的数据结构),目的只是记录一下当前发生过更新的点。

3) Bellman_ford算法里最后return-1的判断条件写的是dist[n]>0x3f3f3f3f/2;而spfa算法写的是dist[n]==0x3f3f3f3f;其原因在于Bellman_ford算法会遍历所有的边，因此不管是不是和源点连通的边它都会得到更新,但是SPFA算法不一样，它相当于采用了BFS，因此遍历到的结点都是与源点连通的，因此如果你要求的n和源点不连通，它不会得到更新，还是保持的0x3f3f3f3f。

4)  Bellman_ford算法可以存在负权回路，是因为其循环的次数是有限制的因此最终不会发生死循环,但是SPFA算法不可以，由于用了队列来存储，只要发生了更新就会不断的入队，因此假如有负权回路请你不要用SPFA否则会死循环。

5) 由于SPFA算法是由Bellman_ford算法优化而来，在最坏的情况下时间复杂度和它一样即时间复杂度为 O(nm) ，假如题目时间允许可以直接用SPFA算法去解Dijkstra算法的题目。(好像SPFA有点小小万能的感觉?)

6) 求负环一般使用SPFA算法，方法是用一个cnt数组记录每个点到源点的边数，一个点被更新一次就+1，一旦有点的边数达到了n那就证明存在了负环。



spfa判断图中是否存在负环 —— 模板题 AcWing 852. spfa判断负环

时间复杂度是 O(nm), n表示点数，m表示边数
int n; // 总点数
int h[N], w[N], e[N], ne[N], idx;  // 邻接表存储所有边
int dist[N], cnt[N];   // dist[x]存储1号点到x的最短距离，cnt[x]存储1到x的最短路中经过的点数
bool st[N];     // 存储每个点是否在队列中
// 如果存在负环，则返回true，否则返回false。
bool spfa()
{
    // 不需要初始化dist数组
    // 原理：如果某条最短路径上有n个点（除了自己），那么加上自己之后一共有n+1个点，由抽屉原理一定有两个点相同，所以存在环。

    queue<int> q;
    for (int i = 1; i <= n; i ++ )
    {
        q.push(i);
        st[i] = true;
    }

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;       // 如果从1号点到x的最短路中包含至少n个点（不包括自己），则说明存在环
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

// 解题代码
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N =2010, M = 10010;

int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool spfa()
{
    queue<int> q;

    for (int i = 1; i <= n; i ++ )
    {
        st[i] = true;
        q.push(i);
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n) return true;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                } 
            }
        }
    }

    return false;
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    if (spfa()) puts("Yes");
    else puts("No");

    return 0;
}


floyd算法 —— 模板题 AcWing 854. Floyd求最短路
多源汇最短路问题-具有多个源点-动态规划

时间复杂度是 O(n3), n表示点数
初始化：
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

// 算法结束后，d[a][b]表示a到b的最短距离
void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

算法分析
f[i, j, k]表示从i走到j的路径上除i和j点外只经过1到k的点的所有路径的最短距离。那么f[i, j, k] = min(f[i, j, k - 1), f[i, k, k - 1] + f[k, j, k - 1]。
因此在计算第k层的f[i, j]的时候必须先将第k - 1层的所有状态计算出来，所以需要把k放在最外层。
读入邻接矩阵，将次通过动态规划装换成从i到j的最短距离矩阵
在下面代码中，判断从a到b是否是无穷大距离时，需要进行if(t > INF/2)判断，而并非是if(t == INF)判断，原因是INF是一个确定的值，并非真正的无穷大，会随着其他数值而受到影响，t大于某个与INF相同数量级的数即可

// 解题代码
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];

void floyd()
{
    for (int k = 1; k <= n; k ++ )
      for (int i = 1; i <= n; i ++ )
         for (int j = 1; j <= n; j ++ )
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);           
}

int main()
{
    scanf("%d%d%d", &n, &m, &Q);

    for (int i = 1; i <= n; i ++ )
      for (int j = 1; j <= n; j ++ )
         if (i == j) d[i][j] = 0;
         else d[i][j] = INF;
    
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);  //注意保存最小的边
    }

    floyd();

    while (Q -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);

        int t = d[a][b];
        if (t > INF / 2) puts("impossible"); //由于有负权边存在所以约大过INF/2也很合理
        else printf("%d\n", t);
    }

    return 0;
}

java代码
import java.util.Scanner;
public class Main {
    /*解题思路，动态规划的思想
    假设节点序号是从1到n。
    假设f[0][i][j]是一个n*n的矩阵，第i行第j列代表从i到j的权值，如果i到j有边，那么其值就为ci,j（边ij的权值）。
    如果没有边，那么其值就为无穷大。

    f[k][i][j]代表（k的取值范围是从1到n），在考虑了从1到k的节点作为中间经过的节点时，从i到j的最短路径的长度。

    比如，f[1][i][j]就代表了，在考虑了1节点作为中间经过的节点时，从i到j的最短路径的长度。
    分析可知，f[1][i][j]的值无非就是两种情况，而现在需要分析的路径也无非两种情况，i=>j，i=>1=>j：
    【1】f[0][i][j]：i=>j这种路径的长度，小于，i=>1=>j这种路径的长度
    【2】f[0][i][1]+f[0][1][j]：i=>1=>j这种路径的长度，小于，i=>j这种路径的长度
    形式化说明如下：
    f[k][i][j]可以从两种情况转移而来：
    【1】从f[k−1][i][j]转移而来，表示i到j的最短路径不经过k这个节点
    【2】从f[k−1][i][k]+f[k−1][k][j]转移而来，表示i到j的最短路径经过k这个节点

    总结就是：f[k][i][j]=min(f[k−1][i][j],f[k−1][i][k]+f[k−1][k][j])
    从总结上来看，发现f[k]只可能与f[k−1]有关。
    */
    static int N = 210;
    static int n, m, q;
    static int[][] d = new int[N][N];
    static int INF = (int)1e9;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); m = sc.nextInt(); q = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) d[i][j] = 0;
                else d[i][j] = INF;
            } 
        }

        for(int i = 0; i < m; i++) {
            int a = sc.nextInt(), b = sc.nextInt(), w = sc.nextInt();
            d[a][b] = Math.min(d[a][b], w);
        }

        Floyd();

        while (q-- > 0) {
            int a = sc.nextInt(), b = sc.nextInt();
            if (d[a][b] > INF / 2) System.out.println("impossible");
            else System.out.println(d[a][b]);
        }
    }

    private static void Floyd() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}


朴素版prim算法 —— 模板题 AcWing 858. Prim算法求最小生成树
Prim算法
dist[i]距离设置为无穷大
dist[1]=0
for i in 0..n-1
1. 找到不在s集合中，距离s集合最近的点t
2. 将这个点t放入集合中
3. 利用这个点t， 更新不在集合中的点

Prim算法与Dijkstra算法的区别
Dijkstra算法是更新不在集合中的点 离起点的距离
dist[j]=min(dist[j], dist[t]+g[t][j])
Prim是更新不在集合中的点 离集合S的距离
dist[j] = min(dist[j], g[t][j])

prim 算法干的事情是：给定一个无向图，在图中选择若干条边把图的所有节点连起来。要求边长之和最小。在图论中，叫做求最小生成树。
prim 算法采用的是一种贪心的策略。
每次将离连通部分的最近的点和点对应的边加入的连通部分，连通部分逐渐扩大，最后将整个图连通起来，并且边长之和最小。


1、初始化dist[i]=无穷大
s：当前已经在连通块当中的所有点
2，for i 1...n
（1）t<- 找到集合外距离最近的点 总共 O（n^2）次
（2）s<-t 对该点进行标志 总共O(n)次
（3）用t更新其他点到集合的距离 总共O（n^2）级别次
注意：若当前的图是稠密图，假设给定n个点，将所有点两两相连，总边数为 m=1/2n(n-1)

时间复杂度是 O(n2+m), n 表示点数，m 表示边数
int n;      // n表示点数
int g[N][N];        // 邻接矩阵，存储所有边
int dist[N];        // 存储其他点到当前最小生成树的距离
bool st[N];     // 存储每个点是否已经在生成树中
// 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

S:当前已经在联通块中的所有点的集合
1. dist[i] = inf
2. for n 次
    t<-S外离S最近的点
    利用t更新S外点到S的距离
    st[t] = true
n次迭代之后所有点都已加入到S中
联系：Dijkstra算法是更新到起始点的距离，Prim是更新到集合S的距离

// 解题代码
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    //如果图不连通返回INF, 否则返回res
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
          if (!st[j] && (t == -1 || dist[t] > dist[j]))
          t = j;//寻找离集合S最近的点 

          //判断是否连通，有无最小生成树
          if (i && dist[t] == INF) return INF;

          if (i) res += dist[t];
          st[t] = true;//更新最新S的权值和

          for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF) puts("impossible");//临时存储防止执行两次函数导致最后仅返回0
    else printf("%d\n", t);

    return 0;
}


伪代码
int dist[n],state[n],pre[n];
dist[1] = 0;
for(i : 1 ~ n)
{
    t <- 没有连通起来，但是距离连通部分最近的点;
    state[t] = 1;
    更新 dist 和 pre;
}

代码
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int g[N][N];//存储图
int dt[N];//存储各个节点到生成树的距离
int st[N];//节点是否被加入到生成树中
int pre[N];//节点的前去节点
int n, m;//n 个节点，m 条边

void prim()
{
    memset(dt,0x3f, sizeof(dt));//初始化距离数组为一个很大的数（10亿左右）
    int res= 0;
    dt[1] = 0;//从 1 号节点开始生成 
    for(int i = 0; i < n; i++)//每次循环选出一个点加入到生成树
    {
        int t = -1;
        for(int j = 1; j <= n; j++)//每个节点一次判断
        {
            if(!st[j] && (t == -1 || dt[j] < dt[t]))//如果没有在树中，且到树的距离最短，则选择该点
                t = j;
        }

        st[t] = 1;// 选择该点
        res += dt[t];
        for(int i = 1; i <= n; i++)//更新生成树外的点到生成树的距离
        {
            if(dt[i] > g[t][i] && !st[i])//从 t 到节点 i 的距离小于原来距离，则更新。
            {
                dt[i] = g[t][i];//更新距离
                pre[i] = t;//从 t 到 i 的距离更短，i 的前驱变为 t.
            }
        }
    }
}

void getPath()//输出各个边
{
    for(int i = n; i > 1; i--)//n 个节点，所以有 n-1 条边。

    {
        cout << i <<" " << pre[i] << " "<< endl;// i 是节点编号，pre[i] 是 i 节点的前驱节点。他们构成一条边。
    }
}

int main()
{
    memset(g, 0x3f, sizeof(g));//各个点之间的距离初始化成很大的数
    cin >> n >> m;//输入节点数和边数
    while(m --)
    {
        int a, b, w;
        cin >> a >> b >> w;//输出边的两个顶点和权重
        g[a][b] = g[b][a] = min(g[a][b],w);//存储权重
    }

    prim();//求最下生成树
    //getPath();//输出路径
    return 0;
}

优化
上面代码的时间复杂度为 O(n^2)。
与Dijkstra类似，Prim算法也可以用堆优化，优先队列代替堆，优化的Prim算法时间复杂度O(mlogn)。适用于稀疏图，但是稀疏图的时候求最小生成树，Kruskal 算法更加实用。

Kruskal算法 —— 模板题 AcWing 859. Kruskal算法求最小生成树


Kruskal算法 (解决稀疏图) O(mlog(m))
将所有边按照权重从小到大排序 O(mlog(m))
枚举每条边(a, b， 权重c) O(m)
      if a, b 两点不连通
            将a, b边加入集合中
第二步与 连通块中点的数量 相似
使用并查集，查询两个结点是否属于一个集合， 合并两个结点

算法思路：
将所有边按照权值的大小进行升序排序，然后从小到大一一判断。
如果这个边与之前选择的所有边不会组成回路，就选择这条边分反之，舍去。
直到具有 n 个顶点的连通网筛选出来 n-1 条边为止。
筛选出来的边和所有的顶点构成此连通网的最小生成树。
判断是否会产生回路的方法为：使用并查集。
在初始状态下给各个个顶点在不同的集合中。
遍历过程的每条边，判断这两个顶点的是否在一个集合中。
如果边上的这两个顶点在一个集合中，说明两个顶点已经连通，这条边不要。如果不在一个集合中，则要这条边。

res 最小生成树中的权重之和
cnt 当前加了多少条边
1.将所有边按权重排序O(mlogm)
2.枚举每条边（并查集应用） 
    if a,b 不连通
        加入集合
3.需重载< 
bool operator < (const Edge &C) const {
    return w < C.w;


时间复杂度是 O(mlogm), n 表示点数，m 表示边数
int n, m; // n是点数，m是边数
int p[N];  // 并查集的父节点数组

struct Edge // 存储边
{
    int a, b, w;

    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];

int find(int x)     // 并查集核心操作
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges + m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b)     // 如果两个连通块不连通，则将这两个连通块合并
        {
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}


Kruskal算法（解决稀疏图）
时间复杂度是O（mlogm）m为边数
1、将所有边按权重从小到大排序共0（mlogm）次
2、枚举每条边a，b，权重c共0（m）次
if a，b两点不连通
  将a，b边加入集合中
注意：
（1）2操作是并查集操作
（2）需要使用变量cnt来记录加进集合的边数 若 cnt < n-1 表示不能遍历所有点

// 解题代码
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;
int p[N];//祖宗节点

struct Edge
{
    int a, b, w;

    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];

int find(int x)  //并查集核心
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges + m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集

    int res = 0, cnt = 0;
    //res 最小生成树中的权重之和
    //cnt 当前加了多少条边
    for (int i = 0; i < m; i ++ )
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i ++ )
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    int t = kruskal();

    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;
int p[N];//保存并查集

struct E{
    int a;
    int b;
    int w;
    bool operator < (const E& rhs){//通过边长进行排序
        return this->w < rhs.w;
    }

}edg[N * 2];
int res = 0;

int n, m;
int cnt = 0;
int find(int a){//并查集找祖宗
    if(p[a] != a) p[a] = find(p[a]);
    return p[a];
}
void klskr(){
    for(int i = 1; i <= m; i++)//依次尝试加入每条边
    {
        int pa = find(edg[i].a)；// a 点所在的集合
        int pb = find(edg[i].b);// b 点所在的集合
        if(pa != pb){//如果 a b 不在一个集合中
            res += edg[i].w;//a b 之间这条边要
            p[pa] = pb;// 合并a b
            cnt ++; // 保留的边数量+1
        }
    }
}
int main()
{

    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;//初始化并查集
    for(int i = 1; i <= m; i++){//读入每条边
        int a, b , c;
        cin >> a >> b >>c;
        edg[i] = {a, b, c};
    }
    sort(edg + 1, edg + m + 1);//按边长排序
    klskr();
    if(cnt < n - 1) {//如果保留的边小于点数-1，则不能连通
        cout<< "impossible";
        return 0;
    }
    cout << res;
    return 0;
}

https://www.bilibili.com/video/BV1Eb41177d1/ b站Kruskal算法求最小生成树
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=200010,M=100010;         

int p[M];
int n,m;

struct Edge
{
    int a,b,w;

     bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[N];

int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    else return x;
} 

int Kruskal()
{
    int res=0,cnt=0;//res记录最小生成树的树边权重之和,cnt记录的是全部加入到树的集合中边的数量(可能有多个集合)
    for(int i=0;i<m;i++)
    {
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        if(find(a)!=find(b))
        /*
        具体可以参考连通块中点的数量,如果a和b已经在一个集合当中了,说明这两个点已经被一种方式连接起来了,
        如果加入a-b这条边,会导致集合中有环的生成,而树中不允许有环生成,所以一个连通块中的点的数量假设
        为x,那么里面x个节点应该是被串联起来的,有x-1条边,所以只有当a,b所属的集合不同时,才能将a-b这条
        边加入到总集合当中去
        */
        {
            p[find(a)]=p[find(b)];//将a,b所在的两个集合连接起来
            cnt++;//因为加入的是a-b的这一条边,将a,b所在的两个集合连接之后,全部集合中的边数加1
            res+=w;//加入到集合中的边的权重之和
        }
    }

    if(cnt==n-1) return res;//可以生成最小生成树
    else return 0x3f3f3f3f;//树中有n个节点便有n-1条边,如果cnt不等于n-1的话,说明无法生成有n个节点的树
}

int main()
{
    cin>>n>>m;

    for(int i=0;i<n;i++) p[i]=i;//初始化并查集

    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }

    sort(edges,edges+m);//将边的权重按照大小一一排序

    int t=Kruskal();

    if(t==0x3f3f3f3f) printf("impossible\n");
    else printf("%d\n",t);

    return 0;
}


染色法判别二分图 —— 模板题 AcWing 860. 染色法判定二分图


奇数环：由奇数条边形成的一个环
二分图：当且仅当图中不含有奇数环，两个集合内部的内部没有边 一定不含有奇数环，可能包含长度为偶数的环， 不一定是连通图 左侧的点只和右侧的点相连，右侧的点只和左侧的点相连。
如何判断一个图是不是二分图？
开始对任意一未染色的顶点染色。
判断其相邻的顶点中，若未染色则将其染上和相邻顶点不同的颜色。
若已经染色且颜色和相邻顶点的颜色相同则说明不是二分图，若颜色不同则继续判断。
bfs和dfs可以搞定！

染色法
将所有点分成两个集合，使得所有边只出现在集合之间，就是二分图


算法1：
使用bfs 约定染的颜色有1颜色和2颜色
for i 1...n（此操作是为了每一个点都能保证染到色）
    若该点未染色，则进入如下操作：
    queue<-i染色成1号颜色
        while queue不为空
            t = queue.top（）
                queue.pop（）
                使用t来染其他出边的点
                （1）若该点未染色，则染成与t不同的颜色，并加入到队列
                （2）否则，若该点颜色与t相同，则表示染色失败
注意：队列维护的是刚刚被染色，准备去染其他出边点的点

代码思路
颜色 1 和 2 表示不同颜色, 0 表示 未染色
定义queue是存PII，表示 <点编号, 颜色>,
同理，遍历所有点, 将未染色的点都进行bfs
队列初始化将第i个点入队, 默认颜色可以是1或2
while (队列不空)
每次获取队头t, 并遍历队头t的所有邻边
若邻边的点未染色则染上与队头t相反的颜色，并添加到队列
若邻边的点已经染色且与队头t的颜色相同, 则返回false

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
typedef pair<int, int> PII;

int e[M], ne[M], h[N], idx;
int n, m;
int st[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool bfs(int u){
    int hh = 0, tt = 0;
    PII q[N];
    q[0] = {u, 1};
    st[u] = 1;

    while(hh <= tt){
        auto t = q[hh ++];
        int ver = t.first, c = t.second;

        for (int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];

            if(!st[j])
            {
                st[j] = 3 - c;
                q[++ tt] = {j, 3 - c};
            }
            else if(st[j] == c) return false;
        }
    }

    return true;
}

int main(){
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while(m --){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    int flag = true;
    for(int i = 1; i <= n; i ++) {
        if (!st[i]){
            if(!bfs(i)){
                flag = false;
                break;
            }
        }
    }

    if (flag) puts("Yes");
    else puts("No");
    return 0;
}




算法2
使用dfs（注意：在这里使用java会直接爆栈hh）
dfs(u,c)表示把u号点染色成c颜色，并且判断从u号点开始染其他相连的点是否染成功
代码思路：
染色可以使用1和2区分不同颜色，用0表示未染色
遍历所有点，每次将未染色的点进行dfs, 默认染成1或者2
由于某个点染色成功不代表整个图就是二分图,因此只有某个点染色失败才能立刻break/return
染色失败相当于存在相邻的2个点染了相同的颜色
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10; // 由于是无向图, 顶点数最大是N，那么边数M最大是顶点数的2倍
int e[M], ne[M], h[N], idx;
int st[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int color) {
    st[u] = color;

    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]) {
            if(!dfs(j, 3 - color)) return false;
        }else if(st[j] == color) return false;
    }

    return true;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m --){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b,a);  // 无向图，a->b, b->a
    }

    bool flag = true;
    for(int i = 1; i <= n; i ++){
        if(!st[i]){
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
        }
    }

    if(flag) puts("Yes");
    else puts("No");
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010 * 2;
int e[N], ne[N], idx;//邻接表存储图
int h[N];
int color[N];//保存各个点的颜色，0 未染色，1 是红色，2 是黑色
int n, m;//点和边

void add(int a, int b)//邻接表插入点和边
{
    e[idx] = b, ne[idx]= h[a], h[a] = idx++;
}

bool dfs(int u, int c)//深度优先遍历
{
    color[u] = c;//u的点成 c 染色

    //遍历和 u 相邻的点
    for(int i = h[u]; i!= -1; i = ne[i])
    {
        int b = e[i];                   
        if(!color[b])//相邻的点没有颜色,则递归处理这个相邻点
        {
            if(!dfs(b, 3 - c)) return false;//（3 - 1 = 2， 如果 u 的颜色是2，则和 u 相邻的染成 1）
                                            //（3 - 2 = 1， 如果 u 的颜色是1，则和 u 相邻的染成 2）
        }
        else if(color[b] && color[b] != 3 - c)//如果已经染色，判断颜色是否为 3 - c
        {                                     
            return false;//如果不是，说明冲突，返回                   
        }
    }
    return true;
}

int main()
{
    memset(h, -1, sizeof h);//初始化邻接表
    cin >> n >> m;
    for(int i = 1; i <= m; i++)//读入边
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    for(int i = 1; i <= n; i++)//遍历点
    {
        if(!color[i])//如果没染色
        {
            if(!dfs(i, 1))//染色该点，并递归处理和它相邻的点
            {
                cout << "No" << endl;//出现矛盾，输出NO 
                return 0;
            }

        }
    }
    cout << "Yes" << endl;//全部染色完成，没有矛盾，输出YES
    return 0;
}


/*
for i:0~n
    if i未染色
    dfs(i, 1);
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10, M = 2*N;

int n, m;
int h[N], e[M], ne[M], idx, color[N];
//邻接表方式存储图, 无向图可能会连接M条边
//color[N], 为0代表还未染色省去一个bool数组,1代表染颜色1,2代表染颜色2

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
//返回是否可以成功将u染色为c
bool dfs(int u, int c) {
    color[u] = c;
    //修改当前颜色

    //尝试染链接边的颜色
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        //如果color[j]没有染过色
        if(!color[j]) {
            //如果不可以将j成功染色
            if(!dfs(j, 3 - c)) return false;
        } else if(color[j] == c) return false;
        //如果染过颜色且和c相同
    }

    return true;
}

int main() {
    cin >> n >> m;
    int u, v;

    memset(h, -1, sizeof h);

    while(m--) {
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    bool flag = true;
    for(int i = 1; i <= n; i++) {
        //如果未染色
        if(!color[i]) {
            //如果dfs返回false 说明出现矛盾
            if(!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    }

    if(!flag) puts("No");
    else puts("Yes");
    return 0;
}

为什么未染色则直接染成1呢，为什么这样能保证正确性啊
因为二分图未必是联通的

时间复杂度是 O(n+m), n 表示点数，m 表示边数
int n;  // n表示点数
int h[N], e[M], ne[M], idx; // 邻接表存储图
int color[N];  // 表示每个点的颜色，-1表示未染色，0表示白色，1表示黑色

// 参数：u表示当前节点，c表示当前点的颜色
bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (color[j] == -1)
        {
            if (!dfs(j, !c)) return false;
        }
        else if (color[j] == c) return false;
    }

    return true;
}

bool check()
{
    memset(color, -1, sizeof color);
    bool flag = true;
    for (int i = 1; i <= n; i ++ )
        if (color[i] == -1)
            if (!dfs(i, 0))
            {
                flag = false;
                break;
            }
    return flag;
}

// 解题代码
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u, int c)
{
    color[u] = c;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j, 3 - c)) return false;
        }
        else if (color[j] == c) return false;
    }

    return true;
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i ++ )
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }

    if (flag) puts("Yes");
    else puts("No");

    return 0;
}


匈牙利算法 —— 模板题 AcWing 861. 二分图的最大匹配
要了解匈牙利算法必须先理解下面的概念：
匹配：在图论中，一个「匹配」是一个边的集合，其中任意两条边都没有公共顶点。
最大匹配：一个图所有匹配中，所含匹配边数最多的匹配，称为这个图的最大匹配。
完美匹配：如果一个图的某个匹配中，所有的顶点都是匹配点，那么它就是一个完美匹配。
交替路：从一个未匹配点出发，依次经过非匹配边、匹配边、非匹配边…形成的路径叫交替路。
增广路：从一个未匹配点出发，走交替路，如果途径另一个未匹配点（出发的点不算），则这条交替 路称为增广路（agumenting path）。

时间复杂度是 O(nm), n 表示点数，m 表示边数
int n1, n2;     // n1表示第一个集合中的点数，n2表示第二个集合中的点数
int h[N], e[M], ne[M], idx;     // 邻接表存储所有边，匈牙利算法中只会用到从第一个集合指向第二个集合的边，所以这里只用存一个方向的边
int match[N];       // 存储第二个集合中的每个点当前匹配的第一个集合中的点是哪个
bool st[N];     // 表示第二个集合中的每个点是否已经被遍历过

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

// 求最大匹配数，依次枚举第一个集合中的每个点能否匹配第二个集合中的点
int res = 0;
for (int i = 1; i <= n1; i ++ )
{
    memset(st, false, sizeof st);
    if (find(i)) res ++ ;
}

// 解题代码
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i ++ )
    {
        memset(st, false, sizeof st);
        if (find(i)) res ++ ;
    }

    printf("%d\n", res);

    return 0;
}

代码实现匈牙利算法

首先是存图模板
//邻接表写法，存稀疏图
int h[N],ne[N],e[N],idx;
//n1,n2分别是两个点集的点的个数
int n1,n2,m;
void add(int a , int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void init()
{
    memset(h,-1,sizeof h);
}
//存边只存一边就行了，虽然是无向图。
for(int i = 0 ; i < n1 ; i ++)
{
    int a,b;
    cin>>a>>b;
    add(a,b);
}

接下来看算法模板(c++)
//match[j]=a,表示女孩j的现有配对男友是a
int match[N];
//st[]数组我称为临时预定数组，st[j]=a表示一轮模拟匹配中，女孩j被男孩a预定了。
int st[N];
//这个函数的作用是用来判断,如果加入x来参与模拟配对,会不会使匹配数增多
int find(int x)
{
    //遍历自己喜欢的女孩
    for(int i = h[x] ; i != -1 ;i = ne[i])
    {
        int j = e[i];
        if(!st[j])//如果在这一轮模拟匹配中,这个女孩尚未被预定
        {
            st[j] = true;//那x就预定这个女孩了
            //如果女孩j没有男朋友，或者她原来的男朋友能够预定其它喜欢的女孩。配对成功,更新match
            if(!match[j]||find(match[j]))
            {
                match[j] = x;
                return true;
            }

        }
    }
    //自己中意的全部都被预定了。配对失败。
    return false;
}

//记录最大匹配
int res = 0;
for(int i = 1; i <= n1 ;i ++)
{  
    //因为每次模拟匹配的预定情况都是不一样的所以每轮模拟都要初始化
    memset(st,false,sizeof st);
    if(find(i)) 
        res++;
}  

练习例题： 二分图的最大匹配
AC代码

#include<iostream>
#include<cstring>
using namespace std;
const int N = 510 , M = 100010;
int n1,n2,m;
int h[N],ne[M],e[M],idx;
bool st[N];
int match[N];

void add(int a , int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void init()
{
    memset(h,-1,sizeof h);
}

int find(int x)
{
    //遍历自己喜欢的女孩
    for(int i = h[x] ; i != -1 ;i = ne[i])
    {
        int j = e[i];
        if(!st[j])//如果在这一轮模拟匹配中,这个女孩尚未被预定
        {
            st[j] = true;//那x就预定这个女孩了
            //如果女孩j没有男朋友，或者她原来的男朋友能够预定其它喜欢的女孩。配对成功
            if(!match[j]||find(match[j]))
            {
                match[j] = x;
                return true;
            }

        }
    }
    //自己中意的全部都被预定了。配对失败。
    return false;
}
int main()
{
    init();
    cin>>n1>>n2>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }


    int res = 0;
    for(int i = 1; i <= n1 ;i ++)
    {  
         //因为每次模拟匹配的预定情况都是不一样的所以每轮模拟都要初始化
          memset(st,false,sizeof st);
        if(find(i)) 
          res++;
    }  

    cout<<res<<endl;
}


使用 vector 来实现邻接表，更简单一些，便于不熟悉链式前向星的同学理解。

vector<int> g[510]; // g[a] 为一个动态数组 vector，储存了男生 a 可以匹配的所有女生。
如果读者已经对匈牙利算法的标准模板非常熟悉了，可以跳过下面这部分。

匈牙利算法很容易通过代码理解，所以下面直接展示代码。复杂度是 O(n∗m)O(n∗m)
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n1, n2, m;      // 有 n1 个男生和 n2 个女生 (n1 ≤ 500, n2 ≤ 500)。
                    // 他们之间可以匹配的关系有 m 个 (m ≤ 1e5)。

vector<int> g[N];   // g[a] 为一个动态数组vector，储存了男生 a 可以匹配的所有女生。

int match[N]; //  match[a] = b: 女生 a 目前匹配了男生 b
bool st[N]; // st[a] = true 说明女生 a 目前被一个男生预定了

bool find(int x) { // 为单身狗 x 找一个对象， (或) x的女朋友被别人预定，给x换一个对象
    // 如果成功，返回true
    for (int j: g[x]) { // j 是可以与男生 x 匹配的女生之一
        if (st[j]) continue; // 女生 j 目前被一个男生预定了，跳过它
        st[j] = true; // 将女生 j 预定给男生 x

        // 如果女生 j 没有对象， 或者
        // 女生 j 在前几轮深搜中已预定有对象，但我们成功给她的对象换了个新对象
        if (match[j] == 0 || find(match[j])) {
            match[j] = x;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b); // 读取一条数据，男生 a 可以匹配女生 b
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) { // 尝试为每个男生做一轮深搜找对象（要求成功后总匹配数增加1）。
        memset(st, 0, sizeof st);
        if (find(i)) res++;
    }

    cout << res;
    return 0;
}
问题：为什么不用回溯？
让我们仔细看一下 find(x) 函数。我们为男生 x 找/换一个对象，尝试将女生 j 预订给他。因此，用 st[j] = true 记录。这样其他男生不会同时尝试匹配女生 j。同学们不难意识到这和 DFS 中的记录数组的作用差不多。简单来说，避免搜索过程构成环路，导致无限循环和冲突。但是，当 if (match[j] == 0 || find(match[j])) 中 find 函数递归结果返回后，为什么不需要像很多 DFS 题目那样用 st[j] = false 回溯呢？(也即是说，将女生 j 匹配给男生 x 失败，取消预订)

如果我们使用 st[j] = false 进行回溯，算法其实仍然是正确的。但是复杂度会变成指数级。

实际上，标准模板中的 st 数组是两个不同记录数组和合并。st[a] = true 实际上不仅仅表示女生 a 目前被一个男生预定了。下面的代码中，我们将会把 st 数组拆分成两个不同的数组，请尤其注意用 *** 做注释的地方。

#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n1, n2, m;      // 有 n1 个男生和 n2 个女生 (n1 ≤ 500, n2 ≤ 500)。
                    // 他们之间可以匹配的关系有 m 个 (m ≤ 1e5)。

vector<int> g[N];   // g[a] 为一个动态数组vector，储存了男生 a 可以匹配的所有女生。

int match[N]; //  match[a] = b: 女生 a 目前匹配了男生 b
bool st1[N]; // st[a] = true 说明女生 a 目前被一个男生预定了
bool st2[N]; // st[a] = true 我们曾经尝试为已经有男朋友的女生 a 换对象，但是失败了

bool find(int x) { // 为单身狗 x 找一个对象， (或) x的女朋友被别人预定，给x换一个对象
    // 如果成功，返回true
    for (int j: g[x]) { // j 是可以与男生 x 匹配的女生之一

//***   // 我们曾经尝试为已经有男朋友的女生 j 换对象，但是失败了。
        // 我们可以由此声称之后永远无法成功（后文详证），所以跳过以避免重复运算
        if(st2[j]) continue;

        if (st1[j]) continue; // 女生 j 目前被一个男生预定了，跳过
        st1[j] = true; // 将女生 j 预定给男生 x

        // 如果女生 j 没有对象， 或者
        // 女生 j 在前几轮深搜中已预定有对象，但我们成功给她的对象换了个新对象
        if (match[j] == 0 || find(match[j])) {
            match[j] = x;
//***   // 我们有了 st2 用来记录换对象失败的女生。这里 st1 回溯不影响复杂度
            st1[j] = false; // 回溯
            return true;
        }

//***   // 我们有了 st2 用来记录换对象失败的女生。这里 st1 回溯不影响复杂度
        st1[j] = false; // 回溯
        st2[j] = true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b); // 读取一条数据，男生 a 可以匹配女生 b
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) { // 尝试为每个男生做一轮深搜找对象（要求成功后总匹配数增加1）。
//***   // st2 不需要重置，因为换对象失败一次的女生到程序结束都不可能成功换对象
        // 对于所有的预定 st1[j] = true，我们都用 st1[j] = false 回溯了。st1本身就是默认状态。
        // 所以和标准模板不同，st1 也不需要重置。
        if (find(i)) res++;
    }

    cout << res;
    return 0;
}

上面的代码中，我们将 st 数组拆分成了两个数组。st1 将女生暂时预定给一个男生，st2 则记录所有换对象失败的女生。在标准模板中，st 实际上同时起到了 st1 和 st2 两个数组的两种作用。

不难发现，为了证明算法的正确性，我们要证明：换对象失败了一次的女生，到程序结束也都不可能成功换对象。

让我们想想，什么时候我们能够成功给一个有对象的女生 B 换对象？在我们的算法中，我们可能尝试给一个男生 A 找对象，然后我们试图将男生 A 匹配给女生 B。但女生 B 已经有对象男生 C，所以我们又尝试为男生 C 换女生 D 作新对象… 直到我们为男生 M 换一个新对象：一个目前单身的女生 N。整个交换流程终止于一个单身女生，这样我们才成功为有对象的女生 B 换了对象。

最重要的两个要点：
1. 匈牙利算法中，一个有伴侣的人，无论男女，不会重新变成单身狗
2. 若我们尝试给一个有对象的女生换个对象，如果成功，整个交换链条终止于一个单身女性。

根据 2，如果给女生 B 换对象失败，说明经过她搜索不到结束于一个单身女性的交换链条。我们只有等到一个新的单身女性出现才可能由失败转向成功。又根据 1，不会凭空出现一个新的单生狗，所以交换链条永远等不到一个新的单身女性。

由此，换对象失败了一次的女生，到程序结束也都不可能成功换对象。我们可以跳过她们避免重复运算。这样就证明了上面的代码的算法正确性。

当然，上面的口胡也不完全严谨，只要能理解关键就行。

合并 st1 和 st2
不难发现，我们可以简单地合并 st1 和 st2 为 st 数组。
1. 删除所有含 st2 的代码行
2. 删除所有 st1 的回溯
3. 由于 st1 没有回溯，main()中要重置 st1
4. 将 st1 更名为st

不难理解，合并前与合并后，算法逻辑没有区别。这样我们就得到了标准模板。相信读者已经理解为什么标准模板不需要回溯 st 了。

补充
实际上，合并前与合并后，算法逻辑是有一点点小区别的。举例来说，假设合并后，st[a] = true 此时表示我们尝试为女生 a 换对象但失败了。我们知道换对象失败一次的女生到程序结束都不可能成功换对象。但是，main 函数中会将 st 重置。这显然导致合并后比合并前多了一些重复计算。好在这种重复运算相对较少，不影响复杂度。

此外，我还有一篇以增广路角度来看这个问题的笔记，对复杂度的计算进行了一些简单的讨论，不过没必要看。

https://www.acwing.com/solution/content/54355/

算法增强
复杂度实际上为O(n12*n2)，这表明当两侧的点的数量相差悬殊时，应该选择点较少的一侧作为男生。
算法的本质是找增广路，最多找n次就够了。这表明在运行本算法之前，可以先做一次较优的匹配。这将极大减少存在的增广路，而且这并不复杂（遍历一遍每个男生，如果存在还没匹配过的可以匹配的女生就匹配下。显然，这个预处理复杂度为O(n^2)。随后main方法中的for循环不应该对已经有匹配的男生进行深搜，需要跳过，因为进行深搜的前提是该男生是单生狗，否则匹配数不会增加）。
本题使用网络流的解法可以达到理论更低的复杂度，但由于常数较大，所以实际上一般效率差不多。


