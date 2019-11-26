#!/bin/bash


launch_instance() {
    RUST_BACKTRACE=full sudo docker run --rm --network="host" -v /home/pc-admin/cs848project:/home/cs848project calumbruton/cs848:v7 /bin/bash -c "cd /home/cs848project/timely_experiment/; ./target/debug/timely_experiment -w $1 -n $2 --hostfile hosts.txt -p $3" &
}

launch_instance 1 17 0
launch_instance 1 17 1
launch_instance 1 17 2
launch_instance 1 17 3
launch_instance 1 17 4
launch_instance 1 17 5
launch_instance 1 17 6
launch_instance 1 17 7
launch_instance 1 17 8
launch_instance 1 17 9
launch_instance 1 17 10
launch_instance 1 17 11
launch_instance 1 17 12
launch_instance 1 17 13
launch_instance 1 17 14
launch_instance 1 17 15
launch_instance 1 17 16