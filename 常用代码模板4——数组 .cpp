查C++中:等符号的作用域
x-y 小于10-6 即为相等
2的N次方
高精度计算

#include <iostream>

int main()
{
    int a[N] = {1};
    int n;
    cin >> n;
    int m = 1;


    for (int )
    {
        int t = 0;
        for 
        a[j] 
    }
    if (t) a[m ++];

}

cout << endl;

cstring库里面有清空数组函数 menset(a, 0, 40);  40个bit 从a开始连续40个字节变成0
memset(a, -1, 40) -1代表8个1 就是全部赋值为1



所有单位都是字节byte 1byte= 8bit bit带宽
1kb= 1024 byte 一般都是指这个byte

memset(a, 0, sizeof a); 返回a的字节大小
memset 快
memcpy(b, a,sizeof a);赋值
sizeof() 括号可加可不加 括号只是让代码知道在一句话先执行那部分

字符串 指针 特别麻烦


AcWing 737. 数组替换
#include <cstdio>

int main()
{
    int x[10];

    for (int i = 0; i < 10; i ++ ) scanf("%d", &x[i]);

    for (int i = 0; i < 10; i ++ )
        if (x[i] <= 0)
            x[i] = 1;

    for (int i = 0; i < 10; i ++ ) printf("X[%d] = %d\n", i, x[i]);

    return 0;
}

AcWing 738. 数组填充
#include <cstdio>

int main()
{
    int n[10];
    int v;
    scanf("%d", &v);
    n[0] = v;

    for (int i = 1; i < 10; i ++ ) n[i] = n[i - 1] * 2;

    for (int i = 0; i < 10; i ++ ) printf("N[%d] = %d\n", i, n[i]);

    return 0;
}

AcWing 739. 数组选择
#include <cstdio>

int main()
{
    double a[100];
    for (int i = 0; i < 100; i ++ ) scanf("%lf", &a[i]);

    for (int i = 0 ; i < 100; i ++ )
        if (a[i] <= 10)
            printf("A[%d] = %.1lf\n", i, a[i]);

    return 0;
}

AcWing 743. 数组中的行
#include <cstdio>

int main()
{
    double a[12][12];

    int l;
    char t;
    scanf("%d\n%c", &l, &t);

    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j < 12; j ++ )
            scanf("%lf", &a[i][j]);

    double s = 0;
    for (int i = 0; i < 12; i ++ ) s += a[l][i];

    if (t == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / 12);

    return 0;
}

AcWing 745. 数组的右上半部分
#include <cstdio>

int main()
{
    char t;
    scanf("%c", &t);
    double a[12][12];

    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j < 12; j ++ )
            scanf("%lf", &a[i][j]);

    int c = 0;
    double s = 0;

    for (int i = 0; i < 12; i ++ )
        for (int j = i + 1; j < 12; j ++ )
        {
            c ++ ;
            s += a[i][j];
        }

    if (t == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / c);

    return 0;
}

AcWing 747. 数组的左上半部分
#include <cstdio>

int main()
{
    double a[12][12];
    char t;

    scanf("%c", &t);
    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j < 12; j ++ )
            scanf("%lf", &a[i][j]);

    int c = 0;
    double s = 0;
    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j <= 10 - i; j ++ )
        {
            c ++ ;
            s += a[i][j];
        }

    if (t == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / c);

    return 0;
}

AcWing 749. 数组的上方区域
#include <cstdio>

int main()
{
    char t;
    double a[12][12];

    scanf("%c", &t);
    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j < 12; j ++ )
            scanf("%lf", &a[i][j]);

    double s = 0, c = 0;
    for (int i = 0; i < 5; i ++ )
        for (int j = i + 1; j <= 10 - i; j ++ )
        {
            c += 1;
            s += a[i][j];
        }

    if (t == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / c);

    return 0;
}

AcWing 751. 数组的左方区域
#include <cstdio>

int main()
{
    char t;
    scanf("%c", &t);

    double q[12][12];
    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j < 12; j ++ )
            scanf("%lf", &q[i][j]);

    double s = 0, c = 0;
    for (int i = 1; i <= 5; i ++ )
        for (int j = 0; j <= i - 1; j ++ )
        {
            s += q[i][j];
            c += 1;
        }

    for (int i = 6; i <= 10; i ++ )
        for (int j = 0; j <= 10 - i; j ++ )
        {
            s += q[i][j];
            c += 1;
        }

    if (t == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / c);

    return 0;
}

AcWing 753. 平方矩阵 I
#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        for (int i = 1; i <= n; i ++ )
        {
            for (int j = 1; j <= n; j ++ )
            {
                int up = i, down = n - i + 1, left = j, right = n - j + 1;
                cout << min(min(up, down), min(left, right)) << ' ';
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}

AcWing 740. 数组变换
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a[20], b[20];

    for (int i = 0; i < 20; i ++ ) cin >> a[i];
    for (int i = 19, j = 0; i >= 0; i --, j ++ ) b[j] = a[i];

    for (int i = 0; i < 20; i ++ ) printf("N[%d] = %d\n", i, b[i]);

    return 0;
}

AcWing 741. 斐波那契数列
注意：小心整数溢出。

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    long long f[61];
    f[0] = 0, f[1] = 1;

    for (int i = 2; i <= 60; i ++ ) f[i] = f[i - 1] + f[i - 2];

    int n;
    cin >> n;
    while (n -- )
    {
        int x;
        cin >> x;
        printf("Fib(%d) = %lld\n", x, f[x]);
    }

    return 0;
}

