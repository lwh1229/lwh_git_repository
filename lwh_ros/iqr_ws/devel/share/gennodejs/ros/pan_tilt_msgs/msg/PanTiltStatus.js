// Auto-generated. Do not edit!

// (in-package pan_tilt_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class PanTiltStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.id = null;
      this.serial_num = null;
      this.hw_version = null;
      this.bd_version = null;
      this.sw_version = null;
      this.set_zero = null;
      this.speed = null;
      this.yaw_goal = null;
      this.pitch_goal = null;
      this.reserved = null;
      this.driver_ec = null;
      this.encoder_ec = null;
      this.yaw_now = null;
      this.pitch_now = null;
      this.yaw_temp = null;
      this.pitch_temp = null;
      this.yaw_raw = null;
      this.pitch_raw = null;
      this.loop_ec = null;
      this.loop_time = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
      if (initObj.hasOwnProperty('serial_num')) {
        this.serial_num = initObj.serial_num
      }
      else {
        this.serial_num = '';
      }
      if (initObj.hasOwnProperty('hw_version')) {
        this.hw_version = initObj.hw_version
      }
      else {
        this.hw_version = '';
      }
      if (initObj.hasOwnProperty('bd_version')) {
        this.bd_version = initObj.bd_version
      }
      else {
        this.bd_version = '';
      }
      if (initObj.hasOwnProperty('sw_version')) {
        this.sw_version = initObj.sw_version
      }
      else {
        this.sw_version = '';
      }
      if (initObj.hasOwnProperty('set_zero')) {
        this.set_zero = initObj.set_zero
      }
      else {
        this.set_zero = 0;
      }
      if (initObj.hasOwnProperty('speed')) {
        this.speed = initObj.speed
      }
      else {
        this.speed = 0;
      }
      if (initObj.hasOwnProperty('yaw_goal')) {
        this.yaw_goal = initObj.yaw_goal
      }
      else {
        this.yaw_goal = 0.0;
      }
      if (initObj.hasOwnProperty('pitch_goal')) {
        this.pitch_goal = initObj.pitch_goal
      }
      else {
        this.pitch_goal = 0.0;
      }
      if (initObj.hasOwnProperty('reserved')) {
        this.reserved = initObj.reserved
      }
      else {
        this.reserved = 0;
      }
      if (initObj.hasOwnProperty('driver_ec')) {
        this.driver_ec = initObj.driver_ec
      }
      else {
        this.driver_ec = 0;
      }
      if (initObj.hasOwnProperty('encoder_ec')) {
        this.encoder_ec = initObj.encoder_ec
      }
      else {
        this.encoder_ec = 0;
      }
      if (initObj.hasOwnProperty('yaw_now')) {
        this.yaw_now = initObj.yaw_now
      }
      else {
        this.yaw_now = 0.0;
      }
      if (initObj.hasOwnProperty('pitch_now')) {
        this.pitch_now = initObj.pitch_now
      }
      else {
        this.pitch_now = 0.0;
      }
      if (initObj.hasOwnProperty('yaw_temp')) {
        this.yaw_temp = initObj.yaw_temp
      }
      else {
        this.yaw_temp = 0.0;
      }
      if (initObj.hasOwnProperty('pitch_temp')) {
        this.pitch_temp = initObj.pitch_temp
      }
      else {
        this.pitch_temp = 0.0;
      }
      if (initObj.hasOwnProperty('yaw_raw')) {
        this.yaw_raw = initObj.yaw_raw
      }
      else {
        this.yaw_raw = 0;
      }
      if (initObj.hasOwnProperty('pitch_raw')) {
        this.pitch_raw = initObj.pitch_raw
      }
      else {
        this.pitch_raw = 0;
      }
      if (initObj.hasOwnProperty('loop_ec')) {
        this.loop_ec = initObj.loop_ec
      }
      else {
        this.loop_ec = 0;
      }
      if (initObj.hasOwnProperty('loop_time')) {
        this.loop_time = initObj.loop_time
      }
      else {
        this.loop_time = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PanTiltStatus
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [id]
    bufferOffset = _serializer.uint8(obj.id, buffer, bufferOffset);
    // Serialize message field [serial_num]
    bufferOffset = _serializer.string(obj.serial_num, buffer, bufferOffset);
    // Serialize message field [hw_version]
    bufferOffset = _serializer.string(obj.hw_version, buffer, bufferOffset);
    // Serialize message field [bd_version]
    bufferOffset = _serializer.string(obj.bd_version, buffer, bufferOffset);
    // Serialize message field [sw_version]
    bufferOffset = _serializer.string(obj.sw_version, buffer, bufferOffset);
    // Serialize message field [set_zero]
    bufferOffset = _serializer.uint8(obj.set_zero, buffer, bufferOffset);
    // Serialize message field [speed]
    bufferOffset = _serializer.int16(obj.speed, buffer, bufferOffset);
    // Serialize message field [yaw_goal]
    bufferOffset = _serializer.float32(obj.yaw_goal, buffer, bufferOffset);
    // Serialize message field [pitch_goal]
    bufferOffset = _serializer.float32(obj.pitch_goal, buffer, bufferOffset);
    // Serialize message field [reserved]
    bufferOffset = _serializer.uint16(obj.reserved, buffer, bufferOffset);
    // Serialize message field [driver_ec]
    bufferOffset = _serializer.uint16(obj.driver_ec, buffer, bufferOffset);
    // Serialize message field [encoder_ec]
    bufferOffset = _serializer.uint16(obj.encoder_ec, buffer, bufferOffset);
    // Serialize message field [yaw_now]
    bufferOffset = _serializer.float32(obj.yaw_now, buffer, bufferOffset);
    // Serialize message field [pitch_now]
    bufferOffset = _serializer.float32(obj.pitch_now, buffer, bufferOffset);
    // Serialize message field [yaw_temp]
    bufferOffset = _serializer.float32(obj.yaw_temp, buffer, bufferOffset);
    // Serialize message field [pitch_temp]
    bufferOffset = _serializer.float32(obj.pitch_temp, buffer, bufferOffset);
    // Serialize message field [yaw_raw]
    bufferOffset = _serializer.int16(obj.yaw_raw, buffer, bufferOffset);
    // Serialize message field [pitch_raw]
    bufferOffset = _serializer.int16(obj.pitch_raw, buffer, bufferOffset);
    // Serialize message field [loop_ec]
    bufferOffset = _serializer.uint16(obj.loop_ec, buffer, bufferOffset);
    // Serialize message field [loop_time]
    bufferOffset = _serializer.uint16(obj.loop_time, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PanTiltStatus
    let len;
    let data = new PanTiltStatus(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [id]
    data.id = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [serial_num]
    data.serial_num = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [hw_version]
    data.hw_version = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [bd_version]
    data.bd_version = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [sw_version]
    data.sw_version = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [set_zero]
    data.set_zero = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [speed]
    data.speed = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [yaw_goal]
    data.yaw_goal = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [pitch_goal]
    data.pitch_goal = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [reserved]
    data.reserved = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [driver_ec]
    data.driver_ec = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [encoder_ec]
    data.encoder_ec = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [yaw_now]
    data.yaw_now = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [pitch_now]
    data.pitch_now = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [yaw_temp]
    data.yaw_temp = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [pitch_temp]
    data.pitch_temp = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [yaw_raw]
    data.yaw_raw = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [pitch_raw]
    data.pitch_raw = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [loop_ec]
    data.loop_ec = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [loop_time]
    data.loop_time = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += _getByteLength(object.serial_num);
    length += _getByteLength(object.hw_version);
    length += _getByteLength(object.bd_version);
    length += _getByteLength(object.sw_version);
    return length + 58;
  }

  static datatype() {
    // Returns string type for a message object
    return 'pan_tilt_msgs/PanTiltStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c76162b6578981fa3815bffdd4df6ac3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    ## pan tilt ststus msg
    Header  header
    uint8   id
    string  serial_num
    string  hw_version
    string  bd_version
    string  sw_version
    uint8   set_zero
    int16   speed
    float32 yaw_goal
    float32 pitch_goal
    uint16  reserved
    uint16  driver_ec
    uint16  encoder_ec
    float32 yaw_now
    float32 pitch_now
    float32 yaw_temp
    float32 pitch_temp
    int16   yaw_raw
    int16   pitch_raw
    uint16  loop_ec
    uint16  loop_time
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PanTiltStatus(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    if (msg.serial_num !== undefined) {
      resolved.serial_num = msg.serial_num;
    }
    else {
      resolved.serial_num = ''
    }

    if (msg.hw_version !== undefined) {
      resolved.hw_version = msg.hw_version;
    }
    else {
      resolved.hw_version = ''
    }

    if (msg.bd_version !== undefined) {
      resolved.bd_version = msg.bd_version;
    }
    else {
      resolved.bd_version = ''
    }

    if (msg.sw_version !== undefined) {
      resolved.sw_version = msg.sw_version;
    }
    else {
      resolved.sw_version = ''
    }

    if (msg.set_zero !== undefined) {
      resolved.set_zero = msg.set_zero;
    }
    else {
      resolved.set_zero = 0
    }

    if (msg.speed !== undefined) {
      resolved.speed = msg.speed;
    }
    else {
      resolved.speed = 0
    }

    if (msg.yaw_goal !== undefined) {
      resolved.yaw_goal = msg.yaw_goal;
    }
    else {
      resolved.yaw_goal = 0.0
    }

    if (msg.pitch_goal !== undefined) {
      resolved.pitch_goal = msg.pitch_goal;
    }
    else {
      resolved.pitch_goal = 0.0
    }

    if (msg.reserved !== undefined) {
      resolved.reserved = msg.reserved;
    }
    else {
      resolved.reserved = 0
    }

    if (msg.driver_ec !== undefined) {
      resolved.driver_ec = msg.driver_ec;
    }
    else {
      resolved.driver_ec = 0
    }

    if (msg.encoder_ec !== undefined) {
      resolved.encoder_ec = msg.encoder_ec;
    }
    else {
      resolved.encoder_ec = 0
    }

    if (msg.yaw_now !== undefined) {
      resolved.yaw_now = msg.yaw_now;
    }
    else {
      resolved.yaw_now = 0.0
    }

    if (msg.pitch_now !== undefined) {
      resolved.pitch_now = msg.pitch_now;
    }
    else {
      resolved.pitch_now = 0.0
    }

    if (msg.yaw_temp !== undefined) {
      resolved.yaw_temp = msg.yaw_temp;
    }
    else {
      resolved.yaw_temp = 0.0
    }

    if (msg.pitch_temp !== undefined) {
      resolved.pitch_temp = msg.pitch_temp;
    }
    else {
      resolved.pitch_temp = 0.0
    }

    if (msg.yaw_raw !== undefined) {
      resolved.yaw_raw = msg.yaw_raw;
    }
    else {
      resolved.yaw_raw = 0
    }

    if (msg.pitch_raw !== undefined) {
      resolved.pitch_raw = msg.pitch_raw;
    }
    else {
      resolved.pitch_raw = 0
    }

    if (msg.loop_ec !== undefined) {
      resolved.loop_ec = msg.loop_ec;
    }
    else {
      resolved.loop_ec = 0
    }

    if (msg.loop_time !== undefined) {
      resolved.loop_time = msg.loop_time;
    }
    else {
      resolved.loop_time = 0
    }

    return resolved;
    }
};

module.exports = PanTiltStatus;
