echo 'building project...'
g++ -I /usr/include/xtensor -I ./src/engine ./src/main.cpp -o main
echo 'running...'
./main
