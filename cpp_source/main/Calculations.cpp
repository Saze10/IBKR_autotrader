#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>

#include "Calculations.h"

float MacD(long n) { 
    FILE* data_file;
    data_file = fopen("historicaldata.txt", "r");

    float sum = 0;
    long offset = 0;
    long k = 25;
    for(long i = 0; i < n; i++) {
        fseek(data_file, k, SEEK_END);
        char curr_char = 'v';
        while(curr_char != '\n') {
            curr_char = (char) fgetc(data_file);
            fseek(data_file, k, SEEK_END);
            k++;
        }
        k++;
        fseek(data_file, k, SEEK_END);
        float open, high, low, close;
        fscanf(data_file, "Open:%f,High:%f,Low%f,Close:%f", &open, &high, &low, &close);
        fseek(data_file, k+1, SEEK_END);
        sum += (close - open);
    }

    fclose(data_file);
    return sum/n;
}









