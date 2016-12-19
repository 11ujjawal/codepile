## Linked List

This is a C++ Template implementation of linked list data structure.

### API

#### Initialization

To create a list, invoke the ```make_list``` method. This method accepts an ```initializer_list``` as parameter. The function returns ```node_ptr<T>```, where ```T``` is the data type for example ```int``` or ```string```. ```node_ptr<T>``` is an alias for a shared pointer to a node of the list.

```
/* Invoke the make_list method to generate a linked list */
auto head = make_list({1, 5, 2, 7, 6, 9, 4, 0});

/* The make_list method returns a 'node_ptr' to the object of the specified type */
node_ptr<double> = make_list({2.67, 5.90, 3.89, 79.001});

/* The string STL type can also be used as a type */
node_ptr<std::string> = make_list({std::string("John"), std::string("Taylor"), std::string("Thomas")});
```
