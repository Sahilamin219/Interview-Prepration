import hashlib

class ConsistentHashing:
    def __init__(self, nodes=None, virtual_nodes=10):
        """
        Initialize the consistent hashing ring.
        :param nodes: List of physical nodes.
        :param virtual_nodes: Number of virtual nodes per physical node.
        """
        self.virtual_nodes = virtual_nodes
        self.ring = {}  # Hash ring: {hash_value: node}
        self.sorted_hashes = []  # Sorted list of hash values for binary search

        if nodes:
            for node in nodes:
                self.add_node(node)

    def _hash(self, key):
        """
        Generate a hash value for a key using MD5.
        :param key: The key to hash.
        :return: A 32-bit integer hash value
.        """
        return int(hashlib.md5(key.encode()).hexdigest(), 16) % (2 ** 32)

    def add_node(self, node):
        """
        Add a physical node to the ring with virtual nodes.
        :param node: The physical node to add.
        """
        for i in range(self.virtual_nodes):
            virtual_node = f"{node}-vnode-{i}"
            hash_value = self._hash(virtual_node)
            print(virtual_node, hash_value)
            self.ring[hash_value] = node
            self.sorted_hashes.append(hash_value)

        self.sorted_hashes.sort()

    def remove_node(self, node):
        """
        Remove a physical node and its virtual nodes from the ring.
        :param node: The physical node to remove.
        """
        for i in range(self.virtual_nodes):
            virtual_node = f"{node}-vnode-{i}"
            hash_value = self._hash(virtual_node)
            del self.ring[hash_value]
            self.sorted_hashes.remove(hash_value)

    def get_node(self, key):
        """
        Get the node responsible for a given key.
        :param key: The key to look up.
        :return: The node responsible for the key.
        """
        if not self.ring:
            raise ValueError("No nodes available in the ring.")

        hash_value = self._hash(key)

        # Find the first hash value >= key's hash value (clockwise search)
        for h in self.sorted_hashes:
            if h >= hash_value:
                return self.ring[h]

        # If no hash value is found, wrap around to the first node
        return self.ring[self.sorted_hashes[0]]

# Example usage
if __name__ == "__main__":
    nodes = ["Node-A", "Node-B", "Node-C"]
    ch = ConsistentHashing(nodes, virtual_nodes=5)

    # Add a new node
    ch.add_node("Node-D")

    # Remove a node
    ch.remove_node("Node-B")

    # Get the node for a key
    keys = ["Key1", "Key2", "Key3", "Key4"]
    for key in keys:
        node = ch.get_node(key)
        print(f"Key: {key} => Node: {node}")


"""
Output
Node-A-vnode-0 4293585751
Node-A-vnode-1 4004430801
Node-A-vnode-2 3459103317
Node-A-vnode-3 3556454243
Node-A-vnode-4 2561476115
Node-B-vnode-0 3307655526
Node-B-vnode-1 127732453
Node-B-vnode-2 1928950777
Node-B-vnode-3 1658690279
Node-B-vnode-4 2193940849
Node-C-vnode-0 1868816399
Node-C-vnode-1 2386965716
Node-C-vnode-2 1906635607
Node-C-vnode-3 2030982371
Node-C-vnode-4 1709686731
Node-D-vnode-0 3859941417
Node-D-vnode-1 411781394
Node-D-vnode-2 377916786
Node-D-vnode-3 2326714726
Node-D-vnode-4 1816748579
Key: Key1 => Node: Node-A
Key: Key2 => Node: Node-D
Key: Key3 => Node: Node-C
Key: Key4 => Node: Node-A
"""
