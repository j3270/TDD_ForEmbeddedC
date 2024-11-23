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
if ! [ -d './build' ]; then
    echo $'\r\n' Build directory does not exist, configure build with configCmakeBuild.sh first $'\r\n'
else
    echo $'\r\n' Building CMake build configuration $buildConfig $'\r\n'
    cmake --build ./build --config $buildConfig --target all --
    if [ $? != 0 ]; then
        echo $'\r\n'
        echo CMake build of $buildDir with build configuration of $buildConfig failed!
        exit 1
    fi
fi

cd ..
