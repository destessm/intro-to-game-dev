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
class CountingAllocator: public DefaultAllocator
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
    CountingAllocator( DefaultAllocator copy );
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
}

// FREE OPERATORS
inline
std::ostream& operator<<( std::ostream& stream, const DefaultAllocator& allocator )
{
    return stream << "{ allocator }";
}

// CONSTRUCTORS
inline
CountingAllocator::CountingAllocator()
{
    d_allocationCount = 0;
    d_releaseCount = 0;
}

inline
CountingAllocator::CountingAllocator( DefaultAllocator copy )
{
    d_allocationCount = copy.getAllocationCount();
    d_releaseCount = copy.getReleaseCount();
}

// DESTRUCTOR
inline
CountingAllocator::~CountingAllocator()
{
}

// ACCESSORS
inline
CountingAllocator::getAllocationCount()
{
    return d_allocationCount;
}

inline
CountingAllocator::getReleaseCount()
{
    return d_releaseCount;
}

inline
CountingAllocator::getOutstandingCount()
{
    return d_allocationCount - d_releaseCount;
}

inline
CountingAllocator::getTotalAllocationCount()
{
    return d_totalAllocationCount;
}

inline
CountingAllocator::getTotalReleaseCount()
{
    return d_totalReleaseCount;
}

inline
CountingAllocator::getTotalOutstandingCount()
{
    return d_totalAllocationCount - d_totalReleaseCount;
}

// MUTATORS
inline
CountingAllocator::get( int count )
{
    d_allocationCount += count;
    d_totalAllocationCount += count;
    return DefaultAllocator::get( count );
}

inline
CountingAllocator::release( T* pointer, int count )
{
    assert( d_allocationCount - d_releaseCount != 0 );
    d_releaseCount += count;
    d_totalReleaseCount += count;
    DefaultAllocator::release( pointer, count )
    
}

} // End sgdm namespace
} // End StevensDev namespace

#endif
