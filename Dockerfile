    FROM gcc:5.5
    COPY . /BGCPPChallenge 
    WORKDIR /BGCPPChallenge 
    RUN g++ BGCPPChallenge.cpp -o BGCPPChallenge 
    CMD ["./BGCPPChallenge"]
