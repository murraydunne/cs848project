import itertools
import sys

num_replicas = int(sys.argv[1])

replica_list = [x for x in range(num_replicas)]
replica_perms = [x for x in itertools.permutations(replica_list)]



def pick(me, live_replicas):
    if me in live_replicas:
        return me

    dead_replicas = sorted(list(set([x for x in range(num_replicas)]) - set(live_replicas)))
    return live_replicas[dead_replicas.index(me) % len(live_replicas)]
    

for num_failures in range(num_replicas):

    failed_node_possiblities = [x for x in itertools.combinations([y for y in range(num_replicas)], num_failures)]

    for failed_nodes in failed_node_possiblities:

        num_picked = [0] * num_replicas
        alive_nodes = list(set(replica_list) - set(failed_nodes))

        for i in range(num_replicas):
            num_picked[pick(i, alive_nodes)] += 1

        print(num_failures, "failure(s), picked:", num_picked)
