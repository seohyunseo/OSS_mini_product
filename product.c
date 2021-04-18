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
        printf("5. 이름검색\n");
        printf("6. 가격검색\n");
        printf("0. 종료\n");
        printf("\n=>원하는 메뉴는? ");
        scanf("%d", &menu);
        while (getchar() != '\n')
                continue;

        return menu;
}

void searchByName(Product *p, int count){
	int scount = 0;
	char search[20];

	printf("검색할 이름은? ");
	scanf("%[^\n]", search);

        printf("**************************************************\n");
	printf("No.\t이름\t무게(g)\t가격\t별점\t별점갯수\n");
	for(int i = 0; i < count; i++){
		if(p[i].price == -1)
			continue;
		if(strstr(p[i].name, search)){
			printf("%d\t", i+1);
			readProduct(p[i]);
			scount++;
		}
	}
	if(scount == 0)
		printf("=> 검색된 데이터가 없습니다.");
	printf("\n");
}

	
void searchByPrice(Product *p, int count){
	int scount = 0;
	int smin, smax;

	printf("검색할 가격대를 입력하세요?\n");
	printf("최소 가격은? ");
	scanf("%d", &smin);
	printf("최대 가격은? ");
	scanf("%d", &smax);
        printf("**************************************************\n");
	printf("No.\t이름\t무게(g)\t가격\t별점\t별점갯수\n");
	for(int i = 0; i < count; i++){
		if(p[i].price == -1)
			continue;
		if(p[i].price >= smin && p[i].price <= smax){
			printf("%d\t", i+1);
			readProduct(p[i]);
			scount++;
		}
	}
	if(scount == 0)
		printf("=>검색된 데이터가 없습니다.");
	printf("\n");
}

	
void searchByRate(Product *p, int count);
void saveProduct(Product *p, int count);
int loadProduct(Product *p);

