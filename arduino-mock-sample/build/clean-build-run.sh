#!/bin/bash
echo "cleaning the directory.."
find . ! -name 'clean-build-run.sh' -type f -exec rm -f {} +
echo "CMaking to generate makefile.."
cmake ..
echo "building.."
make
echo "running the executable.."
./arduino-mock-sample-exe
