#!/bin/sh

board="dz60"
layout="splitspace"
chip="atmega32u4"

echo "Making hex file for layout $splitspace on $board"
make $board:$layout

echo "Flash the board? [y/n]"
read input
if [ "$input" == "n" ] || [ "$input" == "N" ]; then
    exit 1
fi

echo "Flashing the board in 5 seconds. hit < space + \ > for RESET mode"
for i in 5 4 3 2 1
do
    echo "$i..."
    sleep 1
done

echo "Starting..."
dfu-programmer $chip erase --force
sleep 1
dfu-programmer $chip flash "${board}_${layout}.hex"
sleep 1
dfu-programmer $chip reset

echo "Finished!"
