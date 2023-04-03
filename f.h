//
// Created by Вадим Герасимович on 4/3/23.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef S2LABA4_F_H
#define S2LABA4_F_H
#endif //S2LABA4_F_H
#define MAX_BRAND_LEN 50
struct CarDetails {
    char* type[20];
    int engine_volume;
};
union body {
    struct CarDetails body;
    int number_of_car;
};
struct car {
    int price;
    char *brand;
    union body body;
    /*union {
            char* type[20];
            int engine_volume;
    } body;*/

    //struct car_body body;
};
int input(int min, int max);
void freee(struct car*cars, int n);
int deleter(int i,int n,struct car*cars,char* brand);
void search(int i, int n, struct car*cars);
void input_struct(int n, struct car*cars, char *buffer);
void task();