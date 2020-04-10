// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// double dobbels(double a, double b, double c)
// {
//     double result;
//     result = a+b+c;
//     printf("%f \n",result);
// }

// main()
// {
//     double a, b, c;
//     scanf("%lf %lf %lf", &a, &b, &c);
//     dobbels(a, b, c);

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     if (argc == 2)
//     {
//         int a = atoi(argv[1]);
//         if (a % 2 == 0)
//         {
//             printf("Even numbers before %d: ", a);
//         }
//         else
//         {
//             printf("Odd numbers before %d: ", a);
//         }
//         for (int i = (a-2); i > 0; i -= 2)
//         {
//             printf("%d ", i);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// #include <time.h>

// #define AMOUNT_WEATHER_DATA 20

// struct weatherDay 
// {
//     unsigned int max;
//     unsigned int min;
//     unsigned int average;
// };

// struct weatherDay data[AMOUNT_WEATHER_DATA];

// void getWeatherData(struct weatherDay *data) {
//     srand(time(NULL));
//     for(int i = 0; i < AMOUNT_WEATHER_DATA; i++) {
//         data[i].max = rand() % 30 + 1;
//         data[i].min = rand() % data[i].max;
//         data[i].average = rand() % data[i].max;
//     }
// }

// void calculate(struct weatherDay *data) {

//     printf("Data: \n\n[max, min, average] ");
//     int i;
//     for (i = 0; i < AMOUNT_WEATHER_DATA; i++) {
//         printf("[%d, %d, %d] ", data[i].max, data[i].min, data[i].average);
//     }    

//     int avgMin = 0;
//     int avgMax = 0;
//     int avgAvg = 0;
//     int maxMax = data[0].max;
//     int minMin = data[0].min;

//     int temp;
//     for (i = 0; i < AMOUNT_WEATHER_DATA; i++) {
//         temp += data[i].max;
//         if (maxMax < data[i].max) {
//             maxMax = data[i].max;
//         }        
//     }
//     avgMax = temp / AMOUNT_WEATHER_DATA;
    
//     temp = 0;
//         for (i = 0; i < AMOUNT_WEATHER_DATA; i++) {
//         temp += data[i].min;
//         if (minMin > data[i].min) {
//             minMin = data[i].min;
//         }
//     }
//     avgMin = temp / AMOUNT_WEATHER_DATA;

//     temp = 0;
//         for (i = 0; i < AMOUNT_WEATHER_DATA; i++) {
//         temp += data[i].average;
//     }
//     avgAvg = temp / AMOUNT_WEATHER_DATA;

//     printf("\n\nAverage over the past %d days:\n\nmax: %d\nmin: %d\naverage: %d\n\nExtrema over the past 20 days:\n\nmax: %d\nmin: %d\n",AMOUNT_WEATHER_DATA, avgMax, avgMin, avgAvg, maxMax, minMin);
// }

// int main() {
//     getWeatherData(data);
//     calculate(data);
// }

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define AMOUNT_WEATHER_DATA 2000000

struct weatherDay 
{
    unsigned int max;
    unsigned int min;
    unsigned int average;
};

struct weatherDay data[AMOUNT_WEATHER_DATA];

void getWeatherData(struct weatherDay *data) {
    srand(time(NULL));
    for(int i = 0; i < AMOUNT_WEATHER_DATA; i++) {
        data[i].max = rand() % 30 + 1;
        data[i].min = rand() % data[i].max;
        data[i].average = rand() % data[i].max;
    }
}

void calculate(struct weatherDay *data) {
    clock_t startTime = clock();
    int i;
    int avgMin = 0;
    int avgMax = 0;
    int avgAvg = 0;
    int maxMax = data[0].max;
    int minMin = data[0].min;

    int temp;
    for (i = 0; i < AMOUNT_WEATHER_DATA; i++) {
        avgMax += data[i].max;
        avgMin += data[i].min;
        avgAvg += data[i].average;

        if (maxMax < data[i].max) {
            maxMax = data[i].max;
        }
        if (minMin > data[i].min) {
            minMin = data[i].min;
        }        
    }
    avgMax /= AMOUNT_WEATHER_DATA;
    avgMin /= AMOUNT_WEATHER_DATA;
    avgAvg /= AMOUNT_WEATHER_DATA;
    clock_t endTime = clock();
    clock_t difference = endTime - startTime;
    printf("Time to calc: %lu\n\n", difference);
    
    printf("\n\nAverage over the past %d days:\n\nmax: %d\nmin: %d\naverage: %d\n\nExtrema over the past 20 days:\n\nmax: %d\nmin: %d\n",AMOUNT_WEATHER_DATA, avgMax, avgMin, avgAvg, maxMax, minMin);
}

int main() {
    getWeatherData(data);
    // printf("Data: \n\n[max, min, average] ");
    // int i;
    // for (i = 0; i < AMOUNT_WEATHER_DATA; i++) {
    //     printf("[%d, %d, %d] ", data[i].max, data[i].min, data[i].average);
    // }    
    calculate(data);
    
}