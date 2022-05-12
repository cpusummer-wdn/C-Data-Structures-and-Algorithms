AcWing 708. 偶数
#include <iostream>

using namespace std;

int main()
{
    for (int i = 2; i <= 100; i += 2) cout << i << endl;

    return 0;
}

AcWing 709. 奇数
#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;

    for (int i = 1; i <= x; i += 2) cout << i << endl;

    return 0;
}

AcWing 712. 正数
#include <iostream>

using namespace std;

int main()
{
    int cnt = 0;

    for (int i = 0; i < 6; i ++ )
    {
        double x;
        cin >> x;

        if (x > 0) cnt ++ ;
    }

    cout << cnt << " positive numbers" << endl;

    return 0;
}



AcWing 714. 连续奇数的和 1
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    if (x > y) swap(x, y);

    int sum = 0;
    int i = x + 1;
    while (i < y)
    {
        if (i % 2) sum += i;
        i ++;
    }

    cout << sum << endl;

    return 0;
}

AcWing 716. 最大数和它的位置
#include <iostream>

using namespace std;

int main()
{
    int max_value = 0, position;

    for (int i = 1; i <= 100; i ++ )
    {
        int value;
        cin >> value;

        if (value > max_value)
        {
            max_value = value;
            position = i;
        }
    }

    cout << max_value << endl << position << endl;

    return 0;
}

AcWing 721. 递增序列
第一种输入方式
include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int x;
    while (true)
    {
        cin >> x;

        if (!x) break;

        for (int i = 1; i <= x; i ++ ) cout << i << ' ';
        cout << endl;
    }

    return 0;
}

第二种输入方式
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int x;
    while (cin >> x && x)???
    {
        for (int i = 1; i <= x; i ++ ) cout << i << ' ';
        cout << endl;
    }

    return 0;
}

第三种输入方式
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int x;
    while (cin >> x, x)???
    {
        for (int i = 1; i <= x; i ++ ) cout << i << ' ';
        cout << endl;
    }

    return 0;
}

AcWing 720. 连续整数相加
#include <iostream>

using namespace std;

int main()
{
    int a, n;
    cin >> a;
    while (cin >> n, n <= 0);

    int s = 0;
    for (int i = 0; i < n; i ++ ) s += a + i;

    cout << s << endl;

    return 0;
}

AcWing 724. 约数
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        if (n % i == 0)
            cout << i << endl;

    return 0;
}

AcWing 723. PUM
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0, k = 1; i < n; i ++ )
    {
        for (int j = 0; j < m - 1; j ++ )
        {
            cout << k << ' ';
            k ++ ;
        }

        cout << "PUM" << endl;
        k ++ ;
    }

    return 0;
}

AcWing 715. 余数
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 10000; i ++ )
        if (i % n == 2)
            cout << i << endl;

    return 0;
}

AcWing 710. 六个奇数
#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;

    if (x % 2 == 0) x ++ ;

    for (int i = 0; i < 6; i ++ ) cout << x + i * 2 << endl;

    return 0;
}

AcWing 711. 乘法表
#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= 10; i ++ )
        printf("%d x %d = %d\n", i, n, i * n);

    return 0;
}

AcWing 718. 实验
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int c = 0, r = 0, f = 0;
    for (int i = 0; i < n; i ++ )
    {
        int k;
        char t;
        scanf("%d %c", &k, &t);  // scanf在读入字符时，不会自动过滤空格、回车、tab
        if (t == 'C') c += k;
        else if (t == 'R') r += k;
        else f += k;
    }

    int s = c + r + f;
    printf("Total: %d animals\n", s);
    printf("Total coneys: %d\n", c);
    printf("Total rats: %d\n", r);
    printf("Total frogs: %d\n", f);
    printf("Percentage of coneys: %.2lf %%\n", (double)c / s * 100);
    printf("Percentage of rats: %.2lf %%\n", (double)r / s * 100);
    printf("Percentage of frogs: %.2lf %%\n", (double)f / s * 100);

    return 0;
}

AcWing 713. 区间 2
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x = 0, y = 0;
    while (n -- )
    {
        int t;
        cin >> t;
        if (t >= 10 && t <= 20) x ++ ;
        else y ++ ;
    }

    cout << x << " in" << endl;
    cout << y << " out" << endl;

    return 0;
}

AcWing 719. 连续奇数的和 2
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int x, y;
        cin >> x >> y;

        if (x > y) swap(x, y);

        int s = 0;
        for (int i = x + 1; i < y; i ++ )
            if (i % 2)
                s += i;
        cout << s << endl;
    }

    return 0;
}

#include<stdio.h>

int x,y,ans,t;
int main(){
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d%d",&x,&y);
        for(int i = (x<y? x:y) + 1; i < (x>y?x:y); i ++) 
        {
         if(i&1) ans += i;//if(i&1) 表示 如果i是奇数
         printf("%d\n",ans);
        }
        
    }
}

AcWing 717. 简单斐波那契
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a = 0, b = 1;

    for (int i = 0; i < n; i ++ )
    {
        cout << a << ' ';
        int c = a + b;
        a = b;
        b = c;
    }

    cout << endl;

    return 0;
}

AcWing 722. 数字序列和它的和
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m, n > 0 && m > 0)
    {
        if (n > m) swap(n, m);

        int sum = 0;
        for (int i = n; i <= m; i ++ )
        {
            cout << i << ' ';
            sum += i;
        }

        cout << "Sum=" << sum << endl;
    }

    return 0;
}

AcWing 725. 完全数
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int x;
        cin >> x;

        int s = 0;
        for (int i = 1; i * i <= x; i ++ )
            if (x % i == 0)
            {
                if (i < x) s += i;
                if (i != x / i && x / i < x) s += x / i;
            }

        if (s == x) printf("%d is perfect\n", x);
        else printf("%d is not perfect\n", x);
    }

    return 0;
}

AcWing 726. 质数
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int p;
        cin >> p;

        bool is_prime = true;
        for (int i = 2; i * i <= p; i ++ )
            if (p % i == 0)
            {
                is_prime = false;
                break;
            }

        if (is_prime) printf("%d is prime\n", p);
        else printf("%d is not prime\n", p);
    }

    return 0;
}

AcWing 727. 菱形
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cx = n / 2, cy = n / 2;
    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < n; j ++ )
            if (abs(i - cx) + abs(j - cy) <= n / 2) cout << '*';
            else cout << ' ';
        cout << endl;
    }

    return 0;
}
