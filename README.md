password_cracker
================

Password cracker using Markov chains to speed up search

The program will initialize several things
* Read in the 10000 most common passwords
* Create a map for the characters from " " to "~" as keys
* For each character, have a map that stores all of the characters as keys and the number of times they precede the outer character in the passwords

Using this map, the program will
* Construct a tree of a specified depth out of nodes, where a node contains the character, the number of times it comes after the parent node, and the list of children nodes
* Take a "password" as input
* Iterate through the tree "randomly", using the number of times a character comes after a character as a weight to be chosen
* Prune already tried outputs
* Add another layer of nodes to the leaves of the current tree
* Repeat until password is "found"
