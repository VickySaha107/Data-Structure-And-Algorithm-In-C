# Data-Structure-And-Algorithms
## Data Structures
### Linked List
 * A *Linked List* is a linear collection of data elements, called nodes, each
   pointing to the next node by means of a pointer. It is a data structure
   consisting of a group of nodes which together represent a sequence.
 * **Singly-linked list**: linked list in which each node points to the next node and the last node points to null
 * **Doubly-linked list**: linked list in which each node has two pointers, p and n, such that p points to the previous node and n points to the next node; the last node's n pointer points to null
 * **Circular-linked list**: linked list in which each node points to the next node and the last node points back to the first node
 * Time Complexity:
   * Access: `O(n)`
   * Search: `O(n)`
   * Insert: `O(1)`
   * Remove: `O(1)`

### Stack
 * A *Stack* is a collection of elements, with two principle operations: *push*, which adds to the collection, and
   *pop*, which removes the most recently added element
 * **Last in, first out data structure (LIFO)**: the most recently added object is the first to be removed
 * Time Complexity:
   * Access: `O(n)`
   * Search: `O(n)`
   * Insert: `O(1)`
   * Remove: `O(1)`

### Queue
 * A *Queue* is a collection of elements, supporting two principle operations: *enqueue*, which inserts an element
   into the queue, and *dequeue*, which removes an element from the queue
 * **First in, first out data structure (FIFO)**: the oldest added object is the first to be removed
 * Time Complexity:
   * Access: `O(n)`
   * Search: `O(n)`
   * Insert: `O(1)`
   * Remove: `O(1)`

### Tree
 * A *Tree* is an undirected, connected, acyclic graph

### Binary Tree
 * A *Binary Tree* is a tree data structure in which each node has at most two children, which are referred to as
   the *left child* and *right child*
 * **Full Tree**: a tree in which every node has either 0 or 2 children
 * **Perfect Binary Tree**: a binary tree in which all interior nodes have two children and all leave have the same depth
 * **Complete Tree**: a binary tree in which every level *except possibly the last* is full and all nodes in the last
   level are as far left as possible

### Binary Search Tree
 * A binary search tree, sometimes called BST, is a type of binary tree which maintains the property that the value in each
   node must be greater than or equal to any value stored in the left sub-tree, and less than or equal to any value stored
   in the right sub-tree
 * Time Complexity:
   * Access: `O(log(n))`
   * Search: `O(log(n))`
   * Insert: `O(log(n))`
   * Remove: `O(log(n))`

### Trie
* A trie, sometimes called a radix or prefix tree, is a kind of search tree that is used to store a dynamic set or associative
  array where the keys are usually Strings. No node in the tree stores the key associated with that node; instead, its position 
  in the tree defines the key with which it is associated. All the descendants of a node have a common prefix of the String associated 
  with that node, and the root is associated with the empty String.

### Fenwick Tree
* A Fenwick tree, sometimes called a binary indexed tree, is a tree in concept, but in practice is implemented as an implicit data
  structure using an array. Given an index in the array representing a vertex, the index of a vertex's parent or child is calculated
  through bitwise operations on the binary representation of its index. Each element of the array contains the pre-calculated sum of
  a range of values, and by combining that sum with additional ranges encountered during an upward traversal to the root, the prefix
  sum is calculated
* Time Complexity:
  * Range Sum: `O(log(n))`
  * Update: `O(log(n))`

### Segment Tree
* A Segment tree, is a tree data structure for storing intervals, or segments. It allows querying which of the stored segments contain
  a given point
* Time Complexity:
  * Range Query: `O(log(n))`
  * Update: `O(log(n))`

### Heap
* A *Heap* is a specialized tree based structure data structure that satisfies the *heap* property: if A is a parent node of
B, then the key (the value) of node A is ordered with respect to the key of node B with the same ordering applying across the entire heap.
A heap can be classified further as either a "max heap" or a "min heap". In a max heap, the keys of parent nodes are always greater
than or equal to those of the children and the highest key is in the root node. In a min heap, the keys of parent nodes are less than
or equal to those of the children and the lowest key is in the root node
* Time Complexity:
  * Access Max / Min: `O(1)`
  * Insert: `O(log(n))`
  * Remove Max / Min: `O(log(n))`

