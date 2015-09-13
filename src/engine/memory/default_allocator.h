// default_allocator.h
#ifndef INCLUDED_DEFAULT_ALLOCATOR
#define INCLUDED_DEFAULT_ALLOCATOR

#include <iostream>
#include <assert.h>
#include "iAllocator.h"

namespace StevensDev
{
namespace sgdm
{

template <class T>
class DefaultAllocator: public iAllocator
{
  public:
    // CONSTRUCTORS
    DefaultAllocator();
      // Default constructor
    DefaultAllocator( DefaultAllocator copy );
      // Copy constructor

    // DESTRUCTOR
    ~DefaultAllocator();

    // MUTATORS (?)
    T* get( int count );
      // Allocates enough memory for count number of Ts
    void release( T* pointer, int count);
      // Releases the memory in ptr, which should be size count.
}

// FREE OPERATORS
inline
std::ostream& operator<<( std::ostream& stream, const DefaultAllocator& allocator )
{
    return stream << "{ allocator }";
}

// CONSTRUCTORS
inline
DefaultAllocator::DefaultAllocator()
{

}

inline
DefaultAllocator::DefaultAllocator( DefaultAllocator copy )
{
    
}

// DESTRUCTOR
inline
DefaultAllocator::~DefaultAllocator()
{

}

// MUTATORS
inline
DefaultAllocator::get( int count )
{
    return new T[count];
}

inline
DefaultAllocator::release( T* pointer, int count )
{
    assert( pointer != nullptr );
    for( int i = 0; i < count; i++ )
    {
        assert( pointer[i] != nullptr );
        delete pointer[i];
    }
    delete[] pointer;
}

} // End sgdm namespace
} // End StevensDev namespace

#endif
