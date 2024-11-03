# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        column_table = defaultdict(list)
        queue = deque([(root, 0, 0)])  # node, column index, row index

        while queue:
            node, column, row = queue.popleft()
            if node:
                column_table[column].append((row, node.val))  # append (row, value)
                queue.append((node.left, column - 1, row + 1))  # go left
                queue.append((node.right, column + 1, row + 1))  # go right

        # Sort the column indices and prepare the result
        sorted_columns = sorted(column_table.keys())
        result = []
        for col in sorted_columns:
            # Sort by row first, then by value
            column_nodes = sorted(column_table[col], key=lambda x: (x[0], x[1]))
            result.append([val for row, val in column_nodes])  # extract values

        return result
