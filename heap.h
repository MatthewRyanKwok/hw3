#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void heapifyUp(int index);
  void heapifyDown(int index);

  std::vector<T> data_; //stores elements in the heap
  int m_; //num children nodes can have
  PComparator comp_; //determines the priority order
  


};

// Add implementation of member functions here

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(int index)
{
    int parentIndex = (index - 1) / m_; //computes parent index
    while (index > 0 && comp_(data_[index], data_[parentIndex])) { //while element at the index has higher priority than parent, move up
        std::swap(data_[index], data_[parentIndex]); //swap w parent
        index = parentIndex;
        parentIndex = (index - 1) / m_;
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(int index)
{
    int smallestChild;
    while (true) {
        smallestChild = index; //current index should have highest priority
        for (int i = 1; i <= m_; ++i) { //finds child with highest priority
            int childIndex = m_ * index + i;
            if (static_cast<size_t>(childIndex) < data_.size() && comp_(data_[childIndex], data_[smallestChild])) { //checks if childs index is in bounds/has higher priority
                smallestChild = childIndex;
            }
        }

        if (smallestChild == index) { //stops if no child has a higher prio
            break;  
        }

        std::swap(data_[index], data_[smallestChild]);
        index = smallestChild; //continues down the tree
    }
}


template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
    : m_(m), comp_(c)
{

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
    return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
    return data_.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("The heap is empty.");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data_.front(); //top element will be at 0 index

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("The heap is empty.");

  }
  std::swap(data_.front(), data_.back()); //swaps root w last element, removes last element
  data_.pop_back();

  if (!empty()) { //if there are still elements, restores the order of the heap
      heapifyDown(0);
  }

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
    data_.push_back(item); //adds item
    heapifyUp(data_.size() - 1); //restores the heap order
}

#endif

