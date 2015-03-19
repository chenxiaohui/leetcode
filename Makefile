#generated by cxh

CXXFLAGS += -isystem $(GTEST_DIR)/include -g -Wall -Wextra -pthread

all: BinarySearch MaximumDepthofBinaryTree Permutations RemoveElement SameTree SearchInsertPosition SearchforaRange SearchinRotatedSortedArray SearchinRotatedSortedArrayII SingleNumber SingleNumberII UniqueSubsets ValidParentheses strStr 
.PHONY:all

BinarySearch : BinarySearch.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
MaximumDepthofBinaryTree : MaximumDepthofBinaryTree.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
Permutations : Permutations.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
RemoveElement : RemoveElement.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
SameTree : SameTree.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
SearchInsertPosition : SearchInsertPosition.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
SearchforaRange : SearchforaRange.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
SearchinRotatedSortedArray : SearchinRotatedSortedArray.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
SearchinRotatedSortedArrayII : SearchinRotatedSortedArrayII.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
SingleNumber : SingleNumber.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
SingleNumberII : SingleNumberII.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
UniqueSubsets : UniqueSubsets.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
ValidParentheses : ValidParentheses.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@
strStr : strStr.cpp common.h
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $< -o $@

.PHONY:clean
clean:
	-rm -f BinarySearch.o BinarySearch
	-rm -f MaximumDepthofBinaryTree.o MaximumDepthofBinaryTree
	-rm -f Permutations.o Permutations
	-rm -f RemoveElement.o RemoveElement
	-rm -f SameTree.o SameTree
	-rm -f SearchInsertPosition.o SearchInsertPosition
	-rm -f SearchforaRange.o SearchforaRange
	-rm -f SearchinRotatedSortedArray.o SearchinRotatedSortedArray
	-rm -f SearchinRotatedSortedArrayII.o SearchinRotatedSortedArrayII
	-rm -f SingleNumber.o SingleNumber
	-rm -f SingleNumberII.o SingleNumberII
	-rm -f UniqueSubsets.o UniqueSubsets
	-rm -f ValidParentheses.o ValidParentheses
	-rm -f strStr.o strStr
