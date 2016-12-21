## Disjoint Set

A **disjoint set** data structure maintains a collection S = {S<sub>1</sub>, S<sub>2</sub>, ... , S<sub>k</sub>} of disjoint dynamic set. Each set is identified by its representative, which can be any arbitrary member of the set.

### API

- ```DisjointSet``` - **Class** whose instantiation yields individual members as distinct set.
```
/* Initialize a member of DisjointSet Class
 *
 * Each value of the initializer_list is assigned a unique set, represented by
 * the given value.
 */
DisjointSet ds{1, 2, 3, 4, 5};
```

- ```Find``` - Fetch the representative of the set the input member is in.
```
/* The below statement yields 2 - since each set has only one member */
ds.Find(2);
```

- ```Union``` - Merge two set into one. Representative of the merged set can be any arbitrary element of the set.

```
/* Merge the sets containing the objects 2 and 4 */
ds.Union(2, 4);

/* The find() will now return the representative of the set which contains the
 * elements 2 and 4
 */
ds.Find(4);
```
