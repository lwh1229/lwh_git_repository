// Generated by gencpp from file world_canvas_msgs/Annotation.msg
// DO NOT EDIT!


#ifndef WORLD_CANVAS_MSGS_MESSAGE_ANNOTATION_H
#define WORLD_CANVAS_MSGS_MESSAGE_ANNOTATION_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <uuid_msgs/UniqueID.h>
#include <uuid_msgs/UniqueID.h>
#include <std_msgs/ColorRGBA.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <uuid_msgs/UniqueID.h>

namespace world_canvas_msgs
{
template <class ContainerAllocator>
struct Annotation_
{
  typedef Annotation_<ContainerAllocator> Type;

  Annotation_()
    : timestamp()
    , id()
    , data_id()
    , world()
    , name()
    , type()
    , shape(0)
    , color()
    , size()
    , pose()
    , keywords()
    , relationships()  {
    }
  Annotation_(const ContainerAllocator& _alloc)
    : timestamp()
    , id(_alloc)
    , data_id(_alloc)
    , world(_alloc)
    , name(_alloc)
    , type(_alloc)
    , shape(0)
    , color(_alloc)
    , size(_alloc)
    , pose(_alloc)
    , keywords(_alloc)
    , relationships(_alloc)  {
  (void)_alloc;
    }



   typedef ros::Time _timestamp_type;
  _timestamp_type timestamp;

   typedef  ::uuid_msgs::UniqueID_<ContainerAllocator>  _id_type;
  _id_type id;

   typedef  ::uuid_msgs::UniqueID_<ContainerAllocator>  _data_id_type;
  _data_id_type data_id;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _world_type;
  _world_type world;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _name_type;
  _name_type name;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _type_type;
  _type_type type;

   typedef int32_t _shape_type;
  _shape_type shape;

   typedef  ::std_msgs::ColorRGBA_<ContainerAllocator>  _color_type;
  _color_type color;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _size_type;
  _size_type size;

   typedef  ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> _keywords_type;
  _keywords_type keywords;

   typedef std::vector< ::uuid_msgs::UniqueID_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::uuid_msgs::UniqueID_<ContainerAllocator> >> _relationships_type;
  _relationships_type relationships;





  typedef boost::shared_ptr< ::world_canvas_msgs::Annotation_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::world_canvas_msgs::Annotation_<ContainerAllocator> const> ConstPtr;

}; // struct Annotation_

typedef ::world_canvas_msgs::Annotation_<std::allocator<void> > Annotation;

typedef boost::shared_ptr< ::world_canvas_msgs::Annotation > AnnotationPtr;
typedef boost::shared_ptr< ::world_canvas_msgs::Annotation const> AnnotationConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::world_canvas_msgs::Annotation_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::world_canvas_msgs::Annotation_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::world_canvas_msgs::Annotation_<ContainerAllocator1> & lhs, const ::world_canvas_msgs::Annotation_<ContainerAllocator2> & rhs)
{
  return lhs.timestamp == rhs.timestamp &&
    lhs.id == rhs.id &&
    lhs.data_id == rhs.data_id &&
    lhs.world == rhs.world &&
    lhs.name == rhs.name &&
    lhs.type == rhs.type &&
    lhs.shape == rhs.shape &&
    lhs.color == rhs.color &&
    lhs.size == rhs.size &&
    lhs.pose == rhs.pose &&
    lhs.keywords == rhs.keywords &&
    lhs.relationships == rhs.relationships;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::world_canvas_msgs::Annotation_<ContainerAllocator1> & lhs, const ::world_canvas_msgs::Annotation_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace world_canvas_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::world_canvas_msgs::Annotation_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::world_canvas_msgs::Annotation_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::world_canvas_msgs::Annotation_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::world_canvas_msgs::Annotation_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::world_canvas_msgs::Annotation_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::world_canvas_msgs::Annotation_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::world_canvas_msgs::Annotation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ad3b363d73f197c0fc0f70645a6b2598";
  }

  static const char* value(const ::world_canvas_msgs::Annotation_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xad3b363d73f197c0ULL;
  static const uint64_t static_value2 = 0xfc0f70645a6b2598ULL;
};

