#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define AMOUNT_WEATHER_DATA 20

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


int main() {
    getWeatherData(&data);
    
}