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
        head_ = new Item();
        tail_ = head_;
        tail_->first = 0;
        tail_->last = 1;
        tail_->val[(tail_->last) - 1] = val;
        ++(this->size_);
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

    if (tail_->first - tail_->last == 1)
    {
        Item* temp = tail_;
        tail_ = tail_->prev; /*will be set to NULL if there is no prev*/
        tail_->next = NULL;
        if (size_ == 1)
        {
            head_ = tail_;
        }
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
        head_ = new Item();
        tail_ = head_;
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
    if (this->empty()) {
        return;
    }

    /*the if statement handles the case where
    pop_front() pops a sole string at index ARRSIZE-1
    and also the case where there is only one string in the entire
    list, and pop_front() makes the list empty.*/
    if (head_->last - head_->first == 1)
    {
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = NULL;
        if (size_ == 1) /*special case where head + tail are alr pointing at the same place*/
        {
            tail_ = head_;
        }
        //head_->first = 0; /*unneeded*/
        delete temp;
        --(this->size_);
        return;
    }
    /*general case*/
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
    /*it is '>=' because size_t loc is an idx*/
    if (loc >= size_) {
        return NULL; /*invalid position*/
    }

    /*walks through the list*/
    Item* temp = head_;
    size_t count = head_->first;
    for (size_t i = 0; i < loc; i++)
    {
        if (count == ARRSIZE - 1)
        {
            temp = temp->next;
            count = 0; /*sets it to first idx*/
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
