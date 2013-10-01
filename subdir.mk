# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AudioHandler.cpp \
../GameManager.cpp \
../GameObject.cpp \
../InputManager.cpp \
../Network.cpp \
../SDLBase.cpp \
../Shape.cpp \
../Sprite.cpp \
../TileMap.cpp \
../TileSet.cpp \
../main.cpp 

OBJS += \
./AudioHandler.o \
./GameManager.o \
./GameObject.o \
./InputManager.o \
./Network.o \
./SDLBase.o \
./Shape.o \
./Sprite.o \
./TileMap.o \
./TileSet.o \
./main.o 

CPP_DEPS += \
./AudioHandler.d \
./GameManager.d \
./GameObject.d \
./InputManager.d \
./Network.d \
./SDLBase.d \
./Shape.d \
./Sprite.d \
./TileMap.d \
./TileSet.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


