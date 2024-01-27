#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

ULListStr::~ULListStr()
{
    clear();
}

bool ULListStr::empty() const
{
    return size_ == 0;
}

size_t ULListStr::size() const
{
    return size_;
}

// WRITE YOUR CODE HERE

/*You need to examine the code provided in ulliststr.h and ulliststr.cpp and add the implementations
for push_back, push_front, pop_back, pop_front, back, front and getValAtLoc in ulliststr.cpp.*/

/**
 * Adds a new value to the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::push_back(const std::string& val)
{
    // if empty, update everything
    // go to tail + go to last + add 1 more
    // if last == arrsize, then new val
    // update size_
    if (this->empty())
    {
        head_, tail_ = new Item();
        tail_->first = 0;
        tail_->last = 1;
        tail_->val[(tail_->last) - 1] = val;
        ++(this->size_);
        head_ = tail_;
        return;
    }
    else if (tail_->last == ARRSIZE)
    {
        Item* temp = tail_;
        tail_ = new Item();
        tail_->prev = temp;
        temp->next = tail_;
        tail_->first = 0;
        tail_->last = 1;
        tail_->val[(tail_->last) - 1] = val;
        ++(this->size_);
        return;
    }
    else
    {
        tail_->val[tail_->last] = val;
        ++(tail_->last); // could also have done tail_->val[(tail_->last)++]...?
        ++(this->size_);
        return;
    }
}

/**
 * Removes a value from the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_back()
{
    if (this->empty()) {
        return;
    }

    if (tail_->last == 1)
    { // when pop_back results in an empty struct
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = NULL;
        tail_->last = ARRSIZE;
        delete temp;
        --(this->size_);
        return;
    }
    else
    {
        --(tail_->last);
        // delete tail_->val[tail_->last];
        --(this->size_);
        return;
    }
}

/**
 * Adds a new value to the front of the list.
 * If there is room before the 'first' value in
 * the head node add it there, otherwise,
 * allocate a new head node.
 *   - MUST RUN in O(1)
 */
void ULListStr::push_front(const std::string& val)
{
    if (this->empty())
    {
        head_, tail_ = new Item();
        head_->first = ARRSIZE - 1;
        head_->last = ARRSIZE;
        head_->val[head_->first] = val;
        ++(this->size_);
        return;
    }
    else if (head_->first == 0)
    {
        Item* temp = head_;
        head_ = new Item();
        head_->next = temp;
        temp->prev = head_;
        head_->last = ARRSIZE;
        head_->first = ARRSIZE - 1;
        head_->val[head_->first] = val;
        ++(this->size_);
        return;
    }
    else
    {
        --(head_->first);
        head_->val[head_->first] = val; // could also merge these two lines: head_->val[--(head_->first)];
        ++(this->size_);
        return;
    }
    // if empty, update everything
    // go to head, go to first, if first == 0 then create new val
    // else insert at first-1 and update first.
    // update size_
}

/**
 * Removes a value from the front of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_front()
{
    // if empty, ___
    // go to head, cast head as temp, move head one up, delete temp
    // size--;
    if (this->empty()) {
        return;
    }

    if (head_->first == ARRSIZE - 1)
    { // when you remove the last element in an Item struct
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = NULL;
        head_->first = 0;
        delete temp;
        --(this->size_);
        return;
    }
    else
    {
        ++(head_->first);
        --(this->size_);
        return;
    }
}

/**
 * Returns a const reference to the back element
 *   - MUST RUN in O(1)
 */
std::string const& ULListStr::back() const
{
    // if empty, return _
    // go to tail, go to last
    return tail_->val[(tail_->last) - 1];
}

/**
 * Returns a const reference to the front element
 *   - MUST RUN in O(1)
 */
std::string const& ULListStr::front() const
{
    // go to head, go to first
    return head_->val[head_->first];
}

/**
 * Returns a pointer to the item at index, loc,
 *  if loc is valid and NULL otherwise
 *   - MUST RUN in O(n)
 */
std::string* ULListStr::getValAtLoc(size_t loc) const
{
    // if loc is bigger than elements in list, throw error
    // else walk the list
    //if (loc > size_)
    //{
    //    return "ERROR: This loc doesn't exist!"; // error: Data Type not std::string* -- needs to be a ptr.
    //}

    if (loc > size_) {
        throw std::invalid_argument("Bad location");
    }

    // check validity of this call
    Item* temp = head_;
    size_t count = head_->first;
    for (int i = 0; i < loc; i++)
    {
        if (count == ARRSIZE - 1)
        {
            temp = temp->next;
            count = 1;
            continue;
        }
        count++;
    }
    return &temp->val[count]; // returns ptr to the val at that location
}

// MY CODE--END

void ULListStr::set(size_t loc, const std::string& val)
{
    std::string* ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
    std::string* ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const& ULListStr::get(size_t loc) const
{
    std::string* ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

void ULListStr::clear()
{
    while (head_ != NULL) {
        Item* temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}
