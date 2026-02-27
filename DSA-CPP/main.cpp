/*
================================================================================
            CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT (DSA) TRONG C++
                    Từ Cơ Bản Đến Nâng Cao
================================================================================

MỤC LỤC:
1. CẤU TRÚC DỮ LIỆU CƠ BẢN
   - Array (Mảng)
   - Linked List (Danh sách liên kết)
   - Stack (Ngăn xếp)
   - Queue (Hàng đợi)
   - Deque (Hàng đợi hai đầu)

2. CẤU TRÚC DỮ LIỆU NÂNG CAO
   - Tree (Cây)
   - Binary Search Tree (Cây tìm kiếm nhị phân)
   - Heap (Đống)
   - Hash Table (Bảng băm)
   - Graph (Đồ thị)

3. GIẢI THUẬT SẮP XẾP
   - Bubble Sort, Selection Sort, Insertion Sort
   - Merge Sort, Quick Sort, Heap Sort

4. GIẢI THUẬT TÌM KIẾM
   - Linear Search, Binary Search
   - DFS, BFS

5. GIẢI THUẬT ĐỒ THỊ
   - Dijkstra, Bellman-Ford
   - Kruskal, Prim

6. KỸ THUẬT LẬP TRÌNH
   - Recursion (Đệ quy)
   - Dynamic Programming (Quy hoạch động)
   - Greedy (Tham lam)
   - Backtracking (Quay lui)

================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>

using namespace std;

/*
================================================================================
                    1. MẢNG (ARRAY)
================================================================================
*/

class ArrayOperations {
public:
    // 1.1. CÁC THAO TÁC CƠ BẢN VỚI MẢNG
    static void basic_array_operations() {
        cout << "\n=== THAO TÁC CƠ BẢN VỚI MẢNG ===" << endl;
        
        // Khai báo mảng tĩnh
        int arr[5] = {1, 2, 3, 4, 5};
        
        // Truy cập phần tử
        cout << "Phần tử đầu tiên: " << arr[0] << endl;
        cout << "Phần tử cuối cùng: " << arr[4] << endl;
        
        // Duyệt mảng
        cout << "Các phần tử: ";
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        // Sử dụng vector (mảng động)
        vector<int> vec = {10, 20, 30, 40, 50};
        
        // Thêm phần tử vào cuối - O(1) amortized
        vec.push_back(60);
        
        // Xóa phần tử cuối - O(1)
        vec.pop_back();
        
        // Insert vào vị trí - O(n)
        vec.insert(vec.begin() + 2, 25);  // Chèn 25 vào vị trí 2
        
        // Xóa phần tử tại vị trí - O(n)
        vec.erase(vec.begin() + 1);  // Xóa phần tử tại index 1
        
        // Duyệt vector
        cout << "Vector: ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    // 1.2. TÌM KIẾM TUYẾN TÍNH - O(n)
    static int linear_search(vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i;  // Trả về index
            }
        }
        return -1;  // Không tìm thấy
    }
    
    // 1.3. TÌM KIẾM NHỊ PHÂN - O(log n)
    // Yêu cầu: Mảng phải được sắp xếp
    static int binary_search(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;  // Tránh overflow
            
            if (arr[mid] == target) {
                return mid;  // Tìm thấy
            } else if (arr[mid] < target) {
                left = mid + 1;  // Tìm bên phải
            } else {
                right = mid - 1;  // Tìm bên trái
            }
        }
        return -1;  // Không tìm thấy
    }
    
    // 1.4. TÌM PHẦN TỬ LỚN NHẤT/NHỎ NHẤT - O(n)
    static void find_min_max(vector<int>& arr) {
        if (arr.empty()) return;
        
        int min_val = arr[0];
        int max_val = arr[0];
        
        for (int x : arr) {
            if (x < min_val) min_val = x;
            if (x > max_val) max_val = x;
        }
        
        cout << "Min: " << min_val << ", Max: " << max_val << endl;
    }
    
    // 1.5. ĐẢO NGƯỢC MẢNG - O(n)
    static void reverse_array(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    
    // 1.6. XOAY MẢNG - O(n)
    static void rotate_array(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;  // Xử lý k > n
        
        // Đảo ngược toàn bộ mảng
        reverse(arr.begin(), arr.end());
        // Đảo ngược k phần tử đầu
        reverse(arr.begin(), arr.begin() + k);
        // Đảo ngược phần còn lại
        reverse(arr.begin() + k, arr.end());
    }
};

