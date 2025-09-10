# hello-world-cpp-fmt

g++ -Ilibs/fmt/include main.cpp libs/fmt/src/format.cc -o main.exe

g++ -Ilibs/fmt/include main.cpp libs/fmt/src/format.cc -o main.exe -O3 -s -DNDEBUG -flto -march=native -mtune=native -fomit-frame-pointer -funroll-loops -pipe -fstack-protector-strong