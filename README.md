# ros-gitlab-ci-example
An attempt at a minimal, opinionated [ROS](www.ros.org) workspace that can be built and tested using [GitLab CI](https://about.gitlab.com/)

## Overview
This has been made for experimental use on a bare-metal server, so configuration for Docker, more complicated mock hardware systems, or really any non-trivial setup would likely need some more work. 

The expected testing cases for a sensible robot project would be something like:

- Unit/library tests, which test library code and functions in isolation from the ROS system. These tests are primarily simple `gtest` tests.
- Integration tests, which spin up more complicated test cases. These tests make use of `rostest` and `gtest`.
- Acceptance tests, which spin up the entire system and manipulate it externally. While this can be done using any number of communication protocols, I've chosen HTTP as it plays nice with everyone. 

This testing setup makes use of a few tools which are assumed to be pre-installed on the target machine. The tools used are:

- ROS and Catkin for the builds and the actual project, and ROS GTest for testing. I've put in flags for checking for Kinetic or Melodic. This was built with a server deployment in mind, so I've used `sudo apt-get install ros-{DISTRO}-ros-base` as the base installation
- [xsltproc](http://xmlsoft.org/XSLT/xsltproc.html) for parsing JUnit test output into HTML
- [Gitlab Pages](https://about.gitlab.com/features/pages/) for displaying said HTML pages
- [Newman](https://www.npmjs.com/package/newman) for running acceptance tests. `newman` requires [NodeJS](https://nodejs.org/) as a pre-requisite

If you are trying to run this on a local server, to get Pages to run you will need a DNS server if you don't have one already - [dnsmasq](www.thekelleys.org.uk/dnsmasq/doc.html) or [bind9](https://www.isc.org/downloads/bind/) worked for me.

## Usage
Be first sure your GitLab instance is set up fully with a Runner and Pages both working. Being able to build and view one of the [example GitLab page repos](https://gitlab.com/pages) is a good indication things are working.

Make a new CI project from the Github source. Then, go to CI and start a pipeline. Gitlab should pick up the `.gitlab-ci.yml` file and start building the phases. Once completed, go to Pages in the Project overview, and you should have a rough hewn page containing all the results. 

## Acknowledgements
Props to all the Open Source authors that make this stuff possible, built on the shoulders of giants. 
XML parsing adapted from [wadefelix's XML style sheet](https://github.com/wadefelix/gtxslt) - cheers buddy!