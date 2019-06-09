#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>  //ptrdiff_t
#include <iterator> //std::bidirectional_iterator_tag
#include <iostream>
#include <utility>
#include <initializer_list>

template <typename T>
class List;

template <typename T>
struct ListNode {
  T         value = T();
  ListNode* prev = nullptr;
  ListNode* next = nullptr;
};

template <typename T>
struct ListIterator {
  using Self              = ListIterator<T>;
  using value_type        = T;
  using pointer           = T*;
  using reference         = T&;
  using difference_type   = ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;


  /* DESCRIPTION  operator*() 
   * When called on the iterator like *It, returns a reference to the value of the Node.
   */
  T& operator*() const {
    return node->value;
  } 

  /* DESCRIPTION  operator->()
   * It-> will return a pointer to the value of the Node.
   * 
   */
  T* operator->() const {
    return &(node->value);
  }

  /* DESCRIPTION operator++() > PREINCREMENT
   * ++It will change the node to the one next to it in the list,
   * and return a reference to the iterator
   *
   */
  ListIterator<T>& operator++() {
    node = node->next;
    return *this;
  }

  
  /* DESCRIPTION operator++() > POSTINCREMENT
   * It++ will change the node to the one next to it in the list,
   * and return a copy of the iterator from before the change
   */
  ListIterator<T> operator++(int) {
    ListIterator<T> copy{this};
    node = node->next;
    return copy;
  }

  /* DESCRIPTION operator==()
   * ItA == ItB will return true if ItA and ItB refer to the same element in the list. It will return false if otherwise. 
   * 
   */
  bool operator==(ListIterator<T> const& x) const {
    return node == x.node;
  }

  
  /* DESCRIPTION operator!=()
   * ItA != ItB will return false if ItA and ItB refer to the same element in the list. It will return true if they are the same.
   * 
   */
  bool operator!=(ListIterator<T> const& x) const {
    return node != x.node;
  }

  
  /* DESCRIPTION
   * It.next() returns the iterator of the next element in the list.
   * If it is the "end" iterator, will return nullptr
   */
  ListIterator<T> next() const {
    if (nullptr != node) {
      return ListIterator{node->next};
    } else {
      return ListIterator{nullptr};
    }
  }
  
  
  /* DESCRIPTION
   * It.prev() returns the iterator of the previous element in the list.
   * If it is the "begin" iterator, will return nullptr
   */
  ListIterator<T> prev() const {
    if (nullptr != node) {
      return ListIterator{node->prev};
    } else {
      return ListIterator{nullptr};
    }
  }
  
  ListNode<T>* node = nullptr;
};



//template <typename T>
template <typename T>
class List {
  public:
    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = T const*;
    using reference       = T&;
    using const_reference = T const&;
    using iterator        = ListIterator<T>;

    /* DESCRIPTION
     * Default Constructor
     * Creates an empty list begin and end point to nullptr
     */
    List() :
      size_{0},
      first_{nullptr},
      last_{nullptr}
    {}

    /* DESCRIPTION
     * Copy Constructor 
     *
     */
    List(List<T> const& rhs)  :
      size_{0},
      first_{nullptr},
      last_{nullptr}
    {
      if (!rhs.empty()) {
        for(auto it = rhs.begin(); it != rhs.end(); ++it) {
          push_back(*it);
        };
      }
    }

    /* DESCRIPTION
     * Move Constructor
     *
     */
    List(List<T>&& rhs) :
      size_(rhs.size_),
      first_(rhs.first_),
      last_(rhs.last_) {
        rhs.size_ = 0;
        rhs.first_ = nullptr;
        rhs.last_ = nullptr;

        #ifndef NDEBUG 
        std::cout << "Called Move-Constructor" << std::endl;
        #endif //NDEBUG
    }

    /* DESCRIPTION
     * Initializer-List Constructor 
     * A series of elements is passed between {} (an initializer list) as argument, which will be the nodes of the constructed list.
     * 
     */
    List(std::initializer_list<T> ini_list) {
      size_ = 0;
      for(auto el : ini_list) {
        push_back(el);
      };
    }

    /* DESCRIPTION
     * Assigns the given list a deep-copy of the list passed as argument
     * (creates a copy of each element).
     * Here the parameter not passed as const&, because we need a copy
     * anyway: passing it so creates the copy we will use to swap and then
     * it will be destroyed once the function closes.
     */
    List<T>& operator=(List<T> rhs) {
      swap(rhs);
      return *this;
    }
    /* DESCRIPTION
     * Implement swap member function to use in operator=
     */
    void swap (List<T>& rhs) {
      std::swap(first_, rhs.first_);
      std::swap(last_, rhs.last_);
    }

    /* DESCRIPTION
     * Compares the list to another list passed as argument.
     * Returns true if the contents of the containers are equal, false otherwise
     */
    bool operator==(List<T> const& rhs) {
      if(size() == rhs.size()) {
        if (!empty()) {
          auto it_rhs = rhs.begin();
          for(auto it = begin(); it != end(); ++it) {
            if(*it != *it_rhs) {
              return false;
            };
            ++it_rhs;
          }
        }
        return true;
      } else {
        return false;
      }
    }

    /* DESCRIPTION
     * Compares the list to another list passed as argument.
     * Returns true if the contents of the containers are not equal, false otherwise
     */
    bool operator!=(List<T> const& rhs) { 
      return !(*this==rhs);
    }