### Hashing
* *Hashing* is used to map data of an arbitrary size to data of a fixed size. The values returned by a hash
  function are called hash values, hash codes, or simply hashes. If two keys map to the same value, a collision occurs
* **Hash Map**: a *hash map* is a structure that can map keys to values. A hash map uses a hash function to compute
  an index into an array of buckets or slots, from which the desired value can be found.
* Collision Resolution
 * **Separate Chaining**: in *separate chaining*, each bucket is independent, and contains a list of entries for each index. The
 time for hash map operations is the time to find the bucket (constant time), plus the time to iterate through the list
 * **Open Addressing**: in *open addressing*, when a new entry is inserted, the buckets are examined, starting with the
 hashed-to-slot and proceeding in some sequence, until an unoccupied slot is found. The name open addressing refers to
 the fact that the location of an item is not always determined by its hash value


### Graph
* A *Graph* is an ordered pair of G = (V, E) comprising a set V of vertices or nodes together with a set E of edges or arcs,
  which are 2-element subsets of V (i.e. an edge is associated with two vertices, and that association takes the form of the
  unordered pair comprising those two vertices)
 * **Undirected Graph**: a graph in which the adjacency relation is symmetric. So if there exists an edge from node u to node
 v (u -> v), then it is also the case that there exists an edge from node v to node u (v -> u)
 * **Directed Graph**: a graph in which the adjacency relation is not symmetric. So if there exists an edge from node u to node v
 (u -> v), this does *not* imply that there exists an edge from node v to node u (v -> u)


## Algorithms

### Sorting

#### Quicksort
* Stable: `No`
* Time Complexity:
  * Best Case: `O(nlog(n))`
  * Worst Case: `O(n^2)`
  * Average Case: `O(nlog(n))`

#### Mergesort
* *Mergesort* is also a divide and conquer algorithm. It continuously divides an array into two halves, recurses on both the
  left subarray and right subarray and then merges the two sorted halves
* Stable: `Yes`
* Time Complexity:
  * Best Case: `O(nlog(n))`
  * Worst Case: `O(nlog(n))`
  * Average Case: `O(nlog(n))`

#### Bucket Sort
* *Bucket Sort* is a sorting algorithm that works by distributing the elements of an array into a number of buckets. Each bucket
  is then sorted individually, either using a different sorting algorithm, or by recursively applying the bucket sorting algorithm
* Time Complexity:
  * Best Case: `Ω(n + k)`
  * Worst Case: `O(n^2)`
  * Average Case:`Θ(n + k)`

#### Radix Sort
* *Radix Sort* is a sorting algorithm that like bucket sort, distributes elements of an array into a number of buckets. However, radix
  sort differs from bucket sort by 're-bucketing' the array after the initial pass as opposed to sorting each bucket and merging
* Time Complexity:
  * Best Case: `Ω(nk)`
  * Worst Case: `O(nk)`
  * Average Case: `Θ(nk)`

### Graph Algorithms

#### Depth First Search
* *Depth First Search* is a graph traversal algorithm which explores as far as possible along each branch before backtracking
* Time Complexity: `O(|V| + |E|)`

#### Breadth First Search
* *Breadth First Search* is a graph traversal algorithm which explores the neighbor nodes first, before moving to the next
  level neighbors
* Time Complexity: `O(|V| + |E|)`

#### Topological Sort
* *Topological Sort* is the linear ordering of a directed graph's nodes such that for every edge from node u to node v, u
  comes before v in the ordering
* Time Complexity: `O(|V| + |E|)`

#### Dijkstra's Algorithm
* *Dijkstra's Algorithm* is an algorithm for finding the shortest path between nodes in a graph
* Time Complexity: `O(|V|^2)`

#### Bellman-Ford Algorithm
* *Bellman-Ford Algorithm* is an algorithm that computes the shortest paths from a single source node to all other nodes in a weighted graph
* Although it is slower than Dijkstra's, it is more versatile, as it is capable of handling graphs in which some of the edge weights are
  negative numbers
* Time Complexity:
  * Best Case: `O(|E|)`
  * Worst Case: `O(|V||E|)`

#### Floyd-Warshall Algorithm
* *Floyd-Warshall Algorithm* is an algorithm for finding the shortest paths in a weighted graph with positive or negative edge weights, but
  no negative cycles
