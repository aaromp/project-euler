/******************************************************************************
 * File: FibonacciIterator.hh
 *
 * FibonacciIterator generically iterates accoring to Fibonacci sequence.  This
 * implementation was heavily influenced by Keith Schwarz. Visit
 * http://www.keithschwarz.com/interesting/code/?dir=fibonacci-iterator to check
 * out his nifty implementation.
 */
#ifndef FibonacciIterator_Included
#define FibonacciIterator_Included

#include <functional> // For std::plus, std::minus
#include <iterator>   // For std::bidirectional_iterator_tag, std::iterator


/**
 * An iterator class capable of stepping across the Fibonacci sequence using
 * user-specified integer, plus and minus types.
 */
template <typename Integer, typename Plus = std::plus<Integer>, typename Minus = std::minus<Integer> >
class FibonacciIterator: public std::iterator<std::bidirectional_iterator_tag, Integer> {
public:
    /**
     * Constructor: FibonacciIterator(Integer n = Integer(0))
     * Usage: FibonacciIterator<int> itr;
     * --------------------------------------------------------------------------
     * Constructs a new Fibonacci iterator traversing the Fibonacci sequence
     * whose first two terms are zero and one and that uses the specified plus
     * and minus function objects to navigate the sequence.
     */
    explicit FibonacciIterator(Integer n = 0, Integer zero = Integer(0), Integer one = Integer(1));
    
    
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
     * Moves the iterator one step forward or backward in the Fibonacci sequence.
     * If integer overflow occurs, the results depend on the type of the integer
     * being used as a counter.  If the iterator is backed up while at 0, nothing
     * happens.
     */
    void operator++ (int);
    void operator-- (int);
    
    
    Integer nthFibonacciNumber(Integer n);
    
    
private:
    /* The index, previous, current and next Fibonacci values in the sequence. */
    Integer i, prev, curr, nxt;
    
    /* The plus and minus operators. */
    Plus plus;
    Minus minus;
    
    /* Increments all instance variables to the next values in the sequence */
    void increment();
};

/* Comparison functions for FibonacciIterator. */
template <typename Integer, typename Plus, typename Minus>
bool operator== (FibonacciIterator<Integer, Plus, Minus> lhs,
                 FibonacciIterator<Integer, Plus, Minus> rhs);
template <typename Integer, typename Plus, typename Minus>
bool operator!= (FibonacciIterator<Integer, Plus, Minus> lhs,
                 FibonacciIterator<Integer, Plus, Minus> rhs);

/* * * * * Implementation Below This Point * * * * */



template <typename Integer>
Integer nthFibonacciNumber(Integer n) {
    // base case: n of 0 is defined to be 0
    if (n < Integer(1)) return Integer(0);

    // base case: n of 1 or 2 are defined to be 1
    if (n == Integer(1) || n == Integer(2)) return Integer(1);
    
    // recursive case: the fibonacci number is generated by adding the previous two terms.
    return nthFibonacciNumber(n - Integer(1)) + nthFibonacciNumber(n - Integer(2));
}


/* Constructor sets up the internal fields based on the parameters. */
template <typename Integer, typename Plus, typename Minus>
FibonacciIterator<Integer, Plus, Minus>::FibonacciIterator(Integer n, Integer zero, Integer one) {
    this->i = Integer(0);    
    plus = Plus();
    minus = Minus();

    prev = zero;
    curr = zero;
    nxt = one;
    
    
    // increment to appropriate n
    if (n != Integer(0))
        while (this->i < n)
            increment();
}


template <typename Integer, typename Plus, typename Minus>
Integer FibonacciIterator<Integer, Plus, Minus>::n() {
    return i;
}


template <typename Integer, typename Plus, typename Minus>
Integer FibonacciIterator<Integer, Plus, Minus>::previous() {
    return prev;
}


template <typename Integer, typename Plus, typename Minus>
Integer FibonacciIterator<Integer, Plus, Minus>::current() {
    return curr;
}


template <typename Integer, typename Plus, typename Minus>
Integer FibonacciIterator<Integer, Plus, Minus>::next() {
    return nxt;
}


template <typename Integer, typename Plus, typename Minus>
void FibonacciIterator<Integer, Plus, Minus>::increment() {
    Integer tmp = plus(curr, nxt);
    prev = curr;
    curr = nxt;
    nxt = tmp;
    
    this->i++;
}


/* Incrementing the Fibonacci iterator walks forward one step in the Fibonacci
 * series.
 */
template <typename Integer, typename Plus, typename Minus>
void FibonacciIterator<Integer, Plus, Minus>::operator++ (int) {
    increment();
}


/* Decrementing the Fibonacci iterator backs it up one step in the sequence. */
template <typename Integer, typename Plus, typename Minus>
void FibonacciIterator<Integer, Plus, Minus>::operator-- (int) {
    if (prev == Integer(1)) return;
    nxt = curr;
    curr = prev;
    prev = minus(nxt, curr);
    
    i--;
}

/* Equality comparisons just check if the two values have equal indeces. */
template <typename Integer, typename Plus, typename Minus>
bool operator== (FibonacciIterator<Integer, Plus, Minus> lhs,
                 FibonacciIterator<Integer, Plus, Minus> rhs) {
    return lhs.getN() == rhs.getN();
}

/* Disequality implemented in terms of equality. */
template <typename Integer, typename Plus, typename Minus>
bool operator!= (FibonacciIterator<Integer, Plus, Minus> lhs,
                 FibonacciIterator<Integer, Plus, Minus> rhs) {
    return !(lhs == rhs);
}

#endif