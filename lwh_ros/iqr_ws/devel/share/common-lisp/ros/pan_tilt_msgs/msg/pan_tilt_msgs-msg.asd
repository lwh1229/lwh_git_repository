
(cl:in-package :asdf)

(defsystem "pan_tilt_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "PanTiltCmdDeg" :depends-on ("_package_PanTiltCmdDeg"))
    (:file "_package_PanTiltCmdDeg" :depends-on ("_package"))
    (:file "PanTiltCmdRad" :depends-on ("_package_PanTiltCmdRad"))
    (:file "_package_PanTiltCmdRad" :depends-on ("_package"))
    (:file "PanTiltStatus" :depends-on ("_package_PanTiltStatus"))
    (:file "_package_PanTiltStatus" :depends-on ("_package"))
  ))