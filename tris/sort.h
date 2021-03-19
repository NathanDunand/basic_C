#include "base.h"

void print_tab(s_data_t tab[], int tab_size);

void bubble_sort(s_data_t tab[], int tab_size);

void insertion_sort(s_data_t tab[], int tab_size);

void selection_sort(s_data_t tab[], int tab_size);

void heap_sort(s_data_t tab[ ], int tab_size);

void quick_sort(s_data_t tab[], int lower, int upper);

int delete_max(s_data_t tab[], int tab_size);

void tab2heap(s_data_t tab[], int tab_size);

void swap_down(s_data_t tab[], int tab_size, int pos);

int split(s_data_t tab[], int deb, int fin);