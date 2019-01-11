cmake_minimum_required(VERSION 3.10)
project(TP3 C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

set(COMPILE_FLAGS
		PRIVATE -pipe
		PRIVATE -march=native
		PRIVATE -Wall
		PRIVATE -Wextra)

add_executable(TP3
		ensemble.c
		ensemble.h
		file.c
		file.h
		filePrioritesMin.c
		filePrioritesMin.h
		graphe.c
		graphe.h
		kruskal.c
		kruskal.h
		liste.c
		liste.h
		ListeAdj.c
		ListeAdj.h
		main.c
		prim.c
		prim.h cycle.c cycle.h)

target_compile_options(TP3 ${COMPILE_FLAGS})
target_link_libraries(TP3 -Wl,--as-needed -lglpk)