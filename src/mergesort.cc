/*
 * mergesort.cc
 *
 *  Created on: Feb 12, 2016
 *      Author: dmitry
 */

#include <string.h>

void mergesort(int *data, int start, int end, int *tempBuf);
void merge(int *data, int start, int end, int mid, int *tempBuf);

void mergesort(int *data, int size) {
    int *pTempBuf = new int[size];
    mergesort(data, 0, size - 1, pTempBuf);
    delete[] pTempBuf;
}

void mergesort(int *data, int start, int end, int *tempBuf) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergesort(data, start, mid, tempBuf);
        mergesort(data, mid + 1, end, tempBuf);
        merge(data, start, end, mid, tempBuf);
    }
}

void merge(int *data, int start, int end, int mid, int *tempBuf) {
    int i = start;
    int j = mid + 1;
    int k = start;
    while (i <= mid && j <= end) {
        if (data[i] <= data[j]) {
            tempBuf[k++] = data[i++];
        } else {
            tempBuf[k++] = data[j++];
        }
    }
    while (i <= mid) {
        tempBuf[k++] = data[i++];
    }
    while (j <= end) {
        tempBuf[k++] = data[j++];
    }
    memcpy(data + start, tempBuf + start, (end - start + 1) * sizeof(*data));
}
