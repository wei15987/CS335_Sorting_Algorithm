Wei Lian
CS335

1)This sorting algorithms program completed all parts.

2)the bugs i found is :the second part of this assignment, the program crash when the quick sort with first item to be pivot with sorted vector. If the vector is large, the quick sort algorithm crash.

3)Tested with provided txt file and type command
./test_sorting_algorithms sorted 2000000 greater
./test_sorting_algorithms random 2000000 greater
./test_sorting_algorithms sorted 2000000 less
./test_sorting_algorithms random 2000000 less
./test_qsort_algorithm sorted 2000000 greater
./test_qsort_algorithm random 2000000 greater
./test_qsort_algorithm sorted 2000000 less
./test_qsort_algorithm random 2000000 less




4)input file:none


Test Case:
Wei:Project4 WilliamLian$ ./test_sorting_algorithms sorted 2000000 greater
HeapSort: Runtime: 518561916ns
Verified: 1
Mergesort: Runtime: 413469892ns
Verified: 1
QuickSort: Runtime: 229796539ns
Verified: 1

Wei:Project4 WilliamLian$ ./test_qsort_algorithm random 2000 less
Testing quicksort: random, 2000, less
quicksort_median3: Runtime: 281497ns
Verified: 1
quicksort_middle: Runtime: 309019ns
Verified: 1
QuickSort_first: Runtime: 288104ns
Verified: 1

Wei:Project4 WilliamLian$ ./test_qsort_algorithm random 20000 greater
Testing quicksort: random, 20000, greater
quicksort_median3: Runtime: 3420246ns
Verified: 1
quicksort_middle: Runtime: 3879457ns
Verified: 1
QuickSort_first: Runtime: 3177114ns
Verified: 1

Wei:Project4 WilliamLian$ ./test_qsort_algorithm sorted 20000 greater
Testing quicksort: sorted, 20000, greater
quicksort_median3: Runtime: 1874718ns
Verified: 1
quicksort_middle: Runtime: 1264665ns
Verified: 1
QuickSort_first: Runtime: 814346010ns
Verified: 1

