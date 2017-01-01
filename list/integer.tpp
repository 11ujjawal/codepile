/* Given reference to two intgers stored as list, add them */
template <typename T>
node_ptr<T> add(node_ptr<T> numOne, node_ptr<T> numTwo) {
    node_ptr<int> sum, sumIter;
    sumIter = sum = nullptr;

    int total, carry = 0;

    while(numOne || numTwo) {
        total = carry;

        if(numOne) {
            total += numOne->data;
            numOne = numOne->next;
        }

        if(numTwo) {
            total += numTwo->data;
            numTwo = numTwo->next;
        }

        if(sum)
            sumIter->next = make_node(total % 10);
        else
            sum = make_node(total % 10);

        carry = total / 10;
    }

    return sum;
}

/* Check for pallindrome */
template <typename T>
bool pallindrome(const node_ptr<T>& head) {
    if(!head)
        return true;

    node_ptr<T> iter, slowIter, fastIter;
    iter = slowIter = fastIter = head;

    while(fastIter && fastIter->next) {
        fastIter = fastIter->next->next;
        slowIter = slowIter->next;
    }

    reverse(slowIter);
    while(slowIter) {
        if(iter->data != slowIter->data)
            return false;

        iter = iter->next;
        slowIter = slowIter->next;
    }

    return true;
}

template <typename T>
void sortEvenOdd(node_ptr<T>& head) {
    if(!head)
        return;

    node_ptr<T> even, odd, evenIter, oddIter;

    while(head) {
        if(head->data % 2 == 0) {
            if(even) {
                evenIter->next = head;
                evenIter = evenIter->next;
            } else {
                even = evenIter = head;
            }
        } else {
            if(odd) {
                oddIter->next = head;
                oddIter = oddIter->next;
            } else {
                odd = oddIter = head;
            }
        }

        head = head->next;
    }

    oddIter->next = nullptr;

    if(even) {
        evenIter->next = odd;
        head = even;
    }
    else
        head = odd;
}
