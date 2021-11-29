/* 
we're not going to talk about kruskal's algorithm's implementation

prim's algo:
start with random, pick edge with the minimum weight, all vertices would be covered and get minimum spanning tree with slightly different 


he'll give us a graph and ask us to find the MST using prim/kruskal (not gonna ask about complexity)


Dijkstra's algorithm:
single pair: shortest distance between u-v
single source: one origin to different vertices 
s->v3 
s->v2 
s->v1 
single destination: multiple origin single destination 
v1 ->s  
v2 ->s 
v3 ->s 
v4 ->s

all pair all possibility

weight of p: sum of all the weights of the edges 

minimize w(p) 

brute-force: find all the possible path and find the minimum (worse case factorial)
d[v] = from s to v 
relaxation: the distance will get updated from the shortest path (sen bunun hakkinda video izledin)

greedy: keep taking the shortest solution, the average will also be the shortest
dijk -> no complexity

greedy-approach: prim, dijk and kruskal are all greedy
*/ 