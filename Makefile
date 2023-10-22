TRAITS = is_array is_array_v is_bounded_array is_bounded_array_v is_const is_const_v is_function is_function_v is_member_function_pointer is_member_function_pointer_v is_member_object_pointer is_member_object_pointer_v is_member_pointer is_member_pointer_v is_object is_object_v is_pointer is_pointer_v is_reference is_reference_v is_scoped_enum is_scoped_enum_v is_unbounded_array is_unbounded_array_v is_volatile is_volatile_v remove_pointer


clean:
	rm -f *.o

format:
	find . -name "*.hpp" -o -name "*.cc" | xargs clang-format -i


define generate-builds
build_$(1):
	./scripts/build.sh $(1).cc
	./scripts/build.sh $(1).cc --no-builtin
endef

$(foreach trait, $(TRAITS), $(eval $(call generate-builds,$(trait))))

build_all: $(foreach trait, $(TRAITS), build_$(trait))


define generate-benches
bench_$(1):
	./scripts/bench.sh $(1).cc
endef

$(foreach trait, $(TRAITS), $(eval $(call generate-benches,$(trait))))

bench_all: $(foreach trait, $(TRAITS), bench_$(trait))
