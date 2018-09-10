BGCPPChallenge

This project is a challenge in C++ for Altran. With a .xsd file you can create a .xml and a .json, depending on the option that you choose.
This repository contains the source code file, in C++, and a xsd file, that is an example. 

Prerequisites:
1. Install docker and use only Linux images and containers within Docker
2. Use the docker image available in https://hub.docker.com/_/gcc/ to allow C++ development 
3. Clone the repository to your machine (https://github.com/AnaDiasAltranPT/BGCPPChallenge.git)

These are the steps to execute the program:
	
	$ docker pull anamrdias/bgcppchallenge

	$ docker images

	$ docker run -d -it <image id> /bin/bash

	Note: the id is from the "anamrdias/bgcppchallenge" repository

	$ docker ps

	Note: Check wich container as the same image id as the step 4, and save the name of that container for the next step

	$ docker exec -it <container name> /bin/bash

	$ g++ Bgcppchallenge.cpp -o bgcppchallenge

	$ ./bgcppchallenge

	$ ls

	$ cat xmlFile.xml

	$ cat jsonFile.json

	Note: The steps 10 and 11 are only to check the files created in the step 8