* A single execution of the algorithm will find the lengths (summed weights) of the shortest paths between *all* pairs of nodes
* Time Complexity:
  * Best Case: `O(|V|^3)`
  * Worst Case: `O(|V|^3)`
  * Average Case: `O(|V|^3)`

#### Prim's Algorithm
* *Prim's Algorithm* is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. In other words, Prim's find a
  subset of edges that forms a tree that includes every node in the graph
* Time Complexity: `O(|V|^2)`


#### Kruskal's Algorithm
* *Kruskal's Algorithm* is also a greedy algorithm that finds a minimum spanning tree in a graph. However, in Kruskal's, the graph does not
  have to be connected
* Time Complexity: `O(|E|log|V|)`

## Greedy Algorithms
* *Greedy Algorithms* are algorithms that make locally optimal choices at each step in the hope of eventually reaching the globally optimal solution
* Problems must exhibit two properties in order to implement a Greedy solution:
 * Optimal Substructure
    * An optimal solution to the problem contains optimal solutions to the given problem's subproblems
 * The Greedy Property
    * An optimal solution is reached by "greedily" choosing the locally optimal choice without ever reconsidering previous choices
* Example - Coin Change
    * Given a target amount V cents and a list of denominations of n coins, i.e. we have coinValue[i] (in cents) for coin types i from [0...n - 1],
      what is the minimum number of coins that we must use to represent amount V? Assume that we have an unlimited supply of coins of any type
    * Coins - Penny (1 cent), Nickel (5 cents), Dime (10 cents), Quarter (25 cents)
    * Assume V = 41. We can use the Greedy algorithm of continuously selecting the largest coin denomination less than or equal to V, subtract that
      coin's value from V, and repeat.
    * V = 41 | 0 coins used
    * V = 16 | 1 coin used (41 - 25 = 16)
    * V = 6  | 2 coins used (16 - 10 = 6)
    * V = 1  | 3 coins used (6 - 5 = 1)
    * V = 0  | 4 coins used (1 - 1 = 0)
    * Using this algorithm, we arrive at a total of 4 coins which is optimal

## Bitmasks
* Bitmasking is a technique used to perform operations at the bit level. Leveraging bitmasks often leads to faster runtime complexity and
  helps limit memory usage
* Test kth bit: `s & (1 << k);`
* Set kth bit: `s |= (1 << k);`
* Turn off kth bit: `s &= ~(1 << k);`
* Toggle kth bit: `s ^= (1 << k);`
* Multiple by 2<sup>n</sup>: `s << n;`
* Divide by 2<sup>n</sup>: `s >> n;`
* Intersection: `s & t;`
* Union: `s | t;`
* Set Subtraction: `s & ~t;`
* Extract lowest set bit: `s & (-s);`
* Extract lowest unset bit: `~s & (s + 1);`
* Swap Values:
             ```
                x ^= y;
                y ^= x;
                x ^= y;
             ```

## Runtime Analysis

#### Big O Notation
* *Big O Notation* is used to describe the upper bound of a particular algorithm. Big O is used to describe worst case scenarios

#### Little O Notation
* *Little O Notation* is also used to describe an upper bound of a particular algorithm; however, Little O provides a bound
  that is not asymptotically tight

#### Big Ω Omega Notation
* *Big Omega Notation* is used to provide an asymptotic lower bound on a particular algorithm

#### Little ω Omega Notation
* *Little Omega Notation* is used to provide a lower bound on a particular algorithm that is not asymptotically tight

#### Theta Θ Notation
* *Theta Notation* is used to provide a bound on a particular algorithm such that it can be "sandwiched" between
  two constants (one for an upper limit and one for a lower limit) for sufficiently large values
  
  ### Data Structures and Algorithms Video Courses

