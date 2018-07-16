#ifndef SOLVER_GLOBAL_H
#define SOLVER_GLOBAL_H

#if defined(SOLVER_LIBRARY)
#  define SOLVERSHARED_EXPORT __declspec( dllexport )
#else
#  define SOLVERSHARED_EXPORT __declspec( dlleimport )
#endif

#endif // SOLVER_GLOBAL_H
