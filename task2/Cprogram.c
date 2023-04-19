#include <stdio.h>
#define MONTH_NUM 12

const char months[12][15] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"};
void month_sales(const float* sales_data) {
    // const char months[12][15]={"January", "February", "March", "April", "May", "June", "July",
    // "August", "September", "October", "November", "December"};
    printf("\nMonth\t\tSales\n");
    int width = 15;
    for (int i = 0; i < MONTH_NUM; i++) {
        printf("%-*s $%7.2f\n", width, months[i], sales_data[i]);
    }
    printf("\n");
}

void sales_summary(float sales_data[MONTH_NUM]) {
    int min_sale_index = 0;
    int max_sale_index = 0;
    float sum_sales = sales_data[0];

    for (int i = 1; i < MONTH_NUM; i++) {
        if (sales_data[i] < sales_data[min_sale_index]) {
            min_sale_index = i;
        }

        if (sales_data[i] > sales_data[max_sale_index]) {
            max_sale_index = i;
        }

        sum_sales += sales_data[i];
    }

    printf("Minimum sales: $%.2f (%s)\n", sales_data[min_sale_index], months[min_sale_index]);
    printf("Maximum sales: $%.2f (%s)\n", sales_data[max_sale_index], months[max_sale_index]);
    printf("Average sales: $%.2f\n", sum_sales / 12);
    printf("\n");
}

void six_moving_average(float sales_data[MONTH_NUM]) {
    printf("\nSix-Month Moving Average Report\n\n");
    float sum = 0.0;
    float avg = 0.0;
    for (int i = 0; i < MONTH_NUM - 5; i++) {
        sum =
            (sales_data[i] + sales_data[i + 1] + sales_data[i + 2] + sales_data[i + 3] +
             sales_data[i + 4] + sales_data[i + 5]);
        avg = sum / 6.0;
        printf("%-8s -  %-12s $%7.2f\n", months[i], months[i + 5], avg);
    }
    printf("\n");
}
void sales_report(const float* sales_data) {

    float temp_month[12];
    float high_month;
    int month_num;
    int* month_ptr = &month_num;

    printf("\nSales Report (Highest - Lowest):\n");
    printf("Month\t\tSales\n");

    for (int i = 0; i < 12; i++) {
        temp_month[i] = sales_data[i];
    }
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (temp_month[i] < temp_month[j]) {
                high_month = temp_month[i];
                temp_month[i] = temp_month[j];
                temp_month[j] = high_month;
            }
        }
    }

    for (int i = 0; i < 12; i++) {
        float find = temp_month[i];
        for (int j = 0; j < 12; j++) {
            if (find == sales_data[j]) {
                printf("%-12s\t$%-10.2f\n", months[j], temp_month[i]);
            }
        }
    }
}

int main() {
    char months[12][15] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};
    float sales_data[MONTH_NUM];
    FILE* fp;
    int i = 0;
    fp = fopen("input.txt", "r");
    if (fp == 0) {
        printf("Error, Please check file!\n");
    }
    for (i = 0; i < MONTH_NUM; i++) {
        fscanf(fp, "%f", &sales_data[i]);
    }

    fclose(fp);
    printf("Monthly Sales Report for 2022:\n");
    month_sales(sales_data);
    sales_summary(sales_data);
    six_moving_average(sales_data);
    sales_report(sales_data);
}