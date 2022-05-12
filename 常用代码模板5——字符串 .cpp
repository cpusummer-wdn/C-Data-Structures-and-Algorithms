z字符串是计算机与人类沟通的重要手段。——闫学灿

1. 字符与整数的联系——ASCII码
每个常用字符都对应一个-128 ~ 127的数字，二者之间可以相互转化：

#include <iostream>

using namespace std;

int main()
{
    char c = 'a';
    cout << (int)c << endl;

    int a = 66;
    cout << (char)a << endl;

    return 0;
}
常用ASCII值：'A'- 'Z'是65 ~ 90，'a' - 'z'是97 - 122，0 - 9是 48 - 57。
字符可以参与运算，运算时会将其当做整数：

#include <iostream>

using namespace std;

int main()
{
    int a = 'B' - 'A';
    int b = 'A' * 'B';
    char c = 'A' + 2;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}
练习：输入一行字符，统计出其中数字字符的个数，以及字母字符的个数。

2. 字符数组
字符串就是字符数组加上结束符'\0'。

可以使用字符串来初始化字符数组，但此时要注意，每个字符串结尾会暗含一个'\0'字符，因此字符数组的长度至少要比字符串的长度多 11 ！

#include <iostream>

using namespace std;

int main()
{
    char a1[] = {'C', '+', '+'};            // 列表初始化，没有空字符
    char a2[] = {'C', '+', '+', '\0'};      // 列表初始化，含有显示的空字符
    char a3[] = "C++";                      // 自动添加表示字符串结尾的空字符
    char a4[6] = "Daniel";                  // 错误：没有空间可以存放空字符

    return 0;
}
2.1 字符数组的输入输出：
#include <iostream>

using namespace std;

int main()
{
    char str[100];

    cin >> str;             // 输入字符串时，遇到空格或者回车就会停止
    cout << str << endl;    // 输出字符串时，遇到空格或者回车不会停止，遇到'\0'时停止
    printf("%s\n", str);

    return 0;
}
读入一行字符串，包括空格：

#include <iostream>

using namespace std;

int main()
{
    char str[100];

    fgets(str, 100, stdin);  // gets函数在新版C++中被移除了，因为不安全。
                             // 可以用fgets代替，但注意fgets不会删除行末的回车字符

    cout << str << endl;

    return 0;
}
2.2 字符数组的常用操作
下面几个函数需要引入头文件:

#include <string.h>
(1) strlen(str)，求字符串的长度
(2) strcmp(a, b)，比较两个字符串的大小，a < b返回-1，a == b返回0，a > b返回1。这里的比较方式是字典序！
(3) strcpy(a, b)，将字符串b复制给从a开始的字符数组。

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char a[100] = "hello world!", b[100];

    cout << strlen(a) << endl;

    strcpy(b, a);

    cout << strcmp(a, b) << endl;

    return 0;
}

2.3 遍历字符数组中的字符：
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char a[100] = "hello world!";

    // 注意：下述for循环每次均会执行strlen(a)，运行效率较低，最好将strlen(a)用一个变量存下来
    
    for (int i = 0; i < strlen(a); i ++ )
        cout << a[i] << endl;

    return 0;
}
练习：给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出no。

练习：把一个字符串中特定的字符全部用给定的字符替换，得到一个新的字符串。

3. 标准库类型string
可变长的字符序列，比字符数组更加好用。需要引入头文件：
#include <string>

3.1 定义和初始化
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;              // 默认初始化，s1是一个空字符串
    string s2 = s1;         // s2是s1的副本，注意s2只是与s1的值相同，并不指向同一段地址
    string s3 = "hiya";     // s3是该字符串字面值的副本
    string s4(10, 'c');     // s4的内容是 "cccccccccc"

    return 0;
}

3.2 string上的操作
(1) string的读写：

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;

    cin >> s1 >> s2;
    cout << s1 << s2 << endl;

    return 0;
}
注意：不能用printf直接输出string，需要写成：printf(“%s”, s.c_str());

(2) 使用getline读取一整行

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;

    getline(cin, s);

    cout << s << endl;

    return 0;
}
(3) string的empty和size操作（注意size是无符号整数，因此 s.size() <= -1一定成立）：

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2 = "abc";

    cout << s1.empty() << endl;
    cout << s2.empty() << endl;

    cout << s2.size() << endl;

    return 0;
}
(4) string的比较：

支持 >, <, >=, <=, ==, !=等所有比较操作，按字典序进行比较。

(5) 为string对象赋值：

string s1(10, 'c'), s2;     // s1的内容是 cccccccccc；s2是一个空字符串
s1 = s2;                    // 赋值：用s2的副本替换s1的副本
                            // 此时s1和s2都是空字符串
(6) 两个string对象相加：

//string s1 = "hello,  "", s2 = "world\n";
string s3 = s1 + s2;                    // s3的内容是 hello, world\n
s1 += s2;                               // s1 = s1 + s2
(7) 字面值和string对象相加：

做加法运算时，字面值和字符都会被转化成string对象，因此直接相加就是将这些字面值串联起来：

string s1 = "hello", s2 = "world";      // 在s1和s2中都没有标点符号
string s3 = s1 + ", " + s2 + '\n';
当把string对象和字符字面值及字符串字面值混在一条语句中使用时，必须确保每个加法运算符的两侧的运算对象至少有一个是string：

string s4 = s1 + ", ";  // 正确：把一个string对象和有一个字面值相加
string s5 = "hello" + ", "; // 错误：两个运算对象都不是string

string s6 = s1 + ", " + "world";  // 正确，每个加法运算都有一个运算符是string
string s7 = "hello" + ", " + s2;  // 错误：不能把字面值直接相加，运算是从左到右进行的

3.3 处理string对象中的字符
可以将string对象当成字符数组来处理：
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "hello world";

    for (int i = 0; i < s.size(); i ++ )
        cout << s[i] << endl;

    return 0;
}

或者使用基于范围的for语句：
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "hello world";

    for (char c: s) cout << c << endl;

    for (char& c: s) c = 'a';

    cout << s << endl;

    return 0;
}
练习：密码翻译，输入一个只包含小写字母的字符串，将其中的每个字母替换成它的后继字母，如果原字母是'z'，则替换成'a'。

练习：输入两个字符串，验证其中一个串是否为另一个串的子串。



AcWing 772. 只出现一次的字符
#include <iostream>
#include <cstring>

using namespace std;

int cnt[26];
char str[100010];

int main()
{
    cin >> str;

    for (int i = 0; str[i]; i ++ ) cnt[str[i] - 'a'] ++ ;

    for (int i = 0; str[i]; i ++ )
        if (cnt[str[i] - 'a'] == 1)
        {
            cout << str[i] << endl;
            return 0;
        }

    puts("no");

    return 0;
}

AcWing 769. 替换字符
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    char str[31];
    scanf("%s", str);

    char c;
    scanf("\n%c", &c);

    for (int i = 0; str[i]; i ++ )
        if (str[i] == c)
            str[i] = '#';

    puts(str);

    return 0;
}

AcWing 767. 信息加密
#include <iostream>

using namespace std;

int main()
{
    string s;

    getline(cin, s);

    for (auto &c : s)
        if (c >= 'a' && c <= 'z') c = (c - 'a' + 1) % 26 + 'a';
        else if (c >= 'A' && c <= 'Z') c = (c - 'A' + 1) % 26 + 'A';

    cout << s << endl;

    return 0;
}

AcWing 760. 字符串长度
注意：fgets函数会把回车也读进来
#include <cstdio>

int main()
{
    char str[101];

    fgets(str, 101, stdin);

    int len = 0;
    for (int i = 0; str[i] && str[i] != '\n'; i ++ ) len ++ ;

    printf("%d\n", len);

    return 0;
}

AcWing 761. 字符串中的数字个数
#include <cstdio>

int main()
{
    char str[101];

    fgets(str, 101, stdin);

    int cnt = 0;
    for (int i = 0; str[i]; i ++ )
        if (str[i] >= '0' && str[i] <= '9')
            cnt ++ ;

    printf("%d\n", cnt);

    return 0;
}

AcWing 763. 循环相克令
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        string a, b;
        cin >> a >> b;

        int x, y;
        if (a == "Hunter") x = 0;
        else if (a == "Bear") x = 1;
        else x = 2;

        if (b == "Hunter") y = 0;
        else if (b == "Bear") y = 1;
        else y = 2;

        if (x == y) puts("Tie");
        else if (x == (y + 1) % 3) puts("Player1");
        else puts("Player2");
    }

    return 0;
}

