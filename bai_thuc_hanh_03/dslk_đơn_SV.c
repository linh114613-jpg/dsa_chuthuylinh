#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;

typedef struct tagNode {
    Data infor;
    struct tagNode *link;
} Node;

typedef struct {
    Node *pHead;
    Node *pTail;
    int spt;
} LList;

/////////////////////////////////////
void initList(LList *L) {
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}

/////////////////////////////////////
int emptyList(LList L) {
    return (L.spt == 0);
}

/////////////////////////////////////
void insert_Head(LList *L, Data x) {
    Node *pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->link = NULL;
    if(emptyList(*L)){
        L->pHead = pp;
        L->pTail = pp;
    } else {
        pp->link = L->pHead;
        L->pHead = pp;
    }
    L->spt++;
}

/////////////////////////////////////

void insert_Tail(LList *L, Data x) {
    Node *pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->link = NULL;
    if(emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pTail->link = pp;
        L->pTail = pp;
    }
    L->spt++;
}

/////////////////////////////////////

Node* searchNode(LList L, int maSV) {
    Node *pp = L.pHead;
    while(pp != NULL) {
        if(pp->infor.masv == maSV)
            return pp;
        pp = pp->link;
    }
    return NULL;
}

/////////////////////////////////////

void insert_After(LList *L, Node *q, Data x) {
    if(q == NULL) return;
    Node *pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->link = q->link;
    q->link = pp;


    if(L->pTail == q) {
        L->pTail = pp;
    }
    L->spt++;
}

///////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv (nhap <=0 de huy): ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ho ten: ");
        scanf(" %[^\n]", x->hoten);
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}

void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n",
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}

void processList(LList L){
    Node *pp = L.pHead;
    if(pp == NULL) {
        printf("Danh sach dang trong!\n");
        return;
    }
    while( pp != NULL ){
        in(pp->infor);
        pp = pp->link;
    }
}

/////////////////////////////////////////
int main(){
    LList L;
    int kt = 0;
    Data x;
    initList(&L);

    do{
        printf("\n=== CHUONG TRINH DSLK DON SINH VIEN ===\n");
        printf("1: Them nut vao dau danh sach\n");
        printf("2: Them nut vao cuoi danh sach\n");
        printf("3: Them nut vao sau mot nut khac\n");
        printf("4: Chen tang (Them sinh vien vao vi tri sap xep theo msv)\n");
        printf("5: Xoa phan tu dau danh sach\n");
        printf("6: Xoa phan tu phia sau mot msv\n");
        printf("7: Xoa phan tu co msv(khoa k)\n");
        printf("8: Tach danh sach (Theo diem mon 1 < 5.0)\n");
        printf("9: Duyet ds\n");
        printf("0: Thoat\n");
        printf("Moi ban chon: ");
        int chon;
        scanf("%d", &chon);

        switch(chon){
            case 1:
                printf("--- Nhap thong tin sv can them vao DAU ---\n");
                nhap(&x);
                if(x.masv > 0)
                    insert_Head(&L, x);
                break;

            case 2:
                printf("--- Nhap thong tin sv can them vao CUOI ---\n");
                nhap(&x);
                if(x.masv > 0)
                    insert_Tail(&L, x);
                break;

            case 3:
                if (emptyList(L)) {
                    printf("Danh sach dang trong, khong the them vao sau!\n");
                    break;
                }
                int maSV;
                printf("Nhap Ma SV cua sinh vien ban muon them vao SAU: ");
                scanf("%d", &maSV);
                Node *q = searchNode(L, maSV);
                if(q != NULL) {
                    printf("--- Nhap thong tin sv can them ---\n");
                    nhap(&x);
                    if(x.masv > 0)
                        insert_After(&L, q, x);
                } else {
                    printf("Khong tim thay sinh vien co Ma SV: %d\n", maSV);
                }
                break;
            
			case 4:
            	printf("\n--- Chen them SV (Sap xep theo msv tang dan) ---\n");
            	nhap(&x);
            	if(x.masv > 0) chen_tang(&L, x);
            	break;
            
			case 5:
            	del_Head(&L);
            	printf("\nDa xoa sinh vien o dau danh sach.\n");
            	break;
            
			case 6: {
				int maSVSearch;
				printf("\nNhap msv ma ban muon xoa sinh vien phia sau: ");
				scanf("%d", &maSVSearch);
				Node *q_del = searchNode(L, maSVSearch);
				if(q_del != NULL){
					if(q_del -> link == NULL){
						printf("Day la sinh vien cuoi cung.\n");
					}else{
						del_After(&L, q_del);
						printf("Da xoa thanh cong.\n");
					}
				}else{
					printf("Khong tim thay msv nay.\n");
				}
				break;
        	}
        	case 7: {
        		int maSVDel;
        		printf("\nNhap msv can xoa: ");
        		scanf("%d", &maSVDel);
        		del_K(&L, maSVDel);
        		printf("Da thuc thi lenh xoa.\n");
				break;
			}
			case 8:{
				LList L1, L2;
				tach(L, &L1, &L2);
				printf("\n--- Danh sach L1 (Diem mon 1 < 5.0) ---\n");
				processList(L1);
				printf("\n--- Danh sach L2 (Diem mon 1 >= 5.0) ---\n");
				processList(L2);
				while(L1.pHead != NULL) del_Head&L1;
				while(L2.pHead != NULL) del_Head&L2;
				break;
			}

            case 9:
                printf("--- DANH SACH SINH VIEN ---\n");
                processList(L);
                break;

            case 0:
                printf("Bye bye\n");
                while(L.pHead != NULL) {
                    Node *temp = L.pHead;
                    L.pHead = L.pHead->link;
                    free(temp);
                }
                kt = 1;
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }while(kt==0);

    return 0;
}
