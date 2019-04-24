#include <iostream>
#include <unordered_map>
/**
 * Copy Node: Write a method that takes a pointer to a Node structure as a
 * parameter and returns a complete copy of the passed in data structure. The
 * Node data structure contains two pointers to other Nodes.
 */
using namespace std;

struct Node {
  Node* l;
  Node* r;
};

typedef std::unordered_map<Node*, Node*> NodeMap;

Node* copy_node(Node* n, NodeMap& nodemap) {
  if (n == nullptr) return nullptr;
  auto res = nodemap.find(n);
  // the node has already been visited
  if (res != nodemap.end()) {
    return res->second;
  } else {
    // build new node
    Node* node = new Node;
    nodemap[n] = node;
    node->l = copy_node(n->l, nodemap);
    node->r = copy_node(n->r, nodemap);
    return node;
  }
}

Node* copy_structure(Node* root) {
  NodeMap nodemap;
  return copy_node(root, nodemap);
}

int main() {
  // Build graph
  Node* root = new Node;
  root->l = new Node;
  root->r = new Node;
  root->l->r = new Node;
  root->r->l = root->l->r;
  root->l->l = new Node;

  Node* copy = copy_structure(root);
  cout << root->l->r << endl;
  cout << root->r->l << endl;

  cout << copy->l->r << endl;
  cout << copy->r->l << endl;
  cout << copy->r->r << endl;
}
