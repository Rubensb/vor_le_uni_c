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

void getAverage(struct weatherDay *averageDay, struct weatherDay *data) {
    (*averageDay).max = 0;
    (*averageDay).min = 0;
    (*averageDay).average = 0;

    for(int i = 0; i < AMOUNT_WEATHER_DATA; ++i) {
        (*averageDay).max += data[i].max;
        (*averageDay).min += data[i].min;
        (*averageDay).average += data[i].average;
    }
    
    (*averageDay).max /= AMOUNT_WEATHER_DATA;
    (*averageDay).min /= AMOUNT_WEATHER_DATA;
    (*averageDay).average /= AMOUNT_WEATHER_DATA;
}

void findExtrema(unsigned int *min, unsigned int *max, struct weatherDay *data) {
    (*min) = 2147483647;
    (*max) = 0;
    for(int i = 0; i < AMOUNT_WEATHER_DATA; ++i) {
        (*min) = data[i].min < (*min) ? data[i].min : (*min);
        (*max) = data[i].max > (*max) ? data[i].max : (*max);
    }
}

void betterCalc(struct weatherDay *averageDay, unsigned int *max, unsigned int *min, struct weatherDay *data) {
    (*averageDay).max = 0;
    (*averageDay).min = 0;
    (*averageDay).average = 0;

    (*min) = 2147483647;
    (*max) = 0;

    for(int i = 0; i < AMOUNT_WEATHER_DATA; ++i) {
        (*averageDay).max += data[i].max;
        (*averageDay).min += data[i].min;
        (*averageDay).average += data[i].average;

        (*min) = data[i].min < (*min) ? data[i].min : (*min);
        (*max) = data[i].max > (*max) ? data[i].max : (*max);
    }

    (*averageDay).max /= AMOUNT_WEATHER_DATA;
    (*averageDay).min /= AMOUNT_WEATHER_DATA;
    (*averageDay).average /= AMOUNT_WEATHER_DATA;
}

int main() {
    getWeatherData(data);
    
    clock_t startTime = clock();

    struct weatherDay average;
    //getAverage(&average, data);


    unsigned int min, max;
    //findExtrema(&min, &max, data);

    betterCalc(&average, &max, &min, data);

    clock_t endTime = clock();
    clock_t difference = endTime - startTime;
    printf("Time to calc: %lu\n\n", difference);

    /*printf("Data: \n\n");
    printf("[max, min, average] ");
    for(int i = 0; i < AMOUNT_WEATHER_DATA; ++i) {
        printf("[%d, %d, %d] ", data[i].max, data[i].min, data[i].average);
    }
    printf("\n\n");*/

    printf("Average over the past %d days:\n\n", AMOUNT_WEATHER_DATA);
    printf("max: %d\nmin: %d\naverage: %d\n\n", average.max, average.min, average.average);

    printf("Extrema over the past %d days:\n\n", AMOUNT_WEATHER_DATA);
    printf("max: %d\nmin: %d\n", max, min);

    return 0;
}