- [CS 61B - Data Structures, Jonathan Shewchuk - UC Berkeley](https://people.eecs.berkeley.edu/~jrs/61b/) ([Videos](https://www.youtube.com/playlist?list=PL4BBB74C7D2A1049C))
- [CS 61B - Data Structures, Josh Hug, Spring 2016 - UC Berkeley](http://datastructur.es/sp16/)
- [MOOC - Design and Analysis of Algorithms Part 1 - Prof Roughgarden - Coursera](https://www.youtube.com/playlist?list=PLLH73N9cB21W1TZ6zz1dLkyIm50HylGyg) ([Part 2](https://www.youtube.com/playlist?list=PLLH73N9cB21VPj3H2xwTTye5TC8-UniA2))
- [MOOC - Algorithms Part 1 - Prof Sedgewick](https://www.youtube.com/playlist?list=PLUX6FBiUa2g4YWs6HkkCpXL6ru02i7y3Q) ([Part 2](https://www.youtube.com/playlist?list=PLqD_OdMOd_6YixsHkd9f4sNdof4IhIima))
- [6.006 - Introduction to Algorithms, MIT OCW](http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/)
- [CSE 373 - Analysis of Algorithms, Stony Brook - Prof Skiena](http://www.cs.sunysb.edu/~algorith/video-lectures/)
- [COP 3530 Data Structures and Algorithms, Prof Sahni, UFL](http://www.cise.ufl.edu/~sahni/cop3530/) ([Videos](http://www.cise.ufl.edu/academics/courses/preview/cop3530sahni/))
- [CS225 - Data Structures - University of Illinois at Urbana-Champaign](https://chara.cs.illinois.edu/cs225/lectures/)
- [CS2 - Data Structures and Algorithms - Richard Buckland - UNSW](https://www.youtube.com/playlist?list=PLE621E25B3BF8B9D1)
- [Data Structures - Pepperdine University](https://itunes.apple.com/us/course/data-structures/id546468797)
- [CS 161 - Design and Analysis of Algorithms, Prof. Tim Roughgarden, Stanford University](http://openclassroom.stanford.edu/MainFolder/CoursePage.php?course=IntroToAlgorithms)
- [6.046J - Introduction to Algorithms - Fall 2005, MIT OCW](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-introduction-to-algorithms-sma-5503-fall-2005/video-lectures/)
- [6.046 - Design and Analysis of Algorithms, Spring 2015 - MIT OCW](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-design-and-analysis-of-algorithms-spring-2015/lecture-videos/)
- [CS 473 - Algorithms - University of Illinois at Urbana-Champaign](https://courses.engr.illinois.edu/cs473/sp2016/lectures.html) ([Notes - Jeff Erickson](http://jeffe.cs.illinois.edu/teaching/algorithms/))
- [Programming Challenges - Prof Skiena](http://www.algorist.com/programming_challenges/)
- [16s-4102 - Algorithms, University of Virginia](http://www.cs.virginia.edu/~shelat/16s-4102/) ([Youtube](https://www.youtube.com/channel/UCxXYk53cSZof2bR_Ax0uJYQ/videos))
- [CS 170 Algorithms - Spring 2015 - UCBerkeley](https://www.youtube.com/playlist?list=PL-XXv-cvA_iDbtIylJDpPPJfaFweeaR-3)
- [ECS 122A - Algorithm Design and Analysis, UC Davis](http://web.cs.ucdavis.edu/~gusfield/cs122f10/videolist.html)
- [CSEP 521 - Applied Algorithms, Winter 2013 - University of Washington](http://courses.cs.washington.edu/courses/csep521/13wi/) ([Videos](http://courses.cs.washington.edu/courses/csep521/13wi/video/))
- [Data Structures And Algorithms - IIT Delhi](http://nptel.ac.in/courses/106102064/)
- [Design and Analysis of Algorithms - IIT Bombay](http://nptel.ac.in/courses/106101060/)
- [Programming, Data Structures and Algorithms - IIT Madras](http://nptel.ac.in/courses/106106127/)
- [Design and Analysis of Algorithms - IIT Madras](http://nptel.ac.in/courses/106106131/)
- [Fundamental Algorithms:Design and Analysis - IIT Kharagpur](http://nptel.ac.in/courses/106105157/)
- [Programming and Data Structure - IIT Kharagpur](http://nptel.ac.in/courses/106105085/)
- [Programming, Data structures and Algorithms - IIT Madras](http://nptel.ac.in/courses/106106133/)
- [Programming, Data Structures and Algorithms in Python - IIT Madras](http://nptel.ac.in/courses/106106145/)
- [Programming and Data structures (PDS) - IIT Madras](http://nptel.ac.in/courses/106106130/)
- [COP 5536 Advanced Data Structures, Prof Sahni - UFL](http://www.cise.ufl.edu/~sahni/cop5536/index.html) ([Videos](http://www.cise.ufl.edu/academics/courses/preview/cop5536sahni/))
- [CS 261 - A Second Course in Algorithms, Stanford University](http://theory.stanford.edu/~tim/w16/w16.html) ([Youtube](https://www.youtube.com/playlist?list=PLEGCF-WLh2RJh2yDxlJJjnKswWdoO8gAc))
- [Informatics 2B - Algorithms, Data Structures and Learning- University of Edinburgh](http://groups.inf.ed.ac.uk/vision/VIDEO/2013/inf2b-adsl.htm)
- [CS 224 - Advanced Algorithms, Harvard University](http://people.seas.harvard.edu/~minilek/cs224/fall14/index.html) ([Lecture Videos](http://people.seas.harvard.edu/~minilek/cs224/fall14/lec.html)) ([Youtube](https://www.youtube.com/playlist?list=PL2SOU6wwxB0uP4rJgf5ayhHWgw7akUWSf))
- [CS 6150 - Advanced Algorithms (Fall 2016), University of Utah](https://www.youtube.com/playlist?list=PLbuogVdPnkCp8X9FHOglnLqFjyvqGLftx)
- [ECS 222A - Graduate Level Algorithm Design and Analysis, UC Davis](http://web.cs.ucdavis.edu/~gusfield/cs222f07/videolist.html)
- [6.851 - Advanced Data Structures, MIT](http://courses.csail.mit.edu/6.851/spring14/lectures/) ([MIT OCW](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-851-advanced-data-structures-spring-2012/lecture-videos/))
- [6.854 - Advanced Algorithms, MIT](https://www.youtube.com/playlist?list=PL6ogFv-ieghdoGKGg2Bik3Gl1glBTEu8c) ([Prof. Karger lectures](https://www.youtube.com/channel/UCtv9PiQVUDzsT4yl7524DCg/videos))
- [CS264 Beyond Worst-Case Analysis, Fall 2014 - Tim Roughgarden Lecture](http://theory.stanford.edu/~tim/f14/f14.html) ([Youtube](https://www.youtube.com/playlist?list=PLEGCF-WLh2RL8jsZpaf2tLHa5LotFEt5b))
- [CS364A Algorithmic Game Theory, Fall 2013 - Tim Roughgarden Lectures](https://www.youtube.com/playlist?list=PLEGCF-WLh2RJBqmxvZ0_ie-mleCFhi2N4)
- [CS364B Advanced Mechanism Design, Winter 2014 - Tim Roughgarden Lectures](https://www.youtube.com/playlist?list=PLEGCF-WLh2RI77PL4gwLld_OU9Zh3TCX9)
- [Algorithms - Aduni](http://aduni.org/courses/algorithms/index.php?view=cw)
- [Advanced Topics in Algorithms and Datastructures - SS 2005 - Universität Freiburg](https://electures.informatik.uni-freiburg.de/portal/web/guest/detail/-/modulnavigation/view/4/252/)
- [Algorithmentheorie/Algorithms Theory - WS 2013 - Universität Freiburg](https://electures.informatik.uni-freiburg.de/portal/web/guest/detail/-/modulnavigation/view/5402/16009/) ([WS 2011](https://electures.informatik.uni-freiburg.de/portal/web/guest/detail/-/modulnavigation/view/4003/12514/))
- [Theory I - SS 2010 - Universität Freiburg](https://electures.informatik.uni-freiburg.de/portal/web/guest/detail/-/modulnavigation/view/2103/8701/)
- [6.889 - Algorithms for Planar Graphs and Beyond (Fall 2011) MIT](http://courses.csail.mit.edu/6.889/fall11/lectures/)
- [6.890 Algorithmic Lower Bounds: Fun with Hardness Proofs - MIT OCW](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-890-algorithmic-lower-bounds-fun-with-hardness-proofs-fall-2014/)
- [Computer Algorithms - 2 - IIT Kanpur](http://nptel.ac.in/courses/106104019/)
- [Parallel Algorithm - IIT Kanpur](http://nptel.ac.in/courses/106104120/)
- [Graph Theory - IISC Bangalore](http://nptel.ac.in/courses/106108054/)
  
### IDE
XCODE

### Machine
MacBook Pro (13-inch, 2019, Two Thunderbolt 3 ports)  
Processor Name: Quad-Core Intel Core i5
Processor Speed: 1.4 GHz
Memory: 8 GB
