#!/bin/bash

newman run RosTestMockApi.postman_collection.json -r junit --reporter-junit-export acceptance_tests.xml