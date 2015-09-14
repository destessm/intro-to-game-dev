// counting_allocator.h
#ifndef INCLUDED_COUNTING_ALLOCATOR
#define INCLUDED_COUNTING_ALLOCATOR

#include <iostream>
#include "default_allocator.h"

namespace StevensDev
{
namespace sgdm
{

template <class T>
class CountingAllocator: public DefaultAllocator<T>
{
  private:
    int d_allocationCount;
    int d_releaseCount;
    static int d_totalAllocationCount;
    static int d_totalReleaseCount;
  public:
    // CONSTRUCTORS
    CountingAllocator();
      // Default constructor
    CountingAllocator( const CountingAllocator<T> &copy );
      // Copy constructor

    // DESTRUCTOR
    ~CountingAllocator();

    // ACCESSORS
    int const getAllocationCount();
      // returns number of allocations that occurred
    int const getReleaseCount();
      // returns number of releases that occured
    int const getOutstandingCount();
      // returns number of outstanding allocations
    static int getTotalAllocationCount();
      // returns number of allocations that occurred across instances
    static int getTotalReleaseCount();
      // returns number of releases that occurred across instances
    static int getTotalOutstandingCount();
      // returns number of outstanding alloations across instances

    // MUTATORS (?)
    T* get( int count );
      // Allocates enough memory for count number of Ts
    void release( T* pointer, int count);
      // Releases the memory in ptr, which should be size count.
};

// DECLARATIONS OF STATIC VARIABLES
template<class T>
int CountingAllocator<T>::d_totalAllocationCount = 0;
template<class T>
int CountingAllocator<T>::d_totalReleaseCount = 0;

// FREE OPERATORS
template<class T>
inline
std::ostream& operator<<( std::ostream& stream, const CountingAllocator<T>& )
{
    return stream << "{ allocator }";
}

// CONSTRUCTORS
template<class T>
inline
CountingAllocator<T>::CountingAllocator()
{
    d_allocationCount = 0;
    d_releaseCount = 0;
}

template<class T>
inline
CountingAllocator<T>::CountingAllocator( const CountingAllocator<T> &copy )
{
    d_allocationCount = copy.getAllocationCount();
    d_releaseCount = copy.getReleaseCount();
}

// DESTRUCTOR
template<class T>
inline
CountingAllocator<T>::~CountingAllocator()
{
}

// ACCESSORS
template<class T>
inline
int const CountingAllocator<T>::getAllocationCount()
{
    return d_allocationCount;
}

template<class T>
inline
int const CountingAllocator<T>::getReleaseCount()
{
    //std::cout << "IN GET RELEASE COUNT: " << d_releaseCount << std::endl;
    return d_releaseCount;
}

template<class T>
inline
int const CountingAllocator<T>::getOutstandingCount()
{
    return d_allocationCount - d_releaseCount;
}

template<class T>
inline
int CountingAllocator<T>::getTotalAllocationCount()
{
    return d_totalAllocationCount;
}

template<class T>
inline
int CountingAllocator<T>::getTotalReleaseCount()
{
    return d_totalReleaseCount;
}

template<class T>
inline
int CountingAllocator<T>::getTotalOutstandingCount()
{
    return d_totalAllocationCount - d_totalReleaseCount;
}

// MUTATORS
template<class T>
inline
T* CountingAllocator<T>::get( int count )
{
    d_allocationCount += count;
    d_totalAllocationCount += count;
    return DefaultAllocator<T>::get( count );
}

template<class T>
inline
void CountingAllocator<T>::release( T* pointer, int count )
{
    assert( d_allocationCount - d_releaseCount != 0 );
    d_releaseCount += count;
    d_totalReleaseCount += count;
    DefaultAllocator<T>::release( pointer, count );
    
};

} // End sgdm namespace
} // End StevensDev namespace

#endif
