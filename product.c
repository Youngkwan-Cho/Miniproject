#include "product.h"

void readProduct(product s) {
    printf("\t%s \t%s %20s %8d", s.name, s.info, s.weight, s.price);
    if (s.shipping==0)  printf("    새벽배송\n");
    if (s.shipping==1)  printf("    택배배송\n");
}

int createProduct(product *s) {
    printf("\n제품이름 ? ");
    scanf(" %[^\n]s", s->name);
    printf("제품정보 ? ");
    scanf(" %[^\n]s", s->info);
    printf("제품 무게 ? ");
    scanf(" %[^\n]s", s->weight);
    printf("제품 가격 ? ");
    scanf(" %d", &s->price);
    printf("배송 방법 ? (0:새벽 배송, 1:택배 배송) ");
    scanf(" %d", &s->shipping);
    printf("=> 제품 추가 완료 ! \n");
    return 1;
}

int updateProduct(product* s) {
    printf("\n새 제품이름 ? ");
    scanf(" %[^\n]s", s->name);
    printf("새 제품정보 ? ");
    scanf(" %[^\n]s", s->info);
    printf("새 제품 무게 ? ");
    scanf(" %[^\n]s", s->weight);
    printf("새 제품 가격 ? ");
    scanf(" %d", &s->price);
    printf("새 배송 방법 ? (0:새벽 배송, 1:택배 배송) ");
    scanf(" %d", &s->shipping);
    printf("=> 제품 변경 완료 ! \n");
    return 1;
}

int deleteProduct(product *s) {
    s->price=-1;
    printf("=> 삭제됨!\n");
    return 1;
}
