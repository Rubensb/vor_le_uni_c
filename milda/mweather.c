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

void getAverage (struct weatherDay *data, int *avemax, int *avemin, int *aveave) 
{
    int sammelmax = 0;
    int sammelmin = 0;
    int sammelave = 0;

    for (int i = 0; i < AMOUNT_WEATHER_DATA; i++)
    {   
        sammelmax += data[i].max;
        sammelmin += data[i].min;
        sammelave += data[i].average;
    }
    sammelmax /= AMOUNT_WEATHER_DATA;
    sammelmin /= AMOUNT_WEATHER_DATA;
    sammelave /= AMOUNT_WEATHER_DATA;

    (*avemax) = sammelmax;
    (*avemin) = sammelmin;
    (*aveave) = sammelave;
}

void getExtrema (struct weatherDay *data, int *extremmax, int *extremmin)
{
    for (int k = 0; k < AMOUNT_WEATHER_DATA; k++)
    {
        if ((*extremmax) < data[k].max)
        {
            (*extremmax) = data[k].max;
        }
        if ((*extremmin) > data[k].min)
        {
            (*extremmin) = data[k].min;
        }
    }
}


int main() {
    int avemax;
    int avemin;
    int aveave;
    int extremmax = 0;
    int extremmin = 1000;
    getWeatherData(data);

    clock_t startTime = clock();

    getAverage (data, &avemax, &avemin, &aveave);

    getExtrema (data, &extremmax, &extremmin);

    clock_t endTime = clock();
    clock_t difference = endTime - startTime;
    printf("Time to calc: %lu\n\n", difference);

    /*
    printf ("Data:\n");
    for (int j = 0; j < AMOUNT_WEATHER_DATA; j++)
    {
        printf ("[%d, %d, %d]", data[j].max, data[j].min, data[j].average);
    }*/
    
    printf ("Average over the past %d days:\n", AMOUNT_WEATHER_DATA);
    printf ("\n");
    printf ("max: %d \n", avemax);
    printf ("min: %d \n", avemin);
    printf ("average: %d \n", aveave);

    printf ("Extrema over the past %d days: \n", AMOUNT_WEATHER_DATA);
    printf ("\n");
    printf ("max: %d \n", extremmax);
    printf ("min: %d \n", extremmin);

    return 0;
}
// 12419 cycles