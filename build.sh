#!/bin/bash
echo "====================="
echo "==  DEBUG VERSION  =="
echo "====================="

cd bin/debug
make
cd ../..

echo "====================="
echo "== RELEASE VERSION =="
echo "====================="

cd bin/release
make
cd ../..
