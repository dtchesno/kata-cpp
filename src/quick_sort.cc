/*
 * quick_sort.cc
 *
 *  Created on: Feb 5, 2016
 *      Author: dmitry
 */

int partition(int *data, int start, int end);
void swap(int *data, int i, int j);

void qsort(int *data, int start, int end) {
    if (start < end) {
        int p = partition(data, start, end);
        qsort(data, start, p - 1);
        qsort(data, p, end);
    }
}

int partition(int *data, int start, int end) {
    //return end;
    int pivot = data[end];
    int i = start;
    for (int j = start; j < end; j++) {
        if (data[j] <= pivot) {
            swap(data, i, j);
            i++;
        }
    }
    swap(data, i, end);
    return i;
}

void swap(int *data, int i, int j) {
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}
