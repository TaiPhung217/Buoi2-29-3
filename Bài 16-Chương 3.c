#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

//khởi tạo node
typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
}QNode;

//khởi tạo Queue chứa node
typedef struct queue
{
    QNode *front;  //con trỏ chỉ vị trí đầu
    QNode *rear;    // con trỏ chỉ vị trí cuối
}Queue;

Queue* s;
int *n,*m;

//tao Satck
void TaoQueue()
{
    s=(Queue*)malloc(sizeof(Queue));  // cấp phát động
    s->rear = NULL; //lúc này chiều cao của stack là NULL|0
    s->front = NULL;
}

//kiểm tra stack có trống hay không
int isEmpty()
{
    return (s->rear == NULL);  //=0 nếu trống,và ngược lại
}

void enq(int tmp)
{
    QNode *node;
    node = (QNode*)malloc(sizeof(QNode));//cấp phát động cho node tạm
    node->data = tmp; //gán biến muốn thêm vào node tạm
    node->next = s->rear;   //liên kết node tạm vào stack
    s->rear = node;    // đẩy node tạm lên làm top của stack
}

void deq()
{
    QNode *node;
    if(isEmpty())   //kiểm tra stack rỗng hay không
        printf("queue empty");
    node = s->rear;
    while(node->next->next!=NULL)
    {
        node=node->next;
    }
    node->next=node->next->next;

}

int Size()
{
    QNode* tmp;
    int count=0;
    for(tmp=s->rear;tmp->next!=NULL;tmp=tmp->next)
        count++;
    return count;
}

void inQueue()
{
    QNode* node;
    if(isEmpty())   //kiem tra stack có rỗng không
        printf("stack empty");
    else{
        /*node = s->rear;   //bắt đầu đọc từ top-down
        do{
            m=node->data; //lặp m trích data từ node ra ngoài
            if(i==0){
                printf("[%d] ",m);
                continue;
                }   //và in ra
                else{
                    printf("")
                }
            node = node->next;// tiếp tục dịch node
        }
        while(!(node==NULL));   //nếu node = NULL thì dừng lại vì hết phần tử
        //printf("Back = Queue[0], Front=Queue[%d]",Size());*/
        int i=0;
        for(node=s->rear;node!=NULL;node=node->next,i++){
            if(i==0||i==Size()){
                printf("[%d] ",node->data);

            }
            else
               printf("%d ",node->data);
        }
    }
    printf("\n");
}

int main()
{
    TaoQueue();
    enq(5);
    inQueue();
    enq(3);
    inQueue();
    deq();
    inQueue();
    enq(2);
    inQueue();
    enq(8);
    inQueue();
    deq();
    inQueue();
    deq();
    inQueue();
    enq(9);
    inQueue();
    enq(1);
    inQueue();
    deq();
    inQueue();
    enq(7);
    inQueue();
    enq(6);
    inQueue();
    deq();
    inQueue();
    deq();
    inQueue();
    enq(4);
    inQueue();
    deq();
    inQueue();
    deq();
    inQueue();

    printf("Back=>Front");
    return 0;
}