AcWing 765. 字符串加空格
#include <iostream>

using namespace std;

int main()
{
    string a;
    getline(cin, a);

    string b;
    for (auto c : a) b = b + c + ' ';

    b.pop_back();  // 把最后一个字符删掉

    cout << b << endl;

    return 0;
}

AcWing 773. 字符串插入
#include <iostream>

using namespace std;

int main()
{
    string a, b;

    while (cin >> a >> b)
    {
        int p = 0;
        for (int i = 1; i < a.size(); i ++ )
            if (a[i] > a[p])
                p = i;

        cout << a.substr(0, p + 1) + b + a.substr(p + 1) << endl;
    }

    return 0;
}

AcWing 762. 字符串匹配
#include <iostream>

using namespace std;

int main()
{
    double k;
    string a, b;
    cin >> k >> a >> b;

    int cnt = 0;
    for (int i = 0; i < a.size(); i ++ )
        if (a[i] == b[i])
            cnt ++ ;

    if ((double)cnt / a.size() >= k) puts("yes");
    else puts("no");

    return 0;
}

AcWing 768. 忽略大小写比较字符串大小
#include <cstdio>
#include <cstring>

int main()
{
    char a[100], b[100];

    fgets(a, 100, stdin);
    fgets(b, 100, stdin);

    if (a[strlen(a) - 1] == '\n') a[strlen(a) - 1] = 0;  // 去掉末尾回车
    if (b[strlen(b) - 1] == '\n') b[strlen(b) - 1] = 0;  // 去掉末尾回车

    for (int i = 0; a[i]; i ++ )
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;

    for (int i = 0; b[i]; i ++ )
        if (b[i] >= 'A' && b[i] <= 'Z')
            b[i] += 32;

    int t = strcmp(a, b);
    if (t == 0) puts("=");
    else if (t < 0) puts("<");
    else puts(">");

    return 0;
}

AcWing 766. 去掉多余的空格
cin做法
#include <iostream>

using namespace std;

int main()
{
    string s;
    while (cin >> s) cout << s << ' ' ;

    return 0;
}
第一类双指针算法
#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    string r;
    for (int i = 0; i < s.size(); i ++ )
        if (s[i] != ' ') r += s[i];
        else
        {
            r += ' ';
            int j = i;
            while (j < s.size() && s[j] == ' ') j ++ ;
            i = j - 1;
        }

    cout << r << endl;

    return 0;
}
局部性判断方法
#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    string r;
    for (int i = 0; i < s.size(); i ++ )
        if (s[i] != ' ') r += s[i];
        else
        {
            if (!i || s[i - 1] != ' ') r += ' ';
        }

    cout << r << endl;

    return 0;
}

AcWing 764. 输出字符串
#include <iostream>

using namespace std;

int main()
{
    string a, b;
    getline(cin, a);

    for (int i = 0; i < a.size(); i ++ ) b += a[i] + a[(i + 1) % a.size()];

    cout << b << endl;

    return 0;
}

AcWing 770. 单词替换
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string s, a, b;

    getline(cin, s);
    cin >> a >> b;

    stringstream ssin(s);
    string str;
    while (ssin >> str)
        if (str == a) cout << b << ' ';
        else cout << str << ' ';

    return 0;
}

AcWing 771. 字符串中最长的连续出现的字符
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        string str;
        cin >> str;

        int cnt = 0;
        char c;

        for (int i = 0; i < str.size(); i ++ )
        {
            int j = i;
            while (j < str.size() && str[j] == str[i]) j ++ ;
            if (j - i > cnt) cnt = j - i, c = str[i];
            i = j - 1;
        }

        cout << c << ' ' << cnt << endl;
    }

    return 0;
}

AcWing 774. 最长单词
#include <iostream>

using namespace std;

int main()
{
    string res, str;

    while (cin >> str)
    {
        if (str.back() == '.') str.pop_back();
        if (str.size() > res.size()) res = str;
    }

    cout << res << endl;

    return 0;
}

AcWing 775. 倒排单词
#include <iostream>

using namespace std;

int main()
{
    string str[100];

    int n = 0;
    while (cin >> str[n]) n ++ ;

    for (int i = n - 1; i >= 0; i -- ) cout << str[i] << ' ';
    cout << endl;

    return 0;
}

