//linkList.c


#include "linkList.h"




// 创建 链表
struct NODE *Create_plist()
{
        int len = 0;
        int i = 0;
        int val = 0; //临时存放数据
        // 头节点
        struct NODE *pHead = (struct NODE *)malloc(sizeof(struct NODE));

        if (pHead == NULL)
        {
                printf("创建链表失败，终止 \n");


                exit(-1);
                return ;
        }
        // 尾节点
        struct NODE *pTail = pHead;
        pTail->pNext = NULL;



        printf("输入需要生成的链表节点个数 \n");
        scanf("%d", &len);

        for (i = 0; i < len; i++)
        {
                printf("输入第%d个节点值 \n", i);
                scanf("%d", &val);

                struct NODE *pNew = (struct NODE *)malloc(sizeof(struct NODE));
                if (pNew == NULL)
                {
                        printf("创建链表节点失败，终止 \n");
                        exit(-1);
                }

                pNew->data = val;
                pTail->pNext = pNew;
                pNew->pNext = NULL;
                pTail = pNew; //尾节点



        }
        return pHead;

}


struct NODE *Create_Null_plist()
{

        //临时存放数据
        // 头节点
        struct NODE *pHead = (struct NODE *)malloc(sizeof(struct NODE));
        if (pHead == NULL)
        {
                printf("创建链表失败，终止 \n");
                exit(-1);
        }
        //      pHead->ch
        pHead->num = 0;
        pHead->data =  0;
        pHead->val = 0 ;
        // 尾节点
        //    struct NODE *pTail = pHead;
        //   pTail->pNext = NULL;
        pHead->pNext = NULL;
        return pHead;

}

void traverse_list(struct NODE *pHead)
{
        struct NODE *p = pHead ;//->pNext;
        if ( p == NULL )
        {
                printf("链表 NULL \n");
                return ;
        }

        while ( NULL != p)
        {
                //  printf("地址   %p ", p);

                printf(" %d.    %4d   data  %2d \n" , p->num, p->val , p->data);

                p = p->pNext;
        }
        printf("  \n");
        return ;

}

void showPiont(struct NODE *p )
{

        printf(" %d .    %4d    data  %2d \n" , p->num, p->val , p->data);


        printf("\n");

}


// 链表是否为空
int is_empty(struct NODE *pHead)
{
        if ( pHead->pNext == NULL )
        {
                return 1;
        }
        else
        {
                return 0;
        }

}

int length_list(struct NODE *pHead)
{
        int len = 0;
        struct NODE *p = pHead;

        while ( NULL != p)
        {
                len++;
                p = p->pNext;
        }
        printf(" 链表len=%d \n", len);
        return len;

}

// 在第i个链表前面插入 新节点
int insert_list(struct NODE *pHead, int newstr, struct NODE *pNew )
{
        int i = 0;
        struct NODE *p = pHead;
        struct NODE *q;
        while (NULL != p && i < newstr - 1)
        {
                p = p->pNext;
                i++;

        }
        if (i > newstr - 1 || NULL == p)
        {
                return -1;
        }


        //   struct NODE  *pNew = (struct NODE *)malloc(sizeof(struct NODE));
        //     if (NULL == pNew)
        {
                //         printf("创建链表节点失败，终止 \n");
                //           return -2;

        }
        //   pNew->data = x;

        q = p->pNext;
        p->pNext = pNew;
        pNew->pNext = q;

        return 1;

}


//删除j节点后面的节点
int delete_list(struct NODE *pHead, int j, int *x)
{
        int i = 0;
        struct NODE *p = pHead, *s;
        struct NODE *q;
        while (NULL != p->pNext && i < j - 1)
        {
                p = p->pNext;
                i++;

        }
        if (i > j - 1 || NULL == p->pNext)
        {
                return -1;
        }

        //  pNew->data = x;
        q = p->pNext;
        *x = q->data;
        //删除p节点后面的节点

        s = p->pNext;
        p->pNext = s->pNext;
        free(q);
        q = NULL;

        return 1;

}
/*

*功能：删除链表的i个结点
*参数1：链表的头结点
*参数2：指定第i个结点

int deleteLinkListNode(linkList head,int i)
{
  int j=0;
  pNode prePnode=head;
  pNode pnode=head->next;

  while(pnode!=NULL&&j<i-1)
  {
          prePnode=pnode;
          pnode=pnode->next;
      j++;
  }
  if(pnode==NULL)
  {
          printf("!!!!!!!!删除结点时位置已经超出了链表!!!!!!!!\n");
          return -1;
  }
  prePnode->next=pnode->next;
  pnode->next=NULL;
  free(pnode);
  return 0;
}
//删除链表函数调用删除结点函数和遍历链表函数
int deleteLinklist(linkList head)
{
        int i=0;
    int lenth=linkListTraverse(head);
    for(i=lenth;i>0;i--)
        {
        deleteLinkListNode(head,i);
        }
        return 0;
}

*/
/*
int CopyListNode (  struct  NODE * qHead, struct  NODE * Copy_pHead )
{
        //by black


        *qHead = *Copy_pHead;



        Copy_pHead = Copy_pHead->pNext;

        struct NODE   *pTail = qHead;

        printf("复制链表中\n" );

        while ( NULL != Copy_pHead)
        {

                struct  NODE *pNew = (struct  NODE *)malloc(sizeof(struct  NODE));

                *pNew = *Copy_pHead;



                //    printf("复制 val  %4d  data %2d \n", pNew->val , pNew->data);
                //    getchar();
                pTail->pNext = pNew;
                pTail = pNew;
                Copy_pHead = Copy_pHead->pNext;


        }
        pTail->pNext = NULL;



        return 0;
}
*/

