#!/bin/bash

# Initialize Program
echo "Program Overview:"
echo "1. Record memory usage every 15 seconds"
echo "2. Open 10 new instances of firefox"
echo ""

echo "Program will be starting in 5 seconds..."
echo ""
sleep 5 # Sleep for 5 seconds
clear # Clear terminal

# Program Start
SECONDS=0

echo "Round 1 - No Process" | tee output.txt #Create output file with no process
echo "Time Elapsed (sec): $SECONDS" | tee -a output.txt

echo "Sleeping for 15 seconds..."
sleep 15

free --mega | tee -a output.txt  
echo "" | tee -a output.txt


x=2
while [ $x -le 10 ]
do
     echo "Round $x - Start 3 Firefox processes" | tee -a output.txt
     echo "Time Elapsed (sec): $SECONDS" | tee -a output.txt

     #Start 3 firefox processes
     firefox &
     firefox &
     firefox &

     echo "Sleeping for 15 seconds..."
     sleep 15

     free --mega | tee -a output.txt
     echo "" | tee -a output.txt

     ((x++)) # Increment counter
done 

echo "Clearing all firefox processes in 5 seconds..."
sleep 5
pkill -f firefox
echo "Processes cleared."
