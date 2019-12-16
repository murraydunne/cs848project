#!/bin/bash


launch_instance() {
    docker run --network="host" --gpus all -v /home/ubuntu/cs848project:/home/cs848project calumbruton/timely-experiment:v5 /bin/bash -c "cd /home/cs848project/timely_experiment/; ./target/debug/timely_experiment -w $1 -n $2 --hostfile hosts.txt -p $3" 2>&1 | tee output-$3.txt &
}

launch_instance 1 17 2
launch_instance 1 17 3
launch_instance 1 17 7
launch_instance 1 17 8
launch_instance 1 17 12