AcWing 776. 字符串移位包含问题
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;

    cin >> a >> b;
    if (a.size() < b.size()) swap(a, b);

    for (int i = 0; i < a.size(); i ++ )
    {
        a = a.substr(1) + a[0];

        for (int j = 0; j + b.size() <= a.size(); j ++ )
        {
            int k = 0;
            for (; k < b.size(); k ++ )
                if (a[j + k] != b[k])
                    break;
            if (k == b.size())
            {
                puts("true");
                return 0;
            }
        }
    }

    puts("false");

    return 0;
}

AcWing 777. 字符串乘方
#include <iostream>

using namespace std;

int main()
{
    string str;

    while (cin >> str, str != ".")
    {
        int len = str.size();

        for (int n = len; n; n -- )
            if (len % n == 0)
            {
                int m = len / n;
                string s = str.substr(0, m);
                string r;
                for (int i = 0; i < n; i ++ ) r += s;

                if (r == str)
                {
                    cout << n << endl;
                    break;
                }
            }
    }

    return 0;
}

AcWing 778. 字符串最大跨距
#include <iostream>

using namespace std;

int main()
{
    string s, s1, s2;

    char c;
    while (cin >> c, c != ',') s += c;
    while (cin >> c, c != ',') s1 += c;
    while (cin >> c) s2 += c;

    if (s.size() < s1.size() || s.size() < s2.size()) puts("-1");
    else
    {
        int l = 0;
        while (l + s1.size() <= s.size())
        {
            int k = 0;
            while (k < s1.size())
            {
                if (s[l + k] != s1[k]) break;
                k ++ ;
            }
            if (k == s1.size()) break;
            l ++ ;
        }

        int r = s.size() - s2.size();
        while (r >= 0)
        {
            int k = 0;
            while (k < s2.size())
            {
                if (s[r + k] != s2[k]) break;
                k ++ ;
            }
            if (k == s2.size()) break;
            r -- ;
        }

        l += s1.size() - 1;

        if (l >= r) puts("-1");
        else printf("%d\n", r - l - 1);
    }

    return 0;
}

AcWing 779. 最长公共字符串后缀
#include <iostream>

using namespace std;

const int N = 200;

int n;
string str[N];

int main()
{
    while (cin >> n, n)
    {
        int len = 1000;
        for (int i = 0; i < n; i ++ )
        {
            cin >> str[i];
            if (len > str[i].size()) len = str[i].size();
        }

        while (len)
        {
            bool success = true;
            for (int i = 1; i < n; i ++ )
            {
                bool is_same = true;
                for (int j = 1; j <= len; j ++ )
                    if (str[0][str[0].size() - j] != str[i][str[i].size() - j])
                    {
                        is_same = false;
                        break;
                    }
                if (!is_same)
                {
                    success = false;
                    break;
                }
            }

            if (success) break;
            len -- ;
        }

        cout << str[0].substr(str[0].size() - len) << endl;
    }

    return 0;
}



顺带一提 cin 和 scanf读入字符串时遇到空格就停止了。
1. c
#include<string.h>
#include<stdio.h>

int main()
{
    char s[105];
    gets(s);
    printf("%d",strlen(s));
    return 0;
}


2.c++
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string a;
    getline(cin, a);
    cout << a.size() << endl;
    return 0;
}

3.
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[105];
    cin.get(a,105);//需要注意cin.get()不会把换行符取出删除，影响下一次读入！
    cout << strlen(a) << endl;
    return 0;
}

4.
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[105];
    cin.getline(a,105);//需要注意cin.getline()会把换行符取出删除，不影响下一次读入！
    cin.getline需要引入头文件cstring
    cout << strlen(a) << endl;
    return 0;
}


5.python
print(len(input()))

6.java
import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        String a = cin.nextLine();
        System.out.println(a.length());
    }
}

7.go
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    var scan = bufio.NewScanner(os.Stdin)
    scan.Scan()
    fmt.Printf("%d", len(scan.Text()))
}

***
2.1
#include<iostream>
using namespace std;

int main()
{
    string a;
    getline(cin,a);
    int ans = 0;
    
    for (int i = 0; i < a.size(); i ++)
    {
        if(a[i] <= '9' && a[i] >= '0')
        {
            ans ++;
        }
    }

    cout << ans << endl;

    return 0;
}

2.2
#include<iostream>
using namespace std;

