;; Auto-generated. Do not edit!


(when (boundp 'pan_tilt_msgs::PanTiltStatus)
  (if (not (find-package "PAN_TILT_MSGS"))
    (make-package "PAN_TILT_MSGS"))
  (shadow 'PanTiltStatus (find-package "PAN_TILT_MSGS")))
(unless (find-package "PAN_TILT_MSGS::PANTILTSTATUS")
  (make-package "PAN_TILT_MSGS::PANTILTSTATUS"))

(in-package "ROS")
;;//! \htmlinclude PanTiltStatus.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass pan_tilt_msgs::PanTiltStatus
  :super ros::object
  :slots (_header _id _serial_num _hw_version _bd_version _sw_version _set_zero _speed _yaw_goal _pitch_goal _reserved _driver_ec _encoder_ec _yaw_now _pitch_now _yaw_temp _pitch_temp _yaw_raw _pitch_raw _loop_ec _loop_time ))

(defmethod pan_tilt_msgs::PanTiltStatus
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:id __id) 0)
    ((:serial_num __serial_num) "")
    ((:hw_version __hw_version) "")
    ((:bd_version __bd_version) "")
    ((:sw_version __sw_version) "")
    ((:set_zero __set_zero) 0)
    ((:speed __speed) 0)
    ((:yaw_goal __yaw_goal) 0.0)
    ((:pitch_goal __pitch_goal) 0.0)
    ((:reserved __reserved) 0)
    ((:driver_ec __driver_ec) 0)
    ((:encoder_ec __encoder_ec) 0)
    ((:yaw_now __yaw_now) 0.0)
    ((:pitch_now __pitch_now) 0.0)
    ((:yaw_temp __yaw_temp) 0.0)
    ((:pitch_temp __pitch_temp) 0.0)
    ((:yaw_raw __yaw_raw) 0)
    ((:pitch_raw __pitch_raw) 0)
    ((:loop_ec __loop_ec) 0)
    ((:loop_time __loop_time) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _id (round __id))
   (setq _serial_num (string __serial_num))
   (setq _hw_version (string __hw_version))
   (setq _bd_version (string __bd_version))
   (setq _sw_version (string __sw_version))
   (setq _set_zero (round __set_zero))
   (setq _speed (round __speed))
   (setq _yaw_goal (float __yaw_goal))
   (setq _pitch_goal (float __pitch_goal))
   (setq _reserved (round __reserved))
   (setq _driver_ec (round __driver_ec))
   (setq _encoder_ec (round __encoder_ec))
   (setq _yaw_now (float __yaw_now))
   (setq _pitch_now (float __pitch_now))
   (setq _yaw_temp (float __yaw_temp))
   (setq _pitch_temp (float __pitch_temp))
   (setq _yaw_raw (round __yaw_raw))
   (setq _pitch_raw (round __pitch_raw))
   (setq _loop_ec (round __loop_ec))
   (setq _loop_time (round __loop_time))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serial_num
   (&optional __serial_num)
   (if __serial_num (setq _serial_num __serial_num)) _serial_num)
  (:hw_version
   (&optional __hw_version)
   (if __hw_version (setq _hw_version __hw_version)) _hw_version)
  (:bd_version
   (&optional __bd_version)
   (if __bd_version (setq _bd_version __bd_version)) _bd_version)
  (:sw_version
   (&optional __sw_version)
   (if __sw_version (setq _sw_version __sw_version)) _sw_version)
  (:set_zero
   (&optional __set_zero)
   (if __set_zero (setq _set_zero __set_zero)) _set_zero)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:yaw_goal
   (&optional __yaw_goal)
   (if __yaw_goal (setq _yaw_goal __yaw_goal)) _yaw_goal)
  (:pitch_goal
   (&optional __pitch_goal)
   (if __pitch_goal (setq _pitch_goal __pitch_goal)) _pitch_goal)
  (:reserved
   (&optional __reserved)
   (if __reserved (setq _reserved __reserved)) _reserved)
  (:driver_ec
   (&optional __driver_ec)
   (if __driver_ec (setq _driver_ec __driver_ec)) _driver_ec)
  (:encoder_ec
   (&optional __encoder_ec)
   (if __encoder_ec (setq _encoder_ec __encoder_ec)) _encoder_ec)
  (:yaw_now
   (&optional __yaw_now)
   (if __yaw_now (setq _yaw_now __yaw_now)) _yaw_now)
  (:pitch_now
   (&optional __pitch_now)
   (if __pitch_now (setq _pitch_now __pitch_now)) _pitch_now)
  (:yaw_temp
   (&optional __yaw_temp)
   (if __yaw_temp (setq _yaw_temp __yaw_temp)) _yaw_temp)
  (:pitch_temp
   (&optional __pitch_temp)
   (if __pitch_temp (setq _pitch_temp __pitch_temp)) _pitch_temp)
  (:yaw_raw
   (&optional __yaw_raw)
   (if __yaw_raw (setq _yaw_raw __yaw_raw)) _yaw_raw)
  (:pitch_raw
   (&optional __pitch_raw)
   (if __pitch_raw (setq _pitch_raw __pitch_raw)) _pitch_raw)
  (:loop_ec
   (&optional __loop_ec)
   (if __loop_ec (setq _loop_ec __loop_ec)) _loop_ec)
  (:loop_time
   (&optional __loop_time)
   (if __loop_time (setq _loop_time __loop_time)) _loop_time)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _id
    1
    ;; string _serial_num
    4 (length _serial_num)
    ;; string _hw_version
    4 (length _hw_version)
    ;; string _bd_version
    4 (length _bd_version)
    ;; string _sw_version
    4 (length _sw_version)
    ;; uint8 _set_zero
    1
    ;; int16 _speed
    2
    ;; float32 _yaw_goal
    4
    ;; float32 _pitch_goal
    4
    ;; uint16 _reserved
    2
    ;; uint16 _driver_ec
    2
    ;; uint16 _encoder_ec
    2
    ;; float32 _yaw_now
    4
    ;; float32 _pitch_now
    4
    ;; float32 _yaw_temp
    4
    ;; float32 _pitch_temp
    4
    ;; int16 _yaw_raw
    2
    ;; int16 _pitch_raw
    2
    ;; uint16 _loop_ec
    2
    ;; uint16 _loop_time
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _id
       (write-byte _id s)
     ;; string _serial_num
       (write-long (length _serial_num) s) (princ _serial_num s)
     ;; string _hw_version
       (write-long (length _hw_version) s) (princ _hw_version s)
     ;; string _bd_version
       (write-long (length _bd_version) s) (princ _bd_version s)
     ;; string _sw_version
       (write-long (length _sw_version) s) (princ _sw_version s)
     ;; uint8 _set_zero
       (write-byte _set_zero s)
     ;; int16 _speed
       (write-word _speed s)
     ;; float32 _yaw_goal
       (sys::poke _yaw_goal (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pitch_goal
       (sys::poke _pitch_goal (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint16 _reserved
       (write-word _reserved s)
     ;; uint16 _driver_ec
       (write-word _driver_ec s)
     ;; uint16 _encoder_ec
       (write-word _encoder_ec s)
     ;; float32 _yaw_now
       (sys::poke _yaw_now (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pitch_now
       (sys::poke _pitch_now (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _yaw_temp
       (sys::poke _yaw_temp (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pitch_temp
       (sys::poke _pitch_temp (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int16 _yaw_raw
       (write-word _yaw_raw s)
     ;; int16 _pitch_raw
       (write-word _pitch_raw s)
     ;; uint16 _loop_ec
       (write-word _loop_ec s)
     ;; uint16 _loop_time
       (write-word _loop_time s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; string _serial_num
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _serial_num (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _hw_version
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _hw_version (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _bd_version
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _bd_version (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _sw_version
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _sw_version (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _set_zero
     (setq _set_zero (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _speed
     (setq _speed (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float32 _yaw_goal
     (setq _yaw_goal (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pitch_goal
     (setq _pitch_goal (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint16 _reserved
     (setq _reserved (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _driver_ec
     (setq _driver_ec (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _encoder_ec
     (setq _encoder_ec (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float32 _yaw_now
     (setq _yaw_now (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pitch_now
     (setq _pitch_now (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _yaw_temp
     (setq _yaw_temp (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pitch_temp
     (setq _pitch_temp (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int16 _yaw_raw
     (setq _yaw_raw (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _pitch_raw
     (setq _pitch_raw (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _loop_ec
     (setq _loop_ec (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _loop_time
     (setq _loop_time (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get pan_tilt_msgs::PanTiltStatus :md5sum-) "c76162b6578981fa3815bffdd4df6ac3")
(setf (get pan_tilt_msgs::PanTiltStatus :datatype-) "pan_tilt_msgs/PanTiltStatus")
(setf (get pan_tilt_msgs::PanTiltStatus :definition-)
      "## pan tilt ststus msg
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

")



(provide :pan_tilt_msgs/PanTiltStatus "c76162b6578981fa3815bffdd4df6ac3")


