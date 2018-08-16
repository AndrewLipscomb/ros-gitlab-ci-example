#!/bin/bash

newman run RosTestMockApi.postman_collection.json -r ros-scenario --reporter-export acceptance_tests.xml;
export NEWMAN_RETURN_CODE=$?;