    FROM gcc:5.5
    COPY . /Teste
    WORKDIR /Teste
    RUN g++ -o Teste Teste.cpp
    CMD ["./Teste"]