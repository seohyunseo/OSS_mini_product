#include <stdio.h>
#include "product.h"
#include "manager.h"

#define MAX 20

int main (){

#ifdef DEBUG
	printf("==> DEBUGMODE\n");
#endif
	Product fruit[MAX];
	
	int count = 0, index = 0; 
	int menu;

	while(1){
		menu = selectMenu();
		if(menu == 0)
			break;
		if ((menu == 1 || menu == 3 || menu == 4) && count == 0){
            		printf("=> 데이터가 없습니다.\n");
			continue;}
		else if(menu == 2)
		{
			fruit[index].num_rate = 0;
			count += createProduct(&fruit[index++]);
		}
		else if(menu == 1)
		{	int islist;
			islist = listProduct(fruit,index); //replace with list() instead of read()
			if(islist == 0)
				printf("=> 데이터가 없습니다.\n");
		}
		else if(menu == 3){
			int isup;
			int no;
			no = selectProductNo(fruit, index);
			if(no > 0)
				isup = updateProduct(&fruit[no-1]);
			else if(no == 0)
				continue;
			if(isup == 1)
				printf("=> 수정에 성공했습니다.\n");
			else
				printf("=> 수정에 실패했니다.\n");
		}
		else if(menu == 4){
			int isdel;
			int no, con;
			no = selectProductNo(fruit, index);
			if(no > 0){
				printf("정말로 삭제하시겠습니까? (삭제:1) ");
				scanf("%d",&con);
				if(con == 1){
					isdel = deleteProduct(&fruit[no-1]);
					if(isdel == 1){
						printf("=> 삭제에 성공했습니다.\n");
						count--;
					}	
					else
						printf("=> 삭제에 실패했습니다.\n");
				}
				
				else{
					printf("=>삭제가 취소되었습니다.\n");
					continue;
				}

			}
		

		}
	}	
	printf("=>프로그램이 종료되었습니다.\n");
	return 0;

}
