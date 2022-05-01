#ifndef SET_H
#define SET_H
template<typename T>
class Set {
private:
    int _size;
    int capacity;
    T* array;
public:
    Set();
    Set(const Set& set);
    Set& operator=(const Set& set);    
    void insert(const T& value);
    void erase(const T& value);
    bool find(const T& value);
    int size();
    Set<T>& intersect(const Set <T>& s);  
   
    friend std::ostream& operator<<(std::ostream& out, const Set<T>& set) {
        for (int i = 0; i < set._size; ++i) {
            std::cout << set.array[i] << " ";
        }
        return out;
    }
    ~Set();
};
#endif 
