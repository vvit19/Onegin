TARGET = hamlet

CFlAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline\
 -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default\
  -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy\
   -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op\
    -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith\
	 -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits\
	  -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

COMPILE = g++ -c $^ $(CFlAGS)

.PHONY: all
all: $(TARGET)

$(TARGET): main.o file_work.o str_functions.o strings_sort.o comparator.o
	@g++ $^ -o $(TARGET) $(CFlAGS)

main.o: main.cpp 
	@$(COMPILE)

file_work.o: file_work.cpp
	@$(COMPILE)

str_functions.o: str_functions.cpp 
	@$(COMPILE)

strings_sort.o: strings_sort.cpp
	@$(COMPILE)

comparator.o: comparator.cpp
	@$(COMPILE)

.PHONY: clean
clean:
	rm -rf $(TARGET) *.o 
	rm -rf *.exe