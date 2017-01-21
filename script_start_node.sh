if (( $# == 0 )); then
  echo "Give filename of edgelist as a command line argument to the script"
  exit
fi

filename=$1
node_label=$2

report="disjoint_start_node_$filename"

if [ $node_label -eq 1 ] && [ -e $report ]
then
  rm $report
fi

if [ -f Membership_$filename ]; then
  ./convert -i $filename -o graph.bin -r labels
  louvain_output=$(./louvain graph.bin -p Membership_$filename 2>&1 | tee /dev/tty)
  no_of_comm=`echo "$louvain_output" | awk -F': ' 'NR==2{print $2}'`
  final_modularity=`echo "$louvain_output" | awk -F': ' 'NR==3{print $2}'`

  echo $node_label $no_of_comm $final_modularity >> $report

  echo
  rm graph.bin
  rm Membership_$filename
  rm labels

else
  echo $node_label 0 >> $report
  echo Only one community
fi
