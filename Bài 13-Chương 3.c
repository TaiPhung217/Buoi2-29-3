#include <stdio.h>
#include <stdlib.h>

struct dllNode{
	int info;
	struct dllNode *next;
	struct dllNode *prev;
};
struct dllNode *dlist,*tail;

//nhap du lieu
int nhapDuLieu()
{
    int n;
    scanf("%d",&n);
    return n;
}

struct dllNode* taoNode()
{
    //cap phat dong
    struct dllNode* pnode = (struct dllNode*)malloc(sizeof(struct dllNode));
    //Them du lieu
	pnode->info = nhapDuLieu();

	//Tro tiep
	pnode->next = NULL;
	//tro lui
	pnode->prev = NULL;
	return pnode;
}

void taoNodeDau()
{
	struct dllNode* pnode = taoNode();
	if(dlist == NULL){
        dlist = pnode;
        tail = pnode;
        return;
	}
	dlist->prev = pnode;
	pnode->next = dlist;
	dlist = pnode;
}

void taoNodeCuoi()
{
    struct dllNode* pnode = taoNode();
    if(dlist == NULL){
        dlist = pnode;
        tail = pnode;
        return;
    }
    tail->next = pnode;
    pnode->prev = tail;
    tail = pnode;
}

void Remove(int key)
{
    struct dllNode* tmp;
    for(tmp=dlist;tmp!=NULL;tmp=tmp->next){
        if(tmp->info == key){
            if(tmp == dlist){   //trường hợp số đang xét nằm ở đầu
                dlist = dlist->next;  //đầu mới sẽ bằng đầu cũ trỏ tới next
                dlist->prev = NULL;    // prev trỏ về NULL
            }
            else if(tmp==tail){  //trường hợp số đang xét nằm ở cuối
                tail = tail->prev;  //cuối mới bằng cuối cũ trỏ về prev
                tail->next = NULL;   //next trỏ về NULL
            }
            else{  //trường hợp số đang xét nằm ở giữa
                struct dllNode* temp = tmp->next;  //tạo biến nằm trước biến đang xét
                struct dllNode* temp2 = tmp->prev;  //tạo biến nằm sau biến đang xét
                temp2->next = tmp->next;   //tạo liên kết cho 2 biến mới
                temp->prev = tmp->prev;
            }
        }
    }
}



void inDanhSach()
{
	struct dllNode* tmp;
	for(tmp=dlist;tmp!=NULL;tmp=tmp->next){
        printf("%d ",tmp->info);
	}
}

void taoDanhSach()
{
    int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){   //tao danh sach lien ket
        taoNodeCuoi();
	}
}


int main()
{
    int key;
    taoDanhSach();
    inDanhSach();
    printf("nhap key: ");
    scanf("%d",&key);
    Remove(key);
    inDanhSach();
    return 0;
}
