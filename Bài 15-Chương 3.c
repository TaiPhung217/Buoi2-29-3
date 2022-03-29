#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

//khởi tạo node
typedef struct StackNode
{
    int data;
    struct StackNode *next;
}SNode;

//khởi tạo stack chứa node
typedef struct stack
{
    SNode *top;
}Stack;

Stack* s;

//tao Satck
void TaoStack()
{
    s=(Stack*)malloc(sizeof(Stack));  // cấp phát động
    s->top = NULL; //lúc này chiều cao của stack là NULL|0
}

//kiểm tra stack có trống hay không
int isEmpty()
{
    return (s->top == NULL);  //=0 nếu trống,và ngược lại
}

void push(int tmp)
{
    SNode *node;
    node = (SNode*)malloc(sizeof(SNode));  //cấp phát động cho node tạm
    node->data = tmp; //gán biến muốn thêm vào node tạm
    node->next = s->top;   //liên kết node tạm vào stack
    s->top = node;    // đẩy node tạm lên làm top của stack
}

void pop()
{
    SNode *node;
    if(isEmpty(s))   //kiểm tra stack rỗng hay không
        printf("stack empty");
    node = s->top;  //gán node tạm là top của stack
    s->top = node->next;   //gán top của phần tử phía dưới node tạm
    free(node);
}

void inStack()
{
    SNode* node;
    int m;
    if(isEmpty())   //kiem tra stack có rỗng không
        printf("stack empty");
    else{
        node = s->top;   //bắt đầu đọc từ top-down
        do{
            m=node->data;  //lặp m trích data từ node ra ngoài
            printf("%d ",m);   //và in ra
            node = node->next;  // tiếp tục dịch node
        }
        while(!(node==NULL));   //nếu node = NULL thì dừng lại vì hết phần tử
    }
    printf("\n");
}

int main()
{
    TaoStack();
    push(5);
    inStack();
    push(3);
    inStack();
    pop();
    inStack();
    push(2);
    inStack();
    push(8);
    inStack();
    pop();
    inStack();
    pop();
    inStack();
    push(9);
    inStack();
    push(1);
    inStack();
    pop();
    inStack();
    push(7);
    inStack();
    push(6);
    inStack();
    pop();
    inStack();
    pop();
    inStack();
    push(4);
    inStack();
    pop();
    inStack();
    pop();
    inStack();

    return 0;
}
