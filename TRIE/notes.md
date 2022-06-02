## Basic functionalities of the TRIE data structure

[ Link to the video ](https://www.youtube.com/watch?v=dBGUmUQhjaM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp)

```cpp

// below structure is to represent the individual nodes of the TRIE
// with different members and member functions

struct Node {

  Node *links[26]; // assuming only lower case alphabets are present
  bool flag = false; // this flag is to mark the end of a word
  // if the flag of current node is true then it means that previous node was end of the word
  
  
  // checks if the reference trie is present or not
  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL); // if the reference trie is empty then it would have been NULL
  }
  
  // creating a reference trie
  void put(char ch, Node* node) {
    links[ch - 'a'] = node; // assinging the newly created node to the current node
  }
  
  // get the next node for the traversal
  Node* get(char ch) {
    return links[ch - 'a'];
  }
  
  // setting the flag to true at the end of the word
  void setEnd() {
    flag = true;
  }
  
  // checking if word is completed or not
  bool isEnd(){
    return flag;
  }
  
};



// Trie Class
Class Trie {
private:
  Node* root; // initially we are at root which is the starting of the TRIE
  
public:
  Trie() {
    root = new Node(); // creating new object
  }
  
  void insert(string word) {
    // initializing the dummy node pointing to the root initially
    Node* node = root;
    
    for(int i = 0; i < word.size(): i++) {
    
      if(!node->containsKey(word[i])) {
        node->put(word[i], new Node());
      }
      
      // moving to referene node of trie
      node = node->get(word[i]);
    }
    
    // marking the end of the word;
    node->setEnd();
    
  }
  
  bool search(string word) {
    Node* node = root;
    
    for(int i = 0; i < word.size(); i++) {
      
      if(!node->containsKey(word[i]))
        return false;
        
      node = node->get(word[i]);
    }
   
    return node->isEnd();
  }
  
  bool startsWith(string prefix) {
    Node* node = root;
    
    for(int i = 0; i < prefix.size(); i++) {
      if(!node->containsKey(prefix[i]))
        return false;
        
      node = node->get(prefix[i]);
    }
    
    return true;
  }
  
};
  


```
