#include <stdio.h>
#include <stdlib.h>


typedef struct Candle {
    char name[20];
    int waxPerCandle;
    int wickPerCandle;
    int fragrancePerCandle;
    struct Candle *next;
} Candle;


Candle* createCandle(const char* name, int wax, int wick, int fragrance) {
    Candle* newCandle = (Candle*)malloc(sizeof(Candle));
    if (newCandle != NULL) {
        snprintf(newCandle->name, sizeof(newCandle->name), "%s", name);
        newCandle->waxPerCandle = wax;
        newCandle->wickPerCandle = wick;
        newCandle->fragrancePerCandle = fragrance;
        newCandle->next = NULL;
    }
    return newCandle;
}


int findMaxCandles(int wax, int wick, int fragrance, Candle* candles) {
    int maxCandles = 0;

    while (1) {
        int requiredWax = (maxCandles + 1) * candles->waxPerCandle;
        int requiredWick = (maxCandles + 1) * candles->wickPerCandle;
        int requiredFragrance = (maxCandles + 1) * candles->fragrancePerCandle;

        if (requiredWax <= wax && requiredWick <= wick && requiredFragrance <= fragrance) {
            maxCandles++;
        } else {
            break;
        }
    }

    return maxCandles;
}


double calculateProfit(int maxCandles, double unitPrice) {
    return maxCandles * unitPrice;
}


void freeCandles(Candle* head) {
    while (head != NULL) {
        Candle* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    Candle* head = NULL;
    printf("Select the size of the candles:\n");
    printf("1. Small candle\n2. Medium candle\n3. Large candle\n");
    printf("Enter the number of selected candle: ");
    scanf("%d", &n);

    while(n < 1 || n > 3){
        if(n < 1 || n > 3){
            printf("\nInvalid selection.\n");
            printf("\n");
        }
        else{
            continue;
        }
        printf("Select the size of the candles:\n");
        printf("1. Small candle\n2. Medium candle\n3. Large candle\n");
        printf("Enter the number of selected candle: ");
        scanf("%d", &n);
    } 
        
    if (n == 1) {
        int waxPerCandle, wickPerCandle, fragrancePerCandle;
        printf("Wax required for one candle is 100g\n");
        waxPerCandle = 100;
        printf("Wick required for one candle is 60mm\n");
        wickPerCandle = 60;
        printf("Fragrance required for one candle is 5g\n");
        fragrancePerCandle = 5;
        head = createCandle("Small", 100, 60, 5);
    } 

    else if (n == 2) {
        int waxPerCandle, wickPerCandle, fragrancePerCandle;
        printf("Wax required for one candle is 200g\n");
        waxPerCandle = 200;
        printf("Wick required for one candle is 80mm, 2 wicks required\n");
        wickPerCandle = 160;
        printf("Fragrance required for one candle is 10g\n");
        fragrancePerCandle = 10;
        head = createCandle("Medium", 200, 160, 10);
    } 
        
    else if (n == 3) {
        int waxPerCandle, wickPerCandle, fragrancePerCandle;
        printf("Wax required for one candle is 300g\n");
        waxPerCandle = 300;
        printf("Wick required for one candle is 85mm, 3 wicks required\n");
        wickPerCandle = 255;
        printf("Fragrance required for one candle is 15g\n");
        fragrancePerCandle = 15;
        head = createCandle("Large", 300, 255, 15);
    }

    int wax, wick, fragrance;
    printf("Enter the quantity of wax in grams: ");
    scanf("%d", &wax);
    printf("Enter the quantity of wick in millimeters: ");
    scanf("%d", &wick);
    printf("Enter the quantity of fragrance in grams: ");
    scanf("%d", &fragrance);

    double unitPrice;
    printf("Enter the unit price of each candle: ");
    scanf("%lf", &unitPrice);

    int maxCandles = findMaxCandles(wax, wick, fragrance, head);
    double profit = calculateProfit(maxCandles, unitPrice);

    printf("Maximum quantity of candles that can be made: %d\n", maxCandles);
    printf("Money made from selling these candles will be: %.2f\n", profit);
    
  
    freeCandles(head);

    return 0;
}