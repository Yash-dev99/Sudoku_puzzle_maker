#!/bin/sh

while true;
do
	./gen > in;
	./solver < in;
	echo "";
done;
