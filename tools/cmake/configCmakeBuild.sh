#!/bin/bash

buildConfig=$1
buildDrir=$2

if (( [ -z "$buildConfig" ] ) || ([ $buildConfig != "debug" ] && [ $buildConfig != "release" ])); then
    echo Build config $buildConfig is undefined,
    echo available options are debug and release
    exit 1
fi

if (( [ -z "$buildDrir" ] ) || ([ $buildDrir != "app" ] && [ $buildDrir != "tests" ])); then
    echo Build directory, $buildDrir is undefined,
    echo available options are app and tests
    exit 1
fi

cd $buildDrir

echo $'\r\n'
if [ -d './build' ] ; then
    echo Removing build dir
    rm -rf ./build
fi

if [ -d './gcovr' ] ; then
    echo Removing gcovr dir
    rm -rf ./gcovr
fi

#Check if we have ninja available. To get is run apt-get install ninja-build
if ! [ -x "$(command -v ninja)" ]; then
   cmakeGenerator="Unix Makefiles"
   echo "ninja could not be found"
   echo "To get is run apt-get install ninja-build"
else
   cmakeGenerator=Ninja
   echo "ninja found"
fi

echo $'\r\n' Configuring $buildDir for CMake build configuration $buildConfig with generator $cmakeGenerator $'\r\n'
if [ $buildDrir == "app" ]; then
    # Uncomment following line and provide a app_toolchain_file.cmake file if cross compiling 
    #cmake -DCMAKE_BUILD_TYPE:STRING=$buildConfig -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_TOOLCHAIN_FILE:FILEPATH=app_toolchain_file.cmake -S . -B ./build -G "$cmakeGenerator"
    cmake -DCMAKE_BUILD_TYPE:STRING=$buildConfig -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -S . -B ./build -G "$cmakeGenerator"
else
    cmake -DCMAKE_BUILD_TYPE:STRING=$buildConfig -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -S . -B ./build -G "$cmakeGenerator"
fi

if [ $? != 0 ]; then
    echo $'\r\n'
    echo CMake Configuration of $buildDir with build configuration of $buildConfig failed!
    exit 1
fi

cd ..
