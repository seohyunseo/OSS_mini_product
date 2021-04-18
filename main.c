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
	
	count = loadProduct(fruit);
	index = count;

	while(1){
		menu = selectMenu();
		if(menu == 0)
			break;
		if ((menu != 2) &&( count == 0)){
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
		else if(menu == 5){
			
			int soption;
			int isdata= 0;
			printf("\n**검색 옵션**\n");
			printf("1. 이름검색\n");
			printf("2. 가격검색\n");
			printf("3. 별점검색\n");
			printf("\n=>원하는 검색옵션은? ");
			scanf("%d", &soption);
			getchar();
			switch(soption){
				case 1 : 
					isdata = searchByName(fruit, index);
					break;
				case 2 : 
					isdata = searchByPrice(fruit, index);
					break;
				case 3 :
					isdata = searchByRate(fruit, index);
					break;
			}
			if(isdata == 0)
				printf("=> 검색된 데이터가 없습니다.\n");

		}
		else if(menu == 6){
			saveProduct(fruit, index);
		}
	}	
	printf("=>프로그램이 종료되었습니다.\n");
	return 0;

}