int main()
{
    int res;
    string s;

    while(cin>>s) 
    for(auto x:s) res+= isdigit(x);
    cout<<res;
}

2.3
#include<iostream>
using namespace std;

int main()
{
    int res;
    string s;

    getline(cin,s); // getline 不需要初始化
    for(auto x:s) res += isdigit(x);
    cout<<res;
}


#include<iostream>
using namespace std;

int main()
{
    string a;
    //int res=0;不需要初始化
    int res;
    
    while (cin >> a)
    {
        for (auto x:a) res += isdigit(x);
        
    }
    
    cout << res <<endl;
    
    return 0;
}
2.4
遍历一个字符串的字符，并判断是不是数字
#include<iostream>
using namespace std;

int main() {
    string s;
    int n=0;
    getline(cin, s);

    for(char c:s){
        if(c>='0'&&c<='9') {
            n++;
        }
    }
    cout<<n;
}


#include<iostream>
using namespace std;

int main()
{
    string a;
    
    int res = 0; 遍历写法 遍历需要res初始化赋值为0
    
    while (cin >> a)
    {
        for (char c:a) 
        {
          if ( c >= '0' && c <='9')
          
          res ++;
        
            
        }
        
    }
    
    cout << res <<endl;
    
    return 0;
}


2.5
#include <iostream>
using namespace std;

int main() 
{
    string s;
    int n=0;
    getline(cin, s);
    for(char c:s){
        if(isdigit(c)) {
            n++;
        }
    }
    cout<<n;
}


if (a[a.size() - 1 - (len - 1)] == s[s.size() - 1 - (len - 1) ])
{
    res ++;
}
else
{
    break;
}

max = min (MAX, res);

if (MAX) 
{
    cout << s.substr                                                                                         
}


3.循环相克令
用string的size之差表示player1赢的三种情况
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string x, y;
    while (n --)
    {
        cin >> x >> y;
        int a = x.size(), b = y.size();
        if (a - b == -1 || a - b == -2 || a - b == 3)//我愿称这两行为绝妙想法
            cout << "Player1" << endl;
        else if (a == b)
            cout << "Tie" << endl;
        else cout << "Player2" << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
   
    while (n --) //这个在循环里有讲
   {
    string a, b;
    cin >> a >> b;
    
  
   int x, y;
   
   if (a == "Hunter") x = 0; 
   else if (a == "Bear") x = 1;
   else x = 2;
   
   if (b == "Hunter") y = 0;
   else if (b == "Bear") y = 1;
   else y = 2;
    
   if (x == y) puts("Tie");
   else if (x == (y + 1) % 3 )  puts("Player1");//妙啊
   else  puts("Player2");
   }
   return 0;
}

4.字符串加空格
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    for(int i =  0; i < s.size(); i++)
    {
        s.insert(i + 1," ");   //stl 函数

        i++; //由于插入了空格 ,工作指针后移一位
    }
    cout << s <<endl;
}


#include <iostream>
#include <string.h>


using namespace std;

int main()
{
    string a;
    getline(cin, a);
    
    for (auto &c:a)  cout << c << ' ';
}

#include <iostream>

using namespace std;

int main()
{
    string a;
    getline(cin, a);
    
    for (int i = 0; i <= a.size(); i ++)
    {
        cout << a[i];
        if (i != a.size() - 1) cout << ' ';
        
    }
    
    cout << endl;
    
    return 0;
}

5.
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    
   char a[31];
   //scanf("%c", a);
   scanf("%s", a);
   char b;
   scanf("\n%c", &b);
   
  
   for (int i = 0; a[i]; i ++)
   if (a[i] == b) a[i] = '#';
   
   puts(a);puts可以最后输出不会自动换行 endl会自动换行很烦
  

}


#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
   char s[31];
   fgets(s, 31, stdin);
   
   char a;
   cin  >> a;
   
   for (int i = 0; s[i]; i ++)
   {
   if (s[i] == a) s[i] = '#';// if (s[i] = a) s[i] = '#'
    printf("%c", s[i]);
   }
   return 0;
}



#include <iostream>

using namespace std ;

int main ()
{
    char a[31];
    cin.getline(a,31);
    char c ;
    cin >> c ;
    for(int i = 0 ; a[i] ; i ++)
    {
        if( a[i] == c) 
        a[i] = '#' ;
        cout <<a[i] ;
    }

    return 0 ;
}

