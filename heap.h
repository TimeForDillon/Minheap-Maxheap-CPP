/*******************************************************************************
* AUTHOR       : Dillon Welsh, Nathan Cheung
* LAB 6        : HEAPS
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/29/2021
*******************************************************************************/

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>       // Provides string type, copy
#include <cassert>

/*******************************************************************************
* CLASS MinHeapComparator
*_______________________________________________________________________________
* This class is a comparator for min heaps
*******************************************************************************/
template <typename E>
class MinHeapComparator
{
public:
    bool operator()(E& left, E& right)
    {
        if(left < right)
            return true;
        return false;
    };
};

/*******************************************************************************
* CLASS MaxHeapComparator
*_______________________________________________________________________________
* This class is a comparator for max heaps
*******************************************************************************/
template <typename E>
class MaxHeapComparator
{
public:
    bool operator()(E& left, E& right)
    {
        if(left > right)
            return true;
        return false;
    };
};

template <typename E, typename C>               // element and comparator
class Heap {                           			// heap interface
public:
    /******************************
     * CONSTRUCTORS & DESTRUCTORS *
     ******************************/
    Heap();                                	// default constructor
    Heap(const Heap<E,C>& source);     		// copy constructor
    Heap(E* arr, size_t len);     			// copy constructor
    ~Heap();                               	// destructor

    /************
     * MUTATORS *
     ************/
    void insert(E value);       			// insert new data
    void insert(E* arr, size_t len);        // insert new data
    E remove();              				// remove root data

    /*************
     * ACCESSORS *
     *************/
    E peek();								// retrieve but don't remove root data
    int size() const;                       // retrieve size
    bool is_empty() const;                  // returns true if empty
    void to_string() const;                 // outputs heap
    Heap<E,C>& operator=(const Heap<E,C>& source);  // overloaded assignment operator
private:
    /************
     * MUTATORS *
     ************/
    void expand();							// resize the array
    size_t get_parent_node(size_t index);   // Gets the parent node of index
    size_t get_left_node(size_t index);     // Gets left node
    size_t get_right_node(size_t index);    // Gets right node

private:
    E* data;                // IN/OUT - pointer to the array of E
    size_t used;            // IN/OUT - how many E is used for data
    size_t allocated;       // IN/OUT - how many E was allocated for data
    C comparator;           // IN/OUT - instance of the comparator
};

/*******************************************************************************
* CONSTRUCTOR Heap
*_______________________________________________________________________________
* This constructs an empty heap
*******************************************************************************/
template <typename E, typename C>
Heap<E,C>::Heap()
{
    data = new E[20];
    used = 0;
    allocated = 20;
}

/*******************************************************************************
* CONSTRUCTOR Heap
*_______________________________________________________________________________
* This constructs an empty heap
*******************************************************************************/
template <typename E, typename C>
Heap<E,C>::Heap(const Heap<E,C>& source)
{
    data = new E[source.allocated];
    used = source.used;
    allocated = source.allocated;
    // Already existing heap should already be sorted, so just copy over.
    std::copy(source.data, source.data+used, data);
}

/*******************************************************************************
* CONSTRUCTOR Heap
*_______________________________________________________________________________
* This constructs an empty heap
*******************************************************************************/
template <typename E, typename C>
Heap<E,C>::Heap(E* arr, size_t len)
{
    data = new E[20];
    used = 0;
    allocated = 20;

    insert(arr, len);
}

/*******************************************************************************
* DESTRUCTOR Heap
*_______________________________________________________________________________
* This destructs a heap
*******************************************************************************/
template <typename E, typename C>
Heap<E,C>::~Heap()
{
    delete[] data;
}

/*******************************************************************************
* MUTATOR Insert
*_______________________________________________________________________________
* This inserts a piece of data into the heap
*******************************************************************************/
template <typename E, typename C>
void Heap<E,C>::insert(E value)
{
    size_t parent_i, i;
    E temp;

    if(used == 0)
    {
        data[0] = value;
        used += 1;
        return;
    }

    if(used == allocated)
        expand();
    i = used;
    data[used++] = value;

    while(i > 0)
    {
        parent_i = get_parent_node(i);

        // Check parent.
        if(!comparator(data[i], data[parent_i]))
            break;

        temp = data[parent_i];
        data[parent_i] = data[i];
        data[i] = temp;

        i = parent_i;
    }
}

/*******************************************************************************
* MUTATOR Insert
*_______________________________________________________________________________
* This inserts a piece of data into the heap
*******************************************************************************/
template <typename E, typename C>
void insert(E* arr, size_t len)
{
    size_t i;

    for(i = 0; i < len; i++)
        insert(arr[i]);
}

