clean:
	rm -f *.o

bench_all: bench_is_array bench_is_array_v bench_is_bonded_array bench_is_bonded_array_v bench_is_const bench_is_const_v bench_is_function bench_is_function_v bench_is_member_function_pointer bench_is_member_function_pointer_v bench_is_member_object_pointer bench_is_member_object_pointer_v bench_is_member_pointer bench_is_member_pointer_v bench_is_object bench_is_object_v bench_is_pointer bench_is_pointer_v bench_is_reference bench_is_reference_v bench_is_scoped_enum bench_is_scoped_enum_v bench_is_unbounded_array bench_is_unbounded_array_v bench_is_volatile bench_is_volatile_v bench_remove_pointer

bench_is_array:
	./scripts/bench.sh is_array.cc
bench_is_array_v:
	./scripts/bench.sh is_array_v.cc

bench_is_bonded_array:
	./scripts/bench.sh is_bounded_array.cc
bench_is_bonded_array_v:
	./scripts/bench.sh is_bounded_array_v.cc

bench_is_const:
	./scripts/bench.sh is_const.cc
bench_is_const_v:
	./scripts/bench.sh is_const_v.cc

bench_is_function:
	./scripts/bench.sh is_function.cc
bench_is_function_v:
	./scripts/bench.sh is_function_v.cc

bench_is_member_function_pointer:
	./scripts/bench.sh is_member_function_pointer.cc
bench_is_member_function_pointer_v:
	./scripts/bench.sh is_member_function_pointer_v.cc

bench_is_member_object_pointer:
	./scripts/bench.sh is_member_object_pointer.cc
bench_is_member_object_pointer_v:
	./scripts/bench.sh is_member_object_pointer_v.cc

bench_is_member_pointer:
	./scripts/bench.sh is_member_pointer.cc
bench_is_member_pointer_v:
	./scripts/bench.sh is_member_pointer_v.cc

bench_is_object:
	./scripts/bench.sh is_object.cc
bench_is_object_v:
	./scripts/bench.sh is_object_v.cc

bench_is_pointer:
	./scripts/bench.sh is_pointer.cc
bench_is_pointer_v:
	./scripts/bench.sh is_pointer_v.cc

bench_is_reference:
	./scripts/bench.sh is_reference.cc
bench_is_reference_v:
	./scripts/bench.sh is_reference_v.cc

bench_is_scoped_enum:
	./scripts/bench.sh is_scoped_enum.cc
bench_is_scoped_enum_v:
	./scripts/bench.sh is_scoped_enum_v.cc

bench_is_unbounded_array:
	./scripts/bench.sh is_unbounded_array.cc
bench_is_unbounded_array_v:
	./scripts/bench.sh is_unbounded_array_v.cc

bench_is_volatile:
	./scripts/bench.sh is_volatile.cc
bench_is_volatile_v:
	./scripts/bench.sh is_volatile_v.cc

bench_remove_pointer:
	./scripts/bench.sh remove_pointer.cc