#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
   string a;
   cin >> a;
   
   char b;
   cin >> b;
   
   for (auto c:a)
   {
       //if (c == b) c = '#';
       if (c == b) cout << '#';
       else cout << c;
   }
   
   return 0;
   
}


6.
#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
   string a, b;
   
   while(cin >> a >>b){
    int p =0;
   for (int i =1 ; i < a.size(); i ++)
   /*i=1意思是用a[1]开始的所有数和a[0]进行比较，如果这个数比a[0]大，则p指向那个数
   然后继续比较a[i]和a[p]谁大，结果就是最大的数是p对应的那个数 */
   {
       
       if (a[i] > a[p]) p = i;
    

    
      
   }
   cout << a.substr(0, p+1) + b + a.substr(p+1) <<endl; //substr左闭右开
       
   }
   
   
   
   
   return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main() {
    string str, sub;
    while(cin >> str >> sub) {
        string res;
        int max = 0;
        for(int i = 1; i < str.size(); ++i) {
            if(str[i] > str[max]) {
                max = i;
            }
        }
        res += str.substr(0, max + 1);
        res += sub;
        res += str.substr(max + 1);
        cout << res << endl;
    }
}




string 的 insert()函数
#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
    string a, b;
    
    while (cin >> a >> b)
    {
        int p = 0;
        for (int i = 1; a[i]; i ++)
        if (a[i] > a[p]) p = i;
        
      cout << a.insert(p+1, b) << endl; //左闭区间 包括p+1
    }
     
   
   
   return 0;
}




注意题目有多组输入，只需要第一个最大的字符
巨集 EOF会在编译原始码前展开实际值给 预处理器 。 C语言中，EOF常被作为文件结束的标志。 还有很多文件处理函数处错误后的返回值也是EOF，因此常被用来判断调用一个函数是否成功。
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[11], substr[4];

    while(scanf("%s %s", str, substr) != EOF){
        int cnt = str[0], res = 0;
        for(int i = 0; i < strlen(str); i++){
            if(str[i] > cnt) cnt = str[i], res = i;
            else if(str[i] == cnt) continue;
        }
        for(int i = 0; i <= res; i ++){
            cout<< str[i];
        }
        for(int i = 0; i < strlen(substr); i++){
            cout<< substr[i];
        }
        for(int i = res + 1; i < strlen(str); i++){
            cout<< str[i];
        }
        puts("");
    }
    return 0;
}



7.

#include <iostream>
#include <cstdio>

using namespace std;

char str[100010];
int cns[26];


int main()
{
   cin  >> str;
   for (int i =0; str[i]; i ++) cns[str[i] - 'a'] ++; 
   
   
   for (int i =0; str[i]; i ++)
   
   if (cns[str[i] - 'a'] == 1)  
   {
    cout << str[i] << endl; //只输出第一个
    // else  cout << "no" << endl;//c ++中单引号和双引号含义不同 题目要求只输出第一个
   
    return 0;//for循环的终止 不能放在全局 必须括号括起来
   }
    puts("no");
    return 0;
}

从前往后查找与从后向前查找同一个字符，如果位置一样那该字符就直出现一次,因为是从第一个开始查找所以找出的是第一个只出现一次的字符


#include<iostream>
#include<cstdio>
#include<string>




using namespace std;

int main()
{
    string a;
    bool b;
    
    while(getline(cin, a))
    {
        for (int i = 0; a[i]; i ++)
        {
            if (a.find(a[i]) == a.rfind(a[i]))
            {
              cout << a[i] << endl;
              //b = 1;
              b == 1;
              return 0;
            }
            
            
            
        }
        
   
    
    }
          //if (b = 0) cout << "no" << endl; = 和 ==
     
     if (b == 0) cout << "no" << endl;
     return 0;
   
    
}



#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    string A;
    bool s=0;
    while(getline(cin,A))
    {
        for(int i=0;i<A.size();i++)
        {
            if(A.find(A[i])==A.rfind(A[i]))
            {
                cout<<A[i]<<endl;
                s=1;
                break;
            }
        }
    }
    if(s==0)
        cout<<"no"<<endl;
    return 0;
}


