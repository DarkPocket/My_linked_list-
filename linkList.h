#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
// 头节点 不存放有效数据



/*
//LLNode是struct linkListNode类型，pNode是struct linkListNode*类型
typedef struct linkListNode
{
        int num;
        int data;
        int val;
        char ch[100];
        struct linkListNode *next;
} LLNode, *pNode, *linkList;
*/
struct NODE
{
        int num;
        int data;
        int val;
        char ch[100];

        struct NODE *pNext;

} node, *pnode;




struct NODE *Create_plist();
struct NODE *Create_Null_plist() ;
void traverse_list(struct NODE * );
int is_empty(struct NODE * );
int length_list(struct NODE * );
int insert_list(struct NODE *pHead, int newstr, struct NODE *pNew );// 在第i个链表前面插入 新节点

int delete_list(struct NODE *pHead, int j, int *x) ; //删除j节点后面的节点

struct NODE * CopyListNode (  struct  NODE * qHead,struct  NODE * Copy_pHead );

void Bublle_sort_list(struct NODE *  );

struct NODE * InsertSortList( struct NODE  *L );

int add_list(struct NODE *pHead, struct NODE *qList) ;

void ListDestroy(struct NODE*head);
//链表快排算法
struct NODE* partitionList( struct NODE* lowPre,  struct NODE* low,  struct NODE* high);
void qsortList( struct NODE *headPre,  struct NODE*head,  struct NODE*tail);
struct NODE *quickSortList( struct NODE *head);
void showPiont(struct NODE *p );


#endif // LINKLIST_H_INCLUDED
