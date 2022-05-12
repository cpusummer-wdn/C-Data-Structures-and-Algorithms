练习和实践是最重要的 针对C++进行多练
快写 快找bug
AC Saber有练习训练模式
天梯模式匹配队友

多态继承封装这些面向对象不讲

AC Editor 云端编辑器

#include <iostream>

using namespace std;

int main()
{
    cout << "hello world" << endl;

    return 0;

}

#编译

1byte=8bit
char 1byte
int 4byte
float 4byte

#include <iostream>

using namespace std;

int main()
{
  int a, b;
  //变量一定要先定义
  cin >> a >> b;//值流进去

  cout << a + b << ' ' << a*b << ' ' << endl;//值流出来 a+b输入到空格 a*b输入到空格

  return 0;
}

AcWing 1. A + B
#include <iostream>

using namespace std;

int main()
{
  int a, b;
  //变量一定要先定义
  cin >> a >> b;//值流进去

  cout << a + b << endl;//值流出来

  return 0;
}

AcWing 608. 差
// cin/cout做法
#include <iostream>

using namespace std;

int main()
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  cout << "DIFERENCA = " << A * B - C * D << endl;
  
  return 0;
}

// scanf/print做法
#include <cstdio>

int main()
{
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);// %代表输入一个整数 &取地址符号 然后对应放到%d上去
  //scanf 会判断读入的类型
  printf("DIFERENCA = %d\n", a * b - c * d);
  return 0;
}

AcWing 604. 圆的面积
#include <cstdio>

using namespace std;

int main() 
{
  double pi = 3.14159, r;
  scanf("%lf", &r);
  printf("A=%.4lf\n", pi * r * r);//保留4位小数的浮点数

  return 0;
}

用scanf 和printf的时候效率好 所以不一定能被cin cout 替代
scanf("") ""不能有空格
long long scanf("%lld")
float %f
double %lf
char %c

取模 
cout << 5 % 2 << endl;
cout << -5 % 2 << endl;
cout << 5 % -2 <<endl;
cout << -5 % -2 << endl;
这些一运算就知道 取模仅取决于-5 2是不是负数无所谓

自增
a++ 
++a

int a = 5;
a ++

int a = 5;
++ a;

int a = 5;
int b = a ++;

int a = 5;
int b = ++ a;

b += a ; b= b + a;

类型转换
int 转换 char ASCII表 'a' 97 'A' 65
int a = 5;
float b = (float)a;

printf("%d", b);

int float做运算 自动转换为float类型的结果(自动向上转换)

int c = b * 2, d; //定义可以一起定义 并且不需要再打一遍int 并且可以定义时候赋值

d = c * 1;





AcWing 606. 平均数1
#include <cstdio>

int main()
{
  double a, b;
  scanf("%lf%lf", &a, &b);
  prinf("MEDIA = %.5lf\n", (a * 3.5 + b * 7.5) / 11);

  return 0;
}

AcWing 609. 工资
#include <cstdio>

int main()
{
  int number, hour;
  double money;
  scanf("%d%d%dlf", &number, &hour, &money);
  prinf("NUMBER = %d\n", nunber);
  prinf("SALARY = U$ %.2lf/n", hour * money);

  return 0;
} 

AcWing 615. 油耗
#include <cstdio>

int main()
{
  double x, y;
  scanf("%lf%lf", &x, &y);
  prinf("%.3lf km/l", x / y);

  return 0;
}

AcWing 616. 两点间的距离
#include <cstdio>
#include <cmath>

int main()
{
  double x1, y1, x2, y2;
  scanf("%lf%lf", &x1, &y1);
  scanf("%lf%lf", &x2, &y2);
  prinf("%.4lf\n", sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));

  return 0;
}

AcWing 654. 时间转换
#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d:%d:%d", n / 3600, n % 3600 / 60, n % 60);
    // n / 3600 小时 n % 3600 / 60 分钟 n % 60 秒

    return 0;
}

AcWing 605. 简单乘积
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "PROD = " << a * b << endl;

    return 0;
}

AcWing 611. 简单计算
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    double n1, s1, p1;
    double n2, s2, p2;

    cin >> n1 >> s1 >> p1;
    cin >> n2 >> s2 >> p2;

    printf("VALOR A PAGAR: R$ %.2lf\n", s1 * p1 + s2 * p2);
    // VALOR A PAGAR: R$ %.2lf ?

    return 0;
}

