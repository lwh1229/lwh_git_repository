; Auto-generated. Do not edit!


(cl:in-package pan_tilt_msgs-msg)


;//! \htmlinclude PanTiltStatus.msg.html

(cl:defclass <PanTiltStatus> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0)
   (serial_num
    :reader serial_num
    :initarg :serial_num
    :type cl:string
    :initform "")
   (hw_version
    :reader hw_version
    :initarg :hw_version
    :type cl:string
    :initform "")
   (bd_version
    :reader bd_version
    :initarg :bd_version
    :type cl:string
    :initform "")
   (sw_version
    :reader sw_version
    :initarg :sw_version
    :type cl:string
    :initform "")
   (set_zero
    :reader set_zero
    :initarg :set_zero
    :type cl:fixnum
    :initform 0)
   (speed
    :reader speed
    :initarg :speed
    :type cl:fixnum
    :initform 0)
   (yaw_goal
    :reader yaw_goal
    :initarg :yaw_goal
    :type cl:float
    :initform 0.0)
   (pitch_goal
    :reader pitch_goal
    :initarg :pitch_goal
    :type cl:float
    :initform 0.0)
   (reserved
    :reader reserved
    :initarg :reserved
    :type cl:fixnum
    :initform 0)
   (driver_ec
    :reader driver_ec
    :initarg :driver_ec
    :type cl:fixnum
    :initform 0)
   (encoder_ec
    :reader encoder_ec
    :initarg :encoder_ec
    :type cl:fixnum
    :initform 0)
   (yaw_now
    :reader yaw_now
    :initarg :yaw_now
    :type cl:float
    :initform 0.0)
   (pitch_now
    :reader pitch_now
    :initarg :pitch_now
    :type cl:float
    :initform 0.0)
   (yaw_temp
    :reader yaw_temp
    :initarg :yaw_temp
    :type cl:float
    :initform 0.0)
   (pitch_temp
    :reader pitch_temp
    :initarg :pitch_temp
    :type cl:float
    :initform 0.0)
   (yaw_raw
    :reader yaw_raw
    :initarg :yaw_raw
    :type cl:fixnum
    :initform 0)
   (pitch_raw
    :reader pitch_raw
    :initarg :pitch_raw
    :type cl:fixnum
    :initform 0)
   (loop_ec
    :reader loop_ec
    :initarg :loop_ec
    :type cl:fixnum
    :initform 0)
   (loop_time
    :reader loop_time
    :initarg :loop_time
    :type cl:fixnum
    :initform 0))
)

