#include <iostream>
#include <vector>
#include <algorithm>

size_t floor( size_t a, size_t b )
{
    return a / b + (( a % b ) > 0);
}

auto operator << (std::ostream & output, std::vector<ssize_t> & array)
{
    std::ostream_iterator<ssize_t> output_iterator = {output, " "};
    std::copy(array.begin(), array.end(), output_iterator);
    output << std::endl;
}

auto max_heapify( std::vector<ssize_t> & heap, size_t heap_size, size_t index ) -> void
{
    size_t left_index = (index + 1) * 2 - 1;
    size_t right_index = (index + 1) * 2;
    size_t largest_index = index;
    
    if ( left_index < heap_size && heap[ left_index ] > heap[ largest_index ] ) {
        largest_index = left_index;
    }
    if ( right_index < heap_size && heap[ right_index ] > heap[ largest_index ] ) {
        largest_index = right_index;
    }
    
    if ( index != largest_index ) {
        std::swap(heap[ index ], heap[ largest_index ]);
        max_heapify(heap, heap_size, largest_index);
    }
}

auto build_max_heap(std::vector<ssize_t> & array)
{
    size_t index = floor(array.size(), 2) - 1;
    do  {
        max_heapify(array, array.size(), index);
    } while ( index-- != 0);
}

auto heapsort(std::vector<ssize_t> & array)
{
    build_max_heap(array);

    size_t index = array.size() - 1;
    do {
        std::swap(array[0], array[index]);
        auto heap_size = index;
        max_heapify(array, heap_size, 0);
    } while ( index-- != 0 );
}

int main(int argc, const char * argv[]) {
    
    std::vector<ssize_t> array = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    
    std::cout << array;
    
    heapsort(array);
    
    std::cout << array;
    
    return 0;
}
