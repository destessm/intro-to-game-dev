// iallocator.h

namespace StevensDev
{

namespace sgdm
{

template <class T>
class iAllocator
{
  public:
    //should it have constructor+copy+destructor?
    virtual get( int count ) : T* =0;
    virtual release( T*, int count) : void =0;
}


} // End sdgm namespace
} // End StevensDev namespace
