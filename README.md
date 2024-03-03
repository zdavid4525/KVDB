key-value store database system implemented with c++ - occasionally a project in final-year/graduate-level course csc443/csc2525 at uoft.

supports:
 - database instance creation
 - inserting key-value pair into database instance
 - getting value associated with a given key
 - database instance deletion

wip:
 - retrieving all key-value pairs in a key range in key order (key 1 < key 2)
 - memtables (avl or red-black trees) and sorted string tables
 - buffer pool caching, ideally O(1) ops
   - hashing
   - eviction
 - (maybe) find a way to integrate lsm trees
