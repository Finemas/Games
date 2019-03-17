#!/bin/bash

for i in 1 2 3 4 5;
	do
		./a.out < $i > out
		if ! diff $i.ref out; then
			echo "Chyba. $i.in"
			exit 1
	fi
done
