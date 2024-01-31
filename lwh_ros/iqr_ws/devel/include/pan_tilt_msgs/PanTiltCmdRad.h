// Generated by gencpp from file pan_tilt_msgs/PanTiltCmdRad.msg
// DO NOT EDIT!


#ifndef PAN_TILT_MSGS_MESSAGE_PANTILTCMDRAD_H
#define PAN_TILT_MSGS_MESSAGE_PANTILTCMDRAD_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace pan_tilt_msgs
{
template <class ContainerAllocator>
struct PanTiltCmdRad_
{
  typedef PanTiltCmdRad_<ContainerAllocator> Type;

  PanTiltCmdRad_()
    : yaw(0.0)
    , pitch(0.0)
    , speed(0.0)  {
    }
  PanTiltCmdRad_(const ContainerAllocator& _alloc)
    : yaw(0.0)
    , pitch(0.0)
    , speed(0.0)  {
  (void)_alloc;
    }



   typedef double _yaw_type;
  _yaw_type yaw;

   typedef double _pitch_type;
  _pitch_type pitch;

   typedef double _speed_type;
  _speed_type speed;





  typedef boost::shared_ptr< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> const> ConstPtr;

}; // struct PanTiltCmdRad_

typedef ::pan_tilt_msgs::PanTiltCmdRad_<std::allocator<void> > PanTiltCmdRad;

typedef boost::shared_ptr< ::pan_tilt_msgs::PanTiltCmdRad > PanTiltCmdRadPtr;
typedef boost::shared_ptr< ::pan_tilt_msgs::PanTiltCmdRad const> PanTiltCmdRadConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator1> & lhs, const ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator2> & rhs)
{
  return lhs.yaw == rhs.yaw &&
    lhs.pitch == rhs.pitch &&
    lhs.speed == rhs.speed;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator1> & lhs, const ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace pan_tilt_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d053c1cec7acafefd82c6ee30134df7a";
  }

  static const char* value(const ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd053c1cec7acafefULL;
  static const uint64_t static_value2 = 0xd82c6ee30134df7aULL;
};

template<class ContainerAllocator>
struct DataType< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pan_tilt_msgs/PanTiltCmdRad";
  }

  static const char* value(const ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> >
{
  static const char* value()
  {
    return "## pan tilt control msg\n"
"## pan tilt yaw angle :rad\n"
"float64 yaw\n"
"\n"
"## pan tilt pitch angle :rad\n"
"float64 pitch \n"
"\n"
"## pan tilt speed :rad/s\n"
"float64 speed\n"
;
  }

  static const char* value(const ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.yaw);
      stream.next(m.pitch);
      stream.next(m.speed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PanTiltCmdRad_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pan_tilt_msgs::PanTiltCmdRad_<ContainerAllocator>& v)
  {
    s << indent << "yaw: ";
    Printer<double>::stream(s, indent + "  ", v.yaw);
    s << indent << "pitch: ";
    Printer<double>::stream(s, indent + "  ", v.pitch);
    s << indent << "speed: ";
    Printer<double>::stream(s, indent + "  ", v.speed);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PAN_TILT_MSGS_MESSAGE_PANTILTCMDRAD_H
