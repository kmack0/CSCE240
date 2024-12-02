// Copyright 2024 Kristen Mack
#ifndef PROGRAMFUNCTIONS3_H_
#define PROGRAMFUNCTIONS3_H_

const int kCols = 10;
const int kMode = 2;
int CountAboveAv(const double nums[][kCols], int rows);

void BubbleSort(double n[], int size);

void SortByCol(double nums[][kCols], int rows, int sortCol,
              bool order);

void SortByRow(double nums[][kCols], int rows, int sortRow,
                bool order);

double MedianInCol(const double nums[][kCols], int rows, int col_to_examine);

int ModeInCol(const double nums[][kCols], int rows, int col_to_examine,
                double found_mode[kMode]);

#endif
