#Setting variable
SRCS	= bulb.cpp lamp.cpp lamp-test.cpp
OBJS	= $(SRCS:.cpp=.o)
DEPS	= $(OBJS:.o=.d)
EXE	= lamp-test
CXXFLAGS = -std=c++11

# Rules: 
$(EXE): $(OBJS) 
  g++ $(CXXFLAGS) -o $@ $(OBJS)

# To include the .d dependency files + generate .d file + compile.o
-include $(DEPS)
.cpp.o:; g++ $(CXXFLAGS) -MMD -MP -c $<

#Clean function
clean:;	/bin/rm $(EXE) $(OBJS) $(DEPS)

#Prevent detection of object(bc they're intemediate)
.PRECIOUS: $(OBJS) %.o #