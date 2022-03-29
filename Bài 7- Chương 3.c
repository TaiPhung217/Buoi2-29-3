#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int info;
    struct ListNode* next;
};

//khai bao danh sach rong
struct ListNode* list;

//nhap du lieu
int nhapDuLieu()
{
    int n;
    scanf("%d",&n);
    return n;
}

struct ListNode* taoNode()
{
    //cap phat dong
    struct ListNode* pnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    //Them du lieu
	pnode->info = nhapDuLieu();

	//Tro tiep
	pnode->next = NULL;

	return pnode;
}

void taoNodeDau()
{
	struct ListNode* pnode = taoNode();
	list = pnode;
}

void taoNodeCuoi()
{
	if (list == NULL)
		taoNodeDau();
	else
	{
		//Tao node moi
		struct ListNode* pnode = taoNode();

		//Tim vi tri cuoi cung
		struct ListNode* tmp;
		for (tmp = list; tmp->next!= NULL; tmp = tmp->next);

		//Them pnode vao sau cung
		tmp->next= pnode;
	}

}

void removeDupes()
{
    struct ListNode* tmp;
    struct ListNode* tmp2;
    for(tmp=list;tmp->next!=NULL;tmp=tmp->next){
        for(tmp2=tmp->next;tmp2->next!=NULL;tmp2=tmp2->next){
            if(tmp2->info == tmp->info){
                tmp->next = tmp2->next;
            }
        }
    }
}

void inDanhSach()
{
	struct ListNode* tmp;
	for(tmp=list;tmp!=NULL;tmp=tmp->next){
        printf("%d ",tmp->info);
	}
}

void taoDanhSach()
{
    int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        taoNodeCuoi();
	}
}


int main()
{
    taoDanhSach();
    removeDupes();
    inDanhSach();

    return 0;
}
