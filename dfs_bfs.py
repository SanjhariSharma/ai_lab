from collections import defaultdict, deque

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def dfs_util(self, v, visited):
        visited[v] = True
        print(v, end = ' ')

        for i in self.graph:
          if not visited[i]:
            self.dfs_util(i, visited)

    def dfs(self, v):
        visited = [False] * len(self.graph)
        self.dfs_util(v, visited)

    def bfs(self, v):
        visited = [False] * len(self.graph)
        queue = deque()
        queue.append(v)
        visited[v] = True

        while queue:
          v = queue.popleft()
          print(v, end = ' ')

          for i in self.graph:
            if not in visited[i]:
              queue.append(i)
              visited[i] = True

g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(0, 3)
g.add_edge(1, 4)
g.add_edge(2, 4)

print("DFS: )
g.dfs(2)
print("\n")

print("BFS: )
g.bfs(2)      
