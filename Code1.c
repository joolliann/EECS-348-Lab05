#include <stdio.h>

void monthly_sales(double *sales, char *months[]);
void sales_summary(double *sales, char *months[]);
void six_month_avg(double *sales, char *months[]);
void highest_lowest(double *sales, char *months[]);

int main() {
    /* Be starting point of the program */
    double sales[12]; 
    
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        printf("Enter %s sales:\n", months[i]);
        scanf("%lf", &sales[i]);  
        /*Read sales*/
    }
    /*Generate reports*/
    monthly_sales(sales, months); 
    sales_summary(sales, months);  
    six_month_avg(sales, months);  
    lowest_highest(sales, months);

    return 0; 
}

void monthly_sales(double *sales, char *months[]) {
    /* Generate sales report*/
    printf("\nMonthly Sales Report\n");
    printf("Month\tSales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\t%.2lf\n", months[i], sales[i]); 
    }
}

void sales_summary(double *sales, char *months[]) {
    /*Create maximum, minimum, and average sales*/
    double total = 0; 
    double minimum = sales[0]; 
    double maximum = sales[0]; 
    int min_index = 0, max_index = 0; 
    /*Initialize variables*/
    for (int i = 0; i < 12; i++) {
        total += sales[i]; 
        /*Find total sales*/
        if (sales[i] < minimum) {
            minimum = sales[i]; 
            min_index = i; 
            /*Find minimum sales and update index*/
        }
        if (sales[i] > maximum) {
            maximum = sales[i];
            max_index = i; 
            /*Find maximum sales and update index*/
        }
    }

    double average = (total / 12); 
    printf("\nSales Summary Report:\n");
    printf("Minimum sales: %.2lf (%s)\n", minimum, months[min_index]); 
    printf("Maximum sales: %.2lf (%s)\n", maximum, months[max_index]); 
    printf("Average sales: %.2lf\n", average); 
}

void six_month_avg(double *sales, char *months[]) {
    /*Calculate six month moving average*/
    printf("\nSix-Month Moving Average Report\n");
    for (int i = 0; i <= 6; i++) {
        double sum = 0; 
        for (int j = 0; j < 6; j++) {
            sum += sales[i + j]; /* Add sales from the current month to the next five months */
        }
        printf("%s - %s: %.2lf\n", months[i], months[i + 5], sum / 6); 
    }
}

void lowest_highest(double *sales, char *months[]){
    /*Arrange months from highest to lowest sales*/
    printf("\nSales Report (lowest to highest):\n\nMonth\tSales\n");
    int i, j;
    for (i = 0; i < 11; i++){
        for (j = 0; j < 11 - i; j++){
            if (sales[j] > sales[j+1]){
                double store = sales[j];
                char *store2 = months[j];
                sales[j] = sales[j+1];
                sales[j+1] = store;
                months[j] = months[j+1];
                months[j+1] = store2;
                /*Simple bubble sort algorithm to get the correct values*/

            }
        }
    }
    for (i = 0; i < 11; i++){
        printf("%s\t%.2lf\n", months[i], sales[i]);
    }

}