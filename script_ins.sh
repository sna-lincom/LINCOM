#!/bin/bash
if (( $# == 0 )); then
  echo "Give filename of edgelist as a command line argument to the script"
  exit
fi

filename=$1
gcc LINCOM_ins.c -o output

report="disjoint_ins"
if [ -e $report ]
then
  rm $report
fi

for r in $(seq 0.4 0.05 0.85)
do
  echo r = $r
  ./output $filename $r

  if (($? != 0)); then
    echo "seg fault in LINCOM, breaking out"
    echo
    break
  fi
  if [ ! -f Membership_$filename ]; then
    echo Only one community
    echo $r 1 0 >> $report
    continue
  fi
  ./convert -i $filename -o graph.bin -r labels

  louvain_output=$(./louvain graph.bin -p Membership_$filename 2>&1 | tee /dev/tty)
  no_of_comm=`echo "$louvain_output" | awk -F': ' 'NR==2{print $2}'`
  final_modularity=`echo "$louvain_output" | awk -F': ' 'NR==3{print $2}'`

  echo $r $no_of_comm $final_modularity >> $report
  echo
  rm graph.bin
  rm Membership_$filename
  rm labels
done
