#include "product.h"
#include "manager.h"
       
int selectProduct(){
    int Product;
    printf("\n****** 제품 판매 ******\n1. 제품 조회\n2. 제품 추가\n3. 제품 수정\n4. 제품 삭제\n5. 제품 저장\n6. 제품이름 검색\n7. 제품가격 검색\n8. 제품 배송방법 검색\n0. 종료\n");
    printf("\n=> 원하는 메뉴는? ");
    scanf("%d", &Product);
    return Product;
}

int main(void){
	int n=50;
    product sp[n];
    int count = 0, a;
    int index=0;

	#ifdef DEBUG
	printf("DEBUG MODE ON:\n");
	#endif
    count = loadData(sp, n);
    index = count;
    while (1){
        a = selectProduct();
        if (a == 0) break;
        if ( a == 1 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8) {
           if (count==0) continue;
        }
        if (a == 1) {
            listProduct(sp, index);
        }
        else if (a == 2) {
		count += createProduct(&sp[index++]);
		#ifdef DEBUG
                printf("\nDEBUG MODE: Count added is: %d\n", count);
                #endif
        }
        else if (a == 3) {
            int no=selectDataNo(sp, index);
            if (no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(&sp[no-1]);
        }
        else if (a == 4) {
            int no=selectDataNo(sp, index);
            if (no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까? (삭제 : 1)");
            scanf("%d", &deleteok);
            if (deleteok == 1) {
                if (deleteProduct(&sp[no-1])) {
                	#ifdef DEBUG
		    	printf("DEBUG MODE: Previous Count Number: %d\n", count);
			#endif			
			count--;
			#ifdef DEBUG
			printf("DEBUG MODE: After Count Number: %d\n", count);
			#endif
                }
            }
        }
	else if (a==5) {
            saveData(sp, index);
        }
        else if (a==6) {
            searchProductName(sp, index);
        }
        else if (a==7) {
            searchProductPrice(sp, index);
        }
        else if (a==8) {
            searchProductShipping(sp, index);
        }
    }
    printf("종료됨!\n");
    return 0;
}

