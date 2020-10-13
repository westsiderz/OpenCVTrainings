#!/bin/sh

rm -rf ../build
mkdir ../build

cmake -G "Eclipse CDT4 - Unix Makefiles" -S . -B ../build

cd ../build

make
