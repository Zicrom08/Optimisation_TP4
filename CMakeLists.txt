cmake_minimum_required(VERSION 3.10)
project(TP3 C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

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
        prim.h)
