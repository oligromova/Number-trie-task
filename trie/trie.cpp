#include "trie.h"

#include <memory>

struct node {
  std::shared_ptr<node> children[26];
  int list;
  int quantity;
  node() {
    quantity = 0;
    list = 0;
  }
};
using node_ptr = std::shared_ptr<node>;

trie_t::trie_t() : root {new node()} {}

trie_t::~trie_t() { }

static void dfs_operator(node_ptr& v_this, node_ptr v_other) {
  v_this->quantity = v_other->quantity;
  v_this->list = v_other->list;
  for (int i = 0; i < 26; ++i) {
    if (v_other->children[i] != nullptr) {
      v_this->children[i].reset(new node());
      dfs_operator(v_this->children[i], v_other->children[i]);
    }
  }
}

trie_t::trie_t(const trie_t &other) : root { new node() } {
  dfs_operator(root, other.root);
}

trie_t& trie_t::operator=(const trie_t &other) {
  if (this == &other)
    return *this;
  clear();
  root.reset(new node());
  dfs_operator(root, other.root);
  return *this;
}

void trie_t::insert(const std::string &str) {
  node_ptr current = root;
  for (size_t i = 0; i < str.size(); ++i) {
    char iter = str[i];
    if (current->children[iter - 'a'] == nullptr) {
      current->children[iter - 'a'].reset(new node());
    }
    current->list++;
    current = current->children[iter - 'a'];
  }
  current->list++;
  current->quantity++;
}

bool trie_t::erase(const std::string &str) {
  node_ptr current = root;
  bool flag = false;
  if (find(str)) {
    flag = true;
  }
  for (size_t i = 0; i < (int)str.size(); ++i) {
    char iter = str[i];
    if (current->children[iter - 'a'] == nullptr) {
      return false;
    }
    if (flag)
      current->list--;
    current = current->children[iter - 'a'];
  }
  if (current->quantity) {
    current->quantity--;
    return true;
  }
  return false;
}

void trie_t::clear() {
  root.reset(new node());
}

bool trie_t::find(const std::string &str) const {
  node_ptr current = root;
  for (size_t i = 0; i < (int)str.size(); ++i) {
    current = current->children[str[i] - 'a'];
    if (current == nullptr) {
      return false;
    }
  }
  if (current->quantity) {
    return true;
  }
  return false;
}

void dfs_size(node_ptr v, int &ans) {
  ans += (int)v->quantity;
  for (int i = 0; i < 26; ++i) {
    if (v->children[i] != nullptr) {
      dfs_size(v->children[i], ans);
    }
  }
}
size_t trie_t::size() const {
  if (root == nullptr) {
    return 0;
  }
  int ans = 0;
  dfs_size(root, ans);
  return ans;
}

size_t trie_t::count_with_prefix(const std::string &prefix) const {
  node_ptr current = root;
  for (size_t i = 0; i < (int)prefix.size(); ++i) {
    current = current->children[prefix[i] - 'a'];
    if (current == nullptr) {
      return 0;
    }
  }
  int ans = 0;
  dfs_size(current, ans);
  return ans;
}

void dfs_sort_and_find(node_ptr v, int &cur, int need, std::string str, std::string &ans) {
  if (ans != "") {
    return;
  }
  cur += v->quantity;
  if (cur >= need) {
    ans = str;
    return;
  }

  for (int i = 0; i < 26; ++i) {
    if (v->children[i] != nullptr) {
      if (v->children[i]->list + cur < need) {
        cur += v->children[i]->list;
        continue;
      }
      str.push_back('a' + i);
      dfs_sort_and_find(v->children[i], cur, need, str, ans);
      str.pop_back();
    }
  }
}

std::string trie_t::operator[](size_t index) const {
  index++;
  std::string answer = "";
  int cur = 0;
  dfs_sort_and_find(root, cur, index, "", answer);
  return answer;
}

void dfs_to_vector(node_ptr v, std::vector <std::string> &ans, std::string str) {
  for (size_t i = 0; i < (int)v->quantity; ++i) {
    ans.push_back(str);
  }
  for (int i = 0; i < 26; ++i) {
    if (v->children[i] != nullptr) {
      str.push_back('a' + i);
      dfs_to_vector(v->children[i], ans, str);
      str.pop_back();
    }
  }
}

std::vector<std::string> trie_t::to_vector() const {
  std::vector <std::string> answer;
  std::string current = "";
  dfs_to_vector(root, answer, "");
  return answer;
}

bool trie_t::empty() const {
  if (size() == 0) {
    return true;
  }
  return false;
}

void trie_t::swap(trie_t &other) {
  root.swap(other.root);
}