#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int index=0;
    int x[100000];
    for(auto i: s)
    {
        x[i]++;
    }
    for(auto i:s)
    {
        if(x[i]==1)
        {
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<"no"<<endl;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
  
    int x[100000];
    
    for (auto i:s)
    {
    
     x[i] ++;
    }
    
    for (auto i:s)
    {
        if (x[i] == 1)
        {
        cout << i <<endl;
        
        return 0;
        } // return 0 必须在if里面终止
    }
       
    
     cout << "no" <<endl;
        
        return 0;
    
    
}                                                       

8. 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    double cnt = 0;
    double k;
    string a,b;
    cin>>k>>a>>b; // getline(cin,a);通不过  因为回车被取进去了
    double len = a.size();
    for(int i = 0;i<len;i++)
    {
        if(a[i] == b[i])
            cnt++;
    }
    cnt = cnt/len; //复用cnt变量 可以少定义一个变量
    if(k<=cnt)
    {
        cout<<"yes";
        return 0;
    }
    else cout<<"no";
    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
   double k;
   string a, b;
//   getline(cin, a);
//   getline(cin, a);
  cin >> k >> a >> b;
    
  int p = 0, q = a.size();
  for ( int i = 0; a[i]; i ++)
  {
      if (a[i] == b[i]) 
      {
          p ++;
      }
     
  }
  
  if ((double)p / q >= k) cout << "yes" <<endl;
  else cout << "no" << endl;
  
   
  
   return 0;
}

#include <iostream>

using namespace std;

int main()
{
    double k;
    string a, b;
    cin >> k >> a >> b;

    int cnt = 0;
    for (int i = 0; i < a.size(); i ++ )
        if (a[i] == b[i])
            cnt ++ ;

    if ((double)cnt / a.size() >= k) puts("yes");
    else puts("no");

    return 0;
}



9.
这个方法走不通
int main()
{
   string a, b;
   getlines(cin, a);
   getlines(cin, b);
   
   for (int i = 0; a[i]; i ++)
   {
       if (int)a[i] > (int)
       if ((abs(a[i] - b[i])) == 32 || (abs(a[i] - b[i])) == 0) cout << "=" <<endl;
       else if 
   }
   
   
   return 0;
}


#include <cstdio>
#include <cstring>

int main()
{
    char a[100], b[100];

    fgets(a, 100, stdin);
    fgets(b, 100, stdin);

    if (a[strlen(a) - 1] == '\n') a[strlen(a) - 1] = 0;  // 去掉末尾回车
    if (b[strlen(b) - 1] == '\n') b[strlen(b) - 1] = 0;  // 去掉末尾回车

    for (int i = 0; a[i]; i ++ )
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;

    for (int i = 0; b[i]; i ++ )
        if (b[i] >= 'A' && b[i] <= 'Z')
            b[i] += 32;

    int t = strcmp(a, b);
    if (t == 0) puts("=");
    else if (t < 0) puts("<");
    else puts(">");

    return 0;
}

#include<iostream>
using namespace std;
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(auto &c:a) c = tolower(c);
    for(auto &c:b) c = tolower(c);
    if(a == b) cout << '=';
    if(a > b) cout << '>';
    if(a < b) cout << '<';
}


c++中的c_str()用法
这一题如果使用string类型，也想用strcmp比较大小，可以使用string的成员函数c_str()把string转换为const char *，然后比较。
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);

    for (int i = 0; i < a.size(); i ++)
        if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 32; 
        //string可以直接加数字 自动执行转换 字符可以参与运算，运算时会将其当做整数 y总笔记说了

    for (int i = 0; i < b.size(); i ++)
        if (b[i] >= 'A' && b[i] <= 'Z') b[i] += 32;

    int c;
    c = strcmp(a.c_str(),b.c_str());
    if(c < 0) cout << "<";
    if(c == 0) cout << "=";
    if(c > 0) cout << ">";

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int t = 0, m = a.size()>b.size() ? a.size():b.size();
    for(int i = 0; i < m; i++)
    {
        if(a[i] >= 'a' && a[i] <= 'z') a[i] -= 32;
        if(b[i] >= 'a' && b[i] <= 'z') b[i] -= 32;
        if(a[i] == b[i])
            t++;
        else if(a[i] > b[i])
        {
            cout << ">" << endl;
            break;
        }
        else if(a[i] < b[i])
        {
            cout << "<" << endl;
            break;
        }
    }
    if(t == m) cout << "=" << endl;
    return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    for (int i = 0; s1[i]; i ++ ) if (s1[i] >= 'A' && s1[i] <= 'Z') s1[i] += 32;
    for (int i = 0; s2[i]; i ++ ) if (s2[i] >= 'A' && s2[i] <= 'Z') s2[i] += 32;

    for (int i = 0; s1[i] || s2[i]; i ++ )
    {
        if (s1[i] > s2[i]) 
        {
            puts(">");
            return 0;
        } else if (s1[i] < s2[i]) { 
            puts("<");
            return 0;
        }
    }

    puts("=");

    return 0;
}

