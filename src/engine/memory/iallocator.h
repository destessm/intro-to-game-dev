// iallocator.h
#ifndef INCLUDED_IALLOCATOR
#define INCLUDED_IALLOCATOR

namespace StevensDev
{
namespace sgdm
{

template <class T>
class iAllocator
{
  public:
    //should it have constructor+copy+destructor?
    virtual T* get( int count ) =0;
    virtual void release( T*, int count) =0;
};


} // End sdgm namespace
} // End StevensDev namespace

#endif
