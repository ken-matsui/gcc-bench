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
NO_BUILTIN := -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS

SAMPLE_SIZE := 10
WARMUP_SIZE := 3


.PHONY: clean
clean:
	rm -f *.o


format:
	find . -name "*.hpp" -o -name "*.cc" | xargs clang-format -i


build_%: %.cc
	$(CXX) $< $(OPTIONS)
	$(CXX) $< $(NO_BUILTIN) $(OPTIONS)

build_all: $(foreach trait, $(TRAITS), build_$(trait))


perf_setup:
	sudo sysctl -w kernel.perf_event_paranoid=1

run_time_no_builtin_%: %.cc
	perf stat -r 1 $(CXX) $< $(NO_BUILTIN) $(OPTIONS)
run_time_builtin_%: %.cc
	perf stat -r 1 $(CXX) $< $(OPTIONS)

warmup_time_no_builtin_%: %.cc
	@echo 'W/o built-in: Running warmup ($(WARMUP_SIZE))'
	@for i in `seq $(WARMUP_SIZE)`; do \
		$(MAKE) run_time_no_builtin_$* 2>&1 | grep 'seconds time elapsed' | awk '{print $$1}'; \
	done > /dev/null
warmup_time_builtin_%: %.cc
	@echo 'With built-in: Running warmup ($(WARMUP_SIZE))'
	@for i in `seq $(WARMUP_SIZE)`; do \
		$(MAKE) run_time_builtin_$* 2>&1 | grep 'seconds time elapsed' | awk '{print $$1}'; \
	done > /dev/null

bench_time_no_builtin_%: %.cc
	@echo 'W/o built-in: Running samples ($(SAMPLE_SIZE))'
	@for i in `seq $(SAMPLE_SIZE)`; do \
		$(MAKE) run_time_no_builtin_$* 2>&1 | grep 'seconds time elapsed' | awk '{print $$1}'; \
	done > ./reports/built-ins/$*/time_no_builtin.txt
bench_time_builtin_%: %.cc
	@echo 'With built-in: Running samples ($(SAMPLE_SIZE))'
	@for i in `seq $(SAMPLE_SIZE)`; do \
		$(MAKE) run_time_builtin_$* 2>&1 | grep 'seconds time elapsed' | awk '{print $$1}'; \
	done > ./reports/built-ins/$*/time_builtin.txt

bench_time_%: warmup_time_no_builtin_% bench_time_no_builtin_% warmup_time_builtin_% bench_time_builtin_%
	ministat -w 70 ./reports/built-ins/$*/time_no_builtin.txt ./reports/built-ins/$*/time_builtin.txt


run_peak_mem_no_builtin_%: %.cc
	/usr/bin/time -v $(CXX) $< $(NO_BUILTIN) $(OPTIONS)
run_peak_mem_builtin_%: %.cc
	/usr/bin/time -v $(CXX) $< $(OPTIONS)

warmup_peak_mem_no_builtin_%: %.cc
	@echo 'W/o built-in: Running warmup ($(WARMUP_SIZE))'
	@for i in `seq $(WARMUP_SIZE)`; do \
		$(MAKE) run_peak_mem_no_builtin_$* 2>&1 | grep 'Maximum resident set size' | awk '{print $$6}'; \
	done > /dev/null
warmup_peak_mem_builtin_%: %.cc
	@echo 'With built-in: Running warmup ($(WARMUP_SIZE))'
	@for i in `seq $(WARMUP_SIZE)`; do \
		$(MAKE) run_peak_mem_builtin_$* 2>&1 | grep 'Maximum resident set size' | awk '{print $$6}'; \
	done > /dev/null

bench_peak_mem_no_builtin_%: %.cc
	@echo 'W/o built-in: Running samples ($(SAMPLE_SIZE))'
	@for i in `seq $(SAMPLE_SIZE)`; do \
		$(MAKE) run_peak_mem_no_builtin_$* 2>&1 | grep 'Maximum resident set size' | awk '{print $$6}'; \
	done > ./reports/built-ins/$*/peak_mem_no_builtin.txt
bench_peak_mem_builtin_%: %.cc
	@echo 'With built-in: Running samples ($(SAMPLE_SIZE))'
	@for i in `seq $(SAMPLE_SIZE)`; do \
		$(MAKE) run_peak_mem_builtin_$* 2>&1 | grep 'Maximum resident set size' | awk '{print $$6}'; \
	done > ./reports/built-ins/$*/peak_mem_builtin.txt

