#!/bin/bash

CONFIGURE=false
EXE_NAME=main
COMPILE_CMD="make"
ROOT_DIR=~/Development/cmake_c_boilerplate # <- CHANGE
RUN_TESTS=false
RUN_EXE=false

while getopts ":cte" option; do
    case $option in
        c)
            CONFIGURE=true
            ;;
        t)
            RUN_TESTS=true
            ;;

        e)
            RUN_EXE=true
            ;;
    esac
done

if [ $CONFIGURE == true ]; then
    cd $ROOT_DIR/build/
    cmake ..
fi

if [ $RUN_TESTS == true ]; then
    cd $ROOT_DIR/build/
    $COMPILE_CMD tests

    cd $ROOT_DIR/bin/
    ./tests
fi


if [ $RUN_EXE == true ]; then
    cd $ROOT_DIR/build/
    $COMPILE_CMD $EXE_NAME
    cd $ROOT_DIR/bin 
    ./$EXE_NAME
fi
