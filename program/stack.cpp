#include <iostream>
using namespace std;

template <typename T>
class stack {
private:
    T* data;               // �`�I�����
    stack<T>* pointer;     // ���V�U�@�Ӹ`�I
    static stack<T>* top;  // ���|��������

public:
    // �غc�禡�A�إ߷s�`�I
    stack(T* d) {
        data = d;
        pointer = top;
        top = this;
    }

   	// �R�A�禡�G�u�X���|��������
	static T* pop() {
   		 if (top == NULL) {
  		      cout << "Stack is empty!" << endl;
  		      return NULL;
    	}
    	// �O�s��e�`�I��ƩM���V�U�@�Ӹ`�I������
    	T* show = top->data;
    	stack<T>* oldTop = top;
    	top = top->pointer;
    	// ����O����
    	delete oldTop;
    	return show;
	}
    // �R�A�禡�G���J��������|
    static void push(T* d) {
        new stack(d); // �ʺA���t�O����
    }
};

// �R�A������l��
template <typename T>
stack<T>* stack<T>::top = NULL;

int main() {
    int k1 = 1, k2 = 2, k3 = 3;
    // �N�������J���|
    stack<int>::push(&k1);
    stack<int>::push(&k2);
    stack<int>::push(&k3);

    // �q���|�u�X�����ÿ�X
    cout << "Popped: " << *stack<int>::pop() << endl; // ��X 3
    cout << "Popped: " << *stack<int>::pop() << endl; // ��X 2
    cout << "Popped: " << *stack<int>::pop() << endl; // ��X 1
    cout << "Popped: " << stack<int>::pop() << endl;  // ���|�šA��X "Stack is empty!"
}

