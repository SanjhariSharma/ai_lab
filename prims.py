def prim(graph):
    mst = []
    visited = set()
    start_node = input("Enter the starting node: ")
    visited.add(start_node)


    while len(visited) < len(graph):
        min_edge = None
        min_weight = float('inf')
        for node in visited:
            for neighbor, weight in graph[node]:
                if neighbor not in visited and weight < min_weight:
                    min_edge = (node, neighbor)
                    min_weight = weight
        mst.append(min_edge)
        visited.add(min_edge[1])


    return mst


graph = {}
num_edges = int(input("Enter the number of edges: "))
for _ in range(num_edges):
    edge = input("Enter the edge (node1 node2 weight) separated by space.").split()
    node1, node2, weight = edge[0], edge[1], int(edge[2])
    if node1 not in graph:
        graph[node1] = []
    if node2 not in graph:
        graph[node2] = []
   
    graph[node1].append((node2, weight))
    graph[node2].append((node1, weight))


mst = prim(graph)
print("Minimum Spanning Tree using Prim's algorithm is: " , mst)
