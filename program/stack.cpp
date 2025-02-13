#include <iostream>
using namespace std;

template <typename T>
class stack {
private:
    T* data;               // 節點的資料
    stack<T>* pointer;     // 指向下一個節點
    static stack<T>* top;  // 堆疊頂部指標

public:
    // 建構函式，建立新節點
    stack(T* d) {
        data = d;
        pointer = top;
        top = this;
    }

   	// 靜態函式：彈出堆疊頂部元素
	static T* pop() {
   		 if (top == NULL) {
  		      cout << "Stack is empty!" << endl;
  		      return NULL;
    	}
    	// 保存當前節點資料和指向下一個節點的指標
    	T* show = top->data;
    	stack<T>* oldTop = top;
    	top = top->pointer;
    	// 釋放記憶體
    	delete oldTop;
    	return show;
	}
    // 靜態函式：壓入元素到堆疊
    static void push(T* d) {
        new stack(d); // 動態分配記憶體
    }
};

// 靜態成員初始化
template <typename T>
stack<T>* stack<T>::top = NULL;

int main() {
    int k1 = 1, k2 = 2, k3 = 3;
    // 將元素壓入堆疊
    stack<int>::push(&k1);
    stack<int>::push(&k2);
    stack<int>::push(&k3);

    // 從堆疊彈出元素並輸出
    cout << "Popped: " << *stack<int>::pop() << endl; // 輸出 3
    cout << "Popped: " << *stack<int>::pop() << endl; // 輸出 2
    cout << "Popped: " << *stack<int>::pop() << endl; // 輸出 1
    cout << "Popped: " << stack<int>::pop() << endl;  // 堆疊空，輸出 "Stack is empty!"
}

