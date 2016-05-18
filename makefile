#
# Compiler
#
compiler = g++


#
# Comliler opts
#
flags = -Wall -std=c++11 -pthread
libraries =


#
# Terminal commands
#
rm = rm
rm_r = rm -r
rm_f = rm -f
rm_rf = rm -rf
mkdir = mkdir
mkdir_p = mkdir -p

#
# Main target
#
target_name = iawar
target_rule = $(binaries_dir)/$(target_name)

#
# Directories
#
sources_dir = src
objects_dir = obj
binaries_dir = bin


#
# Target rule
#
all : createnv $(target_rule)

$(target_rule) : $(objects_dir)/main.o $(objects_dir)/opt.o $(objects_dir)/ropts.o $(objects_dir)/point.o $(objects_dir)/unit.o
	$(compiler) $(flags) $^ $(libraries) -o $@


#
# Dependency rule
#
main_dep = $(sources_dir)/main.c++ $(sources_dir)/defs.h++ $(sources_dir)/opt.h++ $(sources_dir)/ropts.h++ $(sources_dir)/point.h++ $(sources_dir)/unit.h++
$(objects_dir)/main.o : $(main_dep)
	$(compiler) -c $(flags) $< -o $@

opt_dep = $(sources_dir)/opt.c++ $(sources_dir)/opt.h++ $(sources_dir)/defs.h++
$(objects_dir)/opt.o : $(opt_dep)
	$(compiler) -c $(flags) $< -o $@

ropts_dep = $(sources_dir)/ropts.c++ $(sources_dir)/ropts.h++ $(sources_dir)/defs.h++ $(sources_dir)/opt.h++
$(objects_dir)/ropts.o : $(ropts_dep)
	$(compiler) -c $(flags) $< -o $@

point_dep = $(sources_dir)/point.c++ $(sources_dir)/point.h++ $(sources_dir)/defs.h++
$(objects_dir)/point.o : $(point_dep)
	$(compiler) -c $(flags) $< -o $@

unit_dep = $(sources_dir)/unit.c++ $(sources_dir)/unit.h++ $(sources_dir)/defs.h++
$(objects_dir)/unit.o : $(unit_dep)
	$(compiler) -c $(flags) $< -o $@


#
# Template rule
#
$(objects_dir)/%.o : $(sources_dir)/%.c++
	$(compiler) -c $(flags) $< -o $@


#
# Support rule
#
clean :
	$(rm_r) $(objects_dir)/*
	$(rm_r) $(binaries_dir)/*

forceclean :
	$(rm_rf) $(objects_dir)/*
	$(rm_rf) $(binaries_dir)/*

cleanall :
	$(rm_rf) $(objects_dir)/
	$(rm_rf) $(binaries_dir)/

createnv :
	$(mkdir_p) $(objects_dir) $(binaries_dir)


.PHONY : clean forceclean cleanall createnv
