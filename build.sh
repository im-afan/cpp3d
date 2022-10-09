echo 'building project...'
g++ -I /usr/include/xtensor ./src/main.cpp -o main
echo 'running...'
./main
