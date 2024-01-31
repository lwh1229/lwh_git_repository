; Auto-generated. Do not edit!


(cl:in-package pan_tilt_msgs-msg)


;//! \htmlinclude PanTiltCmdRad.msg.html

(cl:defclass <PanTiltCmdRad> (roslisp-msg-protocol:ros-message)
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
    :type cl:float
    :initform 0.0))
)

(cl:defclass PanTiltCmdRad (<PanTiltCmdRad>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PanTiltCmdRad>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PanTiltCmdRad)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pan_tilt_msgs-msg:<PanTiltCmdRad> is deprecated: use pan_tilt_msgs-msg:PanTiltCmdRad instead.")))

(cl:ensure-generic-function 'yaw-val :lambda-list '(m))
(cl:defmethod yaw-val ((m <PanTiltCmdRad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:yaw-val is deprecated.  Use pan_tilt_msgs-msg:yaw instead.")
  (yaw m))

(cl:ensure-generic-function 'pitch-val :lambda-list '(m))
(cl:defmethod pitch-val ((m <PanTiltCmdRad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:pitch-val is deprecated.  Use pan_tilt_msgs-msg:pitch instead.")
  (pitch m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <PanTiltCmdRad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:speed-val is deprecated.  Use pan_tilt_msgs-msg:speed instead.")
  (speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PanTiltCmdRad>) ostream)
  "Serializes a message object of type '<PanTiltCmdRad>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'yaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'pitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PanTiltCmdRad>) istream)
  "Deserializes a message object of type '<PanTiltCmdRad>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pitch) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PanTiltCmdRad>)))
  "Returns string type for a message object of type '<PanTiltCmdRad>"
  "pan_tilt_msgs/PanTiltCmdRad")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PanTiltCmdRad)))
  "Returns string type for a message object of type 'PanTiltCmdRad"
  "pan_tilt_msgs/PanTiltCmdRad")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PanTiltCmdRad>)))
  "Returns md5sum for a message object of type '<PanTiltCmdRad>"
  "d053c1cec7acafefd82c6ee30134df7a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PanTiltCmdRad)))
  "Returns md5sum for a message object of type 'PanTiltCmdRad"
  "d053c1cec7acafefd82c6ee30134df7a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PanTiltCmdRad>)))
  "Returns full string definition for message of type '<PanTiltCmdRad>"
  (cl:format cl:nil "## pan tilt control msg~%## pan tilt yaw angle :rad~%float64 yaw~%~%## pan tilt pitch angle :rad~%float64 pitch ~%~%## pan tilt speed :rad/s~%float64 speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PanTiltCmdRad)))
  "Returns full string definition for message of type 'PanTiltCmdRad"
  (cl:format cl:nil "## pan tilt control msg~%## pan tilt yaw angle :rad~%float64 yaw~%~%## pan tilt pitch angle :rad~%float64 pitch ~%~%## pan tilt speed :rad/s~%float64 speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PanTiltCmdRad>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PanTiltCmdRad>))
  "Converts a ROS message object to a list"
  (cl:list 'PanTiltCmdRad
    (cl:cons ':yaw (yaw msg))
    (cl:cons ':pitch (pitch msg))
    (cl:cons ':speed (speed msg))
))