bench_peak_mem_%: warmup_peak_mem_no_builtin_% bench_peak_mem_no_builtin_% warmup_peak_mem_builtin_% bench_peak_mem_builtin_%
	ministat -w 70 ./reports/built-ins/$*/peak_mem_no_builtin.txt ./reports/built-ins/$*/peak_mem_builtin.txt


run_total_mem_no_builtin_%: %.cc
	$(CXX) -ftime-report $< $(NO_BUILTIN) $(OPTIONS)
run_total_mem_builtin_%: %.cc
	$(CXX) -ftime-report $< $(OPTIONS)

warmup_total_mem_no_builtin_%: %.cc
	@echo 'W/o built-in: Running warmup ($(WARMUP_SIZE))'
	@for i in `seq $(WARMUP_SIZE)`; do \
		$(MAKE) run_total_mem_no_builtin_$* 2>&1 | grep TOTAL | awk '{print $$6}' | sed 's/M$$//'; \
	done > /dev/null
warmup_total_mem_builtin_%: %.cc
	@echo 'With built-in: Running warmup ($(WARMUP_SIZE))'
	@for i in `seq $(WARMUP_SIZE)`; do \
		$(MAKE) run_total_mem_builtin_$* 2>&1 | grep TOTAL | awk '{print $$6}' | sed 's/M$$//'; \
	done > /dev/null

bench_total_mem_no_builtin_%: %.cc
	@echo 'W/o built-in: Running samples ($(SAMPLE_SIZE))'
	@for i in `seq $(SAMPLE_SIZE)`; do \
		$(MAKE) run_total_mem_no_builtin_$* 2>&1 | grep TOTAL | awk '{print $$6}' | sed 's/M$$//'; \
	done > ./reports/built-ins/$*/total_mem_no_builtin.txt
bench_total_mem_builtin_%: %.cc
	@echo 'With built-in: Running samples ($(SAMPLE_SIZE))'
	@for i in `seq $(SAMPLE_SIZE)`; do \
		$(MAKE) run_total_mem_builtin_$* 2>&1 | grep TOTAL | awk '{print $$6}' | sed 's/M$$//'; \
	done > ./reports/built-ins/$*/total_mem_builtin.txt

bench_total_mem_%: warmup_total_mem_no_builtin_% bench_total_mem_no_builtin_% warmup_total_mem_builtin_% bench_total_mem_builtin_%
	ministat -w 70 ./reports/built-ins/$*/total_mem_no_builtin.txt ./reports/built-ins/$*/total_mem_builtin.txt


bench_%: %.cc
	mkdir -p ./reports/built-ins/$*
	@echo '--- Time: $* ---'
	@$(MAKE) bench_time_$*
	@echo '--- Peak memory: $* ---'
	@$(MAKE) bench_peak_mem_$*
	@echo '--- Total memory: $* ---'
	@$(MAKE) bench_total_mem_$*

bench_all: perf_setup $(foreach trait, $(TRAITS), bench_$(trait))


gen_report_%:
	echo "## `date`\n" >> ./$*.md

	echo '### Time\n' >> ./$*.md
	echo '```console' >> ./$*.md
	ministat -w 70 ./reports/built-ins/$*/time_no_builtin.txt ./reports/built-ins/$*/time_builtin.txt >> ./$*.md
	echo '```\n' >> ./$*.md

	echo '### Peak Memory Usage\n' >> ./$*.md
	echo '```console' >> ./$*.md
	ministat -w 70 ./reports/built-ins/$*/peak_mem_no_builtin.txt ./reports/built-ins/$*/peak_mem_builtin.txt >> ./$*.md
	echo '```\n' >> ./$*.md

	echo '### Total Memory Usage\n' >> ./$*.md
	echo '```console' >> ./$*.md
	ministat -w 70 ./reports/built-ins/$*/total_mem_no_builtin.txt ./reports/built-ins/$*/total_mem_builtin.txt >> ./$*.md
	echo '```\n' >> ./$*.md

	echo '---\n' >> ./$*.md

gen_report_all: $(foreach trait, $(TRAITS), gen_report_$(trait))

gen_charts:
	python3 ./scripts/gen-charts.py
