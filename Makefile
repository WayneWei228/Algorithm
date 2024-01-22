CXX=g++
CXXFLAGS=--std=c++17

%: %.cpp
	$(CXX) $(CXXFLAGS) $<