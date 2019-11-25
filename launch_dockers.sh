#!/bin/bash


launch_instance() {
    RUST_BACKTRACE=full sudo docker run --rm --network="host" -v /home/pc-admin/cs848project:/home/cs848project calumbruton/cs848:v7 /bin/bash -c "cd /home/cs848project/timely_experiment/; ./target/debug/timely_experiment -w $1 -n $2 --hostfile hosts.txt -p $3" &
}

launch_instance 1 10 0
launch_instance 1 10 1
launch_instance 1 10 2
launch_instance 1 10 3
launch_instance 1 10 4
launch_instance 1 10 5
launch_instance 1 10 6
launch_instance 1 10 7
launch_instance 1 10 8
launch_instance 1 10 9