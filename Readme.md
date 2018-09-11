BGCPPChallenge

This project is a challenge in C++ for Altran. With a .xsd file you can create a .xml and a .json, depending on the option that you choose.
This repository contains the source code file, in C++, and a xsd file, that is an example. 

Prerequisites:
1. Install docker and use only Linux images and containers within Docker
2. Use the docker image available in https://hub.docker.com/_/gcc/ to allow C++ development 
3. Clone the repository to your machine (https://github.com/AnaDiasAltranPT/BGCPPChallenge.git)

These are the steps to execute the program:
	
	$ cd <local repository folder>
	
	$ docker pull anamrdias/bgcppchallenge
	
	$ docker run -d -it gcc /bin/bash
	
	$ docker ps
	
	$ docker cp <source code file> <container>:/<source code file>
	
	$ docker exec -it <container> /bin/bash
	
	$ <execute steps to setup required libraries to compile and execute the program mentioned in the Readme.md>
	
	$ g++ <source code file(s)> -o <executable file> -l <library1> -l <library1>
	
	$ ./<executable file> <XSD file location
	
	$ cat xmlFile.xml

	$ cat jsonFile.json

	Note: The final 2 steps are only to check the files created before, to validate the xml and json go to http://www.utilities-online.info/


