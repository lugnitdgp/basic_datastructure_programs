template <typename T>
class Queue {
    T *data;
    int nextIndex;
    int frontIndex;
    int size;
    int capacity;

    public :

    Queue() {
        data = new T[5];
        nextIndex = 0;
        frontIndex = -1;
        size = 0;
        capacity = 5;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(T element) {
        if(size == capacity) {
            // Queue full
            // return;
            T *temp = data;
            data = new T[2 * capacity];
            int j = 0;
            for(int i = frontIndex; i < capacity; i++) {
                data[j++] = temp[i];
            }
            for(int i = 0; i < frontIndex; i++) {
                data[j++] = temp[i];
            }
            delete [] temp;
            frontIndex = 0;
            nextIndex = j;
            capacity *= 2;
        }
        data[nextIndex] = element;
        size++;
        nextIndex = (nextIndex + 1) % capacity;
        if(frontIndex == -1) {
            frontIndex = 0;
        }
    }

    T front() {
        if(frontIndex == -1) {
            // Queue empty
            return 0;
        }
        return data[frontIndex];
    }

    T dequeue() {
        if(frontIndex == -1) {
            // Queue empty
            return 0;
        }
        T ans = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        if(size == 0) {
            frontIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }







};
