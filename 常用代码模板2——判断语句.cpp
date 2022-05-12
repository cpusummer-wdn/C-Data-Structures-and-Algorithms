
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-6;
int main()
{
    int a = 3;
    if (fabs(sqrt(3) * sqrt(3) - 3) < eps) puts ("相等");

    return 0;

}

AcWing 665. 倍数
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a % b == 0 || b % a == 0) cout << "Sao Multiplos" << endl;
    else cout << "Nao sao Multiplos" << endl;

    return 0;
}

AcWing 660. 零食
#include <cstdio>

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);

    double price;
    if (x == 1) price = 4;
    else if (x == 2) price = 4.5;
    else if (x == 3) price = 5;
    else if (x == 4) price = 2;
    else price = 1.5;

    printf("Total: R$ %.2lf\n", price * y);

    return 0;
}

AcWing 659. 区间
#include  <iostream>

using namespace std;

int main()
{
  double x;
  cin >> x;

  if (x >= 0 && x <= 25) cout << < "Intervalo [0,25]" << endl;
  else if (x > 25 && x <= 50) cout << "Intervalo (25,50]" << endl;
  else if (x > 50 && x <= 75) cout << "Intervalo (50,75]" << endl;
  else if (x > 75 && x <= 100) cout << "Intervalo (75,100]" << endl;
  else cout << "Fora de intervalo" << endl;

  return 0;
}

AcWing 664. 三角形
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    //这里的数学公式是什么
    if (a + b > c && a + c > b && b + c > a)
    //三角形成立条件
        printf("Perimetro = %.1lf\n", a + b + c);
    else
    //三角形不成立条件
        printf("Area = %.1lf\n", (a + b) * c / 2);

    return 0;
}

AcWing 667. 游戏时间
//res 代表返回值
//一天是24小时制
// res = b - a + 24;

#include <cstdio>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int res;
    if (a < b) res = b - a;
    else  res = b - a + 24;

    printf("O JOGO DUROU %d HORA(S)\n", res);

    return 0;
}

AcWing 669. 加薪
//选择语句从小到大实现 这样可以少写控制条件
//  if (salary <= 400)
//  else if (salary <= 800)
//  而不是else if (salary <= 800 && salary > 400)
#include <cstdio>

int main()
{
    double salary;
    scanf("%lf", &salary);

    double x;

    if (salary <= 400) x = 0.15;
    else if (salary <= 800) x = 0.12;//小于等于400 执行第一步的选择语句
    else if (salary <= 1200) x = 0.1;
    else if (salary <= 2000) x = 0.07;
    else x = 0.04;

    printf("Novo salario: %.2lf\n", salary * (1 + x));
    printf("Reajuste ganho: %.2lf\n", salary * x);
    printf("Em percentual: %.0lf %%", x * 100);

    return 0;
}

AcWing 670. 动物
#include <iostream>

using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    if (a == "vertebrado")
    {
        if (b == "ave")
        {
            if (c == "carnivoro") cout << "aguia" << endl;
            else cout << "pomba" << endl;
        }
        else
        {
            if (c == "onivoro") cout << "homem" << endl;
            else cout << "vaca" << endl;
        }
    }
    else
    {
        if (b == "inseto")
        {
            if (c == "hematofago") cout << "pulga" << endl;
            else cout << "lagarta" << endl;
        }
        else
        {
            if (c == "hematofago") cout << "sanguessuga" << endl;
            else cout << "minhoca" << endl;
        }
    }

    return 0;
}

AcWing 657. 选择练习1
#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b > c && d > a && c + d > a + b && c > 0 && d > 0 && a % 2 == 0)
    //选择条件
        cout << "Valores aceitos" << endl;
    else
        cout << "Valores nao aceitos" << endl;

    return 0;
}

AcWing 671. DDD
#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    if (x == 61) cout << "Brasilia" << endl;
    else if (x == 71) cout << "Salvador" << endl;
    else if (x == 11) cout << "Sao Paulo" << endl;
    else if (x == 21) cout << "Rio de Janeiro" << endl;
    else if (x == 32) cout << "Juiz de Fora" << endl;
    else if (x == 19) cout << "Campinas" << endl;
    else if (x == 27) cout << "Vitoria" << endl;
    else if (x == 31) cout << "Belo Horizonte" << endl;
    else cout << "DDD nao cadastrado" << endl;

    return 0;
}

AcWing 662. 点的坐标
#include <iostream>

using namespace std;

