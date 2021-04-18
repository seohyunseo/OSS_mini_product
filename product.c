#include <stdio.h>
#include <string.h>

typedef struct{
        char name[20];
        int weight;
        int price;
        int rate[1000];
        int num_rate;
} Product;

int createProduct(Product *p){
        printf("과일이름은? ");
        scanf("%[^\n]" , p->name);
        printf("과일 무게는?(g) ");
        scanf("%d", &p->weight);
        printf("가격은? ");
        scanf("%d", &p->price);
        printf("별점은?(1~5) ");
        scanf("%d", &p->rate[0]);
        p->num_rate++;
        // 별점기능 추가

    return 1;
}

int readProduct(Product p){
       
        printf("%s\t%d\t%d\t%d\t%d\n", p.name, p.weight, p.price, p.rate[0], p.num_rate);
        return 1;
}

int updateProduct(Product *p){


        printf("과일이름은? ");
        scanf("%[^\n]" , p->name);
        printf("과일 무게는?(g) ");
        scanf("%d", &p->weight);
        printf("가격은? ");
        scanf("%d", &p->price);
        printf("별점은?(1~5) ");
        scanf("%d", &p->rate[0]);
        p->num_rate = 0;
        p->num_rate++;

        return 1;
}

int deleteProduct(Product *p){
        p->price = -1;

        return 1;
}

int selectMenu(){
        int menu;
        printf("\n***Fruits***\n");
        printf("1. 제품조회\n");
        printf("2. 제품추가\n");
        printf("3. 제품수정\n");
        printf("4. 제품삭제\n");
        printf("5. 제품검색\n");
        printf("6. 제품저장\n");
        printf("0. 종료\n");
        printf("\n=>원하는 메뉴는? ");
        scanf("%d", &menu);
        while (getchar() != '\n')
                continue;

        return menu;
}

void listName(){
	
        printf("**************************************************\n");
	printf("No.\t이름\t무게(g)\t가격\t별점\t별점갯수\n");
}
int searchByName(Product *p, int count){
	int scount = 0;
	char search[20];

	printf("검색할 이름은? ");
	scanf("%[^\n]", search);

        listName();
	for(int i = 0; i < count; i++){
		if(p[i].price == -1)
			continue;
		if(strstr(p[i].name, search)){
			printf("%d\t", i+1);
			readProduct(p[i]);
			scount++;
		}
	}

	printf("\n");
	return scount;
}
	
int searchByPrice(Product *p, int count){
	int scount = 0;
	int smin, smax;

	printf("검색할 가격대를 입력하세요?\n");
	printf("최소 가격은? ");
	scanf("%d", &smin);
	printf("최대 가격은? ");
	scanf("%d", &smax);
        listName();
	for(int i = 0; i < count; i++){
		if(p[i].price == -1)
			continue;
		if(p[i].price >= smin && p[i].price <= smax){
			printf("%d\t", i+1);
			readProduct(p[i]);
			scount++;
		}
	}
	printf("\n");
	return scount;
}

	
int searchByRate(Product *p, int count){
	int scount = 0;
	int srate;

	printf("검색할 별점은?(1~5) ");
	scanf("%d", &srate);
        listName();
	for(int i = 0; i < count; i++){
		if(p[i].price == -1)
			continue;
		if(p[i].rate[0] == srate){
			printf("%d\t", i+1);
			readProduct(p[i]);
			scount++;
		}
	}
	printf("\n");
	return scount;
}
void saveProduct(Product *p, int count){
	FILE *fp;
	fp = fopen("product.txt", "wt");
	
	for(int i = 0; i < count; i++){
		if(p[i].price == -1)
			continue;
        	fprintf(fp,"%s\t%d\t%d\t%d\t%d\n", p[i].name, p[i].weight, p[i].price, p[i].rate[0], p[i].num_rate);
	}
	fclose(fp);
	printf("=>제품 리스트가 저장되었습니다.\n");
}

int loadProduct(Product *p){
	int i = 0;
	FILE *fp;
	fp = fopen("product.txt", "rt");
	if(fp == NULL)
		printf("=>파일이 존재하지 않습니다.\n");
	else{
		for(; i < 100; i++){
			fscanf(fp,"%[^\t]", p[i].name);
			if(feof(fp))
				break;
			fscanf(fp, "%d ", &p[i].weight);
			fscanf(fp, "%d ", &p[i].price);
			fscanf(fp, "%d ", &p[i].rate[0]);
			fscanf(fp, "%d ", &p[i].num_rate);
		}
	printf("=>로딩에 성공하였습니다.\n");
	}
	fclose(fp);

	return i;
}	

