USE_RASPIKE_ART=1

mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
	util.o \
	Measure.o \
	Brightness.o \
	MyColorSensor.o \
	Polling.o \
	Length.o \
	TurnAngle.o \
	Odometry.o \
	HsvHue.o \
	HsvSatu.o \
	PID.o \
	SimpleWalker.o \
	SpeedControl.o \
	Walker.o \
	LineTracer.o \
	LowPassFilter.o \
	Scene.o \
	Section.o \
	SectionManager.o \
	SpeedSectionManager.o \
	MotorManager.o \
	Judge.o \
	JudgeLength.o \
	JudgeColor.o \
	JudgeTime.o \
	JudgeBrightness.o \
	JudgeTurnAngle.o \
	JudgeReception.o \
	XPosition.o \
	YPosition.o \
	TurnWalker.o \
	VirCurveLine.o \
	VirStraightLine.o \
	DoubleSection.o \
	BlockSection.o \
	Process.o \
	FileWalker.o \
	SmartSection.o \
	StreamCaptureRGB.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
# include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile
include $(EV3RT_SDK_LIB_DIR)/libcpp-spike/Makefile

endif

APPL_LIBS += -lm -lstdc++ -lopencv_core -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui 

APPL_DIRS += $(mkfile_path)app $(mkfile_path)unit $(mkfile_path)device $(mkfile_path)walker $(mkfile_path)section $(mkfile_path)judge $(mkfile_path)measure $(mkfile_path)communication \
		  	$(mkfile_path)camera
INCLUDES += \
	-I/usr/include/opencv4 \
	-I$(mkfile_path)app \
	-I$(mkfile_path)device \
	-I$(mkfile_path)walker \
	-I$(mkfile_path)section \
	-I$(mkfile_path)judge \
	-I$(mkfile_path)measure \
	-I$(mkfile_path)communication \
	-I$(mkfile_path)camera
	

# COPTS += -fno-use-cxa-atexit
COPTS += -std=c++11
