class SparseVector:
    def __init__(self, nums):
        # Store non-zero elements as a dictionary
        self.vector = {i: val for i, val in enumerate(nums) if val != 0}

    def dotProduct(self, vec):
        # Calculate dot product with another SparseVector
        dot_product = 0
        for i in self.vector:
            if i in vec.vector:  # Only consider indices that are non-zero in both vectors
                dot_product += self.vector[i] * vec.vector[i]
        return dot_product
