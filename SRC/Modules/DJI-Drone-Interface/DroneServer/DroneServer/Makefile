OBJS	= DroneComms.o RealDrone.o SimulatedDrone.o Main.o
SOURCE	= DroneComms.cpp RealDrone.cpp SimulatedDrone.cpp Main.cpp
HEADER	= DroneManager.hpp DroneComms.hpp DroneDataStructures.h Drone.hpp
OUT	= DroneServer
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++17
LFLAGS	 = -L/usr/local/lib/ -lpthread -ltacopie -lopencv_core -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgproc  -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab -lopencv_videoio

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

DroneComms.o: DroneComms.cpp
	$(CC) $(FLAGS) DroneComms.cpp 

RealDrone.o: RealDrone.cpp
	$(CC) $(FLAGS) RealDrone.cpp 

SimulatedDrone.o: SimulatedDrone.cpp
	$(CC) $(FLAGS) SimulatedDrone.cpp 

Main.o: Main.cpp
	$(CC) $(FLAGS) Main.cpp 


clean:
	rm -f $(OBJS) $(OUT)

