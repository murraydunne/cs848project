#!/bin/bash


launch_instance() {
    docker run --network="host" --gpus all -v /home/ubuntu/cs848project:/home/cs848project calumbruton/timely-experiment:v5 /bin/bash -c "cd /home/cs848project/timely_experiment/; ./target/debug/timely_experiment -w $1 -n $2 --hostfile hosts.txt -p $3" 2>&1 | tee output-$3.txt &
}

launch_instance 1 17 4
launch_instance 1 17 5
launch_instance 1 17 9
launch_instance 1 17 10
launch_instance 1 17 13