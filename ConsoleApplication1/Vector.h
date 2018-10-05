/* Author: Anderson Taylor
 * Date: 10/4/2018
 * File: Vector.h
 * Description: Header file and implementation of the templated Vector class.
 */
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <typename T>
class Vector {
    private:
        T *elements;
        int size, capacity;

    public:
        Vector();
        /*
        * Description:
        *      Creates a new Vector with default values (0 elements).
        *
        * Inputs:
        *
        * Return:
        *      n/a
        */
		Vector(const Vector &toCopy);
		/*
		* Description:
		*    Copy constructor.  Initializes a dynamic array of the appropriate
		*    size/capacity and copies data from other's array to the new array.
		*
		* Parameters:
		*    other - a constant reference to the vector that is to be copied.
		*
		* Post-conditions:
		*    vec_ptr is initialized, and its array contains other.vec_ptr's data,
		*    vec_size=other.vec_size, and vec_capacity=other.vec_capacity.
		*/
        ~Vector();
        /*
        * Description:
        *      Deletes the dynamic memory used.
        *
        * Inputs:
        *
        * Return:
        *      n/a
        */
        void push_back(T value);
        /*
        * Description:
        *      Pushes a new value onto the end of the Vector.
        *
        * Inputs:
        *      T value
        *          The value to push.
        *
        * Return:
        *      n/a
        */
        T &operator[](int index);
        /*
        * Description:
        *      Accesses the value at index and can modify it.
        *
        * Inputs:
        *      int index
        *          The index of the value to access.
        *
        * Return:
        *      T - value stored at the index.
        */
        Vector<T> &operator=(const Vector<T>& toCopy);
        /*
        * Description:
        *      Creates a deep copy of the Vector on the rhs and assigns it to the Vector on the left.
        *
        * Inputs:
        *      const Vector<T>& toCopy
        *          The Vector to be copied.
        *
        * Return:
        *      Vector<T> & - Returns a dereferenced pointer to the new Vector.
        */
        void resize();
        /*
        * Description:
        *      Doubles the capacity of an Vector.
        *
        * Inputs:
        *
        * Return:
        *      n/a
        */
		int vec_size();
		/*
		* Description:
		*      Returns the size of the Vector.
		*
		* Inputs:
		*
		* Return:
		*      int - the total used elements of the vector.
		*/
		int vec_capacity();
		/*
		* Description:
		*      Returns the capacity of the Vector.
		*
		* Inputs:
		*
		* Return:
		*      int - the total capacity of the vector.
		*/
};

template <typename T>
Vector<T>::Vector()
{
    elements = new T[0];
    capacity = 0;
	size = 0;
}

template <typename T>
Vector<T>::Vector(const Vector &toCopy)
{
	capacity = toCopy.capacity;
	size = toCopy.size;
	elements = new T[capacity];

	for (int i = 0; i < toCopy.size; i++)
	{
		elements[i] = toCopy.elements[i];
	}
}

template <typename T>
Vector<T>::~Vector()
{
	size = 0;
	capacity = 0;
    delete [] elements;
}

template <typename T>
void Vector<T>::push_back(T value)
{
    if(size == capacity)
    {
		resize();		
		elements[size] = value;
		size++;

	}else{
        elements[size] = value;
		size++;
    }
}

template <typename T>
T& Vector<T>::operator[](int index)
{
    if(index >= capacity || index < ((capacity * -1) + 1))
    {
        throw "Index Out of Bounds";
    }

    if(index < 0)
    {
        return elements[capacity - (index * -1)];
    }

    return elements[index];
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T>& toCopy)
{
    delete [] elements;
    capacity = toCopy.capacity;
	size = toCopy.size;
    elements = new T [capacity];

    for(int i = 0; i < toCopy.size; i++)
    {
        elements[i] = toCopy.elements[i];
    }
    return *this;
}

template <typename T>
void Vector<T>::resize()
{
    T *tempElements;
	if (capacity == 0) {
		tempElements = new T[(1)];
	}
	else {
		tempElements = new T[(capacity * 2)];
	}

    for(int i = 0; i < size; i++)
    {
        tempElements[i] = elements[i];
    }

    delete [] elements;

    elements = tempElements;

	if (capacity == 0) {
		capacity = 1;
	}
	else {
		capacity *= 2;
	}
}

template <typename T>
int Vector<T>::vec_capacity()
{
	return capacity;
}

template <typename T>
int Vector<T>::vec_size()
{
	return size;
}

#endif // VECTOR_H
