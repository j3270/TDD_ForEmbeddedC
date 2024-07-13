#!/bin/bash


cd tests

echo $'\r\n'

#********* Remove old txt files if they exist *************************************************************************
if [ -f '../gcovr/driversGcovr/driversDetailedCoverage.txt' ]; then
    echo Removing old driversDetailedCoverage txt file report
    rm ../gcovr/driversGcovr/driversDetailedCoverage.txt
fi

if [ -f '../gcovr/utilsGcovr/utilsDetailedCoverage.txt' ]; then
    echo Removing old utilsDetailedCoverage txt file report
    rm ../gcovr/utilsGcovr/utilsDetailedCoverage.txt
fi

if [ -f '../gcovr/appGcovr/appDetailedCoverage.txt' ]; then
    echo Removing old appDetailedCoverage txt file report
    rm ../gcovr/appGcovr/appDetailedCoverage.txt
fi

#********** Remove old html files if they exist ***********************************************************************
if [ -d '../gcovr/utilsGcovr' ]; then
    echo Removing old utilsGcovr html output dir
    rm -rf ../gcovr/utilsGcovr
fi
mkdir ../gcovr/utilsGcovr

if [ -d '../gcovr/driversGcovr' ]; then
    echo Removing old driversGcovr html output dir
    rm -rf ../gcovr/driversGcovr
fi
mkdir ../gcovr/driversGcovr

if [ -d '../gcovr/appGcovr' ]; then
    echo Removing old appGcovr html output dir
    rm -rf ../gcovr/appGcovr
fi
mkdir ../gcovr/appGcovr

#********** Make sure Unit Tests have been built **********************************************************************
if ! [ -d 'build' ]; then
    echo Unit Tests build doesn't exist, build Unit Tests first'
    exit -1
fi

# Have to be in build dir when using CMake; see https://gcovr.com/en/stable/cookbook.html#out-of-source-builds-with-cmake
cd build

gcovr -r ../../../../ -e ../../../../src/drivers -e ../../../../src/utils >> ../../gcovr/appGcovr/appDetailedCoverage.txt 2>&1
gcovr -r ../../../../ -e ../../../../src/drivers -e ../../../../src/utils --html-details -o ../../gcovr/appGcovr/appDetailedCoverage.html


gcovr -r ../../../../ -e ../../../../src/app -e ../../../../src/utils >> ../../gcovr/driversGcovr/driversDetailedCoverage.txt 2>&1
gcovr -r ../../../../ -e ../../../../src/app -e ../../../../src/utils --html-details -o ../../gcovr/driversGcovr/driversDetailedCoverage.html

gcovr -r ../../../../ -e ../../../../src/app -e ../../../../src/drivers >> ../../gcovr/utilsGcovr/utilsDetailedCoverage.txt 2>&1
gcovr -r ../../../../ -e ../../../../src/app -e ../../../../src/drivers --html-details -o ../../gcovr/utilsGcovr/utilsDetailedCoverage.html

cd ../../