/*
================================================================================
                    2. DANH SÁCH LIÊN KẾT (LINKED LIST)
================================================================================
*/

// Node của Singly Linked List
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    
public:
    // Constructor
    LinkedList() : head(nullptr) {}
    
    // Destructor - giải phóng bộ nhớ
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    
    // 2.1. THÊM VÀO ĐẦU - O(1)
    void insert_at_head(int value) {
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }
    
    // 2.2. THÊM VÀO CUỐI - O(n)
    void insert_at_tail(int value) {
        Node* new_node = new Node(value);
        
        if (head == nullptr) {
            head = new_node;
            return;
        }
        
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    
    // 2.3. THÊM VÀO VỊ TRÍ - O(n)
    void insert_at_position(int value, int position) {
        if (position == 0) {
            insert_at_head(value);
            return;
        }
        
        Node* new_node = new Node(value);
        Node* current = head;
        
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        
        if (current == nullptr) {
            cout << "Vị trí không hợp lệ" << endl;
            delete new_node;
            return;
        }
        
        new_node->next = current->next;
        current->next = new_node;
    }
    
    // 2.4. XÓA NODE ĐẦU - O(1)
    void delete_head() {
        if (head == nullptr) return;
        
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    // 2.5. XÓA NODE CUỐI - O(n)
    void delete_tail() {
        if (head == nullptr) return;
        
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        
        delete current->next;
        current->next = nullptr;
    }
    
    // 2.6. XÓA NODE CÓ GIÁ TRỊ - O(n)
    void delete_value(int value) {
        if (head == nullptr) return;
        
        if (head->data == value) {
            delete_head();
            return;
        }
        
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
    
    // 2.7. TÌM KIẾM - O(n)
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    // 2.8. ĐẢO NGƯỢC LINKED LIST - O(n)
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;  // Lưu node tiếp theo
            current->next = prev;  // Đảo ngược con trỏ
            prev = current;        // Di chuyển prev
            current = next;        // Di chuyển current
        }
        
        head = prev;
    }
    
    // 2.9. PHÁT HIỆN CHU TRÌNH (Floyd's Cycle Detection) - O(n)
    bool has_cycle() {
        if (head == nullptr) return false;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;  // Có chu trình
            }
        }
        
        return false;
    }
    
    // 2.10. TÌM ĐIỂM GIỮA - O(n)
    Node* find_middle() {
        if (head == nullptr) return nullptr;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // In linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

// Doubly Linked List Node
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    // Thêm vào đầu
    void insert_at_head(int value) {
        DNode* new_node = new DNode(value);
        
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    
    // Thêm vào cuối
    void insert_at_tail(int value) {
        DNode* new_node = new DNode(value);
        
        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    
    // Hiển thị từ đầu đến cuối
    void display_forward() {
        DNode* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    
    // Hiển thị từ cuối về đầu
    void display_backward() {
        DNode* current = tail;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }
};

/*
================================================================================
                    3. NGĂN XẾP (STACK)
================================================================================
Đặc điểm: LIFO - Last In First Out (Vào sau, ra trước)
Ứng dụng: Undo/Redo, kiểm tra dấu ngoặc, DFS, evaluation expression
*/

class Stack {
private:
    vector<int> data;
    
public:
    // 3.1. PUSH - Thêm vào đỉnh - O(1)
    void push(int value) {
        data.push_back(value);
    }
    
    // 3.2. POP - Xóa đỉnh - O(1)
    void pop() {
        if (!is_empty()) {
            data.pop_back();
        }
    }
    
    // 3.3. TOP - Xem đỉnh - O(1)
    int top() {
        if (is_empty()) {
            throw runtime_error("Stack rỗng");
        }
        return data.back();
    }
    
    // 3.4. KIỂM TRA RỖNG - O(1)
    bool is_empty() {
        return data.empty();
    }
    
    // 3.5. KÍCH THƯỚC - O(1)
    int size() {
        return data.size();
    }
    
    // Hiển thị stack
    void display() {
        cout << "Stack (đỉnh -> đáy): ";
        for (int i = data.size() - 1; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// 3.6. ỨNG DỤNG: KIỂM TRA DẤU NGOẶC HỢP LỆ
bool is_valid_parentheses(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);  // Ngoặc mở: push vào stack
        } else {
            if (st.empty()) return false;
            
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                st.pop();  // Cặp ngoặc hợp lệ
            } else {
                return false;
            }
        }
    }
    
    return st.empty();  // Stack phải rỗng
}

// 3.7. ỨNG DỤNG: TÍNH BIỂU THỨC POSTFIX (Hậu tố)
// VD: "2 3 + 5 *" = (2 + 3) * 5 = 25
int evaluate_postfix(string expression) {
    stack<int> st;
    
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue;
        
        // Nếu là số
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;  // Lùi lại 1 vì vòng for sẽ tăng
            st.push(num);
        }
        // Nếu là toán tử
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            
            switch (expression[i]) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    
    return st.top();
}

/*
================================================================================
                    4. HÀNG ĐỢI (QUEUE)
================================================================================
Đặc điểm: FIFO - First In First Out (Vào trước, ra trước)
Ứng dụng: BFS, Task scheduling, Buffer
*/

class Queue {
private:
    vector<int> data;
    int front_idx;
    
public:
    Queue() : front_idx(0) {}
    
    // 4.1. ENQUEUE - Thêm vào cuối - O(1)
    void enqueue(int value) {
        data.push_back(value);
    }
    
    // 4.2. DEQUEUE - Xóa đầu - O(1) amortized
    void dequeue() {
        if (!is_empty()) {
            front_idx++;
            
            // Tối ưu: nén lại khi front_idx quá lớn
            if (front_idx > data.size() / 2) {
                data.erase(data.begin(), data.begin() + front_idx);
                front_idx = 0;
            }
        }
    }
    
    // 4.3. FRONT - Xem phần tử đầu - O(1)
    int front() {
        if (is_empty()) {
            throw runtime_error("Queue rỗng");
        }
        return data[front_idx];
    }
    
    // 4.4. KIỂM TRA RỖNG
    bool is_empty() {
        return front_idx >= data.size();
    }
    
    // 4.5. KÍCH THƯỚC
    int size() {
        return data.size() - front_idx;
    }
    
    // Hiển thị queue
    void display() {
        cout << "Queue (đầu -> cuối): ";
        for (int i = front_idx; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// Priority Queue (Hàng đợi ưu tiên)
// STL cung cấp sẵn: priority_queue
void priority_queue_demo() {
    cout << "\n=== PRIORITY QUEUE ===" << endl;
    
    // Max heap (mặc định)
    priority_queue<int> max_heap;
    max_heap.push(10);
    max_heap.push(30);
    max_heap.push(20);
    max_heap.push(5);
    
    cout << "Max heap: ";
    while (!max_heap.empty()) {
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
    cout << endl;
    
    // Min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;
    min_heap.push(10);
    min_heap.push(30);
    min_heap.push(20);
    min_heap.push(5);
    
    cout << "Min heap: ";
    while (!min_heap.empty()) {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
    cout << endl;
}

/*
================================================================================
                    5. CÂY NHỊ PHÂN (BINARY TREE)
================================================================================
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;
    
    BinaryTree() : root(nullptr) {}
    
    // 5.1. DUYỆT CÂY PREORDER (Tiền tự): Root -> Left -> Right
    void preorder(TreeNode* node) {
        if (node == nullptr) return;
        
        cout << node->val << " ";  // Xử lý root
        preorder(node->left);      // Duyệt trái
        preorder(node->right);     // Duyệt phải
    }
    
    // 5.2. DUYỆT CÂY INORDER (Trung tự): Left -> Root -> Right
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        
        inorder(node->left);       // Duyệt trái
        cout << node->val << " ";  // Xử lý root
        inorder(node->right);      // Duyệt phải
    }
    
    // 5.3. DUYỆT CÂY POSTORDER (Hậu tự): Left -> Right -> Root
    void postorder(TreeNode* node) {
        if (node == nullptr) return;
        
        postorder(node->left);     // Duyệt trái
        postorder(node->right);    // Duyệt phải
        cout << node->val << " ";  // Xử lý root
    }
    
    // 5.4. DUYỆT CÂY LEVEL ORDER (Theo mức): BFS
    void level_order(TreeNode* root) {
        if (root == nullptr) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            cout << node->val << " ";
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    // 5.5. CHIỀU CAO CỦA CÂY
    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        
        int left_height = height(node->left);
        int right_height = height(node->right);
        
        return 1 + max(left_height, right_height);
    }
    
    // 5.6. ĐẾM SỐ NODE
    int count_nodes(TreeNode* node) {
        if (node == nullptr) return 0;
        
        return 1 + count_nodes(node->left) + count_nodes(node->right);
    }
    
    // 5.7. TÌM KIẾM TRONG CÂY
    bool search(TreeNode* node, int value) {
        if (node == nullptr) return false;
        if (node->val == value) return true;
        
        return search(node->left, value) || search(node->right, value);
    }
};

/*
================================================================================
                6. CÂY TÌM KIẾM NHỊ PHÂN (BST)
================================================================================
Tính chất: Left < Root < Right
*/

class BST {
public:
    TreeNode* root;
    
    BST() : root(nullptr) {}
    
    // 6.1. THÊM NODE - O(log n) trung bình, O(n) worst case
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        
        if (value < node->val) {
            node->left = insert(node->left, value);
        } else if (value > node->val) {
            node->right = insert(node->right, value);
        }
        
        return node;
    }
    
    // 6.2. TÌM KIẾM - O(log n) trung bình
    bool search(TreeNode* node, int value) {
        if (node == nullptr) return false;
        
        if (value == node->val) return true;
        else if (value < node->val) return search(node->left, value);
        else return search(node->right, value);
    }
    
    // 6.3. TÌM MIN (node trái nhất)
    TreeNode* find_min(TreeNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    // 6.4. TÌM MAX (node phải nhất)
    TreeNode* find_max(TreeNode* node) {
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    
    // 6.5. XÓA NODE - O(log n)
    TreeNode* delete_node(TreeNode* node, int value) {
        if (node == nullptr) return nullptr;
        
        if (value < node->val) {
            node->left = delete_node(node->left, value);
        } else if (value > node->val) {
            node->right = delete_node(node->right, value);
        } else {
            // Tìm thấy node cần xóa
            
            // Trường hợp 1: Không có con hoặc 1 con
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            
            // Trường hợp 2: Có 2 con
            // Tìm successor (node nhỏ nhất bên phải)
            TreeNode* successor = find_min(node->right);
            node->val = successor->val;
            node->right = delete_node(node->right, successor->val);
        }
        
        return node;
    }
    
    // 6.6. KIỂM TRA BST HỢP LỆ
    bool is_valid_bst(TreeNode* node, long min_val, long max_val) {
        if (node == nullptr) return true;
        
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }
        
        return is_valid_bst(node->left, min_val, node->val) &&
               is_valid_bst(node->right, node->val, max_val);
    }
    
    // In BST theo inorder (sẽ ra thứ tự tăng dần)
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }
};

/*
================================================================================
                    7. BẢNG BĂM (HASH TABLE)
================================================================================
*/

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    vector<list<pair<string, int>>> table;  // Chaining để xử lý collision
    
    // Hàm băm đơn giản
    int hash_function(string key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash + c) % TABLE_SIZE;
        }
        return hash;
    }
    
public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }
    
    // 7.1. INSERT - O(1) trung bình
    void insert(string key, int value) {
        int index = hash_function(key);
        
        // Kiểm tra key đã tồn tại chưa
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;  // Cập nhật value
                return;
            }
        }
        
        // Thêm mới
        table[index].push_back({key, value});
    }
    
    // 7.2. SEARCH - O(1) trung bình
    bool search(string key, int& value) {
        int index = hash_function(key);
        
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        
        return false;
    }
};

