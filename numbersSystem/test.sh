#!/bin/bash

PROG=./a.out
GREEN='\e[32m'
RED='\e[31m'
NC='\e[0m'

for IN_FILE in 0*_in.txt; do
  REF_FILE=`echo -n $IN_FILE | sed 's/in/out/'`
  $PROG < $IN_FILE > my_out.txt
  if ! diff $REF_FILE my_out.txt ; then
    printf "${RED}FAIL${NC}: $IN_FILE\n"
  else
    printf "${GREEN}SUCCESS${NC}: $IN_FILE\n"
  fi
done
