#!/bin/bash


launch_instance() {
    RUST_BACKTRACE=full sudo docker run --rm --network="host" -v /home/pc-admin/cs848project:/home/cs848project calumbruton/cs848:v7 /bin/bash -c "cd /home/cs848project/timely_experiment/; ./target/debug/timely_experiment -w $1 -n $2 --hostfile hosts.txt -p $3" &
}

launch_instance 1 15 0
launch_instance 1 15 1
launch_instance 1 15 2
launch_instance 1 15 3
launch_instance 1 15 4
launch_instance 1 15 5
launch_instance 1 15 6
launch_instance 1 15 7
launch_instance 1 15 8
launch_instance 1 15 9
launch_instance 1 15 10
launch_instance 1 15 11
launch_instance 1 15 12
launch_instance 1 15 13
launch_instance 1 15 14