#!/bin/bash
# Compile the program with code coverage flags and generate report

# Set the name of the executable program
EXEC_PROGRAM="./a.out "

######################################################################
# Initialize variables
PROG=$0
EXE="a.out"
PROFDATA=$EXE.profdata
CC=clang++

# Remove any existing files
rm $EXE $PROFDATA default.profraw 2>/dev/null

# Check if required programs are available
programs=($CC "llvm-profdata" "llvm-cov")
for p in "${programs[@]}"; do
    if ! hash $CC 2>/dev/null; then
        echo "ERROR: $PROG: cannot find $CC executable"
        exit 1
    fi
done

# Compile the program with code coverage flags
$CC -g -std=c++11 -fprofile-instr-generate -fcoverage-mapping *.cpp -o $EXE

# Check if compilation was successful
if [ ! -f $EXE ]; then
    echo "ERROR: $PROG: Failed to create executable"
    exit 1
fi

# Execute the program to generate coverage data
$EXEC_PROGRAM > /dev/null 2>/dev/null

# Check if coverage data was generated
if [ ! -f "default.profraw" ]; then
    echo "ERROR: $PROG: Failed to create default.profraw data"
    rm -rf ./a.out* 
    exit 1
fi

# Merge coverage data
llvm-profdata merge default.profraw -output=$PROFDATA

# Check if merged coverage data was generated
if [ ! -f $PROFDATA ]; then
    echo "ERROR: $PROG: Failed to create $PROFDATA"
    rm -rf ./a.out* default.profraw 
    exit 1
fi

# Generate coverage report
if hash llvm-cxxfilt 2>/dev/null; then
    llvm-cov report -show-functions=1 -Xdemangler=llvm-cxxfilt $EXE -instr-profile=$PROFDATA *.cpp
else
    llvm-cov report -show-functions=1 $EXE -instr-profile=$PROFDATA *.cpp
fi

# Display lines that were never executed
echo "====================================================="
echo "The lines below were never executed"
echo "====================================================="
llvm-cov show $EXE -instr-profile=$PROFDATA | grep " 0|"

# Clean up temporary files
rm -rf ./a.out* $EXE $PROFDATA default.profraw 2>/dev/null
