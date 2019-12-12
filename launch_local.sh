#!/bin/bash


launch_instance() {
    ./timely_experiment/target/debug/timely_experiment -w $1 -n $2 --hostfile timely_experiment/hosts2.txt -p $3 &
}

launch_instance 1 13 0
launch_instance 1 13 1
launch_instance 1 13 2
launch_instance 1 13 3
launch_instance 1 13 4
launch_instance 1 13 5
launch_instance 1 13 6
launch_instance 1 13 7
launch_instance 1 13 8
launch_instance 1 13 9
launch_instance 1 13 10
launch_instance 1 13 11
launch_instance 1 13 12