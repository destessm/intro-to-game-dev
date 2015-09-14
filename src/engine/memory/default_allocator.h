// default_allocator.h
#ifndef INCLUDED_DEFAULT_ALLOCATOR
#define INCLUDED_DEFAULT_ALLOCATOR

#include <iostream>
#include <assert.h>
#include "iallocator.h"

namespace StevensDev
{
namespace sgdm
{

template <class T>
class DefaultAllocator: public iAllocator<T>
{
  public:
    // CONSTRUCTORS
    DefaultAllocator();
      // Default constructor
    DefaultAllocator( const DefaultAllocator<T>& );
      // Copy constructor

    // DESTRUCTOR
    ~DefaultAllocator();

    // MUTATORS (?)
    T* get( int count );
      // Allocates enough memory for count number of Ts
    void release( T* pointer, int count);
      // Releases the memory in ptr, which should be size count.
};

// FREE OPERATORS
template<class T>
inline
std::ostream& operator<<( std::ostream& stream, const DefaultAllocator<T> )
{
    return stream << "{ allocator }";
}

// CONSTRUCTORS
template<class T>
inline
DefaultAllocator<T>::DefaultAllocator() 
{

}

template<class T>
inline
DefaultAllocator<T>::DefaultAllocator( const DefaultAllocator<T>& )
{
    
}

// DESTRUCTOR
template<class T>
inline
DefaultAllocator<T>::~DefaultAllocator()
{

}

// MUTATORS
template<class T>
inline
T* DefaultAllocator<T>::get( int count )
{
    return new T[count];
}

template<class T>
inline
void DefaultAllocator<T>::release( T* pointer, int count )
{
    assert( pointer != 0 );
/*
    for( int i = 0; i < count; i++ )
    {
        assert( pointer[i] != 0 );
        delete pointer[i];
    }*/
    delete pointer;
}

} // End sgdm namespace
} // End StevensDev namespace

#endif