#include<iostream>

using namespace std;

long long fib[61]={0,1};

int main()
{
    for(int i=2; i<61; i++) fib[i]=fib[i-1]+fib[i-2];

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<"Fib("<<n<<") = "<<fib[n]<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

long long f[10001];

int main()
{
    int n,i,k; 

    cin>>n;

    f[0]=0;
    f[1]=1;
    f[2]=1; 

    for(i=3;i<=60;i++) f[i]=f[i-1]+f[i-2];

    for(i=0;i<=n-1;i++)
    {
        cin>>k;
        cout<<"Fib("<<k<<") = "<<f[k]<<endl; 
    }   
}

递归做法
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll t, n, a[105];

ll fb(int n) 
{
    if (a[n] != -1)
        return a[n];
    else 
    {
        if (n < 2)
            return a[n] = n;
        else
            return a[n] = fb(n - 1) + fb(n - 2);
    }
}

int main() {
    memset(a, -1, sizeof(a));
    cin >> t;
    
    while (t--) {
        cin >> n;
        printf("Fib(%lld) = %lld\n", n, fb(n));
    }
    return 0;
}


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long int dp[100];//数据太大，不开long long 见祖宗

void hhh(){
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=60;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
}

int main(){
    hhh();
    int n;
    cin>>n;
   
    while(n--){
        int T;
        cin>>T;
        printf("Fib(%d) = %lld\n",T,dp[T]);//long long int 要用%lld
    }
}


AcWing 742. 最小数和它的位置
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a[1001];
    int n;

    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    int p = 0;
    for (int i = 1; i < n; i ++ )
        if (a[i] < a[p])
            p = i;

    printf("Minimum value: %d\n", a[p]);
    printf("Position: %d\n", p);

    return 0;
}

AcWing 744. 数组中的列
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int c;
    char t;
    double q[12][12];

    cin >> c >> t;
    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j < 12; j ++ )
            cin >> q[i][j];

    double s = 0;
    for (int i = 0; i < 12; i ++ ) s += q[i][c];

    if (t == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / 12);

    return 0;
}

AcWing 748. 数组的右下半部分
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    char t;
    cin >> t;
    double q[12][12];

    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j < 12; j ++ )
            cin >> q[i][j];

    double s = 0, c = 0;
    for (int i = 1; i <= 11; i ++ )
        for (int j = 12 - i; j <= 11; j ++ )
        {
            s += q[i][j];
            c += 1;
        }

    if (t == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / c);

    return 0;
}

AcWing 746. 数组的左下半部分
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char t;
    cin >> t;

    double q[12][12];
    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j < 12; j ++ )
            cin >> q[i][j];

    double s = 0, c = 0;
    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j <= i - 1; j ++ )
        {
            s += q[i][j];
            c += 1;
        }

    if (t == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / c);

    return 0;
}

AcWing 750. 数组的下方区域
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char t;
    cin >> t;

    double q[12][12];
    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j < 12; j ++ )
            cin >> q[i][j];

    double s = 0, c = 0;
    for (int i = 7; i <= 11; i ++ )
        for (int j = 12 - i; j <= i - 1; j ++ )
        {
            s += q[i][j];
            c += 1;
        }

    if (t == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / c);

    return 0;
}

AcWing 752. 数组的右方区域
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    char t;
    cin >> t;
    double q[12][12];

    for (int i = 0; i < 12; i ++ )
        for (int j = 0; j < 12; j ++ )
            cin >> q[i][j];

    double s = 0, c = 0;
    for (int i = 1; i <= 5; i ++ )
        for (int j = 12 - i; j <= 11; j ++ )
        {
            s += q[i][j];
            c += 1;
        }

    for (int i = 6; i <= 10; i ++ )
        for (int j = i + 1; j <= 11; j ++ )
        {
            s += q[i][j];
            c += 1;
        }

    if (t == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / c);

    return 0;
}

AcWing 754. 平方矩阵 II
#include <iostream>

using namespace std;

int q[100][100];

int main()
{
    int n;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i ++ )
        {
            q[i][i] = 1;
            for (int j = i + 1, k = 2; j < n; j ++, k ++ ) q[i][j] = k;
            for (int j = i + 1, k = 2; j < n; j ++, k ++ ) q[j][i] = k;
        }

        for (int i = 0; i < n; i ++ )
        {
            for (int j = 0; j < n; j ++ ) cout << q[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

AcWing 755. 平方矩阵 III
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i ++ )
        {
            for (int j = 0; j < n; j ++ )
            {
                int v = 1;
                for (int k = 0; k < i + j; k ++ ) v *= 2;
                cout << v << ' ';
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n,n)
    {
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j ++)
                cout << (1 << i) * (1 << j) << ' ';//两个乘数 后者控制基数 1 ~ 2^(n-1) ，前者控制倍数
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}



AcWing 756. 蛇形矩阵
#include <iostream>

using namespace std;

int res[100][100];

int main()
{
    int n, m;
    cin >> n >> m;

    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

    for (int x = 0, y = 0, d = 0, k = 1; k <= n * m; k ++ )
    {
        res[x][y] = k;
        int a = x + dx[d], b = y + dy[d];
        if (a < 0 || a >= n || b < 0 || b >= m || res[a][b])
        {
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }

    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < m; j ++ ) cout << res[i][j] << ' ';
        cout << endl;
    }

    return 0;
}

字符串类型的数组 char str[]
