"""
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [A[i], B[i]] and values[i] represent the equation A[i] / B[i] = values[i]. Each A[i] or B[i] is a string that represents a single variable.

You are also given some queries, where queries[j] = [C[j], D[j]] represents the jth query where you must find the answer for C[j] / D[j] = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.
 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]

Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0

Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
"""


def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:

    result = [-1.00000] * len(queries)
    vertex_set = set()
    adj_list = defaultdict(list) # { u -> [ (v1, wt), (v2, wt) ..  ] }

    # if we go a --> b, we multiply by values[i]
    # if we go b --> a, we divide by values[i]
    for i, (u, v) in enumerate(equations):
        adj_list[u].append( (v, values[i]) )
        adj_list[v].append( (u, 1/values[i]) )
        vertex_set.add(u)
        vertex_set.add(v)


    def _DFS(u, target, visited, product, query_ans):

        visited.add(u)

        if u == target:
            query_ans[0] = product
            return

        for pair in adj_list[u]:
            node = pair[0]
            wt = pair[1]
            
            if node not in visited:
                _DFS(node, target, visited, product * wt, query_ans)


    for i, query in enumerate(queries):
        u = query[0]
        v = query[1]

        if u not in vertex_set or v not in vertex_set:
            continue
        
        visited = set()
        query_ans = [-1] # to pass res by reference

        _DFS(u, v, visited, 1.0, query_ans)

        result[i] = query_ans[0]


    return result