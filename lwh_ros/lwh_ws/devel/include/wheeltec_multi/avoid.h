// Generated by gencpp from file wheeltec_multi/avoid.msg
// DO NOT EDIT!


#ifndef WHEELTEC_MULTI_MESSAGE_AVOID_H
#define WHEELTEC_MULTI_MESSAGE_AVOID_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace wheeltec_multi
{
template <class ContainerAllocator>
struct avoid_
{
  typedef avoid_<ContainerAllocator> Type;

  avoid_()
    : angleX(0.0)
    , angleY(0.0)
    , distance(0.0)  {
    }
  avoid_(const ContainerAllocator& _alloc)
    : angleX(0.0)
    , angleY(0.0)
    , distance(0.0)  {
  (void)_alloc;
    }



   typedef float _angleX_type;
  _angleX_type angleX;

   typedef float _angleY_type;
  _angleY_type angleY;

   typedef float _distance_type;
  _distance_type distance;





  typedef boost::shared_ptr< ::wheeltec_multi::avoid_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::wheeltec_multi::avoid_<ContainerAllocator> const> ConstPtr;

}; // struct avoid_

typedef ::wheeltec_multi::avoid_<std::allocator<void> > avoid;

typedef boost::shared_ptr< ::wheeltec_multi::avoid > avoidPtr;
typedef boost::shared_ptr< ::wheeltec_multi::avoid const> avoidConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::wheeltec_multi::avoid_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::wheeltec_multi::avoid_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::wheeltec_multi::avoid_<ContainerAllocator1> & lhs, const ::wheeltec_multi::avoid_<ContainerAllocator2> & rhs)
{
  return lhs.angleX == rhs.angleX &&
    lhs.angleY == rhs.angleY &&
    lhs.distance == rhs.distance;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::wheeltec_multi::avoid_<ContainerAllocator1> & lhs, const ::wheeltec_multi::avoid_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace wheeltec_multi

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::wheeltec_multi::avoid_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::wheeltec_multi::avoid_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::wheeltec_multi::avoid_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::wheeltec_multi::avoid_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::wheeltec_multi::avoid_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::wheeltec_multi::avoid_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::wheeltec_multi::avoid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e4df5e09e92d9d2b4758c9aab7a9ebeb";
  }

  static const char* value(const ::wheeltec_multi::avoid_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe4df5e09e92d9d2bULL;
  static const uint64_t static_value2 = 0x4758c9aab7a9ebebULL;
};

template<class ContainerAllocator>
struct DataType< ::wheeltec_multi::avoid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "wheeltec_multi/avoid";
  }

  static const char* value(const ::wheeltec_multi::avoid_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::wheeltec_multi::avoid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 angleX\n"
"float32 angleY\n"
"float32 distance\n"
;
  }

  static const char* value(const ::wheeltec_multi::avoid_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::wheeltec_multi::avoid_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.angleX);
      stream.next(m.angleY);
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct avoid_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::wheeltec_multi::avoid_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::wheeltec_multi::avoid_<ContainerAllocator>& v)
  {
    s << indent << "angleX: ";
    Printer<float>::stream(s, indent + "  ", v.angleX);
    s << indent << "angleY: ";
    Printer<float>::stream(s, indent + "  ", v.angleY);
    s << indent << "distance: ";
    Printer<float>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // WHEELTEC_MULTI_MESSAGE_AVOID_H
