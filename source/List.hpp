#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>  //ptrdiff_t
#include <iterator> //std::bidirectional_iterator_tag
#include <iostream>

#include <initializer_list>

template <typename T>
class List;

template <typename T>
struct ListNode {
  T         value = T ();
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
   * When called on the iterator like It*, returns a reference to the value of the Node.
   */
  T&  operator*()  const {
    //not implemented yet
    return {};
  } 

  /* DESCRIPTION  operator->()
   * It-> will return a pointer to the value of the Node.
   * 
   */
  T* operator->() const {
    //not implemented yet
    return nullptr;
  }

  /* DESCRIPTION operator++() 
   * It++ will return a reference to the iterator of the next element in the list
   *
   */
  ListIterator<T>& operator++() {
    //not implemented yet
    return {};
  } //PREINCREMENT

  
  /* DESCRIPTION operator++() 
   * It++(int) will return the iterator that is next at so many steps as specified (param int).
   * @param int - How many iterators to "advance"
   */
  ListIterator<T> operator++(int) {
    //not implemented yet
    return {};
  } //POSTINCREMENT (signature distinguishes)

  /* DESCRIPTION operator==()
   * ItA == ItB will return true if ItA and ItB refer to the same element in the list. It will return false if otherwise. 
   * 
   */
  bool operator==(ListIterator<T> const& x) const {
    //not implemented yet
  }

  
  /* DESCRIPTION operator==()
   * ItA != ItB will return false if ItA and ItB refer to the same element in the list. It will return true if they are the same.
   * 
   */
  bool operator!=(ListIterator<T> const& x) const {
    //not implemented yet
  }

  
  /* DESCRIPTION operator==()
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


  ListNode <T>* node = nullptr;
};



template <typename T>
class List {
  public:
    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = T const*;
    using reference       = T&;
    using const_reference = T const&;
    using iterator        = ListIterator<T>;

    // not implemented yet
    // do not forget about the initialiser list !
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
    //TODO: Copy-Konstruktor using Deep-Copy semantics (Aufgabe 4.8)
    List(List<T> const&) {}

    /* DESCRIPTION
     * Move Constructor
     *
     */
    //TODO: Move-Konstruktor (Aufgabe 4.13)
    List(List<T>&&) {}

    //TODO: Initializer-List Konstruktor (4.14)
    /* DESCRIPTION
     * Initializer-List Constructor 
     * A series of elements is passed between {} (an initializer list) as argument, which will be the nodes of the constructed list.
     * 
     */
    List(std::initializer_list<T> ini_list) {
      //not implemented yet
    }

    /* DESCRIPTION
     * Assigns the given list a deep-copy of the list passed as argument
     * (creates a copy of each element).
     */
    List<T>& operator=(List<T> const&) {
      //TODO: Assignment operator (Aufgabe 4.12)
      return *this;
    }

    /* DESCRIPTION
     * Compares the list to another list passed as argument.
     * Returns true if the contents of the containers are equal, false otherwise
     */
    bool operator==(List<T> const& rhs) {
      //TODO: operator== (Aufgabe 4.7)
      return false;
    }

    /* DESCRIPTION
     * Compares the list to another list passed as argument.
     * Returns true if the contents of the containers are not equal, false otherwise
     */
    bool operator!=(List<T> const& rhs) { 
      //TODO: operator!= (Aufgabe 4.7)
      return false
    }

    /* DESCRIPTION
     * Destructor
     * Empties the list 
     */
    ~List() {
      //TO IMPLEMENT PROPERLY
    }

    /* DESCRIPTION
     * Returns an Iterator pointing to the first element of the list
     */
    ListIterator<T> begin() {
      assert(!empty());
      ////not implemented yet
      return ListIterator<T>{};
    }


    /* DESCRIPTION
     * Returns an Iterator pointing to the last element of the list
     */
    ListIterator<T> end() {
      assert(!empty());

      ////not implemented yet
      return ListIterator<T>{};
    }

    /* DESCRIPTION
     * Removes (and destroys) all elements from the list and leaves it with size 0 
     */
    void clear() {
      ////not implemented yet
    }

    /* DESCRIPTION
     * Inserts an element of type T in the list at the given position (ListIterator).
     * It returns the iterator of the new element. 
     */
    ListIterator<T> insert(ListIterator<T> pos, T const& value) {
      //TODO: member function insert
      return ListIterator<T>{};
    }

    /* DESCRIPTION
     * It inverts the order of the list elements.
     */
    void reverse() {
      //TODO: member function reverse
    }


    /* DESCRIPTION
     * It adds a new element T to the list as first element 
     */
    void push_front(T const& element) {
      //not implemented yet
    }

    /* DESCRIPTION
     * It adds a new element T to the list as last element 
     */
    void push_back(T const& element) {
      //not implemented yet
    }

    /* DESCRIPTION
     * It removes the first element of the list
     */
    void pop_front() {
      assert(!empty());
      //not implemented yet
    }

    /* DESCRIPTION
     * It removes the last element of the list
     */
    void pop_back() {
      assert(!empty());
    //not implemented yet
    }

    /* DESCRIPTION
     * It returns a reference to the first node of the list
     */
    T& front() {
      assert(!empty());
      //not implemented yet
      
      return T(); //<- obviously wrong because of 
            // returned reference to tmp-Object
    }
   
    /* DESCRIPTION
     * It returns a reference to the last node of the list
     */
    T& back() {
      assert(!empty());

      //not implemented yet

      return T(); //<- obviously wrong because of
            // returned reference to tmp-Object
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
  //TODO: Freie Funktion reverse
  return List{};
} 

/* DESCRIPTION
 *  
 */
template<typename T>
List<T> operator+(List<T> const& lhs, List<T> const& rhs) {
  //TODO: Freie Funktion operator+ (4.14)
  return List{};
} 


#endif // # define BUW_LIST_HPP