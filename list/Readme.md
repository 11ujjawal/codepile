## Linked List

This is a C++ Template implementation of linked list data structure.

### API

#### Initialization

To create a list, invoke the ```make_list``` method. This method accepts an ```initializer_list``` as parameter. The function returns ```node_ptr<T>```, where ```T``` is the data type for example ```int``` or ```string```. ```node_ptr<T>``` is an alias for a shared pointer to a node of the list.

```
/* Invoke the make_list method to generate a linked list */
auto ilist = make_list({1, 7, 6, 9, 4, 0});

/* The make_list method returns a 'node_ptr' to the object of the specified type */
node_ptr<double> dlist = make_list({2.67, 5.90, 3.89, 79.001});

/* The string STL type can also be used as a type */
node_ptr<std::string> slist = make_list({std::string("John"), std::string("Taylor"), std::string("Thomas")});
```

#### Insertion

Items can be inserted at various position in the list. The methods are -
- ```push_front``` - Inserts a node at the front of the list
```
/* List after insertion -
 * HEAD -> 5 -> 1 -> 7 -> 6 -> 9 -> 4 -> 0 -> nullptr
 */
push_back(ilist, 5);
```
- ```push_back``` - Inserts a node at the end of the list
```
/* List after insertion -
 * HEAD -> 5 -> 1 -> 7 -> 6 -> 9 -> 4 -> 0 -> 5 -> nullptr
 */
push_back(ilist, 5);
```
- ```push_at``` - Accepts a pointer to a node in the list and inserts the new
node after the given node.
```
/* To insert a node after the third node, invoke the fetch method to
 * retrieve the third node and pass the node to the push_at method
 * along with the key to be inserted
 *
 * List after insertion -
 * HEAD -> 5 -> 1 -> 7 -> 5 -> 6 -> 9 -> 4 -> 0 -> 5 -> nullptr
 */
push_at(fetch(ilist, 3), 5);
```
- ```push_sorted``` - Inserts a node in a sorted list.
```
/* CAUTION - This method does node verify whether the list is sorted.
 *
 * List after insertion -
 * HEAD -> 1 -> 3 -> 5 -> 6 -> 8 -> 10 -> nullptr
 */
auto sortedList = make_list({1, 3, 6, 8, 10});
push_sorted(sortedList, 5);
```


#### Deletion

Items can be deleted from various positions in the list -
- ```pop_front``` - Removes the element from the start of the list
```
/* List after deletion -
 * HEAD -> 1 -> 7 -> 5 -> 6 -> 9 -> 4 -> 0 -> 5 -> nullptr
 */
pop_front(ilist);
```
- ```pop_back``` - Removes the element from the end of the list
```
/* List after deletion -
 * HEAD -> 1 -> 7 -> 5 -> 6 -> 9 -> 4 -> 0 -> nullptr
 */
pop_back(ilist);
```
- ```pop_at``` - Accepts a reference to a node and removes the next node
```
/* List after deletion -
 * HEAD -> 1 -> 7 -> 6 -> 9 -> 4 -> 0 -> nullptr
 */
pop_at(ilist);
```
- ```pop_k_back``` - Removes kth element from the end of the list
```
/* List after deletion -
 * HEAD -> 1 -> 7 -> 6 -> 4 -> 0 -> nullptr
 */
pop_k_back(ilist, 3);
```
- ```pop_all``` - Removes all the elements from the list
```
/* List after deletion -
 * HEAD -> nullptr
 */
pop_all(ilist);
```
