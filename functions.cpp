#include "functions.h"


void findSameElements(int* Arr1, int size1, int* Arr2, int size2) 
{

	int k = 0;
        int m = 0;
        int n = 0;
        int p = 0;
        int temp = 0;
        int counter = 0;
        int comp = 0;
        int comp_1 = 0;

        for (int i = 0; i < size1 - 1; i++) {
            for (int j = 0; j < size1 - i - 1; j++) {
                if (Arr1[j] > Arr1[j + 1]) {
                    temp = Arr1[j];
                    Arr1[j] = Arr1[j + 1];
                    Arr1[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < size2 - 1; i++) {
            for (int j = 0; j < size2 - i - 1; j++) {
                if (Arr2[j] > Arr2[j + 1]) {
                    temp = Arr2[j];
                    Arr2[j] = Arr2[j + 1];
                    Arr2[j + 1] = temp;
                }
            }
        }

        int* Arr_comp = new int[size1 * size2];
        int* Arr_count = new int[size1 * size2];

        int j = 0;

        for (int i = 0; i < size1 * size2; i++) {
            Arr_comp[i] = 0;
            Arr_count[i] = 0;
        }
        
        for (int i = 0; i < size1; i++) {
            counter = 0;
            comp = 0;
            comp_1 = 0;
            for (int j = 0; j < size2; j++) {
                if (Arr1[i] == Arr2[j]) {
                    if (comp == 0) {
                        Arr_comp[k] = Arr1[i];
                        k++;
                        counter++;
                        comp = 1;
                    }
                    if ((j != size2 - 1) && (Arr2[j] == Arr2[j + 1])) {
                        counter++;
                    }
                    Arr_count[m] = counter;
                    comp_1 = 1;
                }
                if ((j != size2 - 1) && (Arr2[j] != Arr2[j + 1])) {
                    comp = 0;
                    counter = 0;
                }
            }
            if (i == size1 - 1) {
                Arr_count[m] = counter;
            }
            if (comp_1 == 1) {
                m++;
            }
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < m - i - 1; j++) {
                if (Arr_comp[j] == Arr_comp[j + 1]) {
                    Arr_comp[j + 1] = Arr_comp[j + 2];
                    Arr_count[j] = Arr_count[j] + Arr_count[j + 1];
                    Arr_count[j + 1] = 0;
                } 
            }          
        }
	
	
	delete[] Arr_comp;
        delete[] Arr_count;
    return 0;
	

}

//TODO: it's better to write additional functions which help solve the task 
