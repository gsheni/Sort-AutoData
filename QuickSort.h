#include <vector>
#include <functional>
using namespace std;
int quickswapcount = 0;
template <typename Comparable>
void insertionSort( vector<Comparable> & a, int left, int right ){
    for( int p = left + 1; p <= right; ++p ){
        Comparable tmp = std::move( a[ p ] );
        int j;

        for( j = p; j > left && tmp < a[ j - 1 ]; --j ){
            a[ j ] = std::move( a[ j - 1 ] );
            quickswapcount++;
        }
        a[ j ] = std::move( tmp );
    }
}
template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right ){
    int center = ( left + right ) / 2;

    if( a[ center ] < a[ left ] ){
        std::swap( a[ left ], a[ center ] );
            quickswapcount++;
    }
    if( a[ right ] < a[ left ] ){
        std::swap( a[ left ], a[ right ] );
            quickswapcount++;
    }
    if( a[ right ] < a[ center ] ){
        std::swap( a[ center ], a[ right ] );
            quickswapcount++;
    }

    std::swap( a[ center ], a[ right - 1 ] );
    quickswapcount++;
    return a[ right - 1 ];
}
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right ){
        int swapcount = 0;
        if( left + 10 <= right ){
        const Comparable & pivot = median3( a, left, right );
        int i = left, j = right - 1;
        for( ; ; ){
        while( a[ ++i ] < pivot ) { }
        while( pivot < a[ --j ] ) { }
                if( i < j ){
                std::swap( a[ i ], a[ j ] );
                quickswapcount++;
                }
                else
                break;
        }

        std::swap( a[ i ], a[ right - 1 ] ); 
        quickswapcount++;

        quicksort( a, left, i - 1 );     
        quicksort( a, i + 1, right ); 
    }
    else  
        insertionSort( a, left, right );
}

template <typename Comparable>
void quicksort( vector<Comparable> & a )
{
    quicksort( a, 0, a.size( ) - 1 );
}
