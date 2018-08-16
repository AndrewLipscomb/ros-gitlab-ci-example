#!/bin/bash

if [[ $ALLOW_FAILING_TESTS -eq "1" ]]; then
    echo "Test failure is permitted - newman results are not being checked";
    exit 0;
else 
    exit $NEWMAN_RETURN_CODE;
fi
