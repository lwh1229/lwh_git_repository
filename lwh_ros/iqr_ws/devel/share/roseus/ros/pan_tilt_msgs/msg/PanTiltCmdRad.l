;; Auto-generated. Do not edit!


(when (boundp 'pan_tilt_msgs::PanTiltCmdRad)
  (if (not (find-package "PAN_TILT_MSGS"))
    (make-package "PAN_TILT_MSGS"))
  (shadow 'PanTiltCmdRad (find-package "PAN_TILT_MSGS")))
(unless (find-package "PAN_TILT_MSGS::PANTILTCMDRAD")
  (make-package "PAN_TILT_MSGS::PANTILTCMDRAD"))

(in-package "ROS")
;;//! \htmlinclude PanTiltCmdRad.msg.html


(defclass pan_tilt_msgs::PanTiltCmdRad
  :super ros::object
  :slots (_yaw _pitch _speed ))

(defmethod pan_tilt_msgs::PanTiltCmdRad
  (:init
   (&key
    ((:yaw __yaw) 0.0)
    ((:pitch __pitch) 0.0)
    ((:speed __speed) 0.0)
    )
   (send-super :init)
   (setq _yaw (float __yaw))
   (setq _pitch (float __pitch))
   (setq _speed (float __speed))
   self)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:serialization-length
   ()
   (+
    ;; float64 _yaw
    8
    ;; float64 _pitch
    8
    ;; float64 _speed
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _yaw
     (setq _yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pitch
     (setq _pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _speed
     (setq _speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get pan_tilt_msgs::PanTiltCmdRad :md5sum-) "d053c1cec7acafefd82c6ee30134df7a")
(setf (get pan_tilt_msgs::PanTiltCmdRad :datatype-) "pan_tilt_msgs/PanTiltCmdRad")
(setf (get pan_tilt_msgs::PanTiltCmdRad :definition-)
      "## pan tilt control msg
## pan tilt yaw angle :rad
float64 yaw

## pan tilt pitch angle :rad
float64 pitch 

## pan tilt speed :rad/s
float64 speed

")



(provide :pan_tilt_msgs/PanTiltCmdRad "d053c1cec7acafefd82c6ee30134df7a")