/*******************************************************************************
* MUTATOR Remove
*_______________________________________________________________________________
* This removes a piece of data from the heap
*******************************************************************************/
template <typename E, typename C>
E Heap<E,C>::remove()
{
    size_t i, left_i, right_i, target;
    E root, temp;

    assert(!is_empty());

    root = data[0];
    used--;
    data[0] = data[used];
    i = 0;
    left_i = get_left_node(i);
    right_i = get_right_node(i);
    while(left_i < used)
    {
        // Init target.
        target = left_i;
        // Both children exist, check right_i.
        if(right_i < used && comparator(data[right_i], data[left_i]))
            target = right_i;

        temp = data[i];
        data[i] = data[target];
        data[target] = temp;
        i = target;
        left_i = get_left_node(i);
        right_i = get_right_node(i);
    }
    return root;
}

/*******************************************************************************
* ACCESSOR Peak
*_______________________________________________________________________________
* This returns the data at the root of the heap
*******************************************************************************/
template <typename E, typename C>
E Heap<E,C>::peek()
{
    return data[0];
}

/*******************************************************************************
* ACCESSOR Size
*_______________________________________________________________________________
* This returns the size of the heap
*******************************************************************************/
template <typename E, typename C>
int Heap<E,C>::size() const
{
    return used;
}

/*******************************************************************************
* ACCESSOR is_empty
*_______________________________________________________________________________
* This returns true if the heap is empty
*******************************************************************************/
template <typename E, typename C>
bool Heap<E,C>::is_empty() const
{
    return used == 0;
}

/*******************************************************************************
* ACCESSOR to_string
*_______________________________________________________________________________
* This outputs the heap
*******************************************************************************/
template <typename E, typename C>
void Heap<E,C>::to_string() const
{
    for(int i = 0; i < this->used; i++)
    {
        std::cout << this->data[i] << " ";
    }
}

/*******************************************************************************
* MUTATOR expand
*_______________________________________________________________________________
* This expands the allocated size of the heap
*******************************************************************************/
template <typename E, typename C>
void Heap<E,C>::expand()
{
    E* old_data;

    allocated *= 20;
    old_data = data;

    data = new E[allocated];
    std::copy(old_data, old_data+used, data);

    delete[] old_data;
}

/*******************************************************************************
* MUTATOR get_parent_node
*_______________________________________________________________________________
* This returns the parent node of the heap
*******************************************************************************/
template <typename E, typename C>
size_t Heap<E,C>::get_parent_node(size_t index)
{
    size_t i, depth, depth_start;

    // Get current depth
    for(i = 1, depth = 0; i-1 <= index; i*=2, depth++);

    // Calculate current depth start
    for(i = 2, depth_start = 2; i < depth; i++, depth_start*=2);
    depth_start -= 1;

    // Divide by 2 to get previous depth row index
    index = (index - depth_start) / 2;

    // Calculate previous depth start
    depth_start = (depth_start + 1) / 2 - 1;
    index += depth_start;

    return index;
}

/*******************************************************************************
* MUTATOR get_left_node
*_______________________________________________________________________________
* This returns the left node of the heap
*******************************************************************************/
template <typename E, typename C>
size_t Heap<E,C>::get_left_node(size_t index)
{
    size_t i, depth, depth_start;

    // Get current depth
    for(i = 1, depth = 0; i-1 <= index; i*=2, depth++);

    // Calculate current depth start
    for(i = 2, depth_start = 2; i < depth; i++, depth_start*=2);
    depth_start -= 1;

    // Divide by 2 to get previous depth row index
    index = (index - depth_start) * 2;

    // Calculate next depth start
    depth_start = (depth_start + 1) * 2 - 1;
    index += depth_start;

    return index;
}

/*******************************************************************************
* MUTATOR get_right_node
*_______________________________________________________________________________
* This returns the right node of the heap
*******************************************************************************/
template <typename E, typename C>
size_t Heap<E,C>::get_right_node(size_t index)
{
    return get_left_node(index) + 1;
}

/*******************************************************************************
* ACCESSOR operator=
*_______________________________________________________________________________
* This overrides the assignment operator
*******************************************************************************/
template <typename E, typename C>
Heap<E,C>& Heap<E,C>::operator=(const Heap<E,C>& source)
{
    while(allocated < source.used)
        expand();

    std::copy(source.data, source.data+source.used, data);
    used = source.data;

    return this;
}

#endif // HEAP_H
