/***************************************************************************************
 *    File Name                :    AQueue.h
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
#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>
#include"constant.h"
/**************************************************************
 *    Macro Define Section
 **************************************************************/
#define MAXQUEUE 10

/**************************************************************
 *    Struct Define Section
 **************************************************************/
//循环队列结构
//typedef struct Aqueue
//{
//    void* data[MAXQUEUE];      //数据域
//    int front;
//    int rear;
//    size_t length;        //队列长度
//} AQueue;

typedef struct Aqueue
{
    void* data[MAXQUEUE];
    int data_size;
    int front;
    int rear;
    size_t length;
}AQueue;
//char type;
//char datatype[MAXQUEUE];
/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue* Q,int b_size)
{
    Q->data_size = b_size;
    Q->length = MAXQUEUE;
    int i = 0;
    for (; i < MAXQUEUE; i++)
        Q->data[i] = (void*)malloc(b_size);
    //Q->front = Q->rear = 0;
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue* Q)
{
    for (int i = MAXQUEUE - 1; i >= 0; i--) 
        free(Q->data[i]);
    free(Q);
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue* Q)
{
    return Q->length == MAXQUEUE ? TRUE : FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue* Q)
{
    return Q->length == 0 ? TRUE : FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue* Q, void* e)
{
    //printf(":::%c\n",Q->data[1] );
    if (Q->length == 0) return FALSE;
    memcpy(e, Q->data[Q->front],Q->data_size);
    return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue* Q)
{
    return Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
    if (Q->length == MAXQUEUE) return FALSE;
    if(Q->length!=0)
        Q->rear++;
    memcpy(Q->data[Q->rear], data, Q->data_size);
    if (Q->rear == 10)
        Q->rear = 0;
    Q->length++;
    return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue* Q)
{
    if (Q->length == 0) return FALSE;
    free(Q->data[Q->front]);
    Q->data[Q->front] = (void*)malloc(Q->data_size);
    Q->front++;
    if (Q->front == 10)
        Q->front = 0;
    Q->length--;
    return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue* Q)
{
    for (int i = 0; i < Q->length; i++)
    {
        DeAQueue(Q);
    }
    Q->length = 0;
}
/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q))
{
    for (int i = 0; i < Q->length; i++)
    {
        int num;
        if (Q->front + i >= 10)
            num = Q->front + i - 10;
        else num = Q->front + i;
        foo(Q->data[num]);
    }
    return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void* q)
{
    printf("%c\n", *(char*)q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED


