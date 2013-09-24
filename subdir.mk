################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Earth.cpp \
../FollowerObject.cpp \
../GameManager.cpp \
../GameObject.cpp \
../InputManager.cpp \
../Moon.cpp \
../Planet.cpp \
../PlanetRed.cpp \
../Planeta.cpp \
../SDLBase.cpp \
../Sprite.cpp \
../TileMap.cpp \
../TileSet.cpp \
../main.cpp 

OBJS += \
./Earth.o \
./FollowerObject.o \
./GameManager.o \
./GameObject.o \
./InputManager.o \
./Moon.o \
./Planet.o \
./PlanetRed.o \
./Planeta.o \
./SDLBase.o \
./Sprite.o \
./TileMap.o \
./TileSet.o \
./main.o 

CPP_DEPS += \
./Earth.d \
./FollowerObject.d \
./GameManager.d \
./GameObject.d \
./InputManager.d \
./Moon.d \
./Planet.d \
./PlanetRed.d \
./Planeta.d \
./SDLBase.d \
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


