#ifndef _PRODUCT_H
#define _PRODUCT_H

typedef struct
{
    char name[20];
    int weight;
    int price;
    int rate[1000];
    int num_rate;

} Product;

// 기능에 대한 메뉴를 출력하고 사용자로부터 메뉴번호를 입력받아 반환한다.
int selectMenu();

// 기존 파일에 저장된 제품들을 읽어들인다.
int loadProduct(Product *p);

// 새로운 제품의 정보를 목록에 추가한다.
int createProduct(Product *p);

// 하나의 제품의 정보를 형식에 맞춰 출력한다.
int readProduct(Product p);

// 목록에 존재하는 제품을 나열하여 출력한다.
//int listProduct(Product *p[], int count);

// 제품의 정보를 수정한다.
int updateProduct(Product *p);

// 선택한 제품의 정보를 목록에서 삭제한다.
int deleteProduct(Product *p);

// 제품의 이름을 통해 검색하여 정보를 출력한다.
void searchByName(Product *p[], int count);

// 제품의 가격을 통해 검색하여 정보를 출력한다.
void searchByPrice(Product *p[], int count);

// 제품의 별저을 통해 검핵하여 정보를 출력한다.
void searchByRate(Product *p[], int count);

// 목록에 담겨있는 제품들을 파일에 저장한다.
void saveProduct(Product *p[], int count);

// 제품의 번호를 선택한다. 선택된 번호를 통해 특정 제품에 대한 delete, update 함수를 실행한다.
//int selectProductNo(Product *p[], int count);
#endif
