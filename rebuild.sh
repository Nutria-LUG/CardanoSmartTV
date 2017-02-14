#!/bin/bash

cd bin/debug
make clean
cmake ../..

cd ../release
make clean
cmake -DNDEBUG=1 ../..
cd ../..
./build.sh
