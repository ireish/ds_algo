"""
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [a[i], b[i]] indicates that you must take course a[i] first if you want to take course b[i].

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [u[j], v[j]]. For the jth query, you should answer whether course u[j] is a prerequisite of course v[j] or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.


Example 2:
Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0, and the pair [1, 2] indicates that you have to take course 1 before you can take course 2.
"""

def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:

    result = [False] * len(queries)
    in_degree = [0] * numCourses
    q = deque()

    # to store list of pre_reqs for specific node
    # and query in O(1)
    prereq_list = defaultdict(set)

    adj = [[] for _ in range(numCourses)]

    for u, v in prerequisites:
        adj[u].append(v)
        in_degree[v] += 1

    for node, val in enumerate(in_degree):
        if val == 0:
            q.append(node)

    while q:
        u = q.popleft()

        for node in adj[u]:
            
            # here before adding the immediate pre-req, we also add all the pre-reqs encountered until now
            # Eg: u --> v then all pre-reqs of u will also be pre-reqs of v
            prereq_list[node].add(u)
            for elem in prereq_list[u]:
                prereq_list[node].add(elem)

            in_degree[node] -= 1

            if in_degree[node] == 0:
                q.append(node)

    for i, (u, v) in enumerate(queries):
        if u in prereq_list[v]:
            result[i] = True
        else: 
            result[i] = False


    return result
