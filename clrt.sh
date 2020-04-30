#! /bin/bash

runFile="test.c"
executable=$1

rm -rf *.o

if [[ -n $executable ]]
  then
    runFile=$executable
fi
list=($(ls))
for file in ${list[*]};
do 
  if [ $file != *$runFile* ] && [[ $file == *".c"* ]]
    then gcc -c $file
  fi
done
gcc -o main *.o
./main
rm -rf *.o main