AcWing 653. 钞票
#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", n);

    printf("%d nota(s) de R$ 100,00\n", n / 100);
    n %= 100;
    printf("%d nota(s) de R$ 50,00\n", n / 50);
    n %= 50;
    printf("%d nota(s) de R$ 20,00\n", n / 20);
    n %= 20;
    printf("%d nota(s) de R$ 10,00\n", n / 10);
    n %= 10;
    printf("%d nota(s) de R$ 5,00\n", n / 5);
    n %= 5;
    printf("%d nota(s) de R$ 2,00\n", n / 2);
    n %= 2;
    printf("%d nota(s) de R$ 1,00\n", n);

    return 0;
}

AcWing 612. 球的体积
#include <cstdio>

int main()
{
    double r;
    scanf("%lf", &r);
    // scanf 把字符型转变成数值型 采用引用 减少读入时间

    printf("VOLUME = %.3lf\n", 4.0 / 3 * 3.14159 * r * r * r);
    //printf 

    return 0;
}

AcWing 613. 面积
#include <cstdio>

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    printf("TRIANGULO: %.3lf\n", a * c / 2);
    printf("CIRCULO: %.3lf\n", 3.14159 * c * c);
    printf("TRAPEZIO: %.3lf\n", (a + b) * c / 2);
    printf("QUADRADO: %.3lf\n", b * b);
    printf("RETANGULO: %.3lf\n", a * b);

    return 0;
}

AcWing 607. 平均数2
#include <cstdio>

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("MEDIA = %.1lf\n", (a * 2 + b * 3 + c * 5) / 10);

    return 0;
}

AcWing 610. 工资和奖金
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string name;
    cin >> name;
    // cin >> 读入 不需要 endl

    double x, y;
    cin >> x >> y;

    printf("TOTAL = R$ %.2lf\n", x + y * 0.15);

    return 0;
}

AcWing 614. 最大值

//本身是数字 不需要英scanf 将字符转变成数字类型
// abs ?
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int t = (a + b + abs(a - b)) / 2;
    int r = (t + c + abs(t - c)) / 2;

    cout << r << " eh o maior" << endl;

    return 0;
}

AcWing 617. 距离
#include <iostream> 

using namespace std;

int main()
{
    int l;
    cin >> l;
    cout << 2 * l << " minutos" << endl;
    //2 * l 数值先输出
    //用cout 而不是 printf
    // printf 一般是需要 % 给定数字 printf("TOTAL = R$ %.2lf\n", x + y * 0.15);
    //printf("%.2lf minutos", 2 * l );

    return 0;
}

AcWing 618. 燃料消耗
#include <cstdio>

int main()
{
    double s, t;
    scanf("%lf%lf", &s, &t);
    printf("%.3lf\n", s * t / 12);
    // 与cout << 2 * l << " minutos" << endl; 对比
    //没有minutos字符串 可以用printf
    return 0;
}

AcWing 656. 钞票和
//取余操作%是不能用在浮点数的,所以y总把数转换为了整数,再用取余操作
#include <cstdio>

int main()
{
    double m;
    scanf("%lf", &m);
    int n = m * 100;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", n / 10000); n %= 10000;
    printf("%d nota(s) de R$ 50.00\n", n / 5000); n %= 5000;
    printf("%d nota(s) de R$ 20.00\n", n / 2000); n %= 2000;
    printf("%d nota(s) de R$ 10.00\n", n / 1000); n %= 1000;
    printf("%d nota(s) de R$ 5.00\n", n / 500); n %= 500;
    printf("%d nota(s) de R$ 2.00\n", n / 200); n %= 200;

    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", n / 100); n %= 100;
    printf("%d moeda(s) de R$ 0.50\n", n / 50); n %= 50;
    printf("%d moeda(s) de R$ 0.25\n", n / 25); n %= 25;
    printf("%d moeda(s) de R$ 0.10\n", n / 10); n %= 10;
    printf("%d moeda(s) de R$ 0.05\n", n / 5); n %= 5;
    printf("%d moeda(s) de R$ 0.01\n", n / 1); n %= 1;

    return 0;
}

AcWing 655. 天数转换
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n / 365 << " ano(s)" << endl;//年
    cout << n % 365 / 30 << " mes(es)" << endl;//月
    cout << n % 365 % 30 << " dia(s)" << endl;//日

    return 0;
}