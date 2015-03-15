#generated by cxh

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra -pthread

all : BinarySearch
all : MaximumDepthofBinaryTree
all : Permutations
all : RemoveElement
all : SameTree
all : SingleNumber
all : SingleNumberII
all : strStr
all : UniqueSubsets
all : ValidParentheses

BinarySearch:
BinarySearch : BinarySearch.o
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $^ -o $@
MaximumDepthofBinaryTree:
MaximumDepthofBinaryTree : MaximumDepthofBinaryTree.o
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $^ -o $@
Permutations:
Permutations : Permutations.o
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $^ -o $@
RemoveElement:
RemoveElement : RemoveElement.o
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $^ -o $@
SameTree:
SameTree : SameTree.o
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $^ -o $@
SingleNumber:
SingleNumber : SingleNumber.o
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $^ -o $@
SingleNumberII:
SingleNumberII : SingleNumberII.o
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $^ -o $@
strStr:
strStr : strStr.o
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $^ -o $@
UniqueSubsets:
UniqueSubsets : UniqueSubsets.o
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $^ -o $@
ValidParentheses:
ValidParentheses : ValidParentheses.o
	$(CXX) $(CXXFLAGS) -lpthread -L$(GTEST_DIR) -lgtest_main $^ -o $@
.PHONY:clean
clean:
	-rm -f BinarySearch.o BinarySearch
	-rm -f MaximumDepthofBinaryTree.o MaximumDepthofBinaryTree
	-rm -f Permutations.o Permutations
	-rm -f RemoveElement.o RemoveElement
	-rm -f SameTree.o SameTree
	-rm -f SingleNumber.o SingleNumber
	-rm -f SingleNumberII.o SingleNumberII
	-rm -f strStr.o strStr
	-rm -f UniqueSubsets.o UniqueSubsets
	-rm -f ValidParentheses.o ValidParentheses
