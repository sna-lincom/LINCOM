#!/bin/bash

if (( $# == 0 )); then
  echo "Give filename of edgelist as a command line argument to the script"
  exit
fi

filename=$1
r=0.75
gcc LINCOM_ins.c -o output

echo r = $r
./output $filename $r

if (($? != 0)); then
  echo "seg fault in LINCOM, exiting out"
  exit
fi
if [ ! -f Membership_$filename ]; then
  echo Only one community
  exit
fi
./convert -i $filename -o graph.bin -r labels
./louvain graph.bin -p Membership_$filename

rm graph.bin
rm Membership_$filename
rm labels
