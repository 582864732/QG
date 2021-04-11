/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include"constant.h"
/**************************************************************
 *    Struct Define Section
 **************************************************************/
//链式队列结构
typedef struct node
{
    void* data;
    struct node* next;
}Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
} LQueue;
/*char type;					
char datatype[30];	*/		

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q)
{
    //Q = (LQueue*)malloc(sizeof(LQueue));
    Q->front = (void*)malloc(sizeof(Node));
    //Q->front->data = (void*)malloc(10);
    Q->rear = (void*)malloc(sizeof(Node));
    Q->front->next = Q->rear;
    Q->rear->data = (void*)malloc(20);
    Q->rear->next = NULL;
    Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q)
{
    while (TRUE)
    {
        if (Q->front->next == NULL) break;
        Node* t=Q->front;
        Q->front = Q->front->next;
        free(t);
    }
    free(Q->rear);
    free(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q)
{
    return Q->length == 0 ? TRUE : FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e)
{
    if (Q->length == 0) return FALSE;
    //printf("%d\n", *(int*)Q->front->next->data);
    //printf("%d\n", *(int*)Q->rear->data);
    memcpy(e, Q->front->next->data, sizeof(Q->front->next->data));
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q)
{
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data)
{
    //memcpy(Q->rear->data, data, 20);
    if (Q->length == 0)
    {
        Q->rear->data = (void*)malloc(sizeof(data));
        memcpy(Q->rear->data, data, sizeof(data));
        Q->length++;
        return TRUE;
    }
    Node* n = (Node*)malloc(sizeof(Node));
    n->next = NULL;
    n->data = (void*)malloc(sizeof(data));
    memcpy(n->data, data, sizeof(data));
    Q->rear->next = n;
    Q->rear = Q->rear->next;
    Q->length++;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q)
{
    if (Q->length == 0) return FALSE;
    Node* t = Q->front->next;
    Q->front->next = t->next;
    free(t);
    Q->length--;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q)
{
    Node* t = Q->front->next;
    Node* rear = (Node*)malloc(sizeof(Node));
    Q->rear = rear;
    Q->front->next = Q->rear;
    Q->rear->next = NULL;
    while (TRUE)
    {
        if (t->next == NULL) break;
        Node* n = t;
        t = t->next;
        free(n);
    }
    Q->length = 0;
    return TRUE;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))
{
    Node* t = Q->front->next;
    while (TRUE)
    {
        if (t->next == NULL) break;
        foo(t->data);
    }
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void* q)
{
    printf("%d", *(int*)q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


