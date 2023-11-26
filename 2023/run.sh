#!/bin/bash
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 'day number' 'task number'"
    exit 1
fi

task=$2
day=$1
if ((day < 1 || day > 24)); then
      echo "Invaild day number: $day"
    exit 1
fi

# Paths
dir=day$1
src=($dir/main.cpp common/AdventOfCodeRunner.cpp)
input=$dir/input
bin=aoc-day$1

# Compler options
CC=clang++
CXX="-Icommon -g -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer"

# Compile, run cleanup
$CC ${src[*]} $CXX -o $bin
./$bin $task $input
rm $bin
