
//#include<stdlib.h>
//#include<malloc.h>

#include"linkList.h"


/*
链表有头节点
   影响 遍历和计算长度

cpp还是c 影响快排代码
        cpp      return &tmpHead;
        c        return tmpHead.pNext;
*/
//插入排序代码有问题

int fun2 (  )
{
        // ListNode *pHead = (ListNode *)malloc(sizeof(ListNode));

        struct NODE *pHead ;//= (  struct NODE *)malloc(sizeof(  struct NODE));
        int len = 0;
        int i = 0;

        pHead = Create_Null_plist();



        struct NODE *pTail = pHead;
        len = 14;
        for (i = 0; i < len; i++)
        {

                struct NODE *pNew = (  struct NODE *)malloc(sizeof(  struct NODE));

                if (pNew == NULL)
                {
                        printf("创建链表节点失败，终止 \n");
                        exit(-1);
                }
                pNew->num = i + 1;
                pNew->data = len - i;
                pNew->val = 2 * i * i * i - 15 * i * (i + 5) + 7 * i + 38;

                pTail->pNext = pNew;
                pNew->pNext = NULL;
                pTail = pNew; //尾节点

        }

        printf("  traverse_list  pHead \n");
        traverse_list(pHead );
        length_list(pHead);
        //length_list(pHead);


        struct NODE  *q = NULL;
        q = InsertSortList( pHead->pNext);

        printf(" InsertSortList  pHead \n");

        traverse_list(pHead );
        printf(" InsertSortList  q \n");

        traverse_list(q );

        length_list(pHead);

        /*
        struct NODE  *q = NULL;
        q = CopyListNode(pHead, q);

        printf("  traverse_list  q \n");
        traverse_list(q);
        length_list(q);
        */

        /*
                struct NODE  *pNews = (struct NODE *)malloc(sizeof(struct NODE));
                if (NULL == pNews)
                {
                        printf("创建链表节点失败，终止 \n");
                        return -2;
                        //   exit(-1);
                }
                pNews->num = 2;
                pNews->data =  202;
                pNews->val = 404 ;

                insert_list(pHead, 2, pNews);

                traverse_list(pHead->pNext);
                length_list(pHead);
        */



        /*
                struct NODE *p = NULL  ;



                p  =  quickSortList(pHead->pNext);



                printf(" quickSortList   pheand \n");

                traverse_list(p );



                struct NODE*q = (  struct NODE *)malloc(sizeof(  struct NODE));

                q->pNext = p;


                traverse_list(q );

                printf(" Destroy  p \n");

                ListDestroy(p);

                traverse_list(q );



                traverse_list(p );




        */

        return 0;

}


int main (void)
{

        fun2();

        return  0;
}


