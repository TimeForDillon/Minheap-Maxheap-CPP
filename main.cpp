/*******************************************************************************
* AUTHOR       : Dillon Welsh, Nathan Cheung
* LAB 6        : HEAPS
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/29/2021
*******************************************************************************/

#include <iostream>

#include "heap.h"

using namespace std;

int main() {
    Heap<int,MinHeapComparator<int>> minheap;
    Heap<int,MaxHeapComparator<int>> maxheap;

    cout << "Instantiating minheap with values 1 - 20..." << endl;
    for(int i = 1; i < 20; i++)
        minheap.insert(i);

    cout << "Outputting minheap: ";
        minheap.to_string();
    cout << endl;

    cout << "Inserting number 67 into minheap..." << endl;
        minheap.insert(67);
    cout << "Outputting minheap: ";
        minheap.to_string();
    cout << endl;
    cout << "Inserting number 88 into minheap..." << endl;
        minheap.insert(88);
    cout << "Outputting minheap: ";
        minheap.to_string();
    cout << endl;
    cout << "Inserting number 77 into minheap..." << endl;
        minheap.insert(77);
    cout << "Outputting minheap: ";
        minheap.to_string();
    cout << endl;
    cout << "Inserting number 52 into minheap..." << endl;
        minheap.insert(52);
    cout << "Outputting minheap: ";
        minheap.to_string();
    cout << endl;
    cout << "Inserting number 44 into minheap..." << endl;
        minheap.insert(44);
    cout << "Outputting minheap: ";
        minheap.to_string();
    cout << endl;
    cout << "Inserting number 11 into minheap..." << endl;
        minheap.insert(11);
    cout << "Outputting minheap: ";
        minheap.to_string();
    cout << endl;
    cout << "Inserting number 66 into minheap..." << endl;
        minheap.insert(66);
    cout << "Outputting minheap: ";
        minheap.to_string();
    cout << endl;
    cout << "Inserting number 93 into minheap..." << endl;
        minheap.insert(93);
    cout << "Outputting minheap: ";
        minheap.to_string();
    cout << endl << endl;

    cout << "Instantiating maxheap with values 1 - 20..." << endl;
    for(int i = 1; i < 20; i++)
        maxheap.insert(i);

    cout << "Outputting maxheap: ";
        maxheap.to_string();
    cout << endl;

    cout << "Inserting number 67 into maxheap..." << endl;
        maxheap.insert(67);
    cout << "Outputting maxheap: ";
        maxheap.to_string();
    cout << endl;
    cout << "Inserting number 88 into maxheap..." << endl;
        maxheap.insert(88);
    cout << "Outputting maxheap: ";
        maxheap.to_string();
    cout << endl;
    cout << "Inserting number 77 into maxheap..." << endl;
        maxheap.insert(77);
    cout << "Outputting maxheap: ";
        maxheap.to_string();
    cout << endl;
    cout << "Inserting number 52 into maxheap..." << endl;
        maxheap.insert(52);
    cout << "Outputting maxheap: ";
        maxheap.to_string();
    cout << endl;
    cout << "Inserting number 44 into maxheap..." << endl;
        maxheap.insert(44);
    cout << "Outputting maxheap: ";
        maxheap.to_string();
    cout << endl;
    cout << "Inserting number 11 into maxheap..." << endl;
        maxheap.insert(11);
    cout << "Outputting maxheap: ";
        maxheap.to_string();
    cout << endl;
    cout << "Inserting number 66 into maxheap..." << endl;
        maxheap.insert(66);
    cout << "Outputting maxheap: ";
        maxheap.to_string();
    cout << endl;
    cout << "Inserting number 93 into maxheap..." << endl;
        maxheap.insert(93);
    cout << "Outputting maxheap: ";
        maxheap.to_string();
    cout << endl;
}
