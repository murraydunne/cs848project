#!/bin/bash


launch_instance() {
    docker run --network="host" --gpus all -v /home/ubuntu/cs848project:/home/cs848project calumbruton/timely-experiment:v5 /bin/bash -c "cd /home/cs848project/timely_experiment/; ./target/debug/timely_experiment -w $1 -n $2 --hostfile hosts.txt -p $3" 2>&1 &
}

launch_instance 1 17 6
launch_instance 1 17 11
launch_instance 1 17 14
launch_instance 1 17 15
launch_instance 1 17 16