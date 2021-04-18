#include <stdio.h>

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
        printf("0. 종료\n");
        printf("\n=>원하는 메뉴는? ");
        scanf("%d", &menu);
        while (getchar() != '\n')
                continue;

        return menu;
}

