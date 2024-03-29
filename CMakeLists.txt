cmake_minimum_required(VERSION 3.17)
project(data-structure)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -fsanitize=leak -g")

add_executable(data-structure main.cpp 05_array/array.c 05_array/array.h data/LinkedList.hpp data/ArrayStack.hpp data/LinkedListStack.hpp data/ArrayQueue.hpp data/LinkedListQueue.hpp algorithm/Sorts.hpp algorithm/Search.hpp data/SortedSet.hpp data/HashMap.hpp data/BinarySearchTree.hpp data/Heap.hpp data/Graph.hpp)
add_executable(4-median-of-two-sorted-arrays leetcode/editor/cn/4-median-of-two-sorted-arrays.cpp)
add_executable(23-merge-k-sorted-lists leetcode/editor/cn/23-merge-k-sorted-lists.cpp)
add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp)
add_executable(2-add-two-numbers leetcode/editor/cn/2-add-two-numbers.cpp)
add_executable(3-longest-substring-without-repeating-characters leetcode/editor/cn/3-longest-substring-without-repeating-characters.cpp)
add_executable(5-longest-palindromic-substring leetcode/editor/cn/5-longest-palindromic-substring.cpp)
add_executable(403-frog-jump leetcode/editor/cn/403-frog-jump.cpp)
add_executable(137-single-number-ii leetcode/editor/cn/137-single-number-ii.cpp)
add_executable(6-zigzag-conversion leetcode/editor/cn/6-zigzag-conversion.cpp)
add_executable(7-reverse-integer leetcode/editor/cn/7-reverse-integer.cpp)
add_executable(8-string-to-integer-atoi leetcode/editor/cn/8-string-to-integer-atoi.cpp)
add_executable(690-employee-importance leetcode/editor/cn/690-employee-importance.cpp)
add_executable(9-palindrome-number leetcode/editor/cn/9-palindrome-number.cpp)
add_executable(10-regular-expression-matching leetcode/editor/cn/10-regular-expression-matching.cpp)
add_executable(11-container-with-most-water leetcode/editor/cn/11-container-with-most-water.cpp)
add_executable(25-reverse-nodes-in-k-group leetcode/editor/cn/25-reverse-nodes-in-k-group.cpp)
add_executable(19-remove-nth-node-from-end-of-list leetcode/editor/cn/19-remove-nth-node-from-end-of-list.cpp)
add_executable(30-substring-with-concatenation-of-all-words leetcode/editor/cn/30-substring-with-concatenation-of-all-words.cpp)
add_executable(32-longest-valid-parentheses leetcode/editor/cn/32-longest-valid-parentheses.cpp)
add_executable(104-maximum-depth-of-binary-tree leetcode/editor/cn/104-maximum-depth-of-binary-tree.cpp)
add_executable(105-construct-binary-tree-from-preorder-and-inorder-traversal leetcode/editor/cn/105-construct-binary-tree-from-preorder-and-inorder-traversal.cpp)
add_executable(141-linked-list-cycle leetcode/editor/cn/141-linked-list-cycle.cpp)
add_executable(142-linked-list-cycle-ii leetcode/editor/cn/142-linked-list-cycle-ii.cpp)
add_executable(1720-decode-xored-array leetcode/editor/cn/1720-decode-xored-array.cpp)
add_executable(295-find-median-from-data-stream leetcode/editor/cn/295-find-median-from-data-stream.cpp)
add_executable(15-3sum leetcode/editor/cn/15-3sum.cpp)
add_executable(169-majority-element leetcode/editor/cn/169-majority-element.cpp)
add_executable(41-first-missing-positive leetcode/editor/cn/41-first-missing-positive.cpp)
add_executable(20-valid-parentheses leetcode/editor/cn/20-valid-parentheses.cpp)
add_executable(150-evaluate-reverse-polish-notation leetcode/editor/cn/150-evaluate-reverse-polish-notation.cpp)
add_executable(641-design-circular-deque leetcode/editor/cn/641-design-circular-deque.cpp)
add_executable(239-sliding-window-maximum leetcode/editor/cn/239-sliding-window-maximum.cpp)
add_executable(70-climbing-stairs leetcode/editor/cn/70-climbing-stairs.cpp)
add_executable(69-sqrtx leetcode/editor/cn/69-sqrtx.cpp)
add_executable(344-reverse-string leetcode/editor/cn/344-reverse-string.cpp)
add_executable(151-reverse-words-in-a-string leetcode/editor/cn/151-reverse-words-in-a-string.cpp)
add_executable(226-invert-binary-tree leetcode/editor/cn/226-invert-binary-tree.cpp)
add_executable(98-validate-binary-search-tree leetcode/editor/cn/98-validate-binary-search-tree.cpp)
add_executable(112-path-sum leetcode/editor/cn/112-path-sum.cpp)
add_executable(200-number-of-islands leetcode/editor/cn/200-number-of-islands.cpp)
add_executable(36-valid-sudoku leetcode/editor/cn/36-valid-sudoku.cpp)
add_executable(64-minimum-path-sum leetcode/editor/cn/64-minimum-path-sum.cpp)
add_executable(322-coin-change leetcode/editor/cn/322-coin-change.cpp)
add_executable(121-best-time-to-buy-and-sell-stock leetcode/editor/cn/121-best-time-to-buy-and-sell-stock.cpp)
add_executable(122-best-time-to-buy-and-sell-stock-ii leetcode/editor/cn/122-best-time-to-buy-and-sell-stock-ii.cpp)
add_executable(123-best-time-to-buy-and-sell-stock-iii leetcode/editor/cn/123-best-time-to-buy-and-sell-stock-iii.cpp)
add_executable(993-cousins-in-binary-tree leetcode/editor/cn/993-cousins-in-binary-tree.cpp)
add_executable(188-best-time-to-buy-and-sell-stock-iv leetcode/editor/cn/188-best-time-to-buy-and-sell-stock-iv.cpp)
add_executable(206-reverse-linked-list leetcode/editor/cn/206-reverse-linked-list.cpp)
add_executable(225-implement-stack-using-queues leetcode/editor/cn/225-implement-stack-using-queues.cpp)
add_executable(509-fibonacci-number leetcode/editor/cn/509-fibonacci-number.cpp)
add_executable(495-teemo-attacking leetcode/editor/cn/495-teemo-attacking.cpp)
add_executable(530-minimum-absolute-difference-in-bst leetcode/editor/cn/530-minimum-absolute-difference-in-bst.cpp)
add_executable(559-maximum-depth-of-n-ary-tree leetcode/editor/cn/559-maximum-depth-of-n-ary-tree.cpp)
add_executable(21-merge-two-sorted-lists leetcode/editor/cn/21-merge-two-sorted-lists.cpp)
add_executable(12-integer-to-roman leetcode/editor/cn/12-integer-to-roman.cpp)
add_executable(173-binary-search-tree-iterator leetcode/editor/cn/173-binary-search-tree-iterator.cpp)
add_executable(143-reorder-list leetcode/editor/cn/143-reorder-list.cpp)
add_executable(146-lru-cache leetcode/editor/cn/146-lru-cache.cpp)
add_executable(147-insertion-sort-list leetcode/editor/cn/147-insertion-sort-list.cpp)
add_executable(148-sort-list leetcode/editor/cn/148-sort-list.cpp)
add_executable(328-odd-even-linked-list leetcode/editor/cn/328-odd-even-linked-list.cpp)
add_executable(13-roman-to-integer leetcode/editor/cn/13-roman-to-integer.cpp)
add_executable(14-longest-common-prefix leetcode/editor/cn/14-longest-common-prefix.cpp)
add_executable(16-3sum-closest leetcode/editor/cn/16-3sum-closest.cpp)
add_executable(17-letter-combinations-of-a-phone-number leetcode/editor/cn/17-letter-combinations-of-a-phone-number.cpp)
add_executable(18-4sum leetcode/editor/cn/18-4sum.cpp)