struct NODE * CopyListNode (  struct  NODE * qSource, struct  NODE * pCopy )
{
        //把qSource复制一份到pCopy中
        pCopy = (struct NODE *)malloc(sizeof(struct NODE));

        //    printf("copy 链表  \n");

        if ( pCopy == NULL)
        {
                printf("创建链表失败，终止 \n");
                exit(-1);
        }

        *pCopy = *qSource;
        struct NODE   *pTail = pCopy;

        qSource = qSource->pNext;
        while (qSource != NULL)
        {

                struct  NODE *pNew = (struct  NODE *)malloc(sizeof(struct  NODE)) ;
                if ( pNew  == NULL)
                {
                        printf("创建链表失败，终止 \n");
                        exit(-1);
                }

                *pNew = *qSource;
                //printf("qSource  %d  \n",qSource->num);
                //  printf(" pTail  %d  data  %d  \n", pTail->num, pTail->data);
                //   printf(" pNew %d  data  %d  \n", pNew->num, pNew->data);

                pNew->pNext = NULL;

                pTail->pNext = pNew;
                pTail = pNew;

                qSource = qSource->pNext;


        }

        pTail->pNext = NULL;



        return pCopy;

}


struct NODE * InsertSortList( struct NODE  *L )
{
        struct NODE  *p1, *p2, *temp, *prep1, *prep2;

        if (L->pNext->pNext == NULL)
        {
                return L;
        }




        for ( p1 = L->pNext->pNext, prep1 = L->pNext; p1 != NULL; p1 = p1->pNext, prep1 = prep1->pNext )
        {
                temp = p1;    /*保存待插入节点*/

                for ( p2 = L->pNext, prep2 = L; p2 != p1; p2 = p2->pNext, prep2 = prep2->pNext )
                {

                        if ( p2->data > p1->data )

                        {
                                p1 = p1->pNext;
                                prep1->pNext = temp->pNext;    /*删除待插入节点*/
                                prep2->pNext = temp;              /*将其插入对应位置*/
                                temp->pNext = p2;
                                break;
                        }

                }
        }

        return L;
}

void Bublle_sort_list(struct NODE *pHead )
{
        int i, j, t;
        struct NODE *p, *q;
        int len;
        len = length_list(pHead) - 1;
        i = j = t = 0;


        for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
        {
                for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
                {
                        if (p->data > q->data)
                        {
                                t = p->data;
                                p->data = q->data;
                                q->data = t;

                                t = p->num;
                                p->num = q->num;
                                q->num = t;

                                t = p->val;
                                p->val = q->val;
                                q->val = t;



                        }


                }
        }

        return ;

}

int add_list(struct NODE *pHead, struct NODE *qList)  //添加节点
{

        int i = 0;
        struct NODE *p = pHead;

        while ( NULL != p->pNext)
        {

                p = p->pNext;
        }

        struct NODE *pNew = (struct NODE *)malloc(sizeof(struct NODE));
        if (pNew == NULL)
        {
                printf("创建链表节点失败，终止 \n");
                exit(-1);
        }


        *pNew = *qList;

        p->pNext = pNew;

        pNew->pNext = NULL;



        return 0;
}





//销毁链表

void ListDestroy(struct NODE*head)
{
        struct NODE *p, *q;
        //
        p = head;
        if (  NULL == head->pNext)
        {
                //     free(head);
                //    head = NULL;

                printf("  链表 NULL \n" );
                return  ;
        }

        while (p->pNext != NULL)
        {
                q = p->pNext;
                p->pNext = q->pNext;
                free(q);
        }
        free(p);
        free(head);
        p = NULL;

        head = NULL;


        //head = NULL;
        return ;
}

struct NODE* partitionList( struct NODE* lowPre,  struct NODE* low,  struct NODE* high)
{
        //链表范围是[low, high)
        int key = low->val; //排序标准
        struct NODE node1, node2;//比key小的链的头结点，比key大的链的头结点
        struct NODE* little = &node1, *big = &node2;
        struct NODE*i;
        for (  i = low->pNext; i != high; i = i->pNext)
                if (i->val < key)
                {
                        little->pNext = i;
                        little = i;
                }
                else
                {
                        big->pNext = i;
                        big = i;
                }
        big->pNext = high;//保证子链表[low,high)和后面的部分连接
        little->pNext = low;
        low->pNext = node2.pNext;
        lowPre->pNext = node1.pNext;//为了保证子链表[low,high)和前面的部分连接
        return low;
}

void qsortList( struct NODE *headPre,  struct NODE*head,  struct NODE*tail)
{
        //链表范围是[low, high)
        if (head != tail && head->pNext != tail)
        {
                struct NODE* mid = partitionList(headPre, head, tail);//注意这里head可能不再指向链表头了
                qsortList(headPre, headPre->pNext, mid);
                qsortList(mid, mid->pNext, tail);
        }
}

struct NODE *quickSortList( struct NODE *head)
{
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表快速排序
        if (head == NULL || head->pNext == NULL)
        {
                return head;
        }
        struct NODE tmpHead;
        tmpHead.pNext = head;
        qsortList(&tmpHead, head, NULL);
        //    return &tmpHead;
        return tmpHead.pNext;
}




