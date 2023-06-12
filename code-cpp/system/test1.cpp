/*
 * @Author: your name
 * @Date: 2021-11-12 18:20:16
 * @LastEditTime: 2021-11-12 21:03:04
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \操作系统\lab5.cpp
 */
#include <iostream>
using namespace std;
typedef struct PROC
{                //进程的 PCB 结构
    char pid;     //进程标志
    int pri;     //优先级
    int cputime; //已用 CPU 时间
    int alltime; //运行完成所需的所有时间
    int state;   //状态
} PROC;
typedef struct Node
{ //有序链表结点定义
    struct PROC data;
    struct Node *next;
} Node, *LinkList;
Node *InitSortedList() //初始化有序链表，返回一个链表的头结点
{
    LinkList head = (struct Node *)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}
void insertSortedList(LinkList L, PROC proc) //按优先级把进程插入有序链表
{
    LinkList temp1 = L->next;
    LinkList temp2 = (struct Node *)malloc(sizeof(Node));
    int pri = proc.pri;
    LinkList temp3 = (struct Node *)malloc(sizeof(Node));
    temp3->data = proc;
    if (temp1 == NULL)
    {
        L->next = temp3;
        temp3->next = NULL;
    }
    else if (temp1->data.pri >= pri)
    {
        while (temp1 != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp3->next = temp1;
        temp2->next = temp3;
    }
    else
    {
        if (temp1 != NULL && temp1->data.pri > pri)
        {
            while (temp1 != NULL && temp1->data.pri > pri)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp3->next = temp1;
            temp2->next = temp3;
        }
        else
        {
            temp3->next = temp1;
            L->next = temp3;
        }
    }
}
PROC *getHeadElement(LinkList L) //摘取链表的头结点，即优先权最高的进程
{
    return &(L->next->data);
}
void reInsertSortedList(LinkList L)
{
    LinkList temp = L;
    LinkList del_node = L->next;
    del_node->data.pri -= 2;
    del_node->data.cputime += 4;
    if (del_node->data.cputime < del_node->data.alltime)
    {
        insertSortedList(L, del_node->data);
    }
    else
    {
        L->next = del_node->next;
    }
}
int main()
{
    PROC proc_lst[5];
    PROC proc_c;
    LinkList llst = InitSortedList();
    for (int i = 0; i < 5; i++)
    {
        cin >> proc_lst[i].pid >> proc_lst[i].pri >> proc_lst[i].cputime >> proc_lst[i].alltime >> proc_lst[i].state;
        insertSortedList(llst, proc_lst[i]);
    }
    cout << "Ready:";
    if (getHeadElement(llst) == NULL)
    {
        cout << "No Process!" << endl;
        return 0;
    }
    for (LinkList temp = llst->next; temp != NULL; temp = temp->next)
    {
        cout << temp->data.pid << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        reInsertSortedList(llst);
    }
    cout << "Compelete:";
    if (getHeadElement(llst) == NULL)
    {
        cout << "All Compeleted!" << endl;
        return 0;
    }
    for (LinkList temp = llst->next; temp != NULL; temp = temp->next)
    {
        cout << temp->data.pid << " ";
    }
    cout << endl;
}