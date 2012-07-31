/******************************************************************************
 * File: TriangleIterator.hh
 *
 * TriangleIterator generically iterates accoring to triangle sequence.  This
 * implementation was heavily influenced by Keith Schwarz. Visit
 * http://www.keithschwarz.com/interesting/code/?dir=fibonacci-iterator to check
 * out his nifty implementation of a Fibonacci iterator.
 */
#ifndef TriangleIterator_Included
#define TriangleIterator_Included

#include <functional> // For std::plus, std::minus
#include <iterator>   // For std::bidirectional_iterator_tag, std::iterator


/**
 * An iterator class capable of stepping across the triangle sequence using
 * user-specified integer, plus and minus types.
 */
template <typename Integer, typename Plus = std::plus<Integer>, typename Minus = std::minus<Integer> >
class TriangleIterator: public std::iterator<std::bidirectional_iterator_tag, Integer> {
public:
    /**
     * Constructor: TriangleIterator(Integer n = Integer(0))
     * Usage: TriangleIterator<int> itr;
     * --------------------------------------------------------------------------
     * Constructs a new triangle iterator traversing the triangle sequence
     * whose first two terms are zero and one and that uses the specified plus
     * and minus function objects to navigate the sequence.
     */
    explicit TriangleIterator(Integer n = Integer(1));
    
    
    /**
     * n()
     * previous()
     * current()
     * next()
     * Usage: cout << itr.current() << endl;
     * --------------------------------------------------------------------------
     * Returns the value of the corresponding instance variable
     */
    Integer n();
    Integer previous();
    Integer current();
    Integer next();
    
    
    /**
     * operator++ (int);
     * operator-- (int);
     * Usage: itr++; itr--;
     * --------------------------------------------------------------------------
     * Moves the iterator one step forward or backward in the triangle sequence.
     * If integer overflow occurs, the results depend on the type of the integer
     * being used as a counter.  If the iterator is backed up while at 0, nothing
     * happens.
     */
    void operator++ (int);
    void operator-- (int);
    
    
private:
    /* The index, previous, current and next triangle values in the sequence. */
    Integer i, prev, curr, nxt;
    
    /* The plus and minus operators. */
    Plus plus;
    Minus minus;
    
    /* Increments all instance variables to the next values in the sequence */
    void increment();
};

/* Comparison functions for TriangleIterator. */
template <typename Integer, typename Plus, typename Minus>
bool operator== (TriangleIterator<Integer, Plus, Minus> lhs,
                 TriangleIterator<Integer, Plus, Minus> rhs);
template <typename Integer, typename Plus, typename Minus>
bool operator!= (TriangleIterator<Integer, Plus, Minus> lhs,
                 TriangleIterator<Integer, Plus, Minus> rhs);

/* * * * * Implementation Below This Point * * * * */


/* Constructor sets up the internal fields based on the parameters. */
template <typename Integer, typename Plus, typename Minus>
TriangleIterator<Integer, Plus, Minus>::TriangleIterator(Integer n) {
    this->i = Integer(1);
    plus = Plus();
    minus = Minus();
    
    prev = Integer(1);
    curr = Integer(1);
    nxt = Integer(3);
    
    
    // increment to appropriate n
    if (n > Integer(1))
        while (this->i < n)
            increment();
}


template <typename Integer, typename Plus, typename Minus>
Integer TriangleIterator<Integer, Plus, Minus>::n() {
    return i;
}


template <typename Integer, typename Plus, typename Minus>
Integer TriangleIterator<Integer, Plus, Minus>::previous() {
    return prev;
}


template <typename Integer, typename Plus, typename Minus>
Integer TriangleIterator<Integer, Plus, Minus>::current() {
    return curr;
}


template <typename Integer, typename Plus, typename Minus>
Integer TriangleIterator<Integer, Plus, Minus>::next() {
    return nxt;
}


template <typename Integer, typename Plus, typename Minus>
void TriangleIterator<Integer, Plus, Minus>::increment() {
    i++;
    
    prev = curr;
    curr = nxt;
    nxt = plus(curr, plus(i, Integer(1)));
}


/* Incrementing the triangle iterator walks forward one step in the triangle
 * series.
 */
template <typename Integer, typename Plus, typename Minus>
void TriangleIterator<Integer, Plus, Minus>::operator++ (int) {
    increment();
}


/* Decrementing the triangle iterator backs it up one step in the sequence. */
template <typename Integer, typename Plus, typename Minus>
void TriangleIterator<Integer, Plus, Minus>::operator-- (int) {
    //if (prev == Integer(1)) return;
    
    i--;
    
    nxt = curr;
    curr = prev;
    prev = minus(curr, i);
}

/* Equality comparisons just check if the two values have equal indeces. */
template <typename Integer, typename Plus, typename Minus>
bool operator== (TriangleIterator<Integer, Plus, Minus> lhs,
                 TriangleIterator<Integer, Plus, Minus> rhs) {
    return lhs.getN() == rhs.getN();
}

/* Disequality implemented in terms of equality. */
template <typename Integer, typename Plus, typename Minus>
bool operator!= (TriangleIterator<Integer, Plus, Minus> lhs,
                 TriangleIterator<Integer, Plus, Minus> rhs) {
    return !(lhs == rhs);
}

#endif