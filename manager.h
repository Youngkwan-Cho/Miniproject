#include "product.h"

int selectDataNo (product *s, int count); // 특정 제품의 데이터 위치를 알아내기 위한 함수
void listProduct(product *s, int count);   // 현재있는 제품 알려주는 함수(삭제된 값은 스킵함)

void saveData(product *s, int count);
int loadData(product *s, int number);
void searchProductName(product *s, int count);
void searchProductShipping(product *s, int count);
void searchProductPrice(product *s, int count);
