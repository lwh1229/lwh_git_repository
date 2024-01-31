; Auto-generated. Do not edit!


(cl:in-package pan_tilt_msgs-msg)


;//! \htmlinclude PanTiltCmdDeg.msg.html

(cl:defclass <PanTiltCmdDeg> (roslisp-msg-protocol:ros-message)
  ((yaw
    :reader yaw
    :initarg :yaw
    :type cl:float
    :initform 0.0)
   (pitch
    :reader pitch
    :initarg :pitch
    :type cl:float
    :initform 0.0)
   (speed
    :reader speed
    :initarg :speed
    :type cl:fixnum
    :initform 0))
)

(cl:defclass PanTiltCmdDeg (<PanTiltCmdDeg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PanTiltCmdDeg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PanTiltCmdDeg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pan_tilt_msgs-msg:<PanTiltCmdDeg> is deprecated: use pan_tilt_msgs-msg:PanTiltCmdDeg instead.")))

(cl:ensure-generic-function 'yaw-val :lambda-list '(m))
(cl:defmethod yaw-val ((m <PanTiltCmdDeg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:yaw-val is deprecated.  Use pan_tilt_msgs-msg:yaw instead.")
  (yaw m))

(cl:ensure-generic-function 'pitch-val :lambda-list '(m))
(cl:defmethod pitch-val ((m <PanTiltCmdDeg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:pitch-val is deprecated.  Use pan_tilt_msgs-msg:pitch instead.")
  (pitch m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <PanTiltCmdDeg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:speed-val is deprecated.  Use pan_tilt_msgs-msg:speed instead.")
  (speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PanTiltCmdDeg>) ostream)
  "Serializes a message object of type '<PanTiltCmdDeg>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'speed)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PanTiltCmdDeg>) istream)
  "Deserializes a message object of type '<PanTiltCmdDeg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pitch) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'speed) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PanTiltCmdDeg>)))
  "Returns string type for a message object of type '<PanTiltCmdDeg>"
  "pan_tilt_msgs/PanTiltCmdDeg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PanTiltCmdDeg)))
  "Returns string type for a message object of type 'PanTiltCmdDeg"
  "pan_tilt_msgs/PanTiltCmdDeg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PanTiltCmdDeg>)))
  "Returns md5sum for a message object of type '<PanTiltCmdDeg>"
  "965a993146bc193a21484f0f1e9162eb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PanTiltCmdDeg)))
  "Returns md5sum for a message object of type 'PanTiltCmdDeg"
  "965a993146bc193a21484f0f1e9162eb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PanTiltCmdDeg>)))
  "Returns full string definition for message of type '<PanTiltCmdDeg>"
  (cl:format cl:nil "## pan tilt control msg~%## pan tilt yaw angle :deg~%float32 yaw~%~%## pan tilt pitch angle :deg~%float32 pitch ~%~%## pan tilt speed :deg/s~%int16 speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PanTiltCmdDeg)))
  "Returns full string definition for message of type 'PanTiltCmdDeg"
  (cl:format cl:nil "## pan tilt control msg~%## pan tilt yaw angle :deg~%float32 yaw~%~%## pan tilt pitch angle :deg~%float32 pitch ~%~%## pan tilt speed :deg/s~%int16 speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PanTiltCmdDeg>))
  (cl:+ 0
     4
     4
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PanTiltCmdDeg>))
  "Converts a ROS message object to a list"
  (cl:list 'PanTiltCmdDeg
    (cl:cons ':yaw (yaw msg))
    (cl:cons ':pitch (pitch msg))
    (cl:cons ':speed (speed msg))
))
