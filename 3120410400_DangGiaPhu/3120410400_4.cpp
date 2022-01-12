#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Tạo một node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Duyệt trung thứ tự (In-order Traversal)
void inorder(struct node *root) {
  if (root != NULL) {
    // Duyệt trái (Traverse left)
    inorder(root->left);

    // Duyệt gốc (Traverse root)
    cout << root->key << " -> ";

    // Duyệt phải (Traversal right)
    inorder(root->right);
  }
}

// Chèn một node
struct node *insert(struct node *node, int key) {
  // Trả về node mới nếu cây rỗng
  if (node == NULL) return newNode(key);

  // Di chuyển và chèn đúng node gốc 
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Tìm giá trị bé nhất trong cây
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Tìm lá cuối của cây
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Xóa đi một node
struct node *deleteNode(struct node *root, int key) {
  // Trả về root nếu giá trị rỗng
  if (root == NULL) return root;

  // Tìm đúng node để xóa
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // Nếu node chỉ có một node con hoặc không có node con
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // Nếu node có 2 node con
    struct node *temp = minValueNode(root->right);

    // Đặt node con vào vị trí node sẽ bị xóa
    root->key = temp->key;

    // Xóa node
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Inorder traversal: ";
  inorder(root);

  cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);
  cout << "Inorder traversal: ";
  inorder(root);
}