#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    for(char x:s)
    {
        if(x>='a'&&x<='y'||x>='A'&&x<='Y') cout<<char(x+1);
        else if(x=='z'||x=='Z') cout<<char(x-25);
        else cout<<x;
    }
    return 0;
}

10.
不会解题
cin做法

#include <iostream>

using namespace std;

int main()
{
    string s;
    while (cin >> s) cout << s << ' ' ;//用了cin的特性，一整条字符串分为多个字符串输入进去，cout<<s<<” “;同时也确保了每个单词之间空一个

    return 0;
}

第一类双指针算法
#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    string r;
    for (int i = 0; i < s.size(); i ++ )
        if (s[i] != ' ') r += s[i];
        else
        {
            r += ' ';
            int j = i;
            while (j < s.size() && s[j] == ' ') j ++ ;
            i = j - 1;
        }

    cout << r << endl;

    return 0;
}

局部性判断方法
#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    string r;
    for (int i = 0; i < s.size(); i ++ )
        if (s[i] != ' ') r += s[i];
        else
        {
            if (!i || s[i - 1] != ' ') r += ' '; // !i 防止i小于0越界
        }

    cout << r << endl;

    return 0;
}

#include<iostream>


using namespace std;


int main()
{
    string s1;
    getline(cin,s1);
    string s2;
    int j = 0;
    for(auto i = 0; i <s1.size();i++)
    {
        if(s1[i] == ' ')
        {
            j++;
        }
        else
        {
            j=0;
        }
        if(j<=1)
            s2+=s1[i];

    }
    cout << s2;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    string a ;
    getline(cin,a);
    for(int i = 0 ; i < a.size() ; i ++ )
    {
        if(a[i] == ' ') //检测到空格
            {
                cout << ' ';//输出一个
                while(a[i+1] == ' ')  //检测下一个是不是空格，是的话就跳过（i++） 
                {
                    i++;
                }
            }
        else cout << a[i];
    }
}


利用标识符flag来标记上一个输出字符是否为空格，如果是,那么本次字符如果还是空格的话不输出。
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int flag=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' ')
            { cout<<s[i];
             flag=0;}
        else if(flag==0)
            {
                cout<<" ";
                flag=1;
            }
        else
            continue;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
string s,s2;
getline(cin,s);
int cnt=0;
for(int i=0;s[i];i++)
{
if(s[i]==’ ‘&&s[i+1]==’ ‘)//过滤掉
continue;
else
s2=s2+s[i];
}
cout<<s2;
return 0;
}

10.
#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
   string a;
   getline(cin, a);
   
   for(auto &c:a) 
   {
   if ( c >= 'a' && c <= 'z')
      // c += 1; 循环公式推导
       c = (c -'a' + 1) % 26 + 'a';
       
    if (c >= 'A' && c <= 'Z')
      c= (c -'A' + 1) % 26 + 'A';
   } 
   
   cout << a <<endl;
   
   return 0;
}


自动算空格法：
用scanf不会过滤空格哦！

#include<bits/stdc++.h>
using namespace std;
int main(){
    char ch;
    while(scanf("%c",&ch)==1) //scanf输入成功后会返回1输出失败返回0，输入内容到缓冲区
    {
        if(ch>='a'&&ch<='z')
            ch=(ch+1-'a')%26+'a';
        else if(ch>='A'&&ch<='Z')
            ch=(ch+1-'A')%26+'A';
    cout<<ch;
    }
    return 0;
}

方法三：

不动脑子法
#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if(a[i]>='a'&&a[i]<'z'||a[i]>='A'&&a[i]<'Z')
        a[i]++;
        else if(a[i]=='z'||a[i]=='Z')a[i]-=25;
    }
    cout<<a<<endl;

    return 0;

11.
