#include "manager.h"

int listProduct(Product *p, int count){
	
	int i;
        printf("**************************************************\n");
	printf("No.\t이름\t무게(g)\t가격\t별점\t별점갯수\n");
	for(i = 0; i < count; i++){
	       	if (p[i].price == -1)
			continue;
		printf("%d\t", i+1);
		readProduct(p[i]);
	}
	if(i == 0)
		return 0;
	return 1;

	
}

int selectProductNo(Product *p, int count){
	
	int no;
	listProduct(p, count);
	printf("제품 번호는? (취소:0) ");
	scanf("%d",&no);
	while(getchar() != '\n')
		continue;
	return no;
}


	
