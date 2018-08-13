#!/bin/bash

if [[ $ALLOW_FAILING_TESTS -eq "1" ]]; then
    echo "Test failure is permitted - catkin results are not being checked";
    exit 0;
else 
    catkin_test_results;
    exit $?;
fi