    /* DESCRIPTION
     * Destructor
     * Empties the list 
     */
    ~List() {
      clear();
    }

    /* DESCRIPTION
     * Returns an Iterator pointing to the first element of the list
     */
    ListIterator<T> begin() const {
      //assert(!empty());
      return ListIterator<T>{first_};
    }

    /* DESCRIPTION
     * Returns an Iterator pointing to the past-the-end element of the list (theoretical??)
     */
    ListIterator<T> end() const {
      //assert(!empty());
      return ListIterator<T>{nullptr};
    }

    /* DESCRIPTION
     * Removes (and destroys) all elements from the list and leaves it with size 0 
     */
    void clear() {
      while(size_ > 0) {
        pop_back();
      }
    }

    /* DESCRIPTION
     * Inserts an element of type T in the list at the given position (ListIterator).
     * It returns the iterator of the new element. 
     */
    ListIterator<T> insert(ListIterator<T> pos, T const& element) {
        if(empty() && pos == end()) {
          push_front(element);
        } 
        else if(pos == begin()) {
        push_front(element);
        return begin();
      } else if(pos == end()) {
        push_back(element);
        return end().prev();
      } else {
        ListNode<T>* node = new ListNode<T>{T(element), pos.prev().node, pos.node};
        if(pos.node->prev != nullptr) 
          pos.prev().node->next = node;
        if(pos.node != nullptr)
          pos.node->prev = node;
        
        ++size_;
        return ListIterator<T>{node};
      }
    }

    /* DESCRIPTION
     * It inverts the order of the list elements.
     */
    void reverse() {
      ListNode<T>* queued = first_;
      while(queued != nullptr) {
        std::swap(queued->next, queued->prev);
        queued = queued->prev;
      }
      std::swap(first_, last_);
    }


    /* DESCRIPTION
     * It adds a new element T to the list as first element 
     */
    void push_front(T const& element) {
      // Copy construct and assign new ref to pointer
		  first_ = new ListNode<T>{T(element), nullptr, first_ };
      if (size_ == 0) {
        // If it is the first added element, then it will also be the last
        last_ = first_;
      } else {
        // If there are already other elements, then the previous first (now second)
        // needs to change its prev pointer from 'nullptr' to the new first
        first_->next->prev = first_;
      }
      ++size_;
    }

    /* DESCRIPTION
     * It adds a new element T to the list as last element 
     */
    void push_back(T const& element) {
      // Copy construct and assign new ref to pointer
		  last_ = new ListNode<T>{T(element), last_, nullptr};
      if (size_ == 0) {
        // If it is the first added element, then it will also be the first
        first_ = last_;
      } else {
        // If there are already other elements, then the previous last (now second last)
        // needs to change its next pointer from 'nullptr' to the new last
        last_->prev->next = last_;
      }
      ++size_;
    }

    /* DESCRIPTION
     * It removes the first element of the list
     */
    void pop_front() {
      assert(!empty()); //abort if already empty
      // Store the pointer to the second (it will be the new first) before delete
      ListNode<T>* n = first_->next;
      // delete the first node, to avoid memory leak
      delete first_;
      first_ = n;
      --size_;
      if (empty()) {
        // If the list is now empty, the last element will be nullptr
        last_ = nullptr;
      } else {
        // if not, we can assign the (existing) new first element, a nullptr as prev
        first_->prev = nullptr;
      }
    }

    /* DESCRIPTION
     * It removes the last element of the list
     */
    void pop_back() {
      assert(!empty()); //abort if already empty
      // Store the pointer to the second last (it will be the new last) before delete
      ListNode<T>* n = last_->prev;
      // delete the last node, to avoid memory leak
      delete last_;
      // now assign the pointer to the new last element
      last_ = n;
      --size_;
      if (empty()) {
        // If the list is now empty, the first element will be nullptr
        first_ = nullptr;
      } else {
        // if not, we can assign the (existing) new last element, a nullptr as next
        last_->next = nullptr;
      }
    }

    /* DESCRIPTION
     * It returns a reference to the first node of the list
     */
    T& front() {
      assert(!empty());
      return first_->value;
    }
   
    /* DESCRIPTION
     * It returns a reference to the last node of the list
     */
    T& back() {
      assert(!empty());
      return last_->value;
    }

    /* DESCRIPTION
     * Returns true if no elements in the list (size is 0), false otherwise 
     */
    bool empty() const {
      return size_ == 0;
    };

    /* DESCRIPTION
     * Returns the amount of elements in the list 
     */
    std::size_t size() const {
      return size_;
  };


  private:
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
};

/* DESCRIPTION
 * Takes a list as parameter and returns a new list with those elements in reversed order 
 */
template<typename T>
List<T> reverse(List<T> const& list) {
  List<T> reversed_list{list};
  reversed_list.reverse();
  return reversed_list;
} 

/* DESCRIPTION
 * Concatenate two lists into a third
 */
template<typename T>
List<T> operator+(List<T> const& lhs, List<T> const& rhs) {
  List<T> concatenated_list{lhs};
  for(auto el : rhs) {
    concatenated_list.push_back(el);
  }
  return concatenated_list;
} 


#endif // # define BUW_LIST_HPP