/*
================================================================================
                    8. ĐỒ THỊ (GRAPH)
================================================================================
Khái niệm:
- Đồ thị G = (V, E)
- V: tập đỉnh (vertices)
- E: tập cạnh (edges)

Phân loại:
- Directed / Undirected
- Weighted / Unweighted

Biểu diễn:
- Adjacency List (phổ biến, tối ưu bộ nhớ)
- Adjacency Matrix
================================================================================
*/

class Graph {
private:
    int V;  // số đỉnh
    vector<vector<pair<int,int>>> adj; 
    // adj[u] = { (v, weight) }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Thêm cạnh (undirected)
    void add_edge(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    /*
    =========================
        DFS - Depth First Search
        O(V + E)
    =========================
    */
    void dfs_util(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (auto& edge : adj[u]) {
            int v = edge.first;
            if (!visited[v]) {
                dfs_util(v, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(V, false);
        cout << "DFS: ";
        dfs_util(start, visited);
        cout << endl;
    }

    /*
    =========================
        BFS - Breadth First Search
        O(V + E)
    =========================
    */
    void bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";

            for (auto& edge : adj[u]) {
                int v = edge.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    /*
    =========================
        DIJKSTRA - Shortest Path
        O((V + E) log V)
    =========================
    */
    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra từ đỉnh " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Đến " << i << ": " << dist[i] << endl;
        }
    }
};

/*
================================================================================
                    9. THUẬT TOÁN SẮP XẾP (SORTING)
================================================================================
*/

/*
-------------------------
    Bubble Sort
    O(n^2) - Stable
-------------------------
*/
void bubble_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

/*
-------------------------
    Selection Sort
    O(n^2) - Not stable
-------------------------
*/
void selection_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        swap(a[i], a[min_idx]);
    }
}

/*
-------------------------
    Insertion Sort
    O(n^2) - Stable
-------------------------
*/
void insertion_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

/*
-------------------------
    Merge Sort
    O(n log n) - Stable
-------------------------
*/
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> L(a.begin()+l, a.begin()+m+1);
    vector<int> R(a.begin()+m+1, a.begin()+r+1);

    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < L.size()) a[k++] = L[i++];
    while (j < R.size()) a[k++] = R[j++];
}

