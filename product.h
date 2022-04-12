#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _HEADER1_
#define _HEADER1_

typedef struct Product{
    char name[50];
    char info[50];
    char weight[20];
    int price;
    int shipping;
} product;

int createProduct(product *s);          // 제품 생성 함수
void readProduct(product s);            // 삭제된 제품을 제외한 다른 제품들 출력
int deleteProduct(product *s);           // 특정 제품 삭제 함수
int updateProduct(product* s);           // 특정 제품 수정 함수
#endif
