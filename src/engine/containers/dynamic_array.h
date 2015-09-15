// dynamic_array.h
#ifndef INCLUDED_DYNAMIC_ARRAY
#define INCLUDED_DYNAMIC_ARRAY

#include <iostream>
#include <stdexcept>
#include "counting_allocator.h"

namespace StevensDev
{
namespace sgdc
{

template <class T>
class DynamicArray
{
  private:
    T* d_array;
    sgdm::iAllocator<T> *d_alloc;
    int d_endIndex; // actual index of last valid element
    int d_capacity;

    
    void reallocate();
      // reallocates memory, adding 5 to capacity
    
  public:
    // CONSTRUCTORS
    DynamicArray();
      // default constructor
    DynamicArray( const DynamicArray<T> &copy );
      // copy constructor
    DynamicArray( sgdm::iAllocator<T>* alloc );
      // pointer to an allocator for use with memory

    // DESTRUCTOR
    ~DynamicArray();

    // OPERATORS
    T operator[]( int index );
      // sets an element, undefined behavior if out of bounds
    const T operator[]( int index ) const;
      // retrieves an element, undefined behavior if out of bounds
    DynamicArray<T>& operator= ( const DynamicArray<T>& other );
      // assignment operator    
    
    // MUTATORS
    void push( const T& element );
      // adds element to end of collection, grow
    void pushFront( T element );
      // pushes to the front of the collection, grow, shift
    T pop();
      // removes and retrieves the last ele ment, shifts
    T popFront();
      // removes and retrieves the first element, shifts
    unsigned int const getLength() const;
      // number of elements contained
    T const at( unsigned int index ) const;
      // retrieves an element at a location, throws if out of bounds
    T removeAt( unsigned int index );
      // removes, throws if invalid, shifts
    void insertAt( T element, unsigned int index );
      // can grow, shifts
};

// FREE OPERATORS
template<class T>
inline
std::ostream& operator<<( std::ostream& stream, const DynamicArray<T>& array)
{
    stream << "\"DynamicArray\":[";
    for( int i = 0; i < array.getLength(); i++ )
    {
        stream << "\n\t{\"DynamicArray[" << i << "]\":\"" << array.at( i ) << "\"}";
        if( i != array.getLength() - 1 )
        {
            stream << ",";
        }
    }
    stream << "\n]";
    return stream;
}

// OPERATORS
template<class T>
inline
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray<T>& other)
{
    if( this != &other )
    {
        if( this.d_array[ 0 ] != NULL )
        {
            //this.d_alloc->release( this.d_array, this.d_capacity );
        }
        DynamicArray<T> newArray ( other );
        return newArray;
    }
    else 
        return *this;
}

// CONSTRUCTORS
template <class T>
inline
DynamicArray<T>::DynamicArray()
{
    d_array = d_alloc->get(5); // base capacity of 5
    d_endIndex = -1;
    d_capacity = 5;
}

template <class T>
inline
DynamicArray<T>::DynamicArray( const DynamicArray<T> &copy )
{
    if( d_array != 0 )
    {
        //delete d_array;
    }
    d_array = copy.d_array; // not sure if right
    d_alloc = copy.d_alloc;
    d_endIndex = copy.d_endIndex;
    d_capacity = copy.d_capacity;
}

template <class T>
inline
DynamicArray<T>::DynamicArray( sgdm::iAllocator<T>* alloc )
{
    d_alloc = alloc;
    d_array = d_alloc->get(5); // base capacity of 5
    d_endIndex = -1;
    d_capacity = 5;
}

// DESTRUCTOR
template <class T>
inline
DynamicArray<T>::~DynamicArray()
{
    d_alloc->release( d_array, d_capacity );

}

template <class T>
inline
void DynamicArray<T>::push( const T& element )
{
    // check if at capacity
    if( d_endIndex == d_capacity - 1 )
    {
        reallocate();
    }
    d_array[ d_endIndex + 1 ] = element;
    d_endIndex++;
}

template <class T>
inline
void DynamicArray<T>::pushFront( T element )
{
    // check if at capacity
    if( d_endIndex == d_capacity - 1 )
    {
        reallocate();
    }
    
    // shift
    for( int i = 0; i < d_endIndex; i++ )
    {
        d_array[ i + 1 ] = d_array[ i ];
    }
    
    // change first index to element
    d_endIndex++;
    d_array[0] = element;
}

template <class T>
inline
T DynamicArray<T>::pop()
{
    T element = d_array[ d_endIndex ];
    d_array[ d_endIndex ] = 0;
    d_endIndex--;
    return element;
}

template <class T>
inline
T DynamicArray<T>::popFront()
{
    T element = d_array[ 0 ];
    for( int i = 1; i <= d_endIndex; i++ )
    {
        d_array[ i - 1 ] = d_array[ i ];
    }
    d_array[ d_endIndex ] = 0;
    d_endIndex--;
    return element;
}

template <class T>
inline
unsigned int const DynamicArray<T>::getLength() const
{
    return ( d_endIndex + 1 );
}

template <class T>
inline
T const DynamicArray<T>::at( unsigned int index ) const
{
    if( index > d_endIndex )
    {
        throw std::out_of_range ("out of range");
    }
    else
    {
        return d_array[ index ];
    }
}

template <class T>
inline
T DynamicArray<T>::operator[]( int index )
{
    return d_array[ index ];
}

template <class T>
inline
T const DynamicArray<T>::operator[]( int index ) const
{
    return d_array[ index ];
}


template <class T>
inline
T DynamicArray<T>::removeAt( unsigned int index )
{
    if( index > d_endIndex )
    {
        throw std::out_of_range ("out of range");
    }

    T element = d_array[ index ];
    for( int i = index + 1; i < d_endIndex; i++ )
    {
        d_array[ i - 1 ] = d_array[ i ];
    }
    d_array[ d_endIndex ] = 0;
    d_endIndex--;
    return element;
}

template <class T>
inline
void DynamicArray<T>::insertAt( T element, unsigned int index )
{
    if( d_endIndex == d_capacity - 1 )
    {
        reallocate();
    }

    for( int i = index; i < d_endIndex; i++ )
    {
        d_array[ index + 1 ] = d_array[ index ];
    }
    
    d_array[ index ] = element;
}

template <class T>
inline
void DynamicArray<T>::reallocate()
{
    T* newArray = d_alloc->get( d_capacity + 5 ); // allocate new memory
    for( int i = 0; i < d_capacity; i++ ) // copy values to new array
    {
        newArray[ i ] = d_array[ i ];
    }
    d_alloc->release(d_array, d_capacity); // release old memory
    d_array = newArray; // point d_alloc to the new array memory
    d_capacity += 5; // add five to capacity
}

} // End sgdc namespace
} // End StevensDev namespace

#endif
