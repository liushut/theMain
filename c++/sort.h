#pragma once
#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;
#define MAX 10
void swap_Sort(int*a, int*b);
void BubbleSort(int arrpp[], int length);
void PrintAaary(int arr[], int length);
void ChanceSort(int arr[],int len);
void InsetSort(int a[], int len);
void HierSort(int a[], int len);
void QuickSort(int a[], int len);
int*CreateArr();
void MergeSort(int a[], int start, int end, int *temp);
void Merge(int a[],int start,int end,int mid, int*temp);
void HeapSort(int a[], int len);