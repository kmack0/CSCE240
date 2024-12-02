// Copyright 2024 Kristen Mack
#include"program3functions.h"
#include"checkArraysMatch.h"
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int CountAboveAv(const double nums[][kCols], int rows) {
double mean = 0.0;
int num = 0;
int num_larger = 0;
  for ( int i = 0; i < rows; ++i ) {
    for ( int j = 0; j < kCols; ++j ) {
      mean += nums[i][j];
      num++;
    }
  }
mean = mean / num;
  // count how many nums are greater than mean
  for ( int i = 0; i < rows; ++i ) {
    for ( int j = 0; j < kCols; ++j ) {
      if ( nums[i][j] > mean )
        num_larger++;
    }
  }
return num_larger;
}

void BubbleSort(double n[], int size) {
  for ( int go_to = size - 1; go_to > 0; --go_to ) {
    for ( int i = 0; i < go_to; ++i ) {
      if ( n[i] > n[i+1] ) {
        double temp = n[i];
        n[i] = n[i+1];
        n[i+1] = temp;
      }
    }
  }
}

void SortByCol(double nums[][kCols], int rows, int sortCol, bool order) {
  for ( int i = 0; i < rows - 1; ++i ) {
    for ( int j = 0; j < rows - i - 1; ++j ) {
      bool which_way;
      if ( order == true ) {
        which_way = (nums[j][sortCol] > nums[j+1][sortCol]);
      } else {
        which_way = (nums[j][sortCol] < nums[j+1][sortCol]);
      }
      if ( which_way == true ) {
        for ( int k = 0; k < kCols; ++k ) {
          double temp = nums[j][k];
          nums[j][k] = nums[j+1][k];
          nums[j+1][k] = temp;
        }
      }
    }
  }
}

void SortByRow(double nums[][kCols], int rows, int sortRow, bool order) {
  for ( int i = 0; i < kCols; ++i ) {
    for ( int j = 0; j < kCols - i - 1; ++j ) {
        bool which_way;
       if ( order == true ) {
         which_way = nums[sortRow][j] > nums[sortRow][j+1];
       } else {
         which_way = nums[sortRow][j] < nums[sortRow][j+1];
       }
       if ( which_way == true ) {
         for ( int k = 0; k < rows; ++k ) {
          double temp = nums[k][j];
          nums[k][j] = nums[k][j+1];
          nums[k][j+1] = temp;
        }
      }
    }
  }
}


double MedianInCol(const double nums[][kCols], int rows, int col_to_examine) {
int kRow = rows;
double find_median[kRow];
  for ( int i = 0; i < rows; ++i )
    find_median[i] = nums[i][col_to_examine];
  // sort to find median
  BubbleSort(find_median, rows);
  int med = rows / 2;
  if ( med % 2 == 1 ) {
    return find_median[med];
  } else {
    double add_med = find_median[med] + find_median[med - 1];
    add_med = add_med / 2;
    return add_med;
  }
}


int ModeInCol(const double nums[][kCols], int rows, int col_to_examine,
             double found_mode[kMode]) {
  int kRows = rows;
  int count = 0;
  int modes = 0;
  int find_mode[kRows];
  double mult_occurence[kRows];
  for ( int i = 0; i < rows; ++i ) {
    find_mode[i] = 0;
    mult_occurence[i] = nums[i][col_to_examine];
  }
  for ( int i = 0; i < rows; ++i ) {
    for ( int j = 0; j < rows; ++j ) {
      if ( nums[i][col_to_examine] == mult_occurence[j] ) {
        find_mode[j]++;
        break;
      }
    }
  }
  for ( int i = 0; i < rows; ++i ) {
    if ( find_mode[i] > count ) {
      count = find_mode[i];
    }
  }
  for ( int i = 0; i < rows; ++i ) {
    if ( find_mode[i] == count ) {
      if ( modes < 2 ) {
        found_mode[modes] = mult_occurence[i];
        modes++;
      } else {
        // if there are no modes found
        found_mode[0] = -1;
        found_mode[1] = -1;
        return 0;
      }
    }
  }

  return modes;
}
