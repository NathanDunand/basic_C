#include "base.h"
#include "sort.h"
#include <stdio.h>

void print_tab(s_data_t tab[], int tab_size)
{
	for(int i=0;i<tab_size;i++) {
		print(tab[i]);
	}
}

void bubble_sort(s_data_t tab[], int tab_size)
{
	for(int i=tab_size-1;i>=0;i--) {
		for(int j=0; j<i;j++) {
			if(tab[j+1]<tab[j]) {
				int temp=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=temp;
			}
		}
	}
}

void insertion_sort(s_data_t tab[], int tab_size) 
{
	for(int i=1;i<tab_size;i++) {
		int x=tab[i];
		int j=i;
		while(j>0 && tab[j-1]>x) {
			tab[j]=tab[j-1];
			j--;
		}
		tab[j]=x;
	}
}

void selection_sort(s_data_t tab[], int tab_size) 
{
	for(int i=0;i<tab_size-1;i++) {
		int min=i;
		for(int j=i+1;j<tab_size;j++) {
			if(tab[j]<tab[min]) {
				min=j;
			}
		}
		if(min!=i) {
			int temp=tab[i];
			tab[i]=tab[min];
			tab[min]=temp;
		}
	}
}

void heap_sort(s_data_t tab[ ], int tab_size) 
{
	int N=tab_size;
	tab2heap(tab,tab_size);
	for(int i=0;i<N;i++) {
		int temp=delete_max(tab,N);
		tab[N-1]=temp;
		N--;
	}
}

int delete_max(s_data_t tab[], int tab_size)
{
	int max=tab[0];
	tab[0]=tab[tab_size-1];
	tab_size=tab_size-1;
	swap_down(tab,tab_size,0);
	return max;
}

void tab2heap(s_data_t tab[], int tab_size)
{
	for(int i=(tab_size/2)-1;i>=0;i--) {
		swap_down(tab,tab_size,i);
	}
}

void swap_down(s_data_t tab[], int tab_size, int pos)
{
	int posMax=0;
	if(pos<tab_size/2) {
		int fg=2*pos+1;
		int fd=2*pos+2;

		if(fd<tab_size) {
			if(tab[fg]>tab[fd]) {
				posMax=fg;
			} else {
				posMax=fd;
			}
		} else {
			posMax=fg;
		}
		if(tab[pos]<tab[posMax]) {
			int temp=tab[pos];
			tab[pos]=tab[posMax];
			tab[posMax]=temp;
			swap_down(tab,tab_size,posMax);
		}
	}

}

void quick_sort(s_data_t tab[], int lower, int upper)
{
	if(lower<upper) {
		int pivot=split(tab, lower, upper);
		quick_sort(tab,lower,pivot);
		quick_sort(tab,pivot+1,upper);
	}
}

int split(s_data_t tab[], int deb, int fin)
{
	int val=tab[deb];
	int gauche=deb-1;
	int droite=fin+1;
	while(gauche<droite) {
		gauche++;
		while(tab[gauche]<val) {
			gauche++;
		}
		droite--;
		while(tab[droite]>val) {
			droite--;
		}
		if(gauche<droite) {
			int temp=tab[gauche];
			tab[gauche]=tab[droite];
			tab[droite]=temp;
		}
	}
	return droite;
}