void merge_sort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r-l)/2;
    merge_sort(a, l, m);
    merge_sort(a, m+1, r);
    merge(a, l, m, r);
}

/*
-------------------------
    Quick Sort
    O(n log n) avg
-------------------------
*/
int partition(vector<int>& a, int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] < pivot) {
            swap(a[++i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quick_sort(vector<int>& a, int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quick_sort(a, l, pi-1);
        quick_sort(a, pi+1, r);
    }
}

/*
================================================================================
                    10. DYNAMIC PROGRAMMING (DP)
================================================================================
*/

/*
-------------------------
    Fibonacci
-------------------------
*/

// Recursive (O(2^n))
int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n-1) + fib_recursive(n-2);
}

// Memoization (Top-down) O(n)
int fib_memo(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib_memo(n-1, dp) + fib_memo(n-2, dp);
}

// Tabulation (Bottom-up) O(n)
int fib_tab(int n) {
    if (n <= 1) return n;
    vector<int> dp(n+1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

/*
-------------------------
    0/1 Knapsack
-------------------------
*/
int knapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(
                    dp[i-1][w],
                    val[i-1] + dp[i-1][w-wt[i-1]]
                );
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

/*
-------------------------
    Longest Common Subsequence (LCS)
-------------------------
*/
int lcs(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

/*
================================================================================
                    MAIN DEMO - DSA BIBLE C++
================================================================================
Mục tiêu:
- Demo cách dùng từng Data Structure / Algorithm
- Giống format khi giải thích trong phỏng vấn
================================================================================
*/

int main() {

    cout << "================ DSA BIBLE C++ DEMO ================\n";

    /*
    ====================================================
        1. ARRAY & VECTOR
    ====================================================
    */
    cout << "\n--- ARRAY / VECTOR ---\n";
    vector<int> arr = {5, 2, 9, 1, 3};

    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    insertion_sort(arr);
    cout << "After Insertion Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    /*
    ====================================================
        2. LINKED LIST
    ====================================================
    */
    cout << "\n--- LINKED LIST ---\n";
    LinkedList list;
    list.insert_at_head(3);
    list.insert_at_head(1);
    list.insert_at_tail(5);
    list.insert_at_tail(7);

    cout << "Linked List: ";
    list.display();

    list.reverse();
    cout << "Reversed List: ";
    list.display();

    /*
    ====================================================
        3. STACK
    ====================================================
    */
    cout << "\n--- STACK ---\n";
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack top: " << st.top() << endl;
    st.pop();
    cout << "After pop, top: " << st.top() << endl;

    string expr = "{[()]}";
    cout << "Valid parentheses '" << expr << "'? "
         << (is_valid_parentheses(expr) ? "YES" : "NO") << endl;

    /*
    ====================================================
        4. QUEUE
    ====================================================
    */
    cout << "\n--- QUEUE ---\n";
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Queue front: " << q.front() << endl;
    q.dequeue();
    cout << "After dequeue, front: " << q.front() << endl;

    /*
    ====================================================
        5. SORTING
    ====================================================
    */
    cout << "\n--- SORTING ---\n";
    vector<int> a = {8, 4, 6, 2, 9};

    cout << "Before Quick Sort: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    quick_sort(a, 0, a.size() - 1);

    cout << "After Quick Sort: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    /*
    ====================================================
        6. BINARY TREE
    ====================================================
    */
    cout << "\n--- BINARY TREE ---\n";
    BinaryTree bt;
    bt.root = new TreeNode(1);
    bt.root->left = new TreeNode(2);
    bt.root->right = new TreeNode(3);
    bt.root->left->left = new TreeNode(4);
    bt.root->left->right = new TreeNode(5);

    cout << "Inorder: ";
    bt.inorder(bt.root);
    cout << endl;

    cout << "Height: " << bt.height(bt.root) << endl;

    /*
    ====================================================
        7. BINARY SEARCH TREE
    ====================================================
    */
    cout << "\n--- BST ---\n";
    BST bst;
    bst.root = bst.insert(bst.root, 8);
    bst.insert(bst.root, 3);
    bst.insert(bst.root, 10);
    bst.insert(bst.root, 1);
    bst.insert(bst.root, 6);

    cout << "BST Inorder: ";
    bst.inorder(bst.root);
    cout << endl;

    cout << "Search 6? "
         << (bst.search(bst.root, 6) ? "FOUND" : "NOT FOUND") << endl;

    /*
    ====================================================
        8. GRAPH
    ====================================================
    */
    cout << "\n--- GRAPH ---\n";
    Graph g(5);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 2, 1);
    g.add_edge(2, 1, 2);
    g.add_edge(1, 3, 1);
    g.add_edge(2, 3, 5);
    g.add_edge(3, 4, 3);

    g.dfs(0);
    g.bfs(0);
    g.dijkstra(0);

    /*
    ====================================================
        9. DYNAMIC PROGRAMMING
    ====================================================
    */
    cout << "\n--- DYNAMIC PROGRAMMING ---\n";

    int n = 10;
    vector<int> dp(n + 1, -1);
    cout << "Fibonacci(" << n << ") = "
         << fib_memo(n, dp) << endl;

    vector<int> wt = {2, 3, 4};
    vector<int> val = {40, 50, 100};
    int W = 5;

    cout << "Knapsack max value = "
         << knapsack(W, wt, val) << endl;

    string s1 = "ABCBDAB";
    string s2 = "BDCAB";

    cout << "LCS length = "
         << lcs(s1, s2) << endl;

    cout << "\n================ END DEMO =================\n";

    return 0;
}
