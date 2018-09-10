BGCPPChallenge

This project is a challenge in C++ for Altran. With a .xsd file you can create a .xml and a .json, depending on the option that you choose.
This repository contains the source code file, in C++, and a xsd file, that is an example.

Prerequisites:
1. Install docker and use only Linux images and containers within Docker
2. Use the docker image available in https://hub.docker.com/_/gcc/ to allow C++ development 

These are the steps to execute the program:
1. git clone 
2. cd <local repository folder>
3. docker run -d -it gcc /bin/bash
4. docker ps
5. docker cp <source code file> <container>:/<source code file>
6. docker exec -it <container> /bin/bash
7. <execute steps to setup required libraries to compile and execute the program mentioned in the Readme.md>
8. g++ <source code file(s)> -o <executable file> -l <library1> -l <library1>
9. ./<executable file> <XSD file location>
