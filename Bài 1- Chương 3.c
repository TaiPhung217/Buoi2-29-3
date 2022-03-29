#include <stdio.h>
#include <stdlib.h>


struct Node
{
	int Inf;
	struct Node* Next;
};
typedef struct Node LIST;
LIST* Linp = NULL;

int nhapDuLieu()
{
    int n;
	scanf("%d",&n);
	return n;
}

LIST* taoNode ()
{
	//Cap phat dong
	LIST* pnode = (LIST*)malloc (sizeof(LIST));

	//Them du lieu
	pnode->Inf = nhapDuLieu();

	//Tro tiep
	pnode->Next = NULL;

	return pnode;
}

void taoNodeDauTien ()
{
	LIST* pnode = taoNode();
	Linp = pnode;
}

void taoNodeViTri_Cuoi()
{
	if (Linp == NULL)
		taoNodeDauTien();
	else
	{
		//Tao node moi
		LIST* pnode = taoNode();

		//Tim vi tri cuoi cung
		LIST* tmp;
		for (tmp = Linp; tmp->Next!= NULL; tmp = tmp->Next);

		//Them pnode vao sau cung
		tmp->Next= pnode;
	}

}

void OddList()
{
    LIST* tmp;
    for(tmp=Linp;tmp!=NULL;tmp=tmp->Next){
        if(tmp->Inf %2 == 0){
            if(tmp == Linp){
                Linp = tmp->Next;
            }
            else{
                LIST* del;
                for(del = Linp; del->Next!=tmp;del=del->Next);
                del->Next = tmp->Next;
            }

        }
    }

}

void inDanhSach()
{
	LIST* tmp;
	for(tmp=Linp;tmp!=NULL;tmp=tmp->Next){
        printf("%d ",tmp->Inf);
	}
}

void taoDanhSachSinhVien ()
{
    int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        taoNodeViTri_Cuoi();
	}
}



int main()
{
    taoDanhSachSinhVien();
    OddList();
    inDanhSach();

    return 0;
}