(cl:defclass PanTiltStatus (<PanTiltStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PanTiltStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PanTiltStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pan_tilt_msgs-msg:<PanTiltStatus> is deprecated: use pan_tilt_msgs-msg:PanTiltStatus instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:header-val is deprecated.  Use pan_tilt_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:id-val is deprecated.  Use pan_tilt_msgs-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'serial_num-val :lambda-list '(m))
(cl:defmethod serial_num-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:serial_num-val is deprecated.  Use pan_tilt_msgs-msg:serial_num instead.")
  (serial_num m))

(cl:ensure-generic-function 'hw_version-val :lambda-list '(m))
(cl:defmethod hw_version-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:hw_version-val is deprecated.  Use pan_tilt_msgs-msg:hw_version instead.")
  (hw_version m))

(cl:ensure-generic-function 'bd_version-val :lambda-list '(m))
(cl:defmethod bd_version-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:bd_version-val is deprecated.  Use pan_tilt_msgs-msg:bd_version instead.")
  (bd_version m))

(cl:ensure-generic-function 'sw_version-val :lambda-list '(m))
(cl:defmethod sw_version-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:sw_version-val is deprecated.  Use pan_tilt_msgs-msg:sw_version instead.")
  (sw_version m))

(cl:ensure-generic-function 'set_zero-val :lambda-list '(m))
(cl:defmethod set_zero-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:set_zero-val is deprecated.  Use pan_tilt_msgs-msg:set_zero instead.")
  (set_zero m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:speed-val is deprecated.  Use pan_tilt_msgs-msg:speed instead.")
  (speed m))

(cl:ensure-generic-function 'yaw_goal-val :lambda-list '(m))
(cl:defmethod yaw_goal-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:yaw_goal-val is deprecated.  Use pan_tilt_msgs-msg:yaw_goal instead.")
  (yaw_goal m))

(cl:ensure-generic-function 'pitch_goal-val :lambda-list '(m))
(cl:defmethod pitch_goal-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:pitch_goal-val is deprecated.  Use pan_tilt_msgs-msg:pitch_goal instead.")
  (pitch_goal m))

(cl:ensure-generic-function 'reserved-val :lambda-list '(m))
(cl:defmethod reserved-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:reserved-val is deprecated.  Use pan_tilt_msgs-msg:reserved instead.")
  (reserved m))

(cl:ensure-generic-function 'driver_ec-val :lambda-list '(m))
(cl:defmethod driver_ec-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:driver_ec-val is deprecated.  Use pan_tilt_msgs-msg:driver_ec instead.")
  (driver_ec m))

(cl:ensure-generic-function 'encoder_ec-val :lambda-list '(m))
(cl:defmethod encoder_ec-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:encoder_ec-val is deprecated.  Use pan_tilt_msgs-msg:encoder_ec instead.")
  (encoder_ec m))

(cl:ensure-generic-function 'yaw_now-val :lambda-list '(m))
(cl:defmethod yaw_now-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:yaw_now-val is deprecated.  Use pan_tilt_msgs-msg:yaw_now instead.")
  (yaw_now m))

(cl:ensure-generic-function 'pitch_now-val :lambda-list '(m))
(cl:defmethod pitch_now-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:pitch_now-val is deprecated.  Use pan_tilt_msgs-msg:pitch_now instead.")
  (pitch_now m))

(cl:ensure-generic-function 'yaw_temp-val :lambda-list '(m))
(cl:defmethod yaw_temp-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:yaw_temp-val is deprecated.  Use pan_tilt_msgs-msg:yaw_temp instead.")
  (yaw_temp m))

(cl:ensure-generic-function 'pitch_temp-val :lambda-list '(m))
(cl:defmethod pitch_temp-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:pitch_temp-val is deprecated.  Use pan_tilt_msgs-msg:pitch_temp instead.")
  (pitch_temp m))

(cl:ensure-generic-function 'yaw_raw-val :lambda-list '(m))
(cl:defmethod yaw_raw-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:yaw_raw-val is deprecated.  Use pan_tilt_msgs-msg:yaw_raw instead.")
  (yaw_raw m))

(cl:ensure-generic-function 'pitch_raw-val :lambda-list '(m))
(cl:defmethod pitch_raw-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:pitch_raw-val is deprecated.  Use pan_tilt_msgs-msg:pitch_raw instead.")
  (pitch_raw m))

(cl:ensure-generic-function 'loop_ec-val :lambda-list '(m))
(cl:defmethod loop_ec-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:loop_ec-val is deprecated.  Use pan_tilt_msgs-msg:loop_ec instead.")
  (loop_ec m))

(cl:ensure-generic-function 'loop_time-val :lambda-list '(m))
(cl:defmethod loop_time-val ((m <PanTiltStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pan_tilt_msgs-msg:loop_time-val is deprecated.  Use pan_tilt_msgs-msg:loop_time instead.")
  (loop_time m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PanTiltStatus>) ostream)
  "Serializes a message object of type '<PanTiltStatus>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'serial_num))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'serial_num))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'hw_version))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'hw_version))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'bd_version))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'bd_version))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'sw_version))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'sw_version))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'set_zero)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'speed)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw_goal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pitch_goal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'driver_ec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'driver_ec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'encoder_ec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'encoder_ec)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw_now))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pitch_now))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw_temp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pitch_temp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'yaw_raw)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'pitch_raw)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'loop_ec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'loop_ec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'loop_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'loop_time)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PanTiltStatus>) istream)
  "Deserializes a message object of type '<PanTiltStatus>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'serial_num) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'serial_num) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'hw_version) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'hw_version) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'bd_version) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'bd_version) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sw_version) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'sw_version) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'set_zero)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'speed) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw_goal) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pitch_goal) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'reserved)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'reserved)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'driver_ec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'driver_ec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'encoder_ec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'encoder_ec)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw_now) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pitch_now) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw_temp) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pitch_temp) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'yaw_raw) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'pitch_raw) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'loop_ec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'loop_ec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'loop_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'loop_time)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PanTiltStatus>)))
  "Returns string type for a message object of type '<PanTiltStatus>"
  "pan_tilt_msgs/PanTiltStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PanTiltStatus)))
  "Returns string type for a message object of type 'PanTiltStatus"
  "pan_tilt_msgs/PanTiltStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PanTiltStatus>)))
  "Returns md5sum for a message object of type '<PanTiltStatus>"
  "c76162b6578981fa3815bffdd4df6ac3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PanTiltStatus)))
  "Returns md5sum for a message object of type 'PanTiltStatus"
  "c76162b6578981fa3815bffdd4df6ac3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PanTiltStatus>)))
  "Returns full string definition for message of type '<PanTiltStatus>"
  (cl:format cl:nil "## pan tilt ststus msg~%Header  header~%uint8   id~%string  serial_num~%string  hw_version~%string  bd_version~%string  sw_version~%uint8   set_zero~%int16   speed~%float32 yaw_goal~%float32 pitch_goal~%uint16  reserved~%uint16  driver_ec~%uint16  encoder_ec~%float32 yaw_now~%float32 pitch_now~%float32 yaw_temp~%float32 pitch_temp~%int16   yaw_raw~%int16   pitch_raw~%uint16  loop_ec~%uint16  loop_time~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PanTiltStatus)))
  "Returns full string definition for message of type 'PanTiltStatus"
  (cl:format cl:nil "## pan tilt ststus msg~%Header  header~%uint8   id~%string  serial_num~%string  hw_version~%string  bd_version~%string  sw_version~%uint8   set_zero~%int16   speed~%float32 yaw_goal~%float32 pitch_goal~%uint16  reserved~%uint16  driver_ec~%uint16  encoder_ec~%float32 yaw_now~%float32 pitch_now~%float32 yaw_temp~%float32 pitch_temp~%int16   yaw_raw~%int16   pitch_raw~%uint16  loop_ec~%uint16  loop_time~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PanTiltStatus>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4 (cl:length (cl:slot-value msg 'serial_num))
     4 (cl:length (cl:slot-value msg 'hw_version))
     4 (cl:length (cl:slot-value msg 'bd_version))
     4 (cl:length (cl:slot-value msg 'sw_version))
     1
     2
     4
     4
     2
     2
     2
     4
     4
     4
     4
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PanTiltStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'PanTiltStatus
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':serial_num (serial_num msg))
    (cl:cons ':hw_version (hw_version msg))
    (cl:cons ':bd_version (bd_version msg))
    (cl:cons ':sw_version (sw_version msg))
    (cl:cons ':set_zero (set_zero msg))
    (cl:cons ':speed (speed msg))
    (cl:cons ':yaw_goal (yaw_goal msg))
    (cl:cons ':pitch_goal (pitch_goal msg))
    (cl:cons ':reserved (reserved msg))
    (cl:cons ':driver_ec (driver_ec msg))
    (cl:cons ':encoder_ec (encoder_ec msg))
    (cl:cons ':yaw_now (yaw_now msg))
    (cl:cons ':pitch_now (pitch_now msg))
    (cl:cons ':yaw_temp (yaw_temp msg))
    (cl:cons ':pitch_temp (pitch_temp msg))
    (cl:cons ':yaw_raw (yaw_raw msg))
    (cl:cons ':pitch_raw (pitch_raw msg))
    (cl:cons ':loop_ec (loop_ec msg))
    (cl:cons ':loop_time (loop_time msg))
))
