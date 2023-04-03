//
// Created by Вадим Герасимович on 4/3/23.
//

#include "f.h"
int input(int min, int max) {
    int x;
    while (scanf("%d", &x) != 1 || x < min || x > max || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

void freee(struct car*cars, int n){
    //struct car *cars;
    for (int j = 0; j < n; ++j) {
        free(cars[j].brand);
        //free(cars[j].body.body.type);
    }
    free(cars);
}
void search(int i, int n, struct car*cars){
    int maxx=0;
    for (int j = 0; j < n; ++j) {
        if (cars[j].body.body.engine_volume>maxx){
            maxx=cars[j].body.body.engine_volume;
            i=j;
        }
    }
    printf("Price: %d, Brand: %s, Type: %s, Engine Volume: %d\n",
           cars[i].price, cars[i].brand, cars[i].body.body.type, cars[i].body.body.engine_volume);
}
int deleter(int i,int n, struct car*cars, char* brand){
    for (i = 0; i < n; i++) {
        if (strcmp(cars[i].body.body.type, brand) == 0) {
            for (int j = i; j < n - 1; j++) {
                cars[j] = cars[j + 1];} n--;
            i--;
        }
    }
    for (i = 0; i < n; i++) {
        if (strcmp(cars[i].brand, " ") != 0) {
            printf("Price: %d, Brand: %s, Type: %s, Engine Volume: %d\n",
                   cars[i].price, cars[i].brand, cars[i].body.body.type, cars[i].body.body.engine_volume);
        }
    }
    return n;
}
void input_struct(int n, struct car*cars, char *buffer){
    for (int i = 0; i < n; ++i) {
        printf("\nPrice: ");
        cars[i].price = input(-999999, 999999);
        printf("\nBrand: ");
        scanf("%s", buffer);
        cars[i].brand = (char *) malloc(strlen(buffer) + 1);
        strcpy(cars[i].brand, buffer);
        printf("\nType of body(positive): ");
        scanf("%s", cars[i].body.body.type);
        printf("\nEngine: : ");
        cars[i].body.body.engine_volume = input(-9999999, 999999);
    }
}
void task() {
    int n, i;
    char *buffer[MAX_BRAND_LEN], brand[MAX_BRAND_LEN];
    printf("\nВведите количество: ");
    n=input(1,999);
    struct car *cars = (struct car *) malloc(n * sizeof(struct car));
    input_struct(n,cars,buffer);
    printf("Car with greatest engin volume: ");
    search(i,n,cars);
    printf("Enter type of body to remove: ");
    scanf("%s", brand);
    printf("Cars after removing %s:\n", brand);
    n=deleter(i,n,cars,brand);
    cars=(struct cars*)realloc(cars, n*sizeof(struct car));
    freee(cars, n);
}
