#LINCOM for disjoint clusters

This package finds out disjoint clusters and its modularity for different Influenced Neighbour Score (INS) values (0.4 to 0.85 interval of 0.05) and for different starting nodes.

##Execution

###Different INS values:

- Commands:

```
$ make                           #builds the Louvain code for your architecture
$ ./script_ins.sh <input_graph>  #runs iterations on LINCOM_disjoint for different INS values.
```

- Sample Output (On Console) :

```
r = 0.7
No. of communities before mod max : 2
Initial modularity: 0.354947
Number of communities after mod max: 2
Final modularity: 0.371795

r = 0.75
No. of communities before mod max : 2
Initial modularity: 0.354947
Number of communities after mod max: 2
Final modularity: 0.371795

r = 0.8
No. of communities before mod max : 4
Initial modularity: 0.3607
Number of communities after mod max: 4
Final modularity: 0.41979
```

- Generated output file:                  
    Filename: disjoint_ins            
    Output format:              
    (ins_value) (no_of_comm) (disjoint_modularity)

### Different Starting Node:

- Commands:

```
$ make                                 #builds the Louvain code for your architecture
$ gcc LINCOM_start_node.c -o output    #runs iterations on LINCOM_disjoint for different starting nodes.
$ ./output <input_graph> <ins_value>   #generates covers for different starting nodes
```

- Sample Output (On Console):

```
start_node = 32
degree of start_node = 6
No. of communities before mod max : 4
Initial modularity: 0.366782
Number of communities after mod max: 4
Final modularity: 0.406969

start_node = 33
degree of start_node = 12
No. of communities before mod max : 3
Initial modularity: 0.233153
Number of communities after mod max: 3
Final modularity: 0.38141

start_node = 34
degree of start_node = 17
No. of communities before mod max : 2
Initial modularity: 0.201183
Number of communities after mod max: 2
Final modularity: 0.371795

```

- Generated output file:

    Filename: disjoint_start_node_input_filename        
    Output format:            
    (node_label) (disjoint_modularity)
