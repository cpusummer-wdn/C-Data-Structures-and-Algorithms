链表结构
#include <iostream>
#include <string.h>

using namespace std;

const int N = 10000;

struct Node 
{
  int val;
  Node *next;
  
} *head;

int main()
{
  for (int i = 1; i <= 5; i ++)
  {
    Node *p = new Node;
    p->val = i;
    p->next = head;
    head = p;
  }

  for (Node* p = head; p; p = p->next)
  {
    cout << p->val << ' ';
    cout << endl;
  }
}



AcWing 21. 斐波那契数列
class Solution {
  public:
     int Fibonacci(int n) {
       if (n <= 1) return n;
       return Fibonacci(n - 1) + Fibonacci(n - 2);
     }
}

class Solution {
public:
    int Fibonacci(int n) {
        int a = 0, b = 1;
        while (n -- ) {
            int c = a + b;
            a = b, b = c;
        }
        return a;
    }
};


AcWing 16. 替换空格
class Solution {
  public:
    string replaceSpace(string &str) {
      string res;
      for (auto c : str)
         if (c == ' ') res += "%20";
         else res += c;
      
      return res;
    }    
}

AcWing 84. 求1+2+…+n
class Solution
{
  public:
     int getSum(int n) 
     {
       int res = n;
       n > 0 && (res += getSum(n - 1));
       return res;
     }
}

AcWing 28. 在O(1)时间删除链表结点
/**
* Definition for singly-linked list.
* struct ListNode
*{   int val;
*    ListNode *next;
*    ListNode(int x) : val(x), next(Null){}
*};
*/
class Solution
{
  public:
     void deleteNode(ListNode* node)
     {
       *(node) = *(node->next);
     }
};

AcWing 36. 合并两个排序的链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
     ListNode* merge(ListNode* l1, ListNode* l2)
     {
       auto dummy = new ListNode(-1), tail = dummy;
       while (l1 && l2)
          if (l1->val < l2->val)
          {
            tail = tail->next = l1;
            l1 = l1->next;
          }
          else
          {
            tail = tail->next = l2;
            l2 = l2->next;
          }

        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy->next;
     }
};

AcWing 78. 左旋转字符串
class Solution{
  public:
  string leftRotateString(string str, int n){
    return str.substr(n) + str.substr(0, n);
  }
}

AcWing 87. 把字符串转换成整数
clas Solution{
public:
   int strToInt(string str){
     int K = 0;
     while (k < str.size() && str[k] == ' ') k ++ ;
     long long res = 0;

     int minus = 1;
     if (k < str.size())
     {
       if (str[k] == '-') minus = -1, k ++ ;
       else if (str[k] == '+') k ++ ;
     }

     while (k < str.size() && str[k] >= '0' && str[k] <= '9')
     {
       res = res * 10 + str[k] - '0';
       if (res > 1e11) break;
       k ++ ;
     }
     res *= minus;
     if (res > INT_MAX) res = INT_MAX;
     if (res < INT_MIN) res = INT_MIN;

     return res;
   }
};

AcWing 35. 反转链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
public:
  ListNode* reverseList(ListNode* head){
    if (!head || !head->next) return head;

    auto p = head, q = p->next;
    while (q)
    {
      auto o = q->next;
      q->next = p;
      p = q, q = o;
    }
    head->next = NULL;

    return p;
  }
}

AcWing 66. 两个链表的第一个公共结点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
public:
   ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB){
     auto p = headA, q = headB;

     while (p != q)
     {
       if (p) p = p->next;
       else p = headB;
       if (q) q = q->next;
       else q = headA;
     }
     return p;
   }
};

AcWing 29. 删除链表中重复的节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
public:
   ListNode* deleteDuplication(ListNode* head){
     auto dummy = new ListNode(-1);
     dummy->next = head;
     auto p = dummy;

     while (p->next)
     {
       auto q = p->next;
       while (q->next && q->next->val == p->next->val) q = q->next;

       if (q == p->next) p = q;
       else p->next = q->next;
     }
     return dummy->next;
   }
};




