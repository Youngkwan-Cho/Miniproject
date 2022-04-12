#include "manager.h"

void listProduct(product *s, int count) {
    printf("\n********* 제품 **********\n");
    printf("\n번호\t제품이름\t\t제품정보\t\t무게     가격    배송방식\n");
    printf("===================================================================================\n");
    int a=count;
    for (int i=0; i<count; i++) {
        if (s[i].price==-1) {
		a--;
		continue;
        }
        printf("%2d", i+1);
        readProduct(s[i]);
    }
    printf("\n총 %d개의 주문이 있습니다.\n", a);
}

int selectDataNo (product *s, int count) {
    int no;
    listProduct(s, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}


void saveData(product *s, int count) {
    FILE *fp;
    fp=fopen("product.txt", "wt");
    for (int i=0; i< count; i++) {
        if(s[i].price==-1) continue;
        fprintf(fp, "%s, %s, %s, %d %d\n",  s[i].name, s[i].info, s[i].weight, s[i].price, s[i].shipping);
    }
    fclose(fp);
    printf("=> 저장됨! \n");
}

int loadData(product *s, int number) {
    int count=0;
    int  i=0;
    FILE *fp;
    fp=fopen("product.txt", "rt");
    printf("=> 데이터 가져오는 중...\n");
    if (fp==NULL) {
        printf("=> 파일 없음 \n");
    }
    else {
    for (;i<number;i++) {
        fscanf(fp, " %[^,], %[^,], %[^,], %d %d", s[i].name, s[i].info, s[i].weight, &s[i].price, &s[i].shipping);
        if (feof(fp)) break;
        count++;
    }
    printf("=> %d 개의 주문 정보를 읽었습니다!\n", count);
    fclose(fp);
    }
    return i;
}

void searchProductName(product *s, int count) {
    int scnt=0;
    char search[20];
    printf("검색할 제품 이름? ");
    scanf(" %[^\n]s", search);
    printf("\n********* 제품 **********\n");
    printf("\n번호\t제품이름\t\t제품정보\t\t무게    가격   배송방식\n===========================================================\n");
    for (int i=0; i<count; i++) {
        if (s[i].price==-1) continue;
        if (strstr(s[i].name, search)) {
             printf("%2d", i+1);
            readProduct(s[i]);
            scnt++;
        }
    }
    printf("\n총 %d개의 주문이 있습니다.\n", scnt);
    if (scnt==0) printf("=> 검색된 데이터 없음!\n");
}

void searchProductShipping(product *s, int count){
    int scnt=0;
    int search;
    printf("검색할 제품 배송 방법? (0:새벽 배송, 1:택배 배송) ");
    scanf(" %d", &search);
    printf("\n********* 제품 **********\n");
    printf("\n번호\t제품이름\t\t제품정보\t\t무게    가격   배송방식\n===========================================================\n");
    for (int i=0; i<count; i++) {
        if (s[i].price==-1) continue;
        if (s[i].shipping==search) {
            printf("%2d", i+1);
            readProduct(s[i]);
            scnt++;
        }
    }
    printf("\n총 %d개의 주문이 있습니다.\n", scnt);
    if (scnt==0) printf("=> 검색된 데이터 없음!\n");
}

void searchProductPrice(product *s, int count){
    int scnt=0;
    int search;
    printf("검색할 제품 가격? ");
    scanf(" %d", &search);
    printf("\n********* 제품 **********\n");
    printf("\n번호\t제품이름\t\t제품정보\t\t무게    가격   배송방식\n===========================================================\n");
    for (int i=0; i<count; i++) {
        if (s[i].price==-1) continue;
        if (s[i].price==search) {
             printf("%2d", i+1);
            readProduct(s[i]);
            scnt++;
        }
    }
    printf("\n총 %d개의 주문이 있습니다.\n", scnt);
    if (scnt==0) printf("=> 검색된 데이터 없음!\n");
}