int main()
{
    double x, y;
    cin >> x >> y;

    if (x > 0 && y > 0) cout << "Q1" << endl;
    else if (x < 0 && y > 0) cout << "Q2" << endl;
    else if (x < 0 && y < 0) cout << "Q3" << endl;
    else if (x > 0 && y < 0) cout << "Q4" << endl;
    else
    {
        if (!x && !y) cout << "Origem" << endl;
        //原点
        else if (!y) cout << "Eixo X" << endl;
        //x轴
        else cout << "Eixo Y" << endl;
        //不用写选择条件了
        //选择语句最重要的是判断选择语句的先后执行顺序
    }

    return 0;
}

AcWing 666. 三角形类型
#include <iostream>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    if (b > a)
    {
        double t = a;
        a = b;
        b = t;
        //已经定义了 a b c的数据类型 只需要定义 t 的数据类型就可
        //交换两个数
    }
    if (c > a)
    {
        double t = a;
        a = c;
        c = t;
    }
    if (c > b)
    {
        double t = b;
        b = c;
        c = t;
    }
    //保证 a b c 的长度是 a > b > c

    if (a >= b + c) cout << "NAO FORMA TRIANGULO" << endl;
    //三角形不成立的条件 a >= b + c
    else
    //三角形成立
    {
        if (a * a == b * b + c * c) cout << "TRIANGULO RETANGULO" << endl;
        // 直角三角形
        if (a * a > b * b + c * c) cout << "TRIANGULO OBTUSANGULO" << endl;
        //钝角三角形
        if (a * a < b * b + c * c) cout << "TRIANGULO ACUTANGULO" << endl;
        //锐角三角形
        if (a == b && b == c) cout << "TRIANGULO EQUILATERO" << endl;
        //等腰三角形
        else if (a == b || b == c || a == c) cout << "TRIANGULO ISOSCELES" << endl;
        //等边三角形
    }

    return 0;
}

AcWing 668. 游戏时间2
#include <cstdio>

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    // 先都转化为分钟
    int start = a * 60 + b;
    int end = c * 60 + d;

    int spent_time = end - start;
    //??
    if (spent_time <= 0) spent_time += 1440;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)", spent_time / 60, spent_time % 60);

    return 0;
}

AcWing 672. 税
#include <cstdio>

int main()
{
  double x;
  scanf("%lf", &x);

  double sum = 0;
  if (x > 2000) 
  {
    double y = 3000;
    if (x < 3000) y = x;
    sum += (y - 2000) * 0.08;
  }
  // else
  // if 可以不接 else 直接再接一个选择语句
  if (x > 3000)
  {
    double y = 4500;
    if (x < 4500) y = x;
    sum += (y - 3000) * 0.18;
  }
  if (x > 4500) 
    sum += (x - 4500) * 0.28;

  if (sum == 0) printf("Isento");
  else printf("R$ %.2lf\n", sum);

  return 0;
}

AcWing 663. 简单排序
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int x = a, y = b, z = c;

    if (b < a)
    {
        int t = a;
        a = b;
        b = t;
    }
    if (c < a)
    {
        int t = a;
        a = c;
        c = t;
    }
    if (c < b)
    {
        int t = b;
        b = c;
        c = t;
    }

    cout << a << endl << b << endl << c << endl << endl; // endl << endl两次?
    cout << x << endl << y << endl << z << endl;

    return 0;
}

AcWing 658. 一元二次方程公式
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    double delta = b * b - 4 * a * c;
    if (delta < 0 || a == 0) printf("Impossivel calcular\n");
    else
    {
        delta = sqrt(delta);//开平方
        double x1 = (-b + delta) / (2 * a);
        double x2 = (-b - delta) / (2 * a);

        printf("R1 = %.5lf\n", x1);
        printf("R2 = %.5lf\n", x2);
    }

    return 0;
}

AcWing 661. 平均数3
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
  double n1, n2, n3, n4;
  scanf("%lf%lf%lf%lf", &n1, &n2, &n3, &n4);

  double x = (n1 * 2 + n2 * 3 + n3 * 4 + n4) / 10;

  printf("Media: %.1lf\n", x + 1e-8); //为了防止出现4.8499999999 这种极端情况
  if (x >= 7) printf("Aluno approvado.\n");
  else if (x < 5) printf("Aluno reprovado.\n");
  else
  {
      printf("Aluno em exame.\n");

      double y;
      scanf("%lf", &y);
      printf("Nota do exame: %.1lf\n", y + 1e-8);
      //

      double z = (x + y) / 2;
      if (z >= 5) printf("Aluno aprovado.\n");
      // 只有if else if else 和 if else 两种选择结构
      else printf("Aluno reprovado.\n");

      printf("Media final: %.1lf\n", z + 1e-8);   
  }
}