template<class ContainerAllocator>
struct DataType< ::world_canvas_msgs::Annotation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "world_canvas_msgs/Annotation";
  }

  static const char* value(const ::world_canvas_msgs::Annotation_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::world_canvas_msgs::Annotation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Annotation: a generic descriptor for an element (object) in a semantic map\n"
"# An annotation can be used to introspect, visualize or key into database filters/searches without\n"
"# having to touch the described object directly\n"
"#  - timestamp : Creation/last update time\n"
"#  - world     : World the object belongs to\n"
"#  - id        : Annotation unique id\n"
"#  - data_id   : Referenced object unique id (an object can be reference by 1 or more annotations)\n"
"#  - name      : Referenced object name\n"
"#  - type      : Referenced object type (a message type, as world canvas objects are ROS messages)\n"
"#  - shape     : One of 1 (CUBE), 2 (SPHERE), 3 (CYLINDER), 9 (TEXT)\n"
"#  - color     : R, G, B, A (optional)\n"
"#  - size      : X, Y, Z (optional)\n"
"#  - keywords  : Generic properties of this object: allows basic filtering without introspecting\n"
"#                the object itself\n"
"#  - relationships : List of associated annotations, used for retrieving operational sets of objects\n"
"\n"
"# General properties\n"
"time timestamp\n"
"uuid_msgs/UniqueID id\n"
"uuid_msgs/UniqueID data_id\n"
"string world\n"
"string name\n"
"string type\n"
"\n"
"# Physical properties\n"
"int32  shape\n"
"std_msgs/ColorRGBA color\n"
"geometry_msgs/Vector3 size\n"
"geometry_msgs/PoseWithCovarianceStamped pose\n"
"\n"
"# Querying properties\n"
"string[] keywords\n"
"uuid_msgs/UniqueID[] relationships\n"
"\n"
"================================================================================\n"
"MSG: uuid_msgs/UniqueID\n"
"# A universally unique identifier (UUID).\n"
"#\n"
"#  http://en.wikipedia.org/wiki/Universally_unique_identifier\n"
"#  http://tools.ietf.org/html/rfc4122.html\n"
"\n"
"uint8[16] uuid\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/ColorRGBA\n"
"float32 r\n"
"float32 g\n"
"float32 b\n"
"float32 a\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseWithCovarianceStamped\n"
"# This expresses an estimated pose with a reference coordinate frame and timestamp\n"
"\n"
"Header header\n"
"PoseWithCovariance pose\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseWithCovariance\n"
"# This represents a pose in free space with uncertainty.\n"
"\n"
"Pose pose\n"
"\n"
"# Row-major representation of the 6x6 covariance matrix\n"
"# The orientation parameters use a fixed-axis representation.\n"
"# In order, the parameters are:\n"
"# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n"
"float64[36] covariance\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::world_canvas_msgs::Annotation_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::world_canvas_msgs::Annotation_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.timestamp);
      stream.next(m.id);
      stream.next(m.data_id);
      stream.next(m.world);
      stream.next(m.name);
      stream.next(m.type);
      stream.next(m.shape);
      stream.next(m.color);
      stream.next(m.size);
      stream.next(m.pose);
      stream.next(m.keywords);
      stream.next(m.relationships);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Annotation_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::world_canvas_msgs::Annotation_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::world_canvas_msgs::Annotation_<ContainerAllocator>& v)
  {
    s << indent << "timestamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.timestamp);
    s << indent << "id: ";
    s << std::endl;
    Printer< ::uuid_msgs::UniqueID_<ContainerAllocator> >::stream(s, indent + "  ", v.id);
    s << indent << "data_id: ";
    s << std::endl;
    Printer< ::uuid_msgs::UniqueID_<ContainerAllocator> >::stream(s, indent + "  ", v.data_id);
    s << indent << "world: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.world);
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.name);
    s << indent << "type: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.type);
    s << indent << "shape: ";
    Printer<int32_t>::stream(s, indent + "  ", v.shape);
    s << indent << "color: ";
    s << std::endl;
    Printer< ::std_msgs::ColorRGBA_<ContainerAllocator> >::stream(s, indent + "  ", v.color);
    s << indent << "size: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.size);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "keywords[]" << std::endl;
    for (size_t i = 0; i < v.keywords.size(); ++i)
    {
      s << indent << "  keywords[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.keywords[i]);
    }
    s << indent << "relationships[]" << std::endl;
    for (size_t i = 0; i < v.relationships.size(); ++i)
    {
      s << indent << "  relationships[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::uuid_msgs::UniqueID_<ContainerAllocator> >::stream(s, indent + "    ", v.relationships[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // WORLD_CANVAS_MSGS_MESSAGE_ANNOTATION_H
