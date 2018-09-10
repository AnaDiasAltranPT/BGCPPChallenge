    FROM gcc:5.5
    COPY . /BGCPPChallenge 
    WORKDIR /BGCPPChallenge 
    RUN g++ -o BGCPPChallenge BGCPPChallenge.cpp
    CMD ["./BGCPPChallenge"]
