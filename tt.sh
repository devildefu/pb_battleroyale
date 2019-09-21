#!/bin/bash

FILES=$(find ./include -type f \( -name '*.hpp' -o -name '*.cpp' \))
echo $FILES
clang-format -i ${FILES}