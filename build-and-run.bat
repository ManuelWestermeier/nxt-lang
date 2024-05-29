cls

cd ./compiler
node .
pause
cls

cd ..
g++ -o out/run .\out\index.cpp
pause
cls

cd out
run.exe