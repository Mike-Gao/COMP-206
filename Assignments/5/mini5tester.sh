#!/bin/bash

# make the database file
echo "10,bob,18,3.5" > database.csv
echo "15,mary,20,4.0" >> database.csv
echo "5,tom, 17 , 3.8" >> database.csv

echo "The following are errors"

# Errong in CMD

./database BUILD
./database show

# Error in argument count

./database
./database DELETE
./database ADD 11 bobby 19

# Correct statements

echo "The following should work"

./database SHOW
./database DELETE 10
./database ADD 11 bobby 19 2.5

