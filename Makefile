TRAITS = is_array is_array_v is_bounded_array is_bounded_array_v is_const is_const_v is_function is_function_v is_member_function_pointer is_member_function_pointer_v is_member_object_pointer is_member_object_pointer_v is_member_pointer is_member_pointer_v is_object is_object_v is_pointer is_pointer_v is_reference is_reference_v is_scoped_enum is_scoped_enum_v is_unbounded_array is_unbounded_array_v is_volatile is_volatile_v remove_pointer

CXX := cc1plus

CC1PLUS_DIR := $(shell dirname $(shell which $(CXX)))
GCC_BUILD_DIR := $(CC1PLUS_DIR)/..
GCC_DIR := $(GCC_BUILD_DIR)/..

# Set include & link directories
INCLUDE_PATHS := \
    $(GCC_BUILD_DIR)/x86_64-pc-linux-gnu/libstdc++-v3/include \
    $(GCC_BUILD_DIR)/x86_64-pc-linux-gnu/libstdc++-v3/include/x86_64-pc-linux-gnu

# Set C++ version (C++23 by default)
CXX_VERSION := c++2b

OPTIONS := -quiet -std=$(CXX_VERSION) $(addprefix -I,$(INCLUDE_PATHS))


clean:
	rm -f *.o

format:
	find . -name "*.hpp" -o -name "*.cc" | xargs clang-format -i


define generate-builds
build_$(1): $(1).cc
	$(CXX) $(1).cc $(OPTIONS)
	$(CXX) $(1).cc -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS $(OPTIONS)
endef

$(foreach trait, $(TRAITS), $(eval $(call generate-builds,$(trait))))

build_all: $(foreach trait, $(TRAITS), build_$(trait))


define generate-benches
bench_$(1):
	./scripts/bench.sh $(1).cc
endef

$(foreach trait, $(TRAITS), $(eval $(call generate-benches,$(trait))))

bench_all: $(foreach trait, $(TRAITS), bench_$(trait))
