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
