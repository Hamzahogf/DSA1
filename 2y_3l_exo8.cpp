#include<vector>
#include<iterator>

template <typename Object>
typename Vector<Object>::iterator Vector<Object>::insert(iterator pos, const Object& x) {
    Object* iter = &objects[0];            // Initialize an iterator pointing to the start of the array `objects`.
    Object* oldArray = objects;            // Store the current array in `oldArray` for later copying.
    theSize++;                             // Increment the size to reflect the addition of a new element.

    // Increase capacity if needed
    if (theCapacity < theSize) {           // Check if the current capacity is less than the new size.
        theCapacity = (theCapacity == 0) ? 1 : 2 * theCapacity; // If capacity is zero, set it to 1; otherwise, double it.
    }

    // Allocate new array with updated capacity
    objects = new Object[theCapacity];     // Allocate a new array with the updated capacity, pointed to by `objects`.

    int i = 0;                             // Initialize `i` to track the index in the new array.
    // Copy elements up to the insertion point
    while (iter != pos) {                  // Copy elements from the old array to the new array up to the insertion point.
        objects[i] = oldArray[i];          // Copy each element from `oldArray` to `objects` at index `i`.
        iter++;                            // Move the iterator one position forward in the old array.
        i++;                               // Move to the next index in the new array.
    }

    // Insert the new element
    objects[i] = x;                        // Insert the new element `x` at index `i` in the new array.

    // Copy remaining elements after the insertion point
    for (int k = i + 1; k < theSize; k++) { // Copy the remaining elements from `oldArray` to `objects`.
        objects[k] = oldArray[k - 1];      // Shift elements by one position in the new array to account for the inserted element.
    }

    // Free the old array
    delete[] oldArray;                     // Deallocate the memory used by `oldArray` to prevent memory leaks.

    // Return iterator to the newly inserted element
    return &objects[i];                    // Return an iterator (pointer) to the newly inserted element.
}


template <typename Object>
typename Vector<Object>::iterator Vector<Object>::erase(iterator pos) {
    int index = pos - &objects[0];         // Calculate the index of `pos` by subtracting the starting address of `objects`.

    // Shift elements to the left to fill the gap
    for (int i = index; i < theSize - 1; i++) { // Start from the `pos` index and move elements left to fill the gap.
        objects[i] = objects[i + 1];       // Move the element one position to the left.
    }

    --theSize;                             // Decrease the size since we removed one element.

    // Return iterator to the next element (or end if at last element)
    return &objects[index];                // Return an iterator pointing to the next element after the erased position.
}



iterator erease(iterator pos){
    copy(pos+1,end(),pos);
    resize(size()-1);
